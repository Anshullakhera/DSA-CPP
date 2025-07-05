class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int count=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            count=max(count,arr[i]+arr[i+1]);
        }
        return count;
    }
};
