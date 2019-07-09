class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator t;
        t=nums.begin();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                nums.erase(t+i);
                i=-1;
            }
        }
        return nums.size();
    }
};