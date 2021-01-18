// Longest Palindromic Subsequence
// Given a sequence, find the length of the longest palindromic subsequence in it.

Approach:

make another string which is reverse of original string & pass it to
LCS(s, reverse(s), len(s), len(s))
the lenght returned is LPS
