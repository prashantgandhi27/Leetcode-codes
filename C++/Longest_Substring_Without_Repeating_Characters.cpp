/*Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int count = 0;
        int m = 10;

        vector< vector<char> > v(s.size());

        for(int i=0,j=0; i<s.size,j<s.size(); j++,i++)
        {
                if((s[0]==s[j+1])){
                    for(int q=0,p=j+1;q<(s.size()-(j+1)), p<s.size();p++,q++)
                    {
                        v[i][q] = s[p];
                    }
                count++;
                }
        }

        if(count == 0){
            for(int q=0,p=0;q<s.size(), p<s.size();p++,q++)
                    {
                        v[0][q] = s[p];
                    }
        }
    }
};
