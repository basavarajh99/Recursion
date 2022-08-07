//using extra space freq[]
void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& store, vector<int>& freq)
    {
        if(store.size() == nums.size()) 
        {
            ans.push_back(store);
            return;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(!freq[i])//not pick
            {
                store.push_back(nums[i]);
                freq[i]=1;
                solve(nums, ans, store, freq);//pick
                freq[i]=0;
                store.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> store;
        vector<int> freq(nums.size(), 0);
        solve(nums, ans, store, freq);
        return ans;
    }
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //space optimized, using swap()
   void solve(int j, vector<int>& nums, vector<vector<int>>& ans)
    {
        if(j==nums.size()) 
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=j; i<nums.size(); i++)
        {
                swap(nums[i], nums[j]);
                solve(j+1, nums, ans);
                swap(nums[j], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
    
