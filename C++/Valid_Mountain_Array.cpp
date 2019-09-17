/*
Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
*/

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3)
            return false;

        unsigned int i=0;

        for(i=0;i<A.size();i++){
            if(i!=A.size()-1){
                if(!(A[i]<A[i+1]))
                    break;
            }else
                return false;
        }

        if(i==0)
            return false;
        else{
            for(unsigned int j=i; j<A.size(); j++){
                if(j!=A.size()-1){
                    if(!(A[j]>A[j+1]))
                        return false;
                }else
                    return true;
            }
        }

        return true;
    }
};
