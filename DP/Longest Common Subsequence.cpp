//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n=s1.length();
        int m=s2.length();
        //base case when i==n return 0
        vector<int> next(m+1,0),cur(m+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j])
                cur[j]=1 + next[j+1];
                
                else
                cur[j]=max(next[j],cur[j+1]);
            }
            next=cur;
        }
        
        return next[0];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
