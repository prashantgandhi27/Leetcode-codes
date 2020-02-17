int maximum69Number (int num) {
        vector<int> vec;
        bool flag = false;
        int temp_1 = num, sum=0, prev_sum=0;
        
        while(temp_1 != 0){
            vec.push_back(temp_1%10);
            temp_1 /= 10; 
        }
        
        for(int i=vec.size()-1; i>-1; i--){
            if(vec[i] == 6 && flag == false){
                sum = 9 + prev_sum*10;
                flag = true;
            }else{
                sum = vec[i] + prev_sum*10;
            }
            prev_sum = sum;
        }
        
        return sum;
    }