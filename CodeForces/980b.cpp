//aneesh bose
#include <bits/stdc++.h>
using namespace std;
const int N=1234567;
int a[N]; bool visited[N];

#define loop(i,n) for(int i=0;i<n;i++)
#define loope(i,n) for(int i=0;i<=n;i++)
#define loope(i,l,r) for(int i=l;i<=r;i++)
#define loopr(i,n) for(int i=n-1;i>=0;i--)
#define endl '\n'

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define yolo "debug_statement"

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

const ll inf = 1e9;
const ld eps = 1e-9;
const ld pi=acos(-1);
const ll mod=1000000007;

ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

/*void dfs(int source){
    visited[source] = true;
    for(auto it: adj[source])
        if(!visited[it])
            dfs(it);
}*/


int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int cols,k;
    cin>>cols>>k;
    char mat[4][100];
    cout<<"YES\n";
    loop(i,4)
    {
    	loop(j,cols)
    		mat[i][j]='.';
    }
    if(!(k&1))
    {
    	for(int i=1,j=cols-2;i<cols/2,j>cols/2;i++,j--)
    	{
    		if(k)
    		{
	    		mat[1][i]=mat[1][j]='#';
	    		k-=2;
    		}
    	}
    	for(int i=1,j=cols-2;i<cols/2,j>cols/2;i++,j--)
    	{
    		if(k)
    		{
	    		mat[2][i]=mat[2][j]='#';
	    		k-=2;
    		}
    	}
    	if(k)
    	{
    		mat[1][cols/2]=mat[2][cols/2]='#';
    	}
    }
    else
    {
    	mat[1][cols/2]='#';
    	k--;
		for(int i=1;i<cols/2;i++)
		{
			if(k)
			{
				mat[1][i]=mat[1][cols-1-i]='#';
				k-=2;
			}
		}
		for(int i=1;i<cols/2;i++)
		{
			if(k)
			{
				mat[2][i]=mat[2][cols-1-i]='#';
				k-=2;
			}
		}
    	
    }
    loop(i,4)
    {
    	loop(j,cols)
    		cout<<mat[i][j];
    	cout<<endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}