//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        vector<vector<int>>ans;
        priority_queue<pair<double,int>>pq;
        int i=0;
        for(auto it:points){
            double dis = (double)it[0]*it[0] + (double)it[1]*it[1];
            if(pq.size()>=k){
                if(pq.top().first>dis){
                    pq.pop();
                    pq.push({dis,i});
                }
            }
            else{
                pq.push({dis,i});
            }
            i++;
        }
        while(pq.size()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
