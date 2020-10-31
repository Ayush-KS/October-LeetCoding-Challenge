// Number of Longest Increasing Subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n);
        int imax = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            dp[i] = {1, 1};
            for(int j = i - 1; j >= 0; j--) {
                if(nums[j] < nums[i]) {
                    if(dp[j].first + 1 > dp[i].first) {
                        dp[i] = dp[j];
                        dp[i].first = 1 + dp[j].first;
                    } else if(dp[j].first + 1 == dp[i].first) {
                        dp[i].second += dp[j].second;
                    }
                }
            }
            if(dp[i].first > imax) {
                imax = dp[i].first;
                ans = dp[i].second;
            } else if(dp[i].first == imax) {
                ans += dp[i].second;
            }
        }
        
        return ans;
    }
};