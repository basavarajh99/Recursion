 void solve(vector<vector<int>>& ans, vector<int>& nums, vector<int>& v, int i)
    {
        ans.push_back(v);
        //if(i>=nums.size()) return;
        
        for(int j=i; j<nums.size(); j++)
        {
            if(j!=i and nums[j]==nums[j-1]) continue;
            v.push_back(nums[j]);
            solve(ans, nums, v, j+1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //TC: O(2^n)*n SC: O(2^n)*n
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        solve(ans, nums, v, 0);
        return ans;    
        
    }
