class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        vector<vector<int>> ans(k);
        priority_queue<pair<double, vector<int>>> pq; // Max-Heap
        
        for(auto pt: points) {
            double dist = sqrt((pt[0] * pt[0]) + (pt[1] * pt[1])); // distance bw origin and point
            
            pq.push({dist, {pt[0], pt[1]}});
            
            if(pq.size() > k) {
                pq.pop(); // remove the point with max distance among current (k + 1) largest-distance points from pq 
            }
        }
        
        int i = 0;
        while(!pq.empty()) {
            ans[i++] = pq.top().second;
            pq.pop();
        }
        
        return ans;
    }
};
