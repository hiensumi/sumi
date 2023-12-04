// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include "bits/stdc++.h"
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) ((a >> i) & 1LL)
#define pb push_back
#define el '\n'
#define odd(i) (i & 1LL)
#define all(v) v.begin(), v.end()
using namespace std;
typedef pair<int, int> ii;
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
struct point{int x, y;};
struct edge{ int u, v, c;};
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true;
}*/ 
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
int n, m, a[base], b[base], c[base];
vector <int> adj[base];
void init(){
	
}
void inp(){
	cin >> n >> m;
	fod(i,1,n) cin >> a[i];	
	fod(i,1,m) cin >> b[i];
	fod(i,1,m) cin >> c[i];
}


namespace sub_task1{
	int rc[3001][3001], f[3001][3001], par[base], addflow = INF;
	void add(int u, int v, int w){
		rc[u][v] += w;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	void dfs(int u){
 		queue <int> q;
 		q.push(u);
 		while(q.size()){
 			int x = q.front();
 			q.pop();
 			for(int v : adj[x]){
 				if(par[v] == -1 and rc[x][v] - f[x][v] > 0){
 					par[v] = x;
 					q.push(v);
 				}
 			}
 		}
 	}
 	void maxflow(int s, int t){
 		int flow = 0;
 		while(1){
 			memset( par, -1, sizeof par);
 			par[s] = 0;
 			addflow = 1e18;
 			dfs(s);
 			if(par[t] == -1) break;
 			for(int u = t; u != s; u = par[u]){
 				addflow = min(addflow, rc[par[u]][u] - f[par[u]][u]);
 			}
 			for(int u = t; u != s; u = par[u]){
 				f[u][par[u]] -= addflow;
 				f[par[u]][u] += addflow;
 			}
 		}
 	}
	void solve(){
		int s = n + m + 11, t = s + 1;
		fod(i,1,n) add(s,i,a[i]);
		fod(i,n+1,n+m) add(i,t,c[i-n]);
		fod(i,1,n) fod(j,n+1,n+m) add(i,j,b[j-n]);
		maxflow(s,t);
		int res = 0;
		fod(i,1,n+m) res += f[i][t];
		cout << res; 
	}	
}
namespace sub_task2{
	// we need to find the minimum cut ?
	bool cmp(int x, int y){
		return c[x] * b[y] < c[y] * b[x];
		// 2 edges that are required in the max flow
	}
	void solve(){
		int suma = 0, sumb = 0, sumc = 0;
		fod(i,1,n) suma += a[i];
		
		vector <int> p(m + 1);
		
		fod(i,1,m) p[i] = i;
		
		sort(p.begin() + 1, p.begin() + m + 1, cmp);
		
		fod(i,1,m) sumb += b[p[i]];
		
		sort(a+1,a+n+1,greater<int>());
		
		int y = 1, res = INF;
		
		fod(x,0,n){
			suma -= a[x];
			while(y <= m and c[p[y]] <= x * b[p[y]]){
				sumc += c[p[y]];
				sumb -= b[p[y]];
				y++;
			}
			res = min(res, suma + sumc + x * sumb);
		}
		cout << res << el;
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	  freopen(name".inp", "r", stdin);
	  freopen(name".out", "w", stdout);
	}
	int Test = 1; if(multitest) cin >> Test;
	init();
	while(Test--){
		inp();
		sub_task2 :: solve();
	}
	kill();
}