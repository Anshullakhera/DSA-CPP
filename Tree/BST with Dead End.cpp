/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    void collectNodes(Node* root, set<int>& all, set<int>& leaf) {
        if (!root) return;

        all.insert(root->data);

        if (!root->left && !root->right) {
            leaf.insert(root->data);
        }

        collectNodes(root->left, all, leaf);
        collectNodes(root->right, all, leaf);
    }

    bool isDeadEnd(Node* root) {
        set<int> all, leaf;
        all.insert(0);  
        collectNodes(root, all, leaf);

        for (int x : leaf) {
            if (all.find(x - 1) != all.end() && all.find(x + 1) != all.end()) {
                return true;
            }
        }
        return false;
    }
};
