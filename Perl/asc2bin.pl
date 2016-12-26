#!/usr/bin/perl -w
#use strict;

#
# Ce programme transforme un fichier ASCII en binaire
#
$infile = 'Z:/ENERIUM50/src/dsp/sorties/N0075.asc';
$outfile = 'Z:/ENERIUM50/src/dsp/sorties/N0075.bin';
open(F_IN,"<$infile") or die"open: $!";
open(F_OUT, ">$outfile") or die"open: $!"; #suppression du fichier précédent
close(F_OUT);
open(F_OUT, ">>$outfile") or die"open: $!";
binmode(F_OUT);
# On saute la première ligne
$line = <F_IN>;
# on scanne toutes les lignes
while( defined( $line = <F_IN> ) ) {
   chomp($line);  # avoid \n on last field
   @array = split(' ',$line);

   # on stoppe si on rencontre le caractère ETX
   if( scalar(@array) == 1 ) {
       last if( $array[0] eq chr(3) );
   }
   
   for( $i=0; $i<scalar(@array); $i++) {
      print(F_OUT chr(hex($array[$i])));
   }
}
close(F_IN);
close(F_OUT);

# fin script
