//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int l=0,r=k-1;
       int n=arr.size();
       
       deque<int> dq;
       vector<int> res;
     
      for(int i=0;i<n;i++){
         
         if(!dq.empty() && dq.front()==i-k) dq.pop_front();
         
         while(!dq.empty() && arr[dq.back()]<=arr[i]) dq.pop_back();
         
         dq.push_back(i);
         
         if(i>=k-1) res.push_back(arr[dq.front()]);
      }
      
      return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
