//fibonacci number
//TC: O(2^n)
int fib(n)
{
  if(n<=1) return n;
  
  return fib(n-1) + fib(n-2);
}
