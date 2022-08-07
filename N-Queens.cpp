//Brute-force

//only check for left half while issafe()
class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n)
    {
        int r = row, c = col;
        
        while(row>=0 and col>=0)//for north-west direction
        {
            if(board[row][col]=='Q')
                return false;
            row--, col--;
        }
        
        row = r, col = c;
        
        while(col>=0) //for west direction
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        
        row = r, col = c;
        while(row<n and col>=0) //for south-west direction
        {
            if(board[row][col]=='Q')
                return false;
            row++, col--;
        }
        
        return true;            
    }
    
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n)
    {
        if(col == n) //once col goes out of range
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++)// try for every row
        {
            if(isSafe(row, col, board, n)) //is it safe to place queen in that row so that it doesn't get attacked 
            {
                board[row][col]='Q';
                solve(col+1, board, ans, n);
                board[row][col]='.'; //remove once recursion over i.e, backtrack
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) //placing empty string in every row of board(nxn)
            board[i] = s;
        solve(0, board, ans, n);
        return ans;
    }
};
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //efficient, by hashing that is check whether a queen is placed in that row before this avoids O(N) while checking for directions in isSafe()
    //mark hash[row+col] = 1 so that after u can check whether a queen is placed in that diagonal or not, this is for south-west
    //for north-west, hash[(n-1)+(col-row)] = 1
    //for west hash[row] = 1
    
    class Solution {
public:    
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n, vector<int>& west, vector<int>& north_west, vector<int>& south_west)
    {
        if(col == n) //once col goes out of range
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++)// try for every row
        {
            if(west[row]==0 and south_west[row+col]==0 and north_west[n-1 + col-row]==0) //is it safe to place queen in that row so that it doesn't get attacked 
            {
                board[row][col]='Q';
                //mark in all three directions
                west[row] = 1; 
                south_west[row+col] = 1;
                north_west[n-1 + col-row] = 1;
                solve(col+1, board, ans, n, west, north_west, south_west);
                //remove once recursion over i.e, backtrack
                board[row][col]='.'; 
                west[row] = 0; 
                south_west[row+col] = 0;
                north_west[n-1 + col-row] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) //placing empty string in every row of board(nxn)
            board[i] = s;
        vector<int> west(n, 0), north_west(2*n-1, 0), south_west(2*n-1, 0);
        solve(0, board, ans, n, west, north_west, south_west);
        return ans;
    }
};
    
    
