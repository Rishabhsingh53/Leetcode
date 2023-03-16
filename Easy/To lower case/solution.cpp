/*
709. To Lower Case
Problem statement:
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
Example 1:
Input: s = "Hello"
Output: "hello"
*/
class Solution {
public:
    string toLowerCase(string s) {
        string res;
        for(char x:s){
            if(isupper(x)){
                res+=(x|' ');
            }
            else{
                res+=x;
            }
        }
        return res;
    }
};
/*
Intitution and Explanation:
we can convert uppercase to lowercase by doing Bitwise OR and space. >>> "(ch | ' ')"
This results in an lowercase string this method when parsed on a uppercase char or a lowercse char will result in an lowercase char
here in this code we iterate over every char in a string and check if its in upper case if this condition is true we use our intitution and 
update that char and increment it into our result string else we increment it as it is.
*/
