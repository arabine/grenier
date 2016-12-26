#!/usr/bin/perl
#use strict;

$dossier = "./";
opendir DIR, $dossier or die "$erreur";

@files = readdir DIR;
foreach $fichier (@files) {
	if (-f $fichier) {
		if( $fichier =~ m/\.c$/ ) {
			open(FNAME, "<$fichier");
			$buffer = "";
			while( defined( $l = <FNAME> ) ) {
				$buffer = $buffer . substr($l, 6, 1024);
				#print( FNAME2 $line_out );
			}
			close(FNAME);
			open(FNAME, ">$fichier");
			print(FNAME $buffer );
			close(FNAME);
		}
	}
}

