class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int>val;
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++) val.push_back(mat[i][j]);
        sort(val.begin(),val.end());
        return val[(mat.size()*mat[0].size())/2];
    }
};
