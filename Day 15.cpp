// Rotate Array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int curr = nums[0];
        int currIndex = 0;
        bool visited[n];
        memset(visited, 0, sizeof(visited));
        
        for(int i = 0; i < n; i++) {
            int nextIndex = (currIndex + k) % n;
            if(visited[nextIndex]) {
                i--;
                currIndex = (currIndex + 1) % n;
                curr = nums[currIndex];
                continue;
            }
            int temp = nums[nextIndex];
            nums[nextIndex] = curr;
            curr = temp;
            visited[nextIndex] = true;
            currIndex = nextIndex;
        }   
    }
};