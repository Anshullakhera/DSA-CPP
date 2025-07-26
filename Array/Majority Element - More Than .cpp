class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        map <int,int> mp;
        vector<int> ans;
        for(int e:arr)mp[e]++;
        for(auto e:mp)if(e.second>arr.size()/3)ans.push_back(e.first);
        return ans;
    }
};
