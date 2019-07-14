/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int saving_big_number = INT_MIN;
        int cnt_sum = 0;

        for (int i=0; i<nums.size(); i++){
            cnt_sum += nums[i];
            if(cnt_sum > saving_big_number)
                saving_big_number = cnt_sum;
            if(cnt_sum < 0)
                cnt_sum = 0;
        }
        return saving_big_number;
    }
};
