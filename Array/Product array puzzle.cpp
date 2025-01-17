//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        long long product=1;
        int n=arr.size();
        vector<int>res(n,0);
        int zero=0;

        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) zero++;
            else product=product*arr[i];
        }

        if(zero>1) return res;

       if(zero==1){
           for(int i=0;i<arr.size();i++){
            if(arr[i]==0) res[i]=product;
            }
        }
        else{
            for(int i=0;i<arr.size();i++){
                res[i] = product / arr[i];
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
