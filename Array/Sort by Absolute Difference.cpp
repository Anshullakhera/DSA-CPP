class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        map<int,vector<int>>mp;
        for(auto it:arr){
            mp[abs(x-it)].push_back(it);
        }
        int i=0;
        for(auto it:mp){
            for(auto num:it.second){
                arr[i++]=num;
            }
        }
    }
};
