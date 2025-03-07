//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int longestPalinSubseq(string &s) {
        // code here
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s[i-1] == rev[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(curr[j-1],prev[j]);
            }
            prev = curr;
        }
        return prev[n];
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
