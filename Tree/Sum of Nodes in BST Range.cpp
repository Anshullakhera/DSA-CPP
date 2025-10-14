/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        if (root == NULL) return 0;
        
        int raj = 0;
        if (root->data >= l && root->data <= r) {
            raj += root->data;
        }
        if (root->data > l) {
            raj += nodeSum(root->left, l, r);
        }
        if (root->data < r) {
            raj += nodeSum(root->right, l, r);
        }
        return raj;
    }
};
