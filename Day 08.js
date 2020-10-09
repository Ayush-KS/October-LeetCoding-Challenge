// Binary Search

var search = function(nums, target) {
    var si = 0;
    var ei = nums.length;
    
    while(si < ei) {
        var mid = si + (ei - si) / 2;
        mid = Math.floor(mid);
        if(nums[mid] >= target) {
            ei = mid;
        } else {
            si = mid + 1;
        }
    }
    
    return nums[si] == target ? si : -1;
};