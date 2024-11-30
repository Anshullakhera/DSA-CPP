//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        unordered_map<char,int> map;
        if(s1.size() != s2.size()) return 0;
        for(char ch:s1) map[ch]++;
        for(char ch:s2){
            if(map[ch]) map[ch]--;
            if(map[ch] == 0)  map.erase(ch);
        }
        return map.size()==0?1:0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
