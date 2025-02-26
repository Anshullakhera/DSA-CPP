//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Function to find the days of buying and selling stock for max profit.
    int f(int index, int buy, vector<int> &arr, int n, vector<vector<int>> &dp){
        if(index==n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit=0;
    
        if(buy){
            profit=max(-arr[index]+ f(index+1, 0, arr,n,dp), 0+f(index+1, 1, arr, n, dp));
        }
        else{
            profit=max(arr[index]+f(index+1, 1, arr,n,dp), 0+f(index+1, 0, arr, n,dp));
        }
        return dp[index][buy]=profit;
    }
    int stockBuySell(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0,1,arr,n,dp);
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.stockBuySell(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
