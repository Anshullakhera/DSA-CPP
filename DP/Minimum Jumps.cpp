//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
        int dp[10001];
        int solve(vector<int>& arr, int i){
        if (i >= arr.size()-1) return 0;
        if (arr[i] == 0) return 1e9; 
        int ans = INT_MAX;
        if (dp[i] != -1) return dp[i];
        for (int j=1; j<=arr[i]; j++){
            int dis = 1+solve(arr, i+j);
            ans = min(ans, dis);
        }
        
        return dp[i] = ans;
    }
    int minJumps(vector<int>& arr) {
        if (arr[0] == 0) return -1;
        memset(dp, -1, sizeof(dp));
        int ans = solve(arr, 0);
        return ans >= 1e9 ? -1 : ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends
