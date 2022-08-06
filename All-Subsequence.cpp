f(i, arr)
{
  if(i>=arr.size()) return;
  
  arr.push_back(arr[i);
  f(i+1, arr);//take
  arr.remove(arr[i]);
  f(i+1, arr);//not take
}
