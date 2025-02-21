//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        for(char i:s)
        {
            if(i=='(' || i=='{' || i=='[')
            {
            st.push(i);
            }
            else if
            (!st.empty() && ((st.top()=='(' && i==')') || (st.top()=='{' && i=='}')
            || (st.top()=='[' && i==']')))
            st.pop();
            else
            return false;
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
