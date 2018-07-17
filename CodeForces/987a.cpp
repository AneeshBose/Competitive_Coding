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
    loop(i,6)
    	a[i]=-1;
    loop(i,n)
    {
    	string str; cin>>str;
    	if(str=="red")
    		a[0]=1;
    	else if(str=="purple")
    		a[1]=1;
    	else if(str=="yellow")
    		a[2]=1;
    	else if(str=="orange")
    		a[3]=1;
    	else if(str=="green")
    		a[4]=1;
    	else if(str=="blue")
    		a[5]=1;
    }
    cout<<6-n<<endl;
    loop(i,6)
    {
    	if(a[i]==-1)
    	{
    		if(i==0)
    			cout<<"Reality";
    		else if(i==1)
    			cout<<"Power";
    		else if(i==2)
    			cout<<"Mind";
    		else if(i==3)
    			cout<<"Soul";
    		else if(i==4)
    			cout<<"Time";
    		else if(i==5)
    			cout<<"Space";
    		cout<<endl;
    	}
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}