/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/

// Works for all size of input

class Solution {
public:
    string addBinary(string a, string b) {
        int counter_1 = a.size()-1;
        int counter_2 = b.size()-1;
        int count_1 = 0,count_2 = 0;
        bool flag = false;
        string output;

        for(int i=0; i<a.size();i++){
            if(a[i] != '0')
                break;
            else
                count_1++;
        }

        for(int i=0; i<b.size();i++){
            if(b[i] != '0')
                break;
            else
                count_2++;
        }

        if((count_1==counter_1+1)&&(count_2==counter_2+1)) return "0";

        while((counter_1>=count_1) && (counter_2>=count_2)){
            if((a[counter_1]=='1' && b[counter_2]=='0') || (a[counter_1]=='0' && b[counter_2]=='1')){
                if(flag){
                    output.push_back('0');
                    flag = true;
                }else{
                    output.push_back('1');
                    flag = false;
                }
            }else if(a[counter_1]=='0' && b[counter_2]=='0'){
                if(flag){
                    output.push_back('1');
                    flag = false;
                }else{
                    output.push_back('0');
                    flag = false;
                }
            }else if(a[counter_1]=='1' && b[counter_2]=='1'){
                if(flag){
                    output.push_back('1');
                    flag = true;
                }else{
                    output.push_back('0');
                    flag = true;
                }
            }
            counter_1--;
            counter_2--;
        }

        while(counter_1 >= count_1){
            if(a[counter_1]=='0'){
                if(flag){
                    output.push_back('1');
                    flag = false;
                }else{
                    output.push_back('0');
                    flag = false;
                }
            }
            if(a[counter_1]=='1'){
                if(flag){
                    output.push_back('0');
                    flag = true;
                }else{
                    output.push_back('1');
                    flag = false;
                }
            }
            counter_1--;
        }



        while(counter_2 >= count_2){
            if(b[counter_2]=='0'){
                if(flag){
                    output.push_back('1');
                    flag = false;
                }else{
                    output.push_back('0');
                    flag = false;
                }
            }
            if(b[counter_2]=='1'){
                if(flag){
                    output.push_back('0');
                    flag = true;
                }else{
                    output.push_back('1');
                    flag = false;
                }
            }
            counter_2--;
        }

        if(flag)
            output.push_back('1');

        reverse(output.begin(),output.end());

        return output;
    }
};
