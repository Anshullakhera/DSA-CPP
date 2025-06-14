/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool issym(Node *left, Node* right){
        if(left==NULL || right== NULL)
        return left==right;
        
        if(left->data !=right->data){
            return false;
        }
        return issym(left->left, right->right)&& issym(left->right,right->left);
    }
    bool isSymmetric(Node* root) {
        // Code here
        return root == NULL|| issym(root->left, root->right);
    }
};
