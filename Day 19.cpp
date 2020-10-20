// Minimum Domino Rotations For Equal Row

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B, bool ret = false) {
        int ans = INT_MAX;
        for(int n = 1; n <= 6; n++) {
            int curr = 0;
            bool flag = true;
            for(int i = 0; i < A.size(); i++) {
                if(A[i] != n) {
                    if(B[i] == n) {
                        curr++;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) {
                ans = min(ans, curr);
            }
        }
        int ans2 = INT_MAX;
        if(!ret) {
            ans2 = minDominoRotations(B, A, true);
        }
        return min(ans, ans2) == INT_MAX ? -1 : min(ans, ans2);
    }
};