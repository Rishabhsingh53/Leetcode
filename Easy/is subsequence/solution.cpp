/*
392. Is Subsequence
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some 
of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,ptr=0;
        while(ptr<t.size() && i<s.size()){
            if(s[i]==t[ptr]){
                i++;
            }
            ptr++;
        }
        if(i==s.size()){
            return true;
        }
        return false;
    }
};
