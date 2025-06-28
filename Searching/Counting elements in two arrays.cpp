class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>ans;
        sort(b.begin(),b.end());
        for(int i=0;i<a.size();i++){
            int low=0,high=b.size()-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(b[mid]<=a[i]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            ans.push_back(low);
        }
        return ans;
        
    }
};
