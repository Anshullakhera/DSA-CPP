class Solution {
  public:
    vector<vector<bool>>vis;
    vector<int>di = {-1 , 1 , 0 , 0};
    vector<int>dj = {0 , 0 , -1 , 1};
  
    bool check(int i , int j , int idx , vector<vector<char>> &mat , string &word){
        int n = mat.size() , m = mat[0].size();
        if(idx >= word.size())
            return true;
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || mat[i][j] != word[idx])
            return false;
        vis[i][j] = true;
        bool flag = false;
        for(int k = 0; k < 4; k++){
            int I = i + di[k];
            int J = j + dj[k];
            flag |= (check(I , J , idx + 1 , mat , word));
        }
        vis[i][j] = false;
        return flag;
    }
  
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        int n = mat.size() , m = mat[0].size();
        vis.assign(n , vector<bool>(m , false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == word.front()){
                    if(check(i , j , 0 , mat , word))
                        return true;
                }
            }
        }
        return false;
    }
};
