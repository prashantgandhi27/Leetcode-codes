class Solution {
public:
    int mySqrt(int x) {
        
        if(x==0) return 0;
        
        
        double counter = 0.0; 
        double prev_num=0.0, curr_num=0.0, num = (double)x;
        double square_number = 0;
        
        while(1){
            square_number = (counter * counter);
            if(square_number > (double)x)
                break;
            counter++;
        }
        counter = counter - 1;
        prev_num = counter;
        while(1){
            if((int)prev_num == (int)curr_num)
                break;
            curr_num = num/prev_num;
            if((curr_num * curr_num) == (double)x)
                break;
            prev_num = (prev_num + curr_num)/2;   
        }
        return floor(curr_num);
    }
};