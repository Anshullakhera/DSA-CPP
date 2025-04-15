//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dis(V, 1e8);
        dis[src] = 0;
        for(int i = 0; i<V-1; i++){
            for(auto& it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dis[u] != 1e8 && dis[u] + wt < dis[v]){
                    dis[v] = dis[u] + wt;
                }
            }
        }
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dis[u] != 1e8 && dis[u] + wt < dis[v]){
                return {-1};
            }
        }
        return dis;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int> > edges;

        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(V, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
