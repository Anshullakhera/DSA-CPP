class Solution {
  public:
    bool dfs (int i , vector<int> adj[] , vector<int> & vis ){
        if(vis[i]==-1) return false;
        if(vis[i]==1) return true ;
        vis[i] = 2;
        for(int it : adj[i]){
            if(vis[it]==2) return false;
            bool dfscall = dfs(it , adj , vis);
            if(!dfscall) 
            {
                vis[it]=-1;
                return false;   
            }else if(dfscall) vis[it]=1;
        }
        vis[i]=1;
        return true ;
    }
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for(auto it : edges) adj[it[0]].push_back(it[1]);
        vector<int> ans ;
        vector<int> vis(V,0); // 1 -> vis , path --> 2 
        for(int i = 0 ; i < V ; i++){
            if(vis[i]==0){
                if(dfs(i , adj , vis)) ans.push_back(i);
            }else if(vis[i]==1)ans.push_back(i);
        }
        return ans ;
    }
};
