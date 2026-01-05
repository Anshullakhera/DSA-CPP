class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int ans = INT_MIN;
        int sum = 0;
        for(int i =0; i<k; i++){
            sum += arr[i];
        }
        ans = max(ans, sum);
        for(int i =k; i<n; i++){
            sum = sum - arr[i-k];
            sum += arr[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
