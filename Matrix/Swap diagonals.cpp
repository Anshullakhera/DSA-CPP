class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        int size = mat.size();
        int i = 0;
        int j = 0;
        
        int k = 0;
        int l = size - 1;
        while(size >= 1){
            int temp = mat[i][j];
            mat[i][j] = mat[k][l];
            mat[k][l] = temp;
            i++;j++;
            k++;l--;
            
            size--;
        }
    }
};
