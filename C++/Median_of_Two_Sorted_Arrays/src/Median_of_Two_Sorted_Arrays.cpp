//============================================================================
// Name        : Median_of_Two_Sorted_Arrays.cpp
// Author      : Prashant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		double output = 0;
		unsigned int count = 0;
		nums1.reserve(nums1.size()+nums2.size());

		for(unsigned int nums2_index = 0; nums2_index < nums2.size(); nums2_index++){
			for(unsigned int i = 0; i<nums1.size(); i++){
				if(nums1[i] >= nums2[nums2_index]){
					nums1.insert(nums1.begin()+i,nums2[nums2_index]);
					count++;
					break;
				}
			}
		}

		if(count < nums2.size()){
			for(unsigned int i = count; i<nums2.size(); i++){
				nums1.push_back(nums2[i]);
			}
		}

		if(nums1.size()%2 != 0)
			output = nums1[((nums1.size()+1)/2)-1];
		else
			output = (nums1[(nums1.size()/2)-1] + nums1[nums1.size()/2])/2.0;


		return output;
	}
};
