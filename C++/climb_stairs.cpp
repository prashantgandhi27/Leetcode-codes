/*
Name: Prashant Gandhi

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


*/

class Solution {
public:
    double factorial(int n){
        if(n==0 || n==1)
            return 1;
        else
            return (double)(n * factorial(n-1));
    }

    int climbStairs(int n) {
        int count_of_ones = n, twos = 0, num = n;
        double sum = 0;

        while(count_of_ones >= 0){
            sum += (factorial(num)/(factorial(count_of_ones)*factorial(twos)));
            num--;
            count_of_ones -= 2;
            twos++;
        }
        return (int)sum;
    }
};
