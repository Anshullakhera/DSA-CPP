//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int cl, int nc, vector<vector<bool>>& vis, vector<pair<int, int>>& dir) {
        int n = image.size();
        int m = image[0].size();
        
        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != cl || vis[i][j])
            return;

        image[i][j] = nc;
        vis[i][j] = true;

        for (auto d : dir)
            dfs(i + d.first, j + d.second, image, cl, nc, vis, dir);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int cl = image[sr][sc];

        if (cl != newColor)
            dfs(sr, sc, image, cl, newColor, vis, dir);

        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
