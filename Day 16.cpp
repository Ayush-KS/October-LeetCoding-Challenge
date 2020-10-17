// Search a 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int si = 0;
        int ei = (matrix.size() * matrix[0].size()) - 1;
        int n = matrix[0].size();
        
        while(si <= ei) {
            int mid = (ei + si) / 2;
            if(matrix[mid / n][mid % n] == target) 
                return true;
            else if(matrix[mid / n][mid % n] > target) {
                ei = mid - 1;
            } else {
                si = mid + 1;
            }
        }
        return false;
    }
};