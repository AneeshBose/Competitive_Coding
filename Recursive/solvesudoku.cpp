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
int fin=0;

bool isfull(int sud[][9])
{
	loop(i,9)
		loop(j,9)
			if(sud[i][j]==0)
				return 0;
	return 1;
}

vector<int> populateNumbers(int sud[][9],int r,int c)
{
	vector<int> rep;
	int pres[10]={0};
	loop(i,9)
		pres[sud[r][i]]=1;
	loop(i,9)
		pres[sud[i][c]]=1;
	r=(r/3)*3; c=(c/3)*3;
	for(int i=r;i<r+3;i++)
	{
		for(int j=c;j<c+3;j++)
			pres[sud[i][j]]=1;
	}
	for(int i=1;i<=9;i++)
		if(pres[i]==0)
			rep.push_back(i);
	return rep;
}

void solveSudoku(int sud[][9])
{
	if(isfull(sud) && !fin)
	{
		fin=1;
		loop(i,9)
			loop(j,9)
				cout<<sud[i][j]<<" ";
		return;
	}
	int i,j; bool flg=0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
			if(sud[i][j]==0)
			{
				flg=1;
				break;
			}
		if(flg)
			break;
	}
	vector<int> possible=populateNumbers(sud,i,j);
	loop(l,sz(possible))
	{
		sud[i][j]=possible[l];
		solveSudoku(sud);
	}
	// loop(l,sz(possible))
	// 	cout<<possible[l]<<" ";
	// cout<<endl;
	sud[i][j]=0;
}

void solve()
{
	int sudoku[9][9];
	loop(i,9)
		loop(j,9)
			cin>>sudoku[i][j];
	solveSudoku(sudoku);
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
    	fin=0;
    	solve();
    	cout<<endl;
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}