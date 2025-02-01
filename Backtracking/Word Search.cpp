//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        // mat.size()--> row
        // mat[0].size()--> col
        for(int i =0; i<mat.size(); i++){
            for(int j =0; j<mat[0].size(); j++){
                if(mat[i][j]==word[0]){
                  vector<vector<bool>> visit(mat.size(), vector<bool>(mat[0].size(), false));
                  if(check(mat, i, j , 0 , word , visit)){
                      return true;
                  }

                }
            }
        }
        return false;
    }
    
    private:
    bool check(vector<vector<char>>& mat, int i, int j, int idx,  string& word ,  vector<vector<bool>>&visit)
   {
    
    if(idx == word.size()){
        return true;
    }
    
    // base case -->
    
    if(i<0 || j<0 || i>=mat.size()||  j>=mat[0].size() || visit[i][j] || mat[i][j]!= word[idx]){
        return false;
    }
    visit[i][j] = true;
    
    if(check(mat , i,  j-1, idx+1 , word, visit )||  //left
     check(mat , i,  j+1, idx+1 , word, visit )|| //right
     check(mat , i-1,  j, idx+1 , word, visit )|| //up
     check(mat , i+1,  j, idx+1 , word, visit )) //down
     {
         return true;
     }
     visit[i][j] = false;
     return false;
   }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
