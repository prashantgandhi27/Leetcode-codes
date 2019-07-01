class Solution {
public:
    bool isPalindrome(int x) {
        double rev_num=0, prev_rem=0, rem=0, qutient=0;
        int output=0,num=0;
        num = x;
        bool ret_val = false;
        if(x>=0){
            while(num != 0){
                rem = num % 10;
                rev_num = rem*10 + prev_rem*10;
                prev_rem = rev_num;
                num = num/10;
            }
            prev_rem = prev_rem/10;
            output = (int)prev_rem;
            if(output == x)
                ret_val = true; 
        }
        return ret_val;
    }
};