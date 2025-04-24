//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool setBit(int n, int pos){
        return ((n & (1<<pos))!=0);
    }
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int Xor = 0, newXor = 0;
        for(auto it: arr) Xor^= it;
        int tempXor = Xor;
        int setbit = 0, pos = 0;
        while(setbit != 1){
            setbit = setbit & 1;
            pos++;
            Xor = Xor>>1;
        }
        for(auto it: arr){
            if(setBit(it, pos-1)){
                newXor^=it;
            }
        }
        arr.clear();
        if(newXor>(tempXor^newXor)){
            arr.push_back(tempXor^newXor);
            arr.push_back(newXor);
            return arr;
        }
        else{
            arr.push_back(newXor);
            arr.push_back(tempXor^newXor);
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
