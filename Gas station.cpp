class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n = gas.size();
        int totalCost = 0, totalGas = 0;
        
        // Calculate total gas and total cost
        for(int i = 0; i < n; ++i) {
            totalCost += cost[i];
            totalGas += gas[i];
        }
        
        // If total cost exceeds total gas, circuit cannot be completed
        if(totalCost > totalGas) return -1;
        
        int start = 0;  // Potential starting station
        int profit = 0; // Cumulative profit (gas - cost)
        
        for(int i = 0; i < n; ++i) {
            // Update current profit
            profit += (gas[i] - cost[i]);
            
            // If profit becomes negative, we can't start from current 'start'
            if(profit < 0) {
                // Move start to next station
                start = (i + 1) % n;
                // Reset profit as we're starting from new station
                profit = 0;
            }
        }
        
        // After checking all stations, 'start' is our answer
        return start;
    }
};
