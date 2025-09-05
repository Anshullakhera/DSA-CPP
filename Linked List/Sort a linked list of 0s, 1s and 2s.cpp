/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if (!head) return nullptr;
        vector<int> values;
        Node* current = head;
        while (current) {
            values.push_back(current->data);
            current = current->next;
        }
        sort(values.begin(), values.end());
        current = head;
        int i = 0;
        while (current) {
            current->data = values[i++];
            current = current->next;
        }
        return head;
    }
};
