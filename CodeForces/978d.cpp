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
int a[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    vector<ll> diff;
    int n; cin>>n;
    loop(i,n)
    	cin>>a[i];
    if(n==1)
    {
    	cout<<0<<endl;
    	return 0;
    }
    loope(i,1,n-1)
    	diff.pb(a[i]-a[i-1]);
    double sum=diff[0];
    loope(i,1,sz(diff)-1)
    	sum+=diff[i];

    int cd2,cd3;
    //cd1=cd2=cd3=0;
	cd2=floor(sum*1.0/sz(diff));
	cd3=ceil(sum*1.0/sz(diff));
    vi same2(n),same3(n),kam2(n),kam3(n),zyada2(n),zyada3(n);
    // loop(i,sz(diff))
    // 	cout<<diff[i]<<" ";
    // cout<<endl;
    int st=a[0];
    loop(i,n)
    {
    	same2[i]=st;
    	st+=cd2;
    //	cout<<same2[i]<<" ";
    }
    //cout<<endl;
    st=a[0];
    loop(i,n)
    {
    	same3[i]=st;
    	st+=cd3;
    //	cout<<same3[i]<<" ";
    }
    //cout<<endl;
    st=a[0]-1;
    loop(i,n)
    {
    	kam2[i]=st;
    	st+=cd2;
    //	cout<<kam2[i]<<" ";
    }
    //cout<<endl;
    st=a[0]-1;
    loop(i,n)
    {
    	kam3[i]=st;
    	st+=cd3;
    //	cout<<kam3[i]<<" ";
    }
    //cout<<endl;
    st=a[0]+1;
    loop(i,n)
    {
    	zyada2[i]=st;
    	st+=cd2;
    //	cout<<zyada2[i]<<" ";
    }
    //cout<<endl;
    st=a[0]+1;
    loop(i,n)
    {
    	zyada3[i]=st;
    	st+=cd3;
    //	cout<<zyada3[i]<<" ";
    }
    //cout<<endl;
    int ans1,ans2,ans3,ans4,ans5,ans6;
    ans1=ans2=ans3=ans4=ans5=ans6=0;
    int f1,f2,f3,f4,f5,f6;
    f1=f2=f3=f4=f5=f6=0;
    loop(i,n)
    	if(abs(same2[i]-a[i])==1)
    		ans1++;
    	else if(abs(same2[i]-a[i])>1)
    	{
    		f1=1;
    		break;
    	}
    loop(i,n)
    	if(abs(same3[i]-a[i])==1)
    		ans2++;
    	else if(abs(same3[i]-a[i])>1)
    	{
    		f2=1;
    		break;
    	}
    loop(i,n)
    	if(abs(kam2[i]-a[i])==1)
    		ans3++;	
    	else if(abs(kam2[i]-a[i])>1)
    	{
    		f3=1;
    		break;
    	}
    loop(i,n)
    	if(abs(kam3[i]-a[i])==1)
    		ans4++;
    	else if(abs(kam3[i]-a[i])>1)
    	{
    		f4=1;
    		break;
    	}
    loop(i,n)
    	if(abs(zyada2[i]-a[i])==1)
    		ans5++;
    	else if(abs(zyada2[i]-a[i])>1)
    	{
    		f5=1;
    		break;
    	}
    loop(i,n)
    	if(abs(zyada3[i]-a[i])==1)
    		ans6++;
    	else if(abs(zyada3[i]-a[i])>1)
    	{
    		f6=1;
    		break;
    	}
    int final=10000000;
    if(f1 && f2 && f3 && f4 && f5 && f6)
    	cout<<-1<<endl;
    else 
    {
    	 //cout<<ans1<<ans2<<ans3<<ans4<<ans5<<ans5<<ans6<<endl;
    	// cout<<min(min(ans1,ans2),min(min(ans3,ans4),min(ans5,ans6)))<<endl;
    	if(ans1<final && f1==0)
    		final=ans1;
    	if(ans2<final && f2==0)
    		final=ans2;
    	if(ans3<final && f3==0)
    		final=ans3;
    	if(ans4<final && f4==0)
    		final=ans4;
    	if(ans5<final && f5==0)
    		final=ans5;
    	if(ans6<final && f6==0)
    		final=ans6;
    	cout<<final<<endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}