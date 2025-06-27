class Solution {
  public:
  int dp[10][15];
    unordered_map<int,vector<int>>mp;
    int solve(int idx,int n){
        if(n==0) return 1;
        if(dp[idx][n]!=-1) return dp[idx][n];
        int count=0;
        for(auto &t:mp[idx]){
            count+=solve(t,n-1);
        }
        return dp[idx][n]=count;
    }
    int getCount(int n) {
        memset(dp,-1,sizeof(dp));
        mp[0]={0,8};
        mp[1]={1,2,4};
        mp[2]={2,1,3,5};
        mp[3]={3,6,2};
        mp[4]={1,4,5,7};
        mp[5]={2,5,4,8,6};
        mp[6]={6,3,5,9};
        mp[7]={7,4,8};
        mp[8]={8,7,5,9,0};
        mp[9]={9,8,6};
        int ans=0;
        for(int i=0;i<=9;i++){
            int temp=solve(i,n-1);
            ans+=temp;
        }
        return ans;
    }
};
