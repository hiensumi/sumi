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
// #define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define name "superm"
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
const int oo = 1e18 + 1 + 2 + 3 + 4 + 5 + 12345678910;
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
	int u, v, c;
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
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1048576 + 5;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
namespace superm{
	int n, m, h[base], mark[base], f[base], cnt = 0;
	int fin[base], fout[base], mustgo[base];
	vector <int> adj[base];
	vector <int> g[base];
	void dfs(int u, int cha){
		if(mark[u]) mustgo[u] = 1;
		for(int v : adj[u]){
			if(v == cha) continue;
			// h[v] = h[u] +  1;
			dfs(v,u);
			mustgo[u] |= mustgo[v];
			if(mustgo[u] and mustgo[v]){
				g[u].pb(v);
				g[v].pb(u);
			}
		}
	}
	void dfsin(int u, int cha){ // khoảng cách max u tới đỉnh nằm trong cây con gốc u = fin[u]
		for(int v : g[u]){
			if(v == cha) continue;
			dfsin(v,u);
			fin[u] = max(fin[u], fin[v] + 1);
		
		}
	}
	void update(int &a, int &b, int c) {
		if (c > a) b = a, a = c;
		else b = max(b, c);
	}
	void dfsout(int u, int par) {
		int first = -1, second = -1;
		for(int v: g[u]) if (v != par) {
			update(first, second, fin[v]);		
		}
		for (int v: g[u]) if (v != par) {
			fout[v] = max(1, fout[u] + 1);
			fout[v] = max(fout[v], (first == fin[v] ? second : first) + 2);
			dfsout(v, u);
		}
	}
	void solve(){
		// int task; cin >> task;
		cin >> n >> m;
		fod(i,1,n-1){
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		fod(i,1,m){
			int x; cin >> x;
			mark[x] = 1;
		}
		int root = 1;
		while(mark[root] == 0) root++;
		dfs(root,0);
		dfsin(root,0);
		dfsout(root,0);
		int res = -2e9;
		vector <int> v;
		fod(i,1,n) if(mustgo[i]) v.pb(i);
		for(int x : v){
			res = max(res, max(fin[x], fout[x]));
		}
		vector <int> ans;
		for(int x : v){
			if(max(fin[x], fout[x]) == res){
				ans.pb(x);
			}
		}
		sort(ans.begin(), ans.end());
		cout << 2 * (v.size() - 1) - res << el;
		for(int x : ans) cout << x << " ";
		// fod(i,1,n) if(mustgo[i]) cout << i << " ";	
		kill();
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
	superm::solve();
	kill();
}
