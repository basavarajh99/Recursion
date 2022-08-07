//TC: O(2^n)
f(i, arr, k)
{
  if(i=arr.size()) 
  {
    if(sum==k)
      print(arr);
    return;
  }
  
  arr.push_back(arr[i);
  sum+=arr[i]'
  f(i+1, arr, k);//take
  arr.remove(arr[i]);
  sum-=arr[i];
  f(i+1, arr, k);//not take
}
