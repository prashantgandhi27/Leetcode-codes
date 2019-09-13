class Solution {
public:
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int pirtition(vector<int>& v, int low, int high){
        int pivot = v[high];

        int i=(low-1);

        for(unsigned int j=low; j<(high); j++){
            if(v[j] <= pivot){
                i++;
                swap(&v[j],&v[i]);
            }
        }
        swap(&v[i+1],&v[high]);
        return (i+1);
    }

    void __quicksort(vector<int>& v, int low, int high){
        int pi=0;
        if(low<high){
            int pi = pirtition(v,low,high);

            __quicksort(v, low, pi-1);
            __quicksort(v, pi+1, high);
        }
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        vector<int> v1;
        vector<int> v2;

        if(nums1.empty() || nums2.empty())
            return output;

        if(nums1.size()<=nums2.size()){
            v1 = nums2;
            v2 = nums1;
        }else{
            v1 = nums1;
            v2 = nums2;
        }

        __quicksort(v1, 0, v1.size()-1);
        __quicksort(v2, 0, v2.size()-1);

        for(unsigned int i=1; i<v2.size();i++){
            if(v2[i-1]==v2[i]){
                v2.erase(v2.begin()+i);
                i=0;
            }
        }
        unsigned int count = 0;

        if(v2[0] <= v1[v1.size()-1]){
                for(int i=0; i<v1.size();i++){
                    if(count != (v2.size())){
                        if(v2[count] == v1[i]){
                            output.push_back(v2[count]);
                            count++;
                            i=-1;
                        }else{
                            if(i == v1.size()-1){
                                count++;
                                i=-1;
                            }
                        }
                    }else
                        break;
                }
            }

        return output;
    }
};
