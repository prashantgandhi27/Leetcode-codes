class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN){
            return 0;
        }
        double quotient=0, rem=0, rev_num=0, prev_rem=0, num = 0;
        int output = 0;
        num = x;
        x = abs(x);
        while(x != 0){
            rem = x%10;
            rev_num = rem*10 + prev_rem*10;
            prev_rem = rev_num;
            x = x/10;
        }
        rev_num = rev_num/10;
        if(rev_num > INT_MAX)
            return 0;
        if(rev_num < INT_MIN)
            return 0;

        output = (int)rev_num;

        if(num < 0)
            output = 0-output;

        return output;
    }
};
