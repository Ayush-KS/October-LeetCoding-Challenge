// 132 Pattern

bool find132pattern(int* nums, int n){
    int stack[n];
    int st = 0;
    int s3 = INT_MIN;
    
    
    for(int i = n - 1; i >= 0; i--) {
        if(nums[i] < s3)
            return true;
        while(st && (stack[st - 1] < nums[i])) {
            s3 = stack[st - 1];
            st--;
        }
        stack[st++] = nums[i];
    }
    return false;
}