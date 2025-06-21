class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int i =0,j=0,ans =0;
       int n = arr.size();
       while(i<n && j<n){
           while(i<n && arr[i]!= 'P')i++;
           while(j<n && arr[j]!='T')j++;
           if(abs(j-i)<=k && i<n && j<n){
               i++;j++;ans++;
           }else{
               if(i<j)i++;
               else j++;
           }
       }
       return ans;
    }
};
