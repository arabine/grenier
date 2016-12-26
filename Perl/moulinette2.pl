#!/usr/bin/perl -w
#use strict;

$fichier = 'N0058.bin';
$fichier2 = 'N0058.txt';
open(FNAME,"<$fichier") or die"open: $!";
open(FNAME2,">$fichier2") or die"open: $!";

binmode(FNAME);

my $i = 0;
while(!eof(FNAME)) {
  $v = sprintf("%02X ", ord(getc(FNAME)) );
  print(FNAME2 $v);
  $i++;
  if( $i == 24 ) {
    $i = 0;
    print(FNAME2 "\n");
  }
}

close(FNAME);
close(FNAME2);


# fin script
