//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        int idx = 0, n = s1.length(), m = s2.length();
        
        if(n >= m){
            for(int i=0; i<=n-m; i++){
                if(s1.substr(i, m) == s2) return 1;
            }
            string temp = s1 + s1;
            for(int i = n-m; i<2*n; i++){
                if(temp.substr(i, m) == s2) return 2; 
            }
            return -1;
        }
        
        for( ; idx <= m-n; idx++){
            if(s2.substr(idx, n) == s1) break;
        }
        
        
        if(idx == m) return -1;
        
        int j = n - 1;
        for(int i = idx - 1; i >= 0; i--){
            if(s2[i] != s1[j]) return -1;
            j--;
        }
        
        int ans = idx!=0 ? 1 : 0, flag = 0;
        j=0;
        while(idx < m){
            if(idx + n < m){
                if(s2.substr(idx, n) == s1){
                    ans++;
                    idx+=n;
                }
                else return -1;
            }
            else{
                if(s1[j] != s2[idx]) return -1;
                idx++;
                j++;
                flag = 1;
            }
        }
        
        if(flag) ans++;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends
