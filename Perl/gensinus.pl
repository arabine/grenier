#!/usr/bin/perl -w
#use strict;
use Math::Trig;

#
# Ce script permet de générer un tableau de 128 échantillons d'un sinus
#


$file_out = 'sin_table.c';
$buffer = "const uint16 sin_table[128] = {";

for( my $i=0; $i<128; $i++ ) { 
    #my $val = int(16000*sin(2*3.1415927*(52.7/6745.6)*$i)+32768);
    my $val = int(20000*sqrt(2)*sin(2*3.1415927*(52.7/6745.6)*$i)+32768);
    print $val."\n";
    $buffer = $buffer."$val,";
}

$buffer = $buffer."};";

open(FNAME, ">$file_out");
print(FNAME $buffer );
close(FNAME);


# fin script
