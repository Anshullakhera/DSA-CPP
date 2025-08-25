class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
      int n = arr.size();
     int index = (n % 2 == 0) ? (n-1)/ 2 : n/ 2;
      long long kk = k;
        int i;
      for ( i = index; i < n - 1; i++) {
          long long need = 1LL * (i + 1 - index) * (arr[i + 1] - arr[index]);
          if (need <= kk) {
              kk -= need;
              arr[index] = arr[i + 1]; 
          } else {
              arr[index] += kk / (i + 1 - index);  
              kk=0;break;
          }
      }
      if (kk > 0) {
          arr[index] += kk / (n - index);
      }
      if(i==index && n%2==0) return (arr[index]+arr[index+1])/2;
      else return arr[index];
    }
};
