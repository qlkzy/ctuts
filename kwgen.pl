#!/usr/bin/perl

$prefix = "";
$\ = "\n";

while (<>) {
    s/\s*//g;
    m/^$/ && next;
    m/^\:(\w+)/ && ($prefix=$1, next);
    print "\\newcommand{\\$prefix$_}{\\texttt{$_}}";
}
