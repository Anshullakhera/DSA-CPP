class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        if(n==0) return false;
        int m=mat[0].size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    mp[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cnt=0;
                unordered_set<int>s(mp[i].begin(),mp[i].end());
                for(auto x:mp[j]){
                    if(s.find(x)!=s.end()){
                        cnt++;
                    }
                    if(cnt>=2) return true;
                }
            }
        }
        return false;
    }
};
