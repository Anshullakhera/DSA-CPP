class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        stack<char> st;
        int i = 0;
        int cnt = 0;
        int n = s.length();
        while(i < n){
            while(st.empty() == false && cnt < k && st.top() < s[i]){
                st.pop();
                cnt++;
            }
            st.push(s[i]);
            i++;
        }
        
        while(cnt < k && st.empty() == false){
            st.pop();
            cnt++;
        }
        
        string ans = "";
        while(st.empty() == false){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
