class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        int n=intervals.size();
        int maxi=-1e9;
        
        for(auto &it:intervals){
            maxi=max(maxi, it[1]);
        }
        
        vector<int>diff(maxi+3, 0);
        
        for(auto &it:intervals){
            diff[it[0]]++;
            diff[it[1]+1]--;
        }
        
        int ans=-1;
        
        for(int i=1; i<maxi+1; i++){
            diff[i]+=diff[i-1];
            if(diff[i]>=k) ans=i;
        }
        
        return ans;
    }
};
