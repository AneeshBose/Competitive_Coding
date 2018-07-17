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


bool alpha(const string &first, const string &second) 
{
    return first.size() < second.size();
}

bool iscontained(string og,string sub)
{
	if (og.find(sub) != string::npos) {
    	return true;
	}
	return false;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    vector<string> names;
    int n; cin>>n;
    loop(i,n)
    {
    	string str; cin>>str;
    	names.pb(str);
    }
    int flg=1;
    sort(names.begin(),names.end(),alpha);
    loope(i,1,n-1)
    {
    	if(sz(names[i])==sz(names[i-1]))
    	{
    		if(names[i]!=names[i-1])
    		{
    			flg=-1;
    			break;
    		}
    	}
    	else
    	{
    		if(!iscontained(names[i],names[i-1]))
    		{
    			flg=-1;
    			break;
    		}
    	}
    }
    if(flg==1)
    {
    	cout<<"YES\n";
    	loop(i,n)
    		cout<<names[i]<<endl;
    }
    else
    	cout<<"NO";
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}