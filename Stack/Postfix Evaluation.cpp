class Solution {
  public:
    bool isDigit(string str) {
        return (str != "+" && str != "-" && str != "*" && str != "/" && str != "^");
    }

    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (isDigit(arr[i])) {
                st.push(stoi(arr[i]));
            } else {
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                
                if (arr[i] == "+") st.push(val2 + val1);
                else if (arr[i] == "-") st.push(val2 - val1);
                else if (arr[i] == "*") st.push(val2 * val1);
                else if (arr[i] == "/") {
                    int res = val2/val1;
                    if(val2%val1!=0 &&((val2<0)^(val1<0))){
                        res = res-1;
                    }
                    st.push(res);
                }
                else if (arr[i] == "^") st.push(pow(val2, val1));
            }
        }
        
        return st.top();
    }
};
