//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        int maxi = 0;
        vector<int> left(n);
        vector<int> right(n);
        stack<int> s;
        
        for(int i=0; i<n; i++)
        {
            while(!s.empty() && arr[s.top()] > arr[i])
            {
                right[s.top()] = i;
                s.pop();
            }
            
            s.push(i);
        }
        
        while(!s.empty())
        {
            right[s.top()] = n;
            s.pop();
        }
        
        while(!s.empty())
        {
            s.pop();
        }
        
        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && arr[s.top()] > arr[i])
            {
                left[s.top()] = i;
                s.pop();
            }
            
            s.push(i);
        }
        
        while(!s.empty())
        {
            left[s.top()] = -1;
            s.pop();
        }
        
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, arr[i] * (right[i] - left[i] - 1));
        }
        
        return maxi;
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
