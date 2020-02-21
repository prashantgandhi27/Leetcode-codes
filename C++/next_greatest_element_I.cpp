class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> output;
        
        if(nums1.empty())
            return output;
        stack<int> s;
        unordered_map<int, int> unmap;
        
        
        s.push(nums2[0]);
        for(int i=1; i<nums2.size(); i++){
            
            if(s.top() < nums2[i]){
                while(!s.empty() && s.top() < nums2[i]){
                    unmap[s.top()] = nums2[i];
                    s.pop();
                }
                s.push(nums2[i]);
            }else{
                s.push(nums2[i]);
            }
        }
        
        while(!s.empty()){
            unmap[s.top()] = -1;
            s.pop();
        }
        
        for(int i=0; i<nums1.size(); i++){
            output.push_back(unmap[nums1[i]]);
        }
                             
        return output; 
    }
};