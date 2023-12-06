/*
DOANHONGBAO
1505
*/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = 0;
 
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
#define int ll
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
const int N = 1e6+5, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), e = 1e-9;

int n,m;
int tms = 0,cnt =0;
int low[N];
int num[N];
int tp[N];
int sl[N];
vi g[N];
stack<int> s;
void doc()
{
	cin>>n>>m;
	FOR(i,1,m)
	{
		int u,v; cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u,int par)
{
	low[u] = num[u] = ++tms;
	s.push(u);
	for(auto v : g[u])
	{
		if(v == par) continue;
		if(num[v] == 0)
		{
			dfs(v,u);
			mini(low[u],low[v]);
		}
		else mini(low[u],num[v]);
	}
	if(num[u] == low[u])
	{
		cnt++;
		int x;
		do
		{
			x = s.top();
			s.pop();
			tp[x] = cnt;
			sl[cnt]++;
		}while(x!=u);
	}
}

void xuly()
{
	FOR(i,1,n) if(tp[i] == 0) dfs(i,0);
	int res = *max_element(sl + 1,sl + cnt + 1);
	cout<<res;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}