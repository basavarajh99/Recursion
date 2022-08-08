class Solution {
public:
    
    void permute(string s, vector<string>& v, int l, int r)
    {
        if(l==r)
        {
            v.push_back(s);
            return;
        }
        
        for(int i=l; i<=r; i++)
        {
            swap(s[l],s[i]);
            permute(s, v, l+1, r);
            swap(s[l],s[i]);
        }
            
    }
    
    string getPermutation(int n, int k) {
        //Brute-force: O(n!*nlogn)
        vector<string> v;
        string s;
        
        for(int i=1; i<=n; i++)
            s+=to_string(i);
        
        permute(s, v, 0, s.length()-1);
        
        sort(v.begin(), v.end());
        
        return v[k-1];
    }
};
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//efficient TC: O(N^2) SC: O(N)
string getPermutation(int n, int k) {
    int fact = 1;
    vector<int> num;

    for(int i=1; i<n; i++) //compute factorial till n-1
    {
        fact*=i;
        num.push_back(i);
    }

    num.push_back(n); //all numbers from 1 to n

    string ans = "";

    k = k-1; // 0 based indexing so k-1th permutation

    while(true)
    {
        ans+=to_string(num[k/fact]); // num[k/fact] will be the first element in the k-1th permuatation

        num.erase(num.begin()+k/fact); // after putting in answer remove it from nums to get next elemnt from remaining numbers 

        if(num.size()==0) //we got all the elements in k-1th permutation
            break;

        k%=fact; //next value of k for second element will be k%fact 

        fact/=num.size(); //next time the factorial will be for fact/num.size() size of numbers
    }

    return ans;
}
