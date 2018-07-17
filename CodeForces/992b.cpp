#include <bits/stdc++.h>
using namespace std;

int l,r;
vector<int> primes;
 
int totalPrimeFactors(int n)
{
    int count = 0;
 
    if (!(n%2))
    {
        primes.push_back(2);
        count++;
        while (!(n%2))
            n /= 2;
    }

    for (int i = 3; i*i <= n; i = i+2)
    {
        // i divides n
        if (!(n%i))
        {
            count++;
            primes.push_back(i);
            while (!(n%i))
                n /= i;
        }
    }

    if (n > 2)
    {
        primes.push_back(n);
        count++;
    }
 
    return count;
}
 
int countPairs(int G, int L)
{
    if (L % G != 0)
       return 0;
 
    int div = L/G;

    return (1 << totalPrimeFactors(div));
}

int main()
{
    int x,y;
    cin>>l>>r>>x>>y;
    if(y<l)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<countPairs(x,y)<<endl;
    return 0;
}