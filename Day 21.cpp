// Asteroid Collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> st;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > 0 || st.empty() || st.back() < 0) {
                st.push_back(arr[i]);
            }
            else if(st.back() == abs(arr[i])) {
                st.pop_back();
            }
            else {
                st.pop_back();
                i--;
            }
        }
        
        return st;
    }
};