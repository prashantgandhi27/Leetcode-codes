class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int max = 0, sum=0;
        int l=0, r=height.size()-1;
        
        int count = r;
        
        while(l < r)
        {
            if(height[l] < height[r])
            {
                sum = height[l] * count;
                if(sum > max)
                    max = sum;
                l++;
                count--;
            }else{
                sum = height[r] * count;
                if(sum > max)
                    max = sum;
                r--;
                count--;
            }
        }
        
        return max;
    }
};