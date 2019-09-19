/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/
class Solution {
public:
    bool isPalindrome(string s) {
        bool ret_val = false;
        string temp;
        if(s.empty() || (s.size()==1)) return true;

        for(int i=0; i<s.size(); i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                temp.push_back(s[i]);
            }else if(s[i]>='A' && s[i]<='Z'){
                temp.push_back(s[i]+32);
            }
        }

        if(temp.empty() || (temp.size()==1)) return true;

        for(int i=0; i<(temp.size()/2);i++){
            if(temp[i] == temp[temp.size()-1-i])
                ret_val = true;
            else{
                ret_val = false;
                break;
            }
        }

        return ret_val;
    }
};
