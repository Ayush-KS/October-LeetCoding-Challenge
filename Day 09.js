// Serialize and Deserialize BST

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    if(root == null)
        return "";
    var ans = "";
    var queue = [];
    queue.push(root);
    while(queue.length != 0) {
        var sz = queue.length;
        for(let i = 0; i < sz; i++) {
            var front = queue[0];
            queue.shift();
            if(front == null) {
                ans += "N*";
                continue;
            } else {
                ans += front.val;
                ans += "*";
            }
            queue.push(front.left);
            queue.push(front.right);
        }
    }
    console.log(ans);
    return ans;
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    if(data.length == 0)
        return null;
    
    var i = 0;
    var num = 0;
    while(data[i] != '*') {
        num *= 10;
        num += (data[i] - '0');
        i++;
    }
    
    var root = new TreeNode(num);
    var queue = [];
    queue.push(root);
    i++;
    while(i < data.length) {
        var front = queue[0];
        queue.shift();
        if(data[i] != 'N') {
            num = 0;
            while(data[i] != '*') {
                num *= 10;
                num += (data[i] - '0');
                i++;
            }
            var left = new TreeNode(num);
            queue.push(left);
            
            front.left = left;
            i++;
        } else {
            i += 2;
        }
        if(i < data.length && data[i] != 'N') {
            num = 0;
            while(data[i] != '*') {
                num *= 10;
                num += (data[i] - '0');
                i++;
            }
            var right = new TreeNode(num);
            queue.push(right);
            
            front.right = right;
            i++;
        } else {
            i += 2;
        }
    }
    return root;
};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */