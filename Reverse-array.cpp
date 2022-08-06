void reverse(l, r, a)
{
  if(l>=r) //base condition
  return;
  
  swap(a[l], a[r]);
  
  reverse(l+1, r-1, a);
}

// or

void rev(i,a)
{
  if(i>=n/2) return;
  
  swap(a[i], a[n-i-1]);
  
  rev(i+1, a);
}
