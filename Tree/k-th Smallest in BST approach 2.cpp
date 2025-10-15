/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
     void solve(Node *root, int k,int &ans,int &cnt){
       if(!root || ans != -1){
           return;
       }
       solve(root->left,k,ans,cnt);
       cnt++;
       if(cnt == k) ans = root->data;
       solve(root->right,k,ans,cnt);
       
   }
  
    int kthSmallest(Node *root, int k) {
        int ans = -1;
        int cnt = 0;
        solve(root,k,ans,cnt);
        return ans;
        
    }
};
