//TC: O(4^(n*m))

class Solution{
    //maintain visit matrix
    //Brute
    public:
    
    void solve(int i, int j, vector<string>& ans, string move, vector<vector<int>> &m, int n, vector<vector<int>> &vis)
    {
        if(i==n-1 and j == n-1)
        {
            ans.push_back(move);
            return;
        }
        
        
        //downward
        if(i+1<n and !vis[i+1][j] and m[i+1][j]==1)
        {
            vis[i][j] = 1;
            solve(i+1, j, ans, move+"D", m, n, vis);
            vis[i][j] = 0;
        }
        
        //leftward
        if(j-1>=0 and !vis[i][j-1] and m[i][j-1])
        {
            vis[i][j] = 1;
            solve(i, j-1, ans, move+"L", m, n, vis);
            vis[i][j] = 0;
        }
        
        //Rightward
        if(j+1<n and !vis[i][j+1] and m[i][j+1])
        {
            vis[i][j] = 1;
            solve(i, j+1, ans, move+"R", m, n, vis);
            vis[i][j] = 0;
        }
        if(i-1>=0 and !vis[i-1][j] and m[i-1][j])
        {
            vis[i][j] = 1;
            solve(i-1, j, ans, move+"U", m, n, vis);
            vis[i][j] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>>vis(n, vector<int>(n, 0));
        if(m[0][0]==1) solve(0, 0, ans, "", m, n, vis);
        return ans;
    }
};
