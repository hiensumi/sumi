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
#define all(v) v.begin(), v.end()
#define odd(i) (i & 1LL)
using namespace std;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { int tmp = x; mul(tmp, Inv(y, mod), mod); return tmp;}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
struct point{int x, y;};
struct edge{int u, v, c;};
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true; }*/ 
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name "V"
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
	
}
int n, t, w[base], b[base], g[base];
vector <int> adj[base];
void inp(){
	cin >> n >> t;
	fod(i,2,n){
		int x; cin >> x;
		adj[x].pb(i);
		adj[i].pb(x);
		// cout << i << " " << x << el;
	}
	fod(i,1,n) cin >> w[i];
	fod(i,1,n) cin >> b[i];
	fod(i,1,n) cin >> g[i];
}

namespace sub_task1{
	int timedfs = 0, tour[base], st[base], en[base];
	void dfs(int u, int p){
		tour[++timedfs] = u;
		st[u] = timedfs;
		for(int v : adj[u]) if(v != p){
			dfs(v,u);
		}
		en[u] = timedfs;
	}
	bool cmp(int a, int b){
		if(w[a] == w[b]) return g[a] < g[b];
		return w[a] < w[b];
	}
	bool cmp2(int a, int b){
		return g[a] < g[b];
	}
	void solve(){
		int res = 0, cnt = 0, root = 0;
		vector <int> ans;
		dfs(1,0);
		fod(i,1,n){
			int k = 0, s = 0;
			vector <int> node;
			fod(j,st[i], en[i]) node.pb(tour[j]);
			sort(all(node), cmp);
			vector <int> tmp;
			for(int j = 0; j < node.size() and s <= t; j++){
				if(s + w[node[j]] <= t){
					s += w[node[j]];
					k++;
					tmp.pb(node[j]);
				}
			}
			sort(all(tmp), cmp2);
			if(res == (b[i] + k * k) and !ans.empty()){
				if(k < cnt){
					cnt = k;
					ans = tmp;
					continue;
				}
				int ch = 0;
				int sz = min(tmp.size(), ans.size());
				fod(i,0,sz-1){
					if(g[tmp[i]] < g[ans[i]]){ch = 1; break;}
					if(g[tmp[i]] > g[ans[i]]){ch = 2; break;} 
				}
				if(ch == 2) continue;
				if(ch == 1) ans = tmp;
				if(ch == 0){
					if(sz == tmp.size()) ans = tmp;
				}
			}
			
			if(maxi(res, b[i] + k * k)){
				root = i;
				cnt = k;
				ans = tmp;	
			}
		}
		sort(all(ans), cmp2);
		//  	cout << root << el;
		cout << res << " " << cnt << el;
		for(int x : ans) cout << g[x] << " ";
		
		cout << el;
		timedfs = 0;
		fod(i,1,n) tour[i] = st[i] = en[i] = w[i] = b[i] = g[i] = 0, adj[i].clear();
	}	
	
}
namespace sub_task3{
	int timedfs = 0, tour[base], st[base], en[base];
	void dfs(int u, int p){
		tour[++timedfs] = u;
		st[u] = timedfs;
		for(int v : adj[u]) if(v != p){
			dfs(v,u);
		}
		en[u] = timedfs;
	}
	bool cmp(int x , int y){
		return b[x] > b[y]; 
	}
	void solve(){
		dfs(1,0);
		int general = w[1];
		int num_node = t / general;
		vector <int> node;
		node.pb(-INF);
		fod(i,1,n) node.pb(i);
		sort(node.begin() + 1, node.begin() + n + 1, cmp);
		int res = 0;
		fod(i,1,n){
			int k = en[node[i]] - st[node[i]] + 1;
			mini(k, num_node);
			res=  max(res, b[node[i]] + k * k);
		}
		
		int aim = INF, cur = INF;
		fod(i,1,n){
			int k = en[node[i]] - st[node[i]] + 1;
			mini(k, num_node);
			if(res == b[node[i]] + k * k){
				// mini(aim, node[i]);
				fod(j,st[node[i]], en[node[i]]){
					if(mini(cur, g[tour[j]])) aim = node[i];
				}
			}
		}
		
		int k = en[aim] - st[aim] + 1;
		mini(k, num_node);
		set <int> hello;
		fod(i,st[aim], en[aim]) hello.insert(g[tour[i]]);
		cout << res << " " << k << el;
		int cnt = 0;
		for(int x : hello){
			cnt++;
			if(cnt > k) break;
			cout << x << " ";
		}
		
		cout << el;
		timedfs = 0;
		fod(i,1,n) tour[i] = st[i] = en[i] = w[i] = b[i] = g[i] = 0, adj[i].clear();
		
	}
}
namespace sub_task4{
	bool cmp(int x ,int y){
		return w[x] < w[y];
	}
	void solve(){
		vector <int> node;
		node.pb(-INF);                                                                   
		fod(i,1,n) node.pb(i);
		sort(node.begin() + 1, node.begin() + n + 1, cmp);
		vector <int> ans;
		int s = 0, pos = 1;
		while(s + w[node[pos]] <= t and pos <= n){
			s += w[node[pos]];
			ans.pb(node[pos]);
		}
		return;
		
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	  freopen(name".inp", "r", stdin);
	  freopen(name".out", "w", stdout);
	}
	init();
	int task, Test;
	cin >> task >> Test;
	while(Test--){
		inp();
		if(task == 1 or task == 2) sub_task1 :: solve();
		else if(task == 3) sub_task3 :: solve();
	}
	kill();
}