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
    Node* swapKth(Node* head, int k) {
        // code here
        int size = 0;
        Node*temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        k--;
        int start = k, end = size - k - 1;
        Node*node1 = NULL, *node2 = NULL;
        temp = head;
        int cnt = 0;
        while(temp){
            if(cnt == start){
                node1 = temp;
            }
            if(cnt == end){
                node2 = temp;
            }
            temp = temp->next;
            cnt++;
        }
        if(node1 && node2){
            int val = node1->data;
            node1->data = node2->data;
            node2->data = val;
        }
        return head;
    }
};
