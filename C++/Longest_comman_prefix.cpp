class Solution {
public:
    string compareTwoStrings(string s1, string s2){
        string temp = "";
        for(int i=1; i<=s1.size(); i++)
        {
            if(s1.compare(0,i,s2,0,i)== 0)
            {
                 temp.push_back(s1[i-1]);
            }else
                break;    
        }
        
        if(temp.empty())
            return "";
        else
            return temp;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        
        string camp_string = strs[0];
        for(int i=1;i<strs.size();i++){
            camp_string = compareTwoStrings(camp_string,strs[i]);
        }
        return camp_string;
    }
};