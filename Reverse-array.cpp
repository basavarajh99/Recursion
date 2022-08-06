void reverse(l, r, a)
{
  if(l>=r) //base condition
  return;
  
  swap(a[l], a[r]);
  
  reverse(l+1, r-1);
}
