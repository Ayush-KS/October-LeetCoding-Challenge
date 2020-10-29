// Summary Ranges

class Solution {
public:
    vector<string> op;
    
    void helper(vector<int>& nums, int si) {
        if(si >= nums.size())
            return;
        string curr = to_string(nums[si]);
        int ei = si + 1;
        
        while(ei < nums.size() && nums[ei] == nums[ei - 1] + 1) {
            ei++;
        }
        
        if(ei > si + 1) {
            curr += "->";
            curr += to_string(nums[ei - 1]);
        }
        op.push_back(curr);
        helper(nums, ei);
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        helper(nums, 0);
        return op;
    }
};