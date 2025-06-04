class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        // Code here
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        int dp[n1 + 1][n2 + 1][n3 + 1];

        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                for (int k = 0; k <= n3; k++) {
                    if (i == 0 || j == 0 || k == 0)
                        dp[i][j][k] = 0;
                    else if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    else
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }

        return dp[n1][n2][n3];
    }
};
