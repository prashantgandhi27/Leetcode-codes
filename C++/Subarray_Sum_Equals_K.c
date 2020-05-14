

int subarraySum(int* nums, int numsSize, int k){
    
    int temp_arr[numsSize];
    int count = 0, sum = 0, val = 0;
    
    for(int i=0; i<numsSize; i++)
    {
        sum += nums[i];
        temp_arr[i] = sum;
    }
    
    for(int i=0; i<numsSize; i++)
    {
        if(temp_arr[i] == k)
        {
            count++;
        }
            val = temp_arr[i] - k;
            for(int j=0; j<i; j++)
            {
                if(temp_arr[j] == val)
                    count++;
            }  
        }
    return count;
}