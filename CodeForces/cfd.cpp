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

bool isPresent(ull ele, const vector<ull> &a)
{
	loop(i,sz(a))
		if(ele==a[i])
			return true;
		return false;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    std::vector<ull> a(n);
    loop(i,n)
    	cin>>a[i];
    vector<ull> ans;
   	int i=0;
   	while(i<n)
   	{
   		ans.pb(a[i]);
   		while(sz(ans)<n)
	   	{
	   		if(ans.back()%3==0)
	   		{
	   			if(isPresent(ans.back()/3,a))
	   				ans.pb(ans.back()/3);
	   			else if(isPresent(ans.back()*2,a))
	   				ans.pb(ans.back()*2);
	   			else
	   			{
	   				ans.clear();
	   				break;
	   			}
	   		}
	   		else
	   		{
	   			if(isPresent(ans.back()*2,a))
	   				ans.pb(ans.back()*2);
	   			else
	   			{
	   				ans.clear();
	   				break;
	   			}
	   		}
	   	}
	   	if(sz(ans)==n)
	   		break;
	   	i++;
   	}
   	loop(i,sz(ans))
   		cout<<ans[i]<<" ";
   	cout<<endl;
	return 0;
}