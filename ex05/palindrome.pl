#!/usr/bin/perl

print "Enter a string: ";
$input = <>;
chomp($input);

$rev_input = scalar reverse($input);

# print ("$input\n");
# print ("$rev_input\n");
if ($input eq $rev_input)
{
    print ("The string is a palindrome!");
}
else
{
    print ("The string is not a palindrome.");
}
