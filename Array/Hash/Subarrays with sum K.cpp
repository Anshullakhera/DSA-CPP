//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        map<int, int> mp;
        
        int ans = 0;  // To store the count of valid subarrays
        int sum = 0;  // Running prefix sum
        int n = arr.size();
        
        // Iterate through the array
        for (int i = 0; i < n; ++i) {
            // Update the running sum
            sum += arr[i];
            
            // If the current prefix sum equals k, increment count
            if (sum == k) ++ans;
            
            // Check if sum - k exists in the map (prefix sum logic)
            if (mp.find(sum - k) != mp.end()) {
                ans += mp[sum - k];  // Add the frequency of sum - k
            }
            
            // Update the current prefix sum in the map
            mp[sum]++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
