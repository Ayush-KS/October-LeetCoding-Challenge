// Clone Graph

class Solution {
public:
    unordered_map<Node*, bool> visited;
    unordered_map<Node*, Node*> nodevisit;
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        Node* newNode = new Node(node -> val);
        vector<Node*> neigh = node -> neighbors;
        vector<Node*> newNeigh;
        nodevisit[node] = newNode;
        visited[node] = true;
        for(Node* n : neigh) {
            if(visited[n]) {
                Node* newn = nodevisit[n];
                newNeigh.push_back(newn);
                continue;
            }
            Node* newn = cloneGraph(n);
            newNeigh.push_back(newn);
        }
        
        newNode -> neighbors = newNeigh;
        
        return newNode;
    }
};