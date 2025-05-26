/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node *currNode = head->next, *headNode = head;
        vector<int> v;
        v.push_back(head->data);
        while(currNode != headNode)
        {
            v.push_back(currNode->data);
            currNode = currNode->next;
        }
        v.push_back(data);
        sort(v.begin(), v.end());
        Node* newHead = new Node(v[0]);
        Node* curr = newHead;
        for(int i = 1; i < v.size(); i++)
        {
            curr->next = new Node(v[i]);
            if(i == v.size() - 1)
            {
                curr->next->next = newHead;
            }
            else
            {
                curr = curr->next;
            }
        }
        return newHead;
    }
};
