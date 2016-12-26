#!/usr/bin/perl -w
#use strict;

$fichier = 'log_hex.txt';
$fichier2 = 'log_hex2.txt';
open(FNAME,"<$fichier") or die"open: $!";
open(FNAME2,">$fichier2") or die"open: $!";

@t = split( / /, <FNAME>);

my $i = 0;
foreach $v (@t) {
  print(FNAME2 $v );
  print(FNAME2 ' ');
  $i++;
  if( $i == 24 ) {
    $i = 0;
    print(FNAME2 "\n");
  }
}

close(FNAME);
close(FNAME2);


# fin script
