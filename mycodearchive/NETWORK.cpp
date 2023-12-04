// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define non 5000+1
#define pog 1000000000+7
#define db double
#define mask(i) (1LL<<(i))
#define BITpos(a,i) (a & mask(i))
#define pb push_back
#define el '\n'
#define odd(i) (i & 1LL)
using namespace std;
void read(){}
void read(long long& a){scanf("%lld",&a);}
void read(long& a){scanf("%ld",&a);}
void read(double& a){scanf("%lf",&a);}
void read(float& a){scanf("%f",&a);}
void read(string& a){cin>>a;}
template<typename x,typename y>void read(pair<x,y>& a){ read(a.first),read(a.second);}
template<typename x>void read(x& a){for(auto  &i : a) read(i);}
template<typename x,typename... y>void read(x& a,y&... b){read(a);read(b...);}
const long long INF = 1e18 + 22022007;
typedef pair<int, int> ii;
struct point{
	int x, y;
	point operator- (const point& a)const{
		return {(x - a.x), (y - a.y)};
	}
	int operator* (const point& a)const{
		return x * a.y - y * a.x;
	}
};
struct edge{
	int u, v, c, id;
};
/*int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}
bool join(int u, int v) {
    int paru = find(u), parv = find(v);
    if (paru == parv) return false;
    par[parv] = paru;
    return true;
}*/	
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 2e5 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
namespace solution{
	int ans[base];
	map <ii, int> mp;
 	edge new_e[base];
	struct Query{
		char type;
		int u, v, c, id;
	};
	bool cmp(Query a, Query b){
		return a.c < b.c;
	}
	int n, m, h[base], lca[base][21], new_tour[base];
	vector <ii> adj[base];
	edge e[base];
	bool cmpw(edge a, edge b){
		return a.c < b.c;
	}
	void dfs(int u, int p){
		for(ii x : adj[u]){
			if(x.fi == p) continue;
			int v = x.fi, w = x.se;
			h[v] = h[u] + 1;
			lca[v][0] = u;
			fod(j,1,__lg(n)){
				lca[v][j] = lca[lca[v][j-1]][j-1];
			}
			dfs(v,u);
		}
	}
	struct FenwickTree {
	    int b1[base], b2[base];
	    int n;
	    void init(int n){
	    	this-> n = n;
	    }
	    void add(int b[], int idx, int x){
		    while(idx <= n){
		        b[idx] += x;
		        idx += idx & -idx;
			}
		}
		void range_add(int l, int r, int x){
		    add(b1,l,x);
		    add(b1,r+1,-x);
		    add(b2,l,x*(l-1));
		    add(b2,r+1,-x*r);
		}
		int sum(int b[], int idx){
		    int res = 0;
		    while(idx){
		        res += b[idx];
		        idx -= idx & -idx;
		    }
		    return res;
		}
		int getall(int idx){
		    return sum(b1, idx) * idx - sum(b2, idx);
		}
		int get(int l, int r){
			if(l > r) return 0;
			if(l == 0 or r == 0) return 0;
			return getall(r) - getall(l-1);
		}
	}BIT,BITT;
	int old_tour[base];
	int timeDFS = 0, tour[base], In[base], Out[base];
	void DFS(int u, int p){
		timeDFS++;
		old_tour[timeDFS] = u;
		In[u] = timeDFS;
		for(ii x : adj[u]){
			if(x.fi == p) continue;
			DFS(x.fi,u);
		}
		timeDFS++;
		old_tour[timeDFS] = u;
		Out[u] = timeDFS;
	}
	int st[base], en[base], DFStime = 0;
	void DFST(int u, int p){
		tour[++DFStime] = u;
		st[u] = DFStime;
		for(ii x : adj[u]){
			if(x.fi == p) continue;
			DFST(x.fi,u);
		}
		tour[++DFStime] = u;
		en[u] = DFStime;
	}
	int LCA(int u, int v){
		if(h[u] < h[v]) swap(u,v);
		int k = h[u] - h[v];
		fod(i,0,__lg(k)){
			if(k & mask(i)){
				u = lca[u][i];
			}	
		}
		if(u == v) return u;
		int d = __lg(h[u]);
		fok(i,d,0){
			if(lca[u][i] != lca[v][i]){
				u = lca[u][i];
				v = lca[v][i];
			}
		}
		return lca[u][0];
	}
	void inp(){
		cin >> n >> m;
		fod(i,1,n-1){
			int u, v, c; 
			cin >> u >> v >> c;
			e[i] = {u,v,c,i};
			adj[u].pb({v,c});
			adj[v].pb({u,c});
			mp[{u,v}] = c;
			mp[{v,u}] = c;
		}
	}
	vector <int> it[4*base];
	Query Q[base];
	void merge(vector <int> &a, vector <int> b, vector <int> c){
		int n = b.size(), m = c.size(), i = 0, j = 0;
		while(i < n and j < m){
			if(b[i] < c[j]){
				a.pb(b[i]);
				i++;
			}
			else{
				a.pb(c[j]);
				j++;
			}
		}
		for(; i < n; i++) a.pb(b[i]);
		for(; j < m; j++) a.pb(c[j]);
	}
	void build(int i, int l, int r){
		if(l == r){
			it[i].pb(new_tour[l]);
			return;
		}
		int mid = l + r >> 1;
		build(2*i,l,mid); build(2*i+1,mid+1,r);
		merge(it[i], it[2*i], it[2*i+1]);
	}
	int get(int i, int l, int r ,int u, int v, int x){
		if(r < u or v < l) return 0;
		if(u <= l and r <= v) return (upper_bound(it[i].begin(), it[i].end(), x) - it[i].begin());
		int mid = l + r >> 1;
		return get(2*i,l,mid,u,v,x) + get(2*i+1,mid+1,r,u,v,x);
	}
	int get(int l, int r, int x){
		return get(1,1,DFStime,l,r,x);
	}
	void sub1(){
		fod(i,1,m){
			cin >> Q[i].type;
			if(Q[i].type == 'P') cin >> Q[i].u >> Q[i].v >> Q[i].c;
			else cin >> Q[i].u >> Q[i].c;
			Q[i].id = i;
		}
		sort(e + 1, e + n, cmpw);
		sort(Q+1,Q+m+1,cmp);
		fod(i,1,n-1){
			new_e[e[i].id] = e[i];
		}
		dfs(1,0);
		DFS(1,0);
		DFST(1,0);
		BIT.init(2 * n);
		BITT.init(2*n);
		int add = 1;
		fod(i,1,m){
			int u = Q[i].u, v = Q[i].v, c = Q[i].c;
			while(add <= n - 1 and e[add].c <= c){
				int a = e[add].u, b = e[add].v;
				if(h[a] > h[b]) swap(a,b);
				BIT.range_add(In[b], In[b], 1);
				BITT.range_add(In[b], In[b], 1);
				BIT.range_add(Out[b], Out[b], -1);
				add++;
			}
			if(Q[i].type == 'P'){
				int p = LCA(u,v);
				// cout << p << el;
				ans[Q[i].id] = BIT.get(1, In[u]) + BIT.get(1, In[v]) - 2 *  BIT.get(1, In[p]);
				// cout << Q[i].id << el;
			}
			else{
				// cout << "L" << el;
				int id = Q[i].u, c = Q[i].c;
				int u = new_e[id].u, v = new_e[id].v;
				if(h[u] < h[v]){
					ans[Q[i].id] = BITT.get(st[v]+1, en[v]-1);
				}
				else{
					ans[Q[i].id] = BITT.get(1, 2 * n) - BITT.get(st[u] + 1, en[u]-1); 
				}
			}
		}
		fod(i,1,m){
			cout << ans[i] << el;
		}
	}
	void solve(){
		inp();
		sub1();
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	else if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	int Test = 1; if(multitest)cin >> Test; 
	while(Test--)solution :: solve();
	kill();
}