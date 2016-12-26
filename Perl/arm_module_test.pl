#!/usr/bin/perl -w

################################################################################
#
#     Script to generate the ARM target and c-reference code
#     and to perform a comparision between target results 
#
################################################################################

################################################################################
# Author:    Anthony Rabine
# History:
#   DATE         VERSION     COMMENT                                      AUTHOR
#
#   28-May-2003, Version  1: initial version                                 ARE
################################################################################

use Getopt::Long;

# global variables
my $mod = "fms";
my $tests = "ss";
my $ctarg = "c-target";
my $cref = "c-ref";
my $cmd = "Ligne de commande\n";
my $vega = "$ENV{VEGA_DSP_PROJECT_ROOT}";
my $test_dir = "$ENV{VEGA_DSP_MODULE_TEST_DIR}";
my $project_root = $test_dir.$mod."/";
my $vob_root = $vega."/code/".$mod;
my $dirctarg = $project_root.$ctarg;
my $dircref =  $project_root.$cref;
my $log_file_build = "log_FMS_build.txt";
my $log_file_build_err = "log_FMS_build.err";
my $build_ok_file = "fms_play";
my $build_targ_result = "NOK";
my $build_ref_result = "NOK";
my $outfile = "raw_data_out.txt";
my $log_file_diff = "log_diff.txt";

#local $all_options="clear env build testcref testtarg comp";

# 
# get command line options
#

GetOptions(
           'testparts=s'=>\$tests
          );
#
# Test environment parameters
#

if(not (-d $test_dir))
{
  # try to execute the script to prepare environment
  my $execfile = $vega."/x/environment/vega_dsp_cshrc.csh";
  if(-f $execfile)
  {
	  print "source ".$execfile."\n";
	  system("source ".$execfile);
  }
  else
  {
	  print "Cannot access to the prepare script.";
	  print "\nPlease load your personal ClearCase view and verify the VEGA_DSP_PROJECT_ROOT env. variable.\n";
	  exit;
  }
}

#
# erase all files in directories
#

if ($tests=~/.*clear.*/ || $tests=~/.*all.*/)
{
  pr("Erasing all files...","=");

  if (-d $project_root.$ctarg)
  {
    # erase files in c-target directory
    $cmd = "rm -f -r ".$project_root.$ctarg."/*";
    print $cmd." \n";
    system($cmd);
  }
  if (-d $project_root.$cref)
  {
	# erase files in c-ref directory
    $cmd = "rm -f -r ".$project_root.$cref."/*";
    print $cmd." \n";
    system($cmd);
  }
}

#
# create directories
#

if ($tests=~/.*env.*/ || $tests=~/.*all.*/)
{
    pr("Create directories and link makefiles","=");

    if (-d $dirctarg)
    {  
        print "Directory Exists: ".$dirctarg."\n";
    }
	else
    {
        my $t = mkdir $dirctarg, 0755;
        if ($t eq 0)
        {
            die "CreateDir ERROR (".$dirctarg.") $!\n";
			exit;
        }
        print "Create Directory: ".$dirctarg."\n";
    }

    if (-d $dircref)
    {  
        print "Directory Exists: ".$dircref."\n";
    }
	else
    {
        my $t = mkdir $dircref, 0755;
        if ($t eq 0)
        {
            die "CreateDir ERROR (".$dircref.") $!\n";
			exit;
        }
        print "Create Directory: ".$dircref."\n";
    }

	# Copy makefile for C-target and C-ref

	print "\nLinking makefiles...\n";

	if(-f $dirctarg."/makefile")
	{
	   print "File Exists: ".$dirctarg."/makefile\n";
	}
	else
	{
	  $cmd = "ln -s ".$vob_root."/tstu/makefile_arm ".$dirctarg."/makefile";
	  print $cmd."\n";
	  system($cmd);
	}
	if(-f $dircref."/makefile")
	{
	   print "File Exists: ".$dircref."/makefile\n";
	}
	else
	{
	  $cmd = "ln -s ".$vob_root."/tstu/makefile_c ".$dircref."/makefile";
	  print $cmd."\n";
	  system($cmd);
	}

	# Generate links
	print "cd $dirctarg\ngmake links\n";
	system("cd $dirctarg ; gmake links");
	
	print "cd $dircref\ngmake links\n";
	system("cd $dircref ; gmake links");
	

}

if ($tests=~/.*build.*/ || $tests=~/.*all.*/)
{
  pr("Building c-target...","=");
  print "cd $dirctarg\ngmake play\n";
  system("cd $dirctarg ; gmake play > $log_file_build 2> $log_file_build_err");

  checkBuild($dirctarg, "C-target");
  
  pr("Building c-reference...","=");
  print "cd $dircref\ngmake play\n";
  system("cd $dircref ; gmake play > $log_file_build 2> $log_file_build_err");
  
  checkBuild($dircref, "C-reference");


}

if ($tests=~/.*testcref.*/ || $tests=~/.*all.*/)
{
  # not necessary to re-check if previously done
  if (not($tests=~/.*build.*/))
  {
	 checkBuild($dircref, "C-reference");
  }

  if($build_ref_result eq "OK")
  {
	pr("Running C-reference unitary test...","=");
	print "cd $dircref\nfms_play timbre.swift cucaracha.psf $outfile\n";
	system("cd $dircref ; fms_play timbre.swift cucaracha.psf $outfile");
	print "\nSee log results in raw_data_out.txt\n";
  }
  else
  {
	print "!!! ERROR : can't find executable of C-reference.\n";
  }

}

if ($tests=~/.*testtarg.*/ || $tests=~/.*all.*/)
{
  # not necessary to re-check if previously done
  if (not($tests=~/.*build.*/))
  {
	checkBuild($dirctarg, "C-target");
  }

  if($build_targ_result eq "OK")
  {
	pr("Running C-target unitary test...","=");
	print "cd $dirctarg\narmsd -e fms_play timbre.swift cucaracha.psf $outfile\n";
	# option -sc armscript.script to load script file
	system("cd $dirctarg ; armsd -e fms_play timbre.swift cucaracha.psf $outfile");
	print "\nSee log results in raw_data_out.txt\n";
  }
  else
  {
	print "!!! ERROR : can't find executable of C-target.\n";
  }

}

if ($tests=~/.*comp.*/ || $tests=~/.*all.*/)
{
  pr("Compare Outputs");

  # compare "$outfile" between C-reference and C-target


  if ((-f $dirctarg."/".$outfile) and (-f $dircref."/".$outfile))
  {
	$cmd = "diff $dirctarg/$outfile $dircref/$outfile > ../$log_file_diff";
	print $cmd."\n";
	$res = system($cmd);
	if ($res == 0)
	{
	  print "... No differences found in $outfile between c-reference and target ! \n";
	}
	else
	{
	  print "!!! ERROR : Differences found in $outfile between c-reference and target ! See ".$project_root.$log_file_diff." \n";
	}
  }
  else
  {
	  print "... !!! output file $outfile does not exist in $dirctarg and/or $dircref \n";
  }
 
}

#############################################################################################


  # PARAMETERS :
  #   $text, $seperator_sign
  # DESCRIPTION :
  #   print text to screen
  #   add a line above and below text
  # RETURN VALUE :
  #   none

sub pr
{
    my $str = shift @_;
    my $sign= shift @_;
    if (not $sign)
    {
        $sign="*";
    }
    my $p = (40-length($str))/2;
    print "\n".$sign x 50,"\n";
    print "    $str\n"; 
    print $sign x 50,"\n\n";
    #"***************************************************\n";
}

  # PARAMETERS :
  #   $path
  # DESCRIPTION :
  #   check, if file build_ok exists in parameter $path
  #   write message about build_ok to protocol
  # RETURN VALUE :
  #   none

sub checkBuild
{
    my $path=shift @_;
    my $name=shift @_;
    $path.="/".$build_ok_file;
    if (-e $path)
    {
        print "... building $name SUCCESSFUL \n";
		if($name eq "C-reference")
		{
		  $build_ref_result = "OK";
		}
		if($name eq "C-target")
		{
		  $build_targ_result = "OK";
		}
    }
    else
    {
        print "!!! ERROR : building $name FAILED \n"; 
    }
}
