class Solution {
  public:
    bool checkCurrentDivisor(int divisor,vector<int>&arr,int k){
        
        int values = 0;
        int n = arr.size();
        
        //calculating the sum of ceiling values with the current divisor.
        for(int i  = 0;i<n;i++){
            
            values += arr[i]/divisor;
            if(arr[i]%divisor)
                values++;
        }
        
        return values <= k;
        
    }
    
    int smallestDivisor(vector<int>& arr, int k) {
        
        int low = 1;
        int high = 1;
        int n  = arr.size();
        int ans = INT_MAX ;
        
        for(int i  = 0;i<n;i++){
            high = max(high,arr[i]);
        }
        
        // now applying the technique of binary search to find the 
        // smallest positive integer divisor according to the question 
        
        while(low<=high){
            
            int mid = low +(high-low)/2;
            
            // check for the current mid (divisor)
            
            if(checkCurrentDivisor(mid,arr,k)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else
                low  = mid+1;
            
        }
        
        return ans;
    }
};
