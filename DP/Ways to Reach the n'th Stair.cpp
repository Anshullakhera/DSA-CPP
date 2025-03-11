//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(int n) {
        // your code here
        if(n==1) {
            return 1;
        }
        if(n==2) {
            return 2;
        }
        
        int dp[n];
        
        dp[0] = 1;
        dp[1] = 2;
        
        for(int i =2;i<n;i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n-1];
        
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
