/*
Problem statement:
Given two version numbers, version1 and version2, compare them.
Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
Input: version1 = "1.01", version2 = "1.001.1"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same number "1". 
The strings differ in their third decimal place: "0" and "1" respectively. Hence, the answer is 0.

Solution:
One way to solve this problem is to split the version strings by '.' and then compare each corresponding part of the strings. 
We can use two pointers to traverse through the parts of the strings and compare them. If a part of one version string is greater than the other, 
then we can return 1 or -1 depending on which version is greater. If both parts are equal, 
we continue to compare the next parts of the strings until we reach the end of both strings. 
If one string has more parts than the other, we can consider the additional parts to be 0.
*/
int compareVersion(string version1, string version2) {
    int i = 0, j = 0;
    int n1 = version1.length(), n2 = version2.length();
    int num1 = 0, num2 = 0;
    while (i < n1 || j < n2) {
        while (i < n1 && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }
        while (j < n2 && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }
        if (num1 > num2) {
            return 1;
        } else if (num1 < num2) {
            return -1;
        }
        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    return 0;
}
/*
In this code, we initialize two pointers i and j to 0, which represent the current positions in the version strings. 
We also initialize two variables num1 and num2 to 0, which will store the numerical value of the current parts of the version strings. 
We use a while loop to traverse through the version strings until we reach the end of both strings. 
Inside the loop, we use nested while loops to extract the numerical value of each part of the version strings. 
We use a variable n1 and n2 to store the length of the version strings. We also use a conditional statement to compare 
the numerical values of the current parts of the version strings. If one part is greater than the other, 
we return 1 or -1 depending on which version is greater. If both parts are equal, we continue to compare the next parts of the strings. 
Finally, we return 0 if we reach the end of both strings and have not yet found a difference in the version numbers.
*/
