//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n = arr.size();
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (arr[mid] == key) return mid;
            if (arr[lo] <= arr[mid]) {  
                if (key >= arr[lo] && key < arr[mid]) 
                    hi = mid - 1;  
                else 
                    lo = mid + 1; 
            } else { 
                if (key <= arr[hi] && key > arr[mid]) 
                    lo = mid + 1; 
                else 
                    hi = mid - 1;  
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
