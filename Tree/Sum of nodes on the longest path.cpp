/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int maxSum=0,maxLevel=0;
    
    void func(Node* root,int sum,int currLevel)
    {
        if(root==NULL)
            return;
        sum+=root->data;
        currLevel++;
        func(root->left,sum,currLevel);
        func(root->right,sum,currLevel);
        
        if(currLevel>maxLevel)
        {
            maxSum=sum;
            maxLevel=currLevel;
        }
        else if(currLevel==maxLevel)
        {
            maxSum=max(maxSum,sum);
            //maxLevel and currLevel are already same
        }
    }
    int sumOfLongRootToLeafPath(Node* root) {
        // code here
        int sum=0;
        int currLevel=0;
        
        maxSum=0;// need to redeclare its values as 0
        maxLevel=0;
        //static variables are shared across all instances 
        //of a class and persist as long as the program 
        //is running 
        
        func(root,sum,currLevel);
        return maxSum;    
    }
};
