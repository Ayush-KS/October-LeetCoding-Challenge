// Recover Binary Search Tree

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        
        TreeNode* temp = root;
        
        while(temp) {
            if(!temp -> left) {
                if(first == NULL) {
                    first = temp;
                } else {
                    if(temp -> val < first -> val) {
                        if(second == NULL) {
                            second = temp;
                        } else {
                            if(temp -> val < second -> val)
                                second = temp;
                        }
                    } else {
                        if(!second)
                            first = temp;
                    }
                }
                temp = temp -> right;
            } else {
                TreeNode* tempLeft = temp -> left;
                while(tempLeft -> right && tempLeft -> right != temp) {
                    tempLeft = tempLeft -> right;
                }
                if(tempLeft -> right) {
                    if(first == NULL) {
                        first = temp;
                    } else {
                        if(temp -> val < first -> val) {
                            if(second == NULL) {
                                second = temp;
                            } else {
                                if(temp -> val < second -> val)
                                    second = temp;
                            }
                        } else {
                            if(!second)
                                first = temp;
                        }
                    }
                    tempLeft -> right = NULL;
                    temp = temp -> right;
                } else {
                    tempLeft -> right = temp;
                    temp = temp -> left;
                }
            }
        }
        
        int tempz = first -> val;
        first -> val = second -> val;
        second -> val = tempz;
    }
};