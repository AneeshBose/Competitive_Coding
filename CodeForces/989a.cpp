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
    string str; cin>>str;
    set<char> garden;
    loop(i,sz(str)-2)
    {
    	if(str[i]=='A' || str[i]=='B' || str[i]=='C')
    	{
    		garden.insert(str[i]);
    		if(str[i+1]=='A' || str[i+1]=='B' || str[i+1]=='C')
    		{
    			garden.insert(str[i+1]);
    			if(str[i+2]=='A' || str[i+2]=='B' || str[i+2]=='C')
    				garden.insert(str[i+2]);
    		}
    	}
    	if(sz(garden)==3)
    		return cout<<"YES\n",0;
    	else
    		garden.clear();
    }
    cout<<"NO\n";
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}