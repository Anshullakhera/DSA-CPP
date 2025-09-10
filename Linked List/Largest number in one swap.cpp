class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();
        vector<int> last(10, -1);

        // store last occurrence of each digit
        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }

        // iterate from left to right
        for (int i = 0; i < n; i++) {
            int curr = s[i] - '0';
            // check if there exists a bigger digit later
            for (int d = 9; d > curr; d--) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return s; // only one swap allowed
                }
            }
        }
        return s; 
    }
};
