/*
DOANHONGBAO
1505
*/
#define TASK "TDL"
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
int L,R,U;
int h[N];
int p[N][LO + 2];
vi g[N];
void doc()
{
	cin>>n;	
	FOR(i,1,n-1)
	{
		int x,y; cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	cin>>m;
	if(m == 1) cin>>U;
	else 
	{
		cin>>L>>R;
	}
}
int f[N];
pii lim;
void dfs(int u,int par)
{
	for(auto v : g[u])
	{
		if(v == par) continue;
		dfs(v,u);
	}
	sort(all(g[u]),[](int x,int y){return f[x] > f[y];});
	int cnt = 0;
	for(auto v : g[u])
	{
		if(v == par) continue;
		if(pii{u,v} == lim || pii{v,u} == lim) continue;
		cnt++;
		maxi(f[u],f[v] + cnt);
	}
}
int cal(int u)
{
	FOR(i,1,n) f[i] = 0;
	dfs(u,0);
	return f[u];
}
int lca(int u,int v)
{
	if(h[u] < h[v]) swap(u,v);
	FORD(j,LO,0) if(h[p[u][j]] >= h[v]) u = p[u][j];
	if(u == v) return u; 
	FORD(j,LO,0) if(h[p[u][j]] != 0 && h[p[v][j]] != 0 && p[u][j] != p[v][j])
	{
		u = p[u][j];
		v = p[v][j];
	}
	return p[u][0];
}
int dis(int u,int v)
{
	return h[u] + h[v] - 2 * h[lca(u,v)];
}
void DFS(int u,int par)
{
	for(auto v : g[u])
	{
		if(v == par) continue;
		p[v][0] = u;
		h[v] = h[u] + 1; 
		DFS(v,u);
	}
}
vi race;
int tinh(int pos)
{
	lim = {race[pos],race[pos+1]};
	int X = cal(L);
	int Y = cal(R);
	int ans = max(X,Y);
	return ans;
}
void xuly()
{
	if(m == 1)
	{
		int res = inf;
		mini(res,cal(U));
		cout<<res;
	}
	else
	{
		DFS(1,0);
		FOR(j,1,lg(n)) FOR(i,1,n) p[i][j] = p[p[i][j-1]][j-1];
		FOR(i,1,n) if(dis(L,i) + dis(R,i) == dis(L,R))
		{
			race.pb(i);
		}
		sort(all(race),[](int x,int y){return dis(x,L) < dis(y,L);});
		int res = inf;
		if(race.size() == 2)
		{
			cout<<tinh(0);
			return;
		}
		int d = 0,c = race.size() - 2;	
		while(c - d > 4)
		{
			int ml = d + (c - d)/2;
			int mr = c - (c - d)/2;
			if(tinh(ml) < tinh(mr)) d = ml;
			else if(tinh(ml) > tinh(mr)) c = mr;
			else 
			{
				d = ml;
				c = mr;
			}
		}
		FOR(i,d,c) mini(res,tinh(i));
		cout<<res;
	}
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