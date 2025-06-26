class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        priority_queue<int> pq;
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(v[i]!=0)pq.push(v[i]);
        }
        while(k>0){
            int l=pq.top();
            pq.pop();
            pq.push(l-1);
            k--;
        }
        int ans=0;
        while(!pq.empty()){
            int m=pq.top();
            ans+=m*m;
            pq.pop();
        }
        return ans;
    }
};
