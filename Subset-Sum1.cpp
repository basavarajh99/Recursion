 void func(int i, int sum, vector<int>& arr, int N, vector<int>& ss)
    {
        if(i==N) 
        {
            ss.push_back(sum);
            return;
        }
        
        //pick
        func(i+1, sum+arr[i], arr, N, ss);
        //not pick
        func(i+1, sum, arr, N, ss);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ss;
        func(0, 0, arr, N, ss);
        sort(ss.begin(), ss.end());
        return ss;
    }
