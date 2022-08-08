 bool isSafe(int node, int color[], int n, bool graph[][101], int newcolor)
    {
        for(int j=0; j<n; j++)
            if(j!=node and graph[j][node]==1 and color[j]==newcolor) //check for adjecent node color
                return false;
        
        return true;
    }
    
    bool solve(int src, int color[], int m, int n, bool graph[101][101])
    {
        if(src == n) 
        return true;
        
        for(int i=1; i<=m; i++) //try for all the colors
        {
            if(isSafe(src, color, n, graph, i)) //check whether adjecent nodes have same color
            {
                color[src] = i;
                if(solve(src+1, color, m, n, graph)) //if any one of the recursive call return true stop
                    return true;
                color[src] = 0; //backtrack if recursive calls return false
            }
        }
        
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        
        if(solve(0, color, m, n, graph)) return true;
        
        return false;
    }
