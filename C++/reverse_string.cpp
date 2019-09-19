/*
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.



Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

class Solution {
public:
    void swap(char *a, char *b){
        char temp = *a;
        *a = *b;
        *b = temp;
    }
    void reverseString(vector<char>& s) {
        int n;
        if(s.size()%2==0)
            n = s.size()/2;
        else
            n = (s.size()-1)/2;

        for(unsigned int i=0; i<n; i++){
            swap(&s[i], &s[s.size()-1-i]);
        }
    }
};
