class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int> m1;
        map<int,set<int>> m2;
        int i = 0;
        int j = 0;
        int r = 0;
        while(j < n){
            if(m1.find(arr[j])!=m1.end()){
                int o = m1[arr[j]]++;
                m2[o].erase(arr[j]);
                m2[o+1].insert(arr[j]); 
            }
            else{ 
                m1[arr[j]]++;  
                m2[m1[arr[j]]].insert(arr[j]);    
            }
            if(j >= k-1){
                auto mi = m2.rbegin();
                auto si = mi->second.begin();
                r += *si; 
                int p = i;
                int po = m1[arr[p]];
                i++;
                m1[arr[p]]--;
                m2[po].erase(arr[p]);
                if(m2[po].empty()) m2.erase(po);
                if(m1[arr[p]] == 0) m1.erase(arr[p]);
                else m2[po-1].insert(arr[p]);
            }
            j++; 
        }
        return r;
    }
};
