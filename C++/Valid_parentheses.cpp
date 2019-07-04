class Solution {
public:
    
    bool isValid(string s) {
        if(s.empty())
            return true;        
        
        for(int i=0;i<s.size();i++){
           switch(s[i]){
                case '(':
                    if(s[i+1]==')'){
                        s.erase(i,2);
                        i=-1;
                    }
                    break;
                case '{':
                    if(s[i+1]=='}'){
                        s.erase(i,2);
                        i=-1;
                    }
                    break;
                case '[':
                    if(s[i+1]==']'){
                        s.erase(i,2);
                        i=-1;
                    }  
                    break;
           }
        }
        
        if(s.empty())
            return true;
        else 
            return false;
    }
};