//without filling blanks 
  bool isvalid(vector<vector<char>>& board, int i, int j, char target)
  {
      for(int k=0; k<9; k++)
      {
          if(k!=j and board[i][k]==target) return false; //duplicates in row

          if(k!=i and board[k][j]==target) return false; // duplicates in col

          //every block has 3 rows
          //let's assume we are at (5,7) so 
          // row = 5/3 = 1 and 1*3  will give the row number/horizontal in 9*9 matrix where (5,7) exists in 3*3 block then adding k/3 will make sure you move to next row in 3*3 block
          //similarly for column do the same but add k%3 to move to next column since k/3 return same '1'
          int r = 3*(i/3)+k/3; //3*3 matrix's rows

          int c = 3*(j/3)+k%3; //3*3 matrix's cols

          if(r!=i and c!=j and board[r][c]==target)
              return false;
      }

      return true;

  }

  bool isValidSudoku(vector<vector<char>>& board) {

      for(int i=0; i<board.size(); i++)
      {
          for(int j=0; j<board[0].size(); j++)
          {
              if(board[i][j]!='.') //to check for only existing elements rather than filling the missing one
              {
                  if(!isvalid(board, i, j, board[i][j]))
                      return false;
              }
          }
      }

      return true;
  }
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // with filling blanks with valid digits
  #include <iostream>

#include <vector>

using namespace std;

bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

bool solve(vector < vector < char >> & board) 
{
  for (int i = 0; i < board.size(); i++) 
  {
    for (int j = 0; j < board[0].size(); j++) 
    {
      if (board[i][j] == '.') 
      {
        for (char c = '1'; c <= '9'; c++) 
        {
          if (isValid(board, i, j, c)) 
          {
            board[i][j] = c;

            if (solve(board))
              return true;
            else
              board[i][j] = '.';
          }
        }

        return false;
      }
    }
  }
  return true;
}
int main() {
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
   
    solve(board);
        	
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}
