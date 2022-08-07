//TC: O(2^n)
void print(int i, vector<int> v, int s, int sum, int arr[], int n)
{
  if(i==n)
  {
    if(s==sum)
    {
      for(auto it : v)
        cout<<it;
      
      return;
    }
  }
  
  //pick
  v.push_back(arr[i]);
  s+=arr[i];
  print(i+1, v, s, sum, arr, n);
  
  //not pick
   v.pop_back(arr[i]);
  s-=arr[i];
  print(i+1, v, s, sum, arr, n);
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//To print only one subsequence
bool print(int i, vector<int> v, int s, int sum, int arr[], int n)
{
  if(i==n)
  {
    if(s==sum)
    {
      for(auto it : v)
        cout<<it;
      
      return true;
    }
    else return false;
  }
  
  //pick
  v.push_back(arr[i]);
  s+=arr[i];
  if(print(i+1, v, s, sum, arr, n)) return true; //no more recursion calls
  
  //not pick
  v.pop_back(arr[i]);
  s-=arr[i];
  if(print(i+1, v, s, sum, arr, n)) return true; //no more recursion calls
  
  return false;
}
