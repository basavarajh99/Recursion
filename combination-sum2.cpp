   void findcomb(int i, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& store)
    {
       if(target == 0) 
       {
            ans.push_back(store);
            return;            
       }
        
        for(int j=i; j<candidates.size(); j++)
        {
            if(j>i and candidates[j]==candidates[j-1]) continue; //not pick
            if(candidates[j]>target) break;
            store.push_back(candidates[j]);
            findcomb(j+1, target-candidates[j], candidates, ans, store);//pick
            store.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //TC: O(2^n)*k
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> store;
        findcomb(0, target, candidates, ans, store);
        return ans;
    }
