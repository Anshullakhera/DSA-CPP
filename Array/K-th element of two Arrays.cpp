class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        vector<int>temp(k);
        int index=0;
        int i=0,j=0;
        
        while(i<a.size() && j<b.size() && index<k){
              if(a[i]<b[j]){
                  temp[index++]=a[i];
                  i++;
              }
              else{
                  temp[index++]=b[j];
                  j++;
              }
        }
        while(i<a.size() && index<k){
            temp[index++]=a[i++];
        }
        while(j<b.size() && index<k){
            temp[index++]=b[j++];
        }
        return temp[k-1];
    }
};
