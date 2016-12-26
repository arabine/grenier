#!/usr/bin/perl

use strict;
use warnings;
use Digest::CRC;

my $string = "Hello Word. How are you?";

my $ctx = Digest::CRC->new(type=>"crc32");
$ctx->add($string);

print "CRC for '$string' is 0x" . $ctx->hexdigest . "\n";
