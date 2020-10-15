// House Robber

var dp = function(nums, si, ei) {
    let p1 = 0, p2 = 0, curr = 0;
    for(let i = si; i <= ei; i++) {
        curr = Math.max(nums[i] + p2, p1);
        p2 = p1;
        p1 = curr;
    }
    
    return curr;
}

var rob = function(nums) {
    let n = nums.length;
    if(n == 1)
        return nums[0];
    
    return Math.max(dp(nums, 0, n - 2), dp(nums, 1, n - 1));
};