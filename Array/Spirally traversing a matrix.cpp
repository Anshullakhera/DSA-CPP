//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int row=0,col=0,srow=0,scol=0,erow = mat.size() - 1, ecol = mat[0].size() - 1; // End row and column
        vector<int>ans;
       while (srow <= erow && scol <= ecol) {
            for(int j=scol;j<=ecol;j++){
                ans.push_back(mat[srow][j]);
            }
            srow++;
            for(int j=srow;j<=erow;j++){
                ans.push_back(mat[j][ecol]);
            }
            ecol--;
               if (srow <= erow) {
            for(int j=ecol;j>=scol;j--){
                ans.push_back(mat[erow][j]);
            }
            erow--;
               }
                 if (scol <= ecol) {
            
              for(int j=erow;j>=srow;j--){
                ans.push_back(mat[j][scol]);
            }
            scol++;
                 }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
