#!/usr/bin/perl -w
#use strict;

#
# Ce programme incrémente le numéro de version build
#
$fichier = 'Z:/ENERIUM50/src/dsp/source/systeme/version.h';
open(FNAME,"<$fichier") or die"open: $!";
$buffer = '';
# on scanne toutes les lignes
while( defined( $line = <FNAME> ) ) {
	# on cherche le bon define
	if( $line =~ m/define _APPLI_BUILD_   \(0x/ ) {
      # ok on choppe le numéro de version
      $version = substr($line, 27, 2);
      # on incrémente la version
      if( $version eq 'FF' ) {
         $hex = '00';
      } else {
         $hex = sprintf("%x", hex($version)+1);
      }
      # enfin on remplace par la nouvelle version
      $line =~ s/$version/$hex/;
   }
   $buffer = $buffer . $line;

}
close(FNAME);
open(FNAME, ">$fichier");
print(FNAME $buffer );
close(FNAME);
# fin script
