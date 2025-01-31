//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a solved Sudoku.
    bool checkValid(int row, int col, int op, vector<vector<int>>&mat){
        // Check the row
        for(int j = 0; j < 9; ++j){
            if(mat[row][j] == op) return false;
        }
        
        // Check the column
        for(int i = 0; i < 9; ++i){
            if(mat[i][col] == op) return false;
        }
        
        // Check the 3x3 sub-grid
        int rc = (row/3) * 3, cc = (col/3) * 3;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(mat[rc + i][cc + j] == op) return false;
            }
        }
        
        return true; // The number is valid in this position
    }
    
    // Function to solve the Sudoku using backtracking
    bool solve(vector<vector<int>>&mat){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                
                // If an empty cell (0) is found
                if(mat[i][j] == 0){
                    
                    // Try placing numbers 1 to 9
                    for(int op = 1; op <= 9; ++op){
                        
                        // Check if the number is valid
                        if(checkValid(i, j, op, mat)){
                            mat[i][j] = op; // Place the number
                            
                            // Recursively solve the next empty cell
                            if(solve(mat)) return true;
                            
                            // Backtrack: If placing 'op' leads to no solution, reset it
                            mat[i][j] = 0;
                        }
                    }
                    
                    return false; // If no number can be placed, return false
                }
            }
        }
        
        return true; // Sudoku solved successfully
    }
    
    // Main function to solve the given Sudoku board
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat); // Start solving the board
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
