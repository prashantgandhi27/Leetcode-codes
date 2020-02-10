class Solution {
public:
    int myAtoi(string str) {
        bool flag = false, min_flag = false;
        double prev_num = 0, current_num=0;

        if(str.empty()) return 0;
        if(!((str[0]>='0' && str[0]<='9') || (str[0]=='-') || (str[0]=='+'))) return 0;

        for(int i=0; i<str.size(); i++){
            if((str[i]>='!' && str[i]<='/') || (str[i]>=':' && str[i]<='~')){

            }
        }



        for(int i=0; i<str.size(); i++){

            if(str[i] == '-'){
                if(str[i+1]>='0' && str[i+1]<='9'){
                    min_flag=true;
                }
            }

            if(str[i]>='0' && str[i]<='9'){
                flag = true;
                current_num = prev_num*10 + (str[i]-'0');
                prev_num = current_num;
            }else{
                if(flag)
                    break;
            }

            if(min_flag){
                if(prev_num == 2147483648) return INT_MIN;
            }else{
                if(prev_num >= INT_MAX) return INT_MAX;
            }
        }

        if(min_flag)
            current_num = 0-current_num;

        return (int)current_num;
    }
};
