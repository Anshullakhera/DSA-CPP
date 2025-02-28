//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<string>st;
        
        unordered_map<string, function<int(int, int)>> ops = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return (b != 0) ? a / b : 0; }}  // Handle divide-by-zero case
    };
        
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/"){
                int ele1 = stoi(st.top());
                st.pop();
                int ele2 = stoi(st.top());
                st.pop();
                int val = ops[arr[i]](ele2,ele1);
                st.push(to_string(val));
                
            }
            else{
            st.push(arr[i]);
            }
        }
        ans += stoi(st.top());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
