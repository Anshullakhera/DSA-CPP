//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        string ans;
        int n=s.size();
        stack<char>st;
        for(char c:s)
        {
            if(c!=']')
                st.push(c);
            else
            {
                string temp="";
                while(!st.empty() && st.top()!='['){
                    temp=st.top()+temp;//order will be reversed this way
                    st.pop();
                }
                st.pop();//to remove [
                string k="";
                while(!st.empty() && isdigit(st.top()))
                {
                    k=st.top()+k;//reversed order to be taken into account
                    st.pop();
                }
                int count=stoi(k);
                string repeat="";
                while(count--)
                    repeat+=temp;
                
                for(char i:repeat)
                    st.push(i);
            }
        }
        while(!st.empty())
        {
            ans=st.top()+ans;//again take reverse
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
