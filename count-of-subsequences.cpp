//general format
// int f()
// {
//   base case
//     return 1; condition satisfies
//     return 0; condition doesn't satisfy
			// for two recursion calls
// 			l = f();
// 			r = f();
// forn n recursion calls
//  for(int i=0 to n)
//       s+=f();
// return s;
// 	return l+r;
// }

int print(int i, int s, int sum, int arr[], int n)
{
  if(i==n)
  { //condition satisfies
    if(s==sum)      
      return 1;
    //condition doesn't satisfy
    else return 0;
  }
  
  //pick
  s+=arr[i];
  int l = print(i+1, v, s, sum, arr, n); //no more recursion calls
  
  //not pick
  s-=arr[i];
  int r = print(i+1, v, s, sum, arr, n); //no more recursion calls
  
  return l+r;
}
