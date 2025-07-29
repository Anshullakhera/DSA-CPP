class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        vector<int>v;
        unordered_set<char>st;
        for(auto &b: s){
            if(st.find(b)==st.end()){
                st.insert(b);
                int first=s.find(b), last=s.rfind(b);
                if(first!=last){
                    int ans=0;
                    for(int i=first+1; i<last; i++){
                        ans+=s[i];
                    }
                    if(ans!=0){v.push_back(ans);}
                }
            }
        }
        return v;
    }
};
