class Solution {
  public:
    map<int,bool> power_mp;
    bool is_power(string s, int startidx, int finalidx)
    {
        // Binary string should not have leading zeros
        if(s[startidx] == '0')return false;
        
        // Binary to Int
        int n = s.size();
        int fact = 1;
        int val = 0;
        for(int i = finalidx;i>=startidx;i--){
            if(s[i] == '1'){
                val += fact;
            }   
            fact = fact*2;
        }
        
        // check if a power of 5
        return power_mp[val];
    }
    int CutString(string s, int startidx, int i, vector<vector<int>> &dp){
            
        if(i == s.size()){
            if(startidx == s.size()){
                return 0;
            }
            return s.size()+1;
        }
        
        if(dp[startidx][i] != -1){
            return dp[startidx][i];
        }
        
        int brk = s.size()+1, notbrk=s.size()+1;
        if(is_power(s, startidx, i)){
            // break
            brk = CutString(s, i+1,i+1, dp) + 1;
        }
        
        // not break
        notbrk = CutString(s, startidx, i+1, dp);
        
        return dp[startidx][i] = min(brk, notbrk);
    }
    int cuts(string s) {
        // Fill power map
        long long fact = 1;
        while(fact<pow(2,30)){
            power_mp[fact] = true;
            fact = fact*5;
        }
        vector<vector<int>> dp(s.size(),vector<int>(s.size(), -1));
        int ans = CutString(s, 0, 0,dp);
        if(ans > s.length())return -1;
        return ans;
    }
};
