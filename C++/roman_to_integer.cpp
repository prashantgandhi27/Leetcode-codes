class Solution {
public:
    int romanValue(char c){
        int ret_val = 0;
        switch(c){
            case 'I':
                ret_val = 1;
                break;
            case 'V':
                ret_val = 5;
                break;
            case 'X':
                ret_val = 10;
                break;
            case 'L':
                ret_val = 50;
                break;
            case 'C':
                ret_val = 100;
                break;
            case 'D':
                ret_val = 500;
                break;
            case 'M':
                ret_val = 1000;
                break;
            default:
                ret_val = 1;
                break; 
        }
        return ret_val;
    }
    
    int romanToInt(string s) {
        
        int sum = 0, prev_sum=0;
        char c = s[0];
        
        for(int i=0; i<s.length();i++)
        {
            if((s[i]=='I') && (s[i+1]=='V' || s[i+1]=='X')){
                sum += romanValue(s[i+1]) - romanValue(s[i]);
                i += 1;
            }else if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C')){
                sum += romanValue(s[i+1]) - romanValue(s[i]);
                i += 1;
            }else if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M')){
                sum += romanValue(s[i+1]) - romanValue(s[i]);
                i += 1;
            }else{
                sum += romanValue(s[i]);
            }
        }
        return sum;
    }
};