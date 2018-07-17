//aneesh bose
#include <bits/stdc++.h>
using namespace std;
const int N=1234567;
bool visited[N];

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

ll a[N]; 


int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    set<ll> ele;
    loop(i,n)
    {
    	cin>>a[i];
    	ele.insert(a[i]);
    }
    int flg=-1; ll val,val1;
    loop(i,32)
    {
    	loop(j,n)
    	{
    		if(ele.count(a[j]-(1LL<<i)) && ele.count(a[j]+(1LL<<i)))
    			return cout<<3<<'\n'<<a[j]<<' '<<a[j]-(1LL<<i)<<' '<<a[j]+(1LL<<i)<<'\n',0;
    		else if(ele.count(a[j]-(1LL<<i)))
    		{
    			flg=11;
    			val=a[j];
    			val1=a[j]-(1LL<<i);
    		}
    	}
    }
    if(flg==11)
    	cout<<2<<'\n'<<val<<' '<<val1<<'\n';
    else
    	cout<<1<<'\n'<<a[0]<<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}