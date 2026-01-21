class Solution {
  public:
        vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> ans(n,0);
        
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(st.size() > 0 && arr[st.top()] <= arr[i]){  // we are removing small value from the stack
                st.pop();
            }
            
            if(st.size() == 0){
                ans[i] = i+1;
            }
            
            else{
                ans[i] = i - st.top();   // i - preHigh
            }
            st.push(i);
        }
        return ans;
    }
};
