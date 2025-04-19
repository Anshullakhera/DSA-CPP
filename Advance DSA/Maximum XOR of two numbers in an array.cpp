//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int maxXor(vector<int> &arr) {
        // code here
         int mask=0, max=0;
        for(int i=31;i>=0;i--){
            mask=mask | (1<<i);
            set<int> set;
            for(int n:arr)
                set.insert(mask & n);
               
            int tmp = max | (1<< i);
            for(int prefix : set){
                if(set.find(tmp ^ prefix)!=set.end()){
                    max = tmp;
                    break ;
                }
            }
        }
        return max;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
