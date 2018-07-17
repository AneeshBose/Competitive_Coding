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


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int floors,sections,stair,elevator,v;
    cin>>floors>>sections>>stair>>elevator>>v;
    vi stairs(stair),elevators(elevator);
	loop(i,stair)
		cin>>stairs[i];
    loop(i,elevator)
    	cin>>elevators[i];
    int q; cin>>q;
    while(q--)
    {
    	int srcx,srcy,endx,endy;
    	cin>>srcy>>srcx>>endy>>endx;
    	int fin_stairs=inf, fin_ele=inf;

    	if(stair>0)
    	{
    		auto st1=upper_bound(all(stairs),srcx);
	    	auto st2=st1; if(st2!=stairs.begin()) st2--;
	    	if(st1!=stairs.end())
	    		fin_stairs=min(fin_stairs,abs(*st1-srcx)+abs(endy-srcy)+abs(*st1-endx));
	    	fin_stairs=min(fin_stairs,abs(*st2-srcx)+abs(endy-srcy)+abs(*st2-endx));
    	}
    	if(elevator>0)
    	{
    		auto ele1=upper_bound(all(elevators),srcx);
	    	auto ele2=ele1; if(ele2!=elevators.begin()) ele2--;
	    	if(ele1!=elevators.end())
	    		fin_ele=min(fin_ele,abs(*ele1-srcx)+(int)ceil(abs(endy-srcy)*1.0/v)+abs(*ele1-endx));
	    	fin_ele=min(fin_ele,abs(*ele2-srcx)+(int)ceil(abs(endy-srcy)*1.0/v)+abs(*ele2-endx));
    	}
    	if(endy==srcy)
    		cout<<abs(srcx-endx);
    	else
    		cout<<min(fin_ele,fin_stairs);
    	cout<<endl;
    }
	return 0;
}