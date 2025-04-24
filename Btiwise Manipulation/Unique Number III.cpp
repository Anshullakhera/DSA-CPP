//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool getBit(int n, int pos){
        return ((n & (1<<pos))!= 0);
    }
    int setBit(int n, int pos){
        return (n | (1<<pos));
    }
    int getSingle(vector<int> &arr) {
        // code here
        int res = 0;
        for(int i = 0; i< 64; i++){
            int sum = 0;
            for(int j = 0; j<arr.size(); j++){
                if(getBit(arr[j], i)){
                    sum++;
                }
            }
            if(sum%3 != 0){
                res = setBit(res, i);
            }
        }
        return res;
            
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
