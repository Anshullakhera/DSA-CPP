//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int Xor = 0, x = 0, y = 0;
        for(auto it: arr) Xor^= it;
        int nums = Xor & -Xor;
        for(auto it: arr){
            if(it & nums){
                x^= it;
            }
            else{
                y^= it;
            }
        }
        arr.clear();
        if(x>y){
            arr.push_back(y);
            arr.push_back(x);
            return arr;
        }
        else{
            arr.push_back(x);
            arr.push_back(y);
            return arr;
        }
    

        
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

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
