//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int maxSum=INT_MIN;
        int minSum=INT_MAX;
        int curr=0,currneg=0;
        int s=0;
        for(int i:arr)
        {
            s+=i;
            curr+=i;
            maxSum= max(curr,maxSum);
            if(curr<0)
            {
                curr=0;
            }
            currneg+=i;
            minSum=min(currneg,minSum);
            if(currneg>0)
            {
                currneg=0;
            }
        }
        if(s==minSum)
        {
            return maxSum;
        }
        return max(maxSum,s-minSum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
