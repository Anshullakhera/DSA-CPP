//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &end) {
        // code here
        map<int, int> mp;
        
        for(int i=0; i<start.size(); i++){
            if(mp[end[i]] < start[i]){
                mp[end[i]] = start[i];
            }
            
        }
        
        sort(end.begin(), end.end());
        
        int ans =1;
        int lastEnd = end[0];
        for(int i=1; i<start.size(); i++){
            if(mp[end[i]] > lastEnd){
                ans++;
                lastEnd = end[i];
            } 
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
