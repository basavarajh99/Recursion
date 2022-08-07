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
