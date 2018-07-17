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
    int n; 
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    if(s[0]=='1') cnt++; 
    if(s[n-1]=='1') cnt++;
   	loope(i,1,n-2)
   	{
   		if(s[i]=='1')
   		{
   			cnt++;
   			if(s[i-1]=='1' || s[i+1]=='1')
   			{
   				cout<<"No\n";
   				return 0;
   			}
   		}
   	}
   	if(n&1)
   	{
   		if(ceil(n*1.0/2)!=cnt)
   			cout<<"No\n";
   		else 
   			cout<<"Yes\n";
   	}
   	else
   	{
   		if(cnt==n/2)
   			cout<<"Yes\n";
   		else
   			cout<<"No\n";
   	}
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}