class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        queue<char>q;
        map<char,int>mp;
        int n=s.size();
        string ans;
        for(int i=0;i<n;i++){
            char x=s[i];
            if(mp.find(x)==mp.end()){
                q.push(x);
                mp[x]++;
            } else {
                mp[x]++;
                while(!q.empty() && mp[q.front()]>1){
                    q.pop();
                }
            }
            ans.push_back(q.empty() ? '#' : q.front());
        }
        return ans;
    }
};
