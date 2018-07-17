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
    int n,k; 
    cin>>n>>k;
    string str;
    cin>>str;
    map<char,int> freq,cpy;
    loop(i,sz(str))
    	freq[str[i]]++;
    cpy=freq;
    for(auto it=cpy.begin();it!=cpy.end();it++)
    {
    	if(k==0)
    		break;
    	if(it->se >= k)
    	{
    		it->se-=k;
    		k=0;
    	}
    	else
    	{
    		k-=it->se;
    		it->se=0;
    	}
    }
    // for(auto it=freq.begin();it!=freq.end();it++)
    // 	cout<<it->se<<" ";
    // cout<<endl;
    for(int i=0;i<26;i++)
    {
    	int tar=freq[(char)('a'+i)]-cpy[(char)('a'+i)]; int cnt=0;
    	loop(j,sz(str))
    	{
    		if(cnt==tar)
    			break;
    		else
    		{
    			if(str[j]==(char)(97+i))
    			{
    				cnt++;
    				//cout<<"Hello\n";
    				str[j]='1';
    			}
    		}
    	}
    }
    //cout<<str<<endl;
    string ans;
    loop(i,sz(str))
    	if(str[i]!='1')
    		ans+=str[i];
    cout<<ans<<endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}