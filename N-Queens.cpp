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
