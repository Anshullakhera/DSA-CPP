//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        map<int, bool> mp2;
        bool flag = false;
        int j=0;
        int p=0;
        
        for(j=0;j<(arr.size()-k);j++)
        {
            mp2.clear();
            for(p=j;p<=(j+k);p++)
            {
                if(mp2.find(arr[p])==mp2.end())
                {
                    mp2[arr[p]] = true;
                }
                else if(mp2.find(arr[p])!=mp2.end())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        
        return false;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
