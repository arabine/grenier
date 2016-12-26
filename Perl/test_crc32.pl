#!/usr/bin/perl

use strict;
use warnings;
use Digest::CRC;

my $string = "factory184032EJH";

my $ctx = Digest::CRC->new(type=>"crc32");
$ctx->add($string);

print "CRC for '$string' is 0x" . $ctx->hexdigest . "\n";
