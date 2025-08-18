class Solution {
  public:
    bool possible(vector<int>& citations, int ayush){
      int count=0;
      for(int i=0;i<citations.size();i++){
          if(citations[i]>=ayush)
          count++;
          if(count>=ayush){
              return true;
          }
      }
      return false;
  }
    int hIndex(vector<int>& citations) {
        // code here
        int n=citations.size();
        sort(citations.begin(),citations.end());
        int start=0,end=citations[n-1];
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(possible(citations,mid)){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};
