/*
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:
Input:
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.
*/

class Solution {
public:
    bool dividingFunction(int num){

        if(num == 1) return true;

        int rem, div, temp_num = num;
        bool ret_val = true;

        while(temp_num != 0){
            rem = temp_num % 10;
            if(rem == 0){
                ret_val = false;
                break;
            }
            if((num % rem) != 0){
                ret_val = false;
                break;
            }
            temp_num /= 10;
        }
        return ret_val;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> output;
        for(int i=left; i<=right; i++){
            if(dividingFunction(i))
                output.push_back(i);
        }
        return output;
    }
};
