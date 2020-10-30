// Maximize Distance to Closest Person

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prev = -1;
        int ans = 0;
        
        for(int i = 0; i < seats.size(); i++) {
            if(seats[i]) {
                if(prev == -1)
                    ans = i;
                else
                    ans = max(ans, (i - prev) / 2);
                prev = i;
            }    
        }
        
        ans = max(ans, (int)seats.size() - 1 - prev);
        
        return ans;
    }
};