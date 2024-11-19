//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int index=-1;
        if(arr.size()==1) return;
        for(int i = arr.size()-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                index=i;
                break;
            }
        }
        if(index!=-1){
            for(int i=arr.size()-1;i>=index+1;i--){
                if(arr[i]>arr[index]){
                    swap(arr[i],arr[index]);
                    break;
                }
            }
        }
        int l=index+1;
        int r=arr.size()-1;
        while(l<=r){
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
