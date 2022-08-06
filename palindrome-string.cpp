bool pal(i, s)
{
  if(i>=n/2) return true;
  
  if(s[i]!=s[n-i-1]) return false;
  
  return pal(i+1, s);
}
