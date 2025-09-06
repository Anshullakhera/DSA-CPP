/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        unordered_map<Node* , int>vis;
        Node* t = head;
        Node* pre = NULL;
        int num = 1;
        
        while(t != NULL){
            if(vis[t] < 1){
                vis[t] = num;
            }
            else{
                return vis[pre] - vis[t] + 1;
            }
            
            num++;
            pre = t;
            t = t->next;
        }
        
        return 0;
    }
};
