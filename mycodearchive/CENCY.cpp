// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
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
//int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
//bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u; return 1;}
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n, m ,k, dd[base],root[base], low[base], num[base], stt = 0, nscc = 0, citi[base];
vector <int> adj[base];
stack <int> st;
int tplt[base];
void dfs(int u){
	low[u] = num[u] = ++stt;
	st.push(u);
	for(int v : adj[u]){
		if(dd[v]) continue;
		if(num[v]) low[u] = min(low[u], num[v]);
		else{
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
	}
	if(low[u] == num[u]){
		int x = 0;
		nscc++;
		do{
			x = st.top();
			st.pop();
			dd[x] = 1;
			tplt[nscc]++;
		}while(x != u);
	}
}
void inp(){
	cin >> n >> m >> k;
	fod(i,1,n) cin >> citi[i];
	fod(i,1,m){
		int u, v; cin >> u >> v; adj[u].pb(v);
	}
}

namespace sub_task1{
	bool check(int mid){
		memset(dd ,0 ,sizeof dd);
		memset(low, 0, sizeof low);
		memset(num, 0, sizeof num);
		memset(tplt, 0, sizeof tplt);
		nscc = 0;
		fod(i,1,n) if(citi[i] < mid) dd[i] = 1;
		fod(i,1,n) if(dd[i] == 0) dfs(i);
		fod(i,1,nscc) if(tplt[i] >= k) return 1;
		return 0; 
	}
    void solve(){
    	int l = 0, r = INF, ans = -1;
    	while(l <= r){
    		int mid = l + r >> 1;
    		if(check(mid)) l = mid + 1, ans = mid;
    		else r = mid - 1;
    	}
    	
    	cout << ans << el;
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
        sub_task1 :: solve();
    }
    kill();
}