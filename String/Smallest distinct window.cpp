//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
       set<char>start(str.begin(),str.end());
       unordered_map<int, int> mp;
       int mini = INT_MAX;
       int st = 0;
       for(int i = 0; i<str.size(); i++){
           mp[str[i]]++;
           while(st<=i && start.size() == mp.size()){
               mini = min(mini, i-st+1);
               mp[str[st]]--;
               if(mp[str[st]]== 0) mp.erase(str[st]);
               st++;
               
           }
       }
       return mini;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
