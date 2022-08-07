//TC: O(2^t)*k
 void findcomb(int i, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& store)
  {
      if(i==candidates.size())
      {
          if(target == 0) 
              ans.push_back(store);
          return;            
      }

      //pick 
      if(candidates[i]<=target)
      {
          store.push_back(candidates[i]);
          findcomb(i, target-candidates[i], candidates, ans, store);
          store.pop_back();
      }

      //not pick
      findcomb(i+1, target, candidates, ans, store);        
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
      vector<int> store;
      findcomb(0, target, candidates, ans, store);
      return ans;
  }
