/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.



Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"

*/

class Solution {
public:
    string countAndSay(int n){
        if(n==1) return "1";

        string starting_string = "1";
        string output_string;
        int temp=0;
        char prev_char='1';
        int count=0;
        for(int i=0; i<n-1; i++){
            output_string.clear();
            for(int j=0;j<starting_string.size();j++){
                if(starting_string[j]==prev_char){
                    count++;
                    prev_char=starting_string[j];
                }else{
                    temp = '0' + count;
                    output_string.push_back(temp);
                    output_string.push_back(prev_char);
                    prev_char = starting_string[j];
                    j--;
                    count=0;
                }
            }
            if(count!=0){
                temp = '0' + count;
                output_string.push_back(temp);
                output_string.push_back(prev_char);
                count=0;
            }
            starting_string = output_string;
            prev_char = output_string[0];
        }
        return output_string;
    }
};
