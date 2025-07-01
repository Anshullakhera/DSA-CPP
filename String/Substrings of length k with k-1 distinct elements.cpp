class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n=s.length();
        int count=0;
        string s1=s.substr(0,k);
        unordered_map<char,int>mp;
        for(auto it:s1){
            mp[it]++;
        }
        int dist=mp.size();
        if(dist==k-1){
            count++;
        }
        for(int i=k;i<n;i++){
            char ch=s[i-k];
            mp[ch]--;
            if(mp[ch]==0){
                mp.erase(ch);
            }
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
                if(mp.size()==k-1){
                    count++;
                }
            }
            else{
                //cout<<mp.size()<<" ";
                mp[s[i]]++;
                if(mp.size()==k-1){
                    count++;
                }
            }
        }
        return count;
    }
};
