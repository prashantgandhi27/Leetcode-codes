/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty() || s == " ") return 0;
        int count=0,prev_count=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                if(count>0)
                    prev_count=count;
                count=0;
            }
            else{
                count++;
            }
        }
        if((s[s.size()-1])==' ')
            return prev_count;
        else
            return count;
    }
};
