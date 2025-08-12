class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
       if(prices.size()%(k+1)!=0)
       k=prices.size()/(k+1)+1;
       else
       k=prices.size()/(k+1);
       int minans=0,maxans=0;
       for(int i=0;i<k;i++)
       {
           minans+=prices[i];
           maxans+=prices[prices.size()-1-i];
       }
       return {minans,maxans};
    }
};
