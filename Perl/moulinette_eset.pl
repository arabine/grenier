#!/usr/bin/perl -w
use XML::Parser;
use XML::Simple;
use Data::Dumper;

my $file = 'eset.xml';
my $xml = XML::Simple->new();
my $data = $xml->XMLin($file);

foreach $e (@{$data->{PACKAGE}})
{
    print  $e->{STRING}->{ORIGINAL} . "\t" . 
            $e->{STRING}->{TRANSLATION}->[0] . "\t" . 
            $e->{STRING}->{TRANSLATION}->[1] . "\t" . 
            $e->{STRING}->{TRANSLATION}->[2] . "\t" . 
            $e->{STRING}->{TRANSLATION}->[3] . "\n";

}

# fin script
