//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxValue(vector<int>& arr) {        
        // your code here
    // Case 1: Exclude last house
    vector<int> case1(arr.begin(), arr.end() - 1);
    // Case 2: Exclude first house
    vector<int> case2(arr.begin() + 1, arr.end());

    return max(robLinear(case1), robLinear(case2));
    }
    

    int robLinear(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    int prev2 = 0, prev1 = 0;
    for (int num : nums) {
        int curr = max(prev1, num + prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
