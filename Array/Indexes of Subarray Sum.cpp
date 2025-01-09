//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        vector<int> ans(2);
        
        int n = arr.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        
        while(j < n){
            sum += arr[j];
           
            while(sum > target){
                sum -= arr[i];
                i++;
            }
            if(sum == target){
                ans[0] = i+1;
                ans[1] = j+1;
                return ans;
            }
            j++;
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends
