class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        long long res = 0;
        long long prev = 0;
        int n = s.size();
        const int MOD = 1e9+7;  // Though not needed as per problem, safe to add for large cases
        
        for (int i = 0; i < n; i++) {
            int num = s[i] - '0';
            prev = (prev * 10 + num * (i + 1));
            res += prev;
        }
        return res;
    }
};
