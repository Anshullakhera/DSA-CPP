/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    map<Node*, Node*> parent;  // To store parent of each node
    map<Node*, bool> vis;      // To keep track of visited nodes
    Node* fireNode = nullptr;  // The node where fire starts

    // Function to find parent of each node and locate the target node
    void findParent(Node* root, int target) {
        queue<Node*> q;
        q.push(root);
        parent[root] = nullptr;  // Root has no parent

        while (!q.empty()) {
            auto top = q.front(); q.pop();
            
            // If current node is the target, store it
            if (top->data == target) {
                fireNode = top;
            }

            // Store left child's parent and enqueue it
            if (top->left) {
                parent[top->left] = top;
                q.push(top->left);
            }

            // Store right child's parent and enqueue it
            if (top->right) {
                parent[top->right] = top;
                q.push(top->right);
            }
        }
    }

    // Main function to compute minimum burning time
    int minTime(Node* root, int target) {
        // Step 1: Store parents and find the fireNode
        findParent(root, target);

        // Step 2: Perform BFS to simulate fire spread
        queue<pair<Node*, int>> q;
        q.push({fireNode, 0});  // Start from fireNode at time 0
        vis[fireNode] = true;    // Mark as visited

        int time = 0;  // To store the maximum time taken

        while (!q.empty()) {
            auto top = q.front(); q.pop();
            Node* node = top.first;
            int tt = top.second;

            time = max(tt, time);  // Update maximum time

            // Check left child if exists and not visited
            if (node->left && !vis[node->left]) {
                q.push({node->left, tt + 1});
                vis[node->left] = true;
            }

            // Check right child if exists and not visited
            if (node->right && !vis[node->right]) {
                q.push({node->right, tt + 1});
                vis[node->right] = true;
            }

            // Check parent if exists and not visited
            if (parent[node] && !vis[parent[node]]) {
                q.push({parent[node], tt + 1});
                vis[parent[node]] = true;
            }
        }

        return time;
    }
};
