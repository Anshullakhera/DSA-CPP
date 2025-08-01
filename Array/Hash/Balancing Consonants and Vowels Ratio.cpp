class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        // code here
            vector<int> vec;
     unordered_map<int,int> mp; 
        mp[0]=1;
        
        int res=0;
        int sum=0;
        for(const string &str : arr){
            int count =0;
            for(char ch : str){
                if (string("aeiou").find(ch) != string::npos) {
                    count--;
                } else {
                    count++;
                }
            }
            vec.push_back(count);
        }
        int size=vec.size();
        for(int i=0;i<size;i++){ 
          sum+=vec[i];
          int rem = sum;
         if(mp.find(rem)!=mp.end()){
             res+=mp[rem];
         }
         mp[sum]++;
        }
        return res;
        
    }
};
