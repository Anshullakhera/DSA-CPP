/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        priority_queue<pair<int,Node*>>pq;
        for(auto it:arr)
        {
          pq.push({-(it->data),it});
        }
        Node*head=NULL;
        Node*curr=NULL;
        while(pq.size())
        {
            Node*temp=pq.top().second;
            pq.pop();
            if(head==NULL)
            {
                head=temp;
                curr=head;
            }
            else{
                curr->next=temp;
                curr=temp;
            }
            if(temp->next!=NULL)
               pq.push({-(temp->next->data),temp->next});
        }
        return head;
    }
};
