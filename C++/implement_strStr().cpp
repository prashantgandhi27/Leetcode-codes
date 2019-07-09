class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.empty() && needle.empty()) return 0;
        int size_of_niddle = needle.size();
        for(int i=0; i<haystack.size();i++){
            if(haystack.compare(i,size_of_niddle,needle,0,size_of_niddle)==0){
                return i;
            }
        }
        return -1;
    }
};
