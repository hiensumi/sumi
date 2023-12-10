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
const ll INF = 1e18, base = 1e5 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name "costquery"
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n, q;
vector <ii> adj[base];
vector <edge> e;
void inp(){
	cin >> n >> q;
	fod(i,1,n-1){
		int u, v, c;
		cin >> u >> v >> c;
		// adj[u].pb(ii(v,c));
		// adj[v].pb(ii(u,c));
		e.pb({u,v,c});
	}
}
namespace sub_task1{ 
	int h[base], lg[base], ma[base][21], par[base][21];
	void dfs(int u, int p){
		for(ii x : adj[u]){
			int v = x.fi , w = x.se;
			if(v == p) continue;
			h[v] = h[u] + 1;
			par[v][0] = u;
			ma[v][0] = u;
			fod(j,1,lg[n]){
				par[v][j] = par[par[v][j-1]][j-1];
				maxi(ma[v][j], ma[ma[v][j-1]][j-1]);
			}
			dfs(v,u);
			
		}
	}
	int lca(int u, int v){
	    if (h[u] < h[v]) swap(u,v);
	    int k = h[u] - h[v];
	    for(int j = 0; (1 << j) <= k; j++) if(k & (1 << j)) u = par[u][j];
	    if (u == v) return u;
	    int d = log2(h[u]);
	    fok(j,d,0) if (par[u][j] != par[v][j]){
	        u = par[u][j]; v = par[v][j];
	    }
	    return par[u][0];
	}
	int query(int u, int v){
		int cha = lca(u,v);
		int res = -1e18;
	    int k = h[u] - h[cha];
	    for(int j = 0; (1 << j) <= k; j++) if(k & (1 << j)){
	        res = max(res, ma[u][j]);
	        u = par[u][j];
	    }
	    k = h[v] - h[cha];
	    for(int j = 0; (1 << j) <= k; j++) if(k & (1 << j)){
	    	maxi(res, ma[v][j]);
	    	v = par[v][j];
	    }
	    return res;
	}
	int ddc[base], cnt1 = 0, cnt2 = 0;
	vector <ii> weight;
	void dfsout(int u, int cur){
		 if(ddc[u]) return; 
		 ddc[u] = 1;
		 for(ii x : adj[u]){
		 	int v = x.fi, c = x.se;
		 	if(ddc[v] == 0 and c <= cur){
		 		cnt1++;
		 		dfsout(v,cur);
		 	}
		 }
	}
	void dfsin(int u, int p, int cur){
		for(ii x : adj[u]){
			int v = x.fi, c = x.se;
			if(v == p or c > cur) continue;
			cnt2++;
			dfsin(v,u,cur);
		}
	}
	int we[base];
	bool cmp(edge u, edge v){
		return u.c < v.c;
	}
    void solve(){
    	dfs(1,0);
		weight.pb(ii(-INF,0));
		int sz = 0;
		sort(all(e), cmp);
		for(edge x : e){
			int u = x.u, v = x.v, c = x.c;
			if(h[u] > h[v]) swap(u,v);
			fod(i,1,n) ddc[i] = 0;
			for(ii x : adj[v]) if(int k = x.fi; h[k] > h[u]) ddc[k] = 1;
			cnt1 = cnt2 = 0;
			dfsout(v,c);
			dfsin(v,u,c);
			cnt2++;
			int res = (cnt1 + cnt2) * (cnt1 + cnt2 - 1) / 2;
			// cout << u << " " << v << " " << c << " " << cnt1 << " " << cnt2 << el;
			if(weight[sz].fi == c) weight[sz].se += res;
			else weight.pb(ii(c,res)), sz++;
		}	
		// fod(i,1,sz){
			// cout << weight[i].fi << " " << weight[i].se << el;
		// }
		fod(i,1,sz) we[i] = weight[i].fi;
		
		while(q--){
			int l, r; cin >> l >> r;
			int u = lower_bound(we + 1, we + sz + 1, l) - we - 1;
			int v = upper_bound(we + 1, we + sz + 1, r) - we - 1;
			// cout << u << " " << v << el;
			cout << max(0ll, weight[v].se - weight[u].se) << " ";
		}
		
    }	
}
namespace sub_task2{
	int lab[base];
	int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u; return 1;}
	int weight[base], wei[base];
	void solve(){
		sort(all(e), [&](edge a, edge b){
			return a.c < b.c;
		});
		memset(lab, -1, sizeof lab);
		int id = 0;
		for(auto [u,v,c] : e){
			id++;
			wei[id] = c;
			u = find(u);
			v = find(v);
			weight[id] = weight[id-1] + lab[u] * lab[v];
			join(u,v);
		}
		
		while(q--){
			int l, r; cin >> l >> r;
			int u = lower_bound(wei + 1, wei + id + 1, l) - wei - 1;
			int v = upper_bound(wei + 1, wei + id + 1, r) - wei - 1;
			cout << max(0ll, weight[v] - weight[u]) << " ";
		}
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
/*
										Trú mưa nơi gốc cây ngày xưa
										Để nhìn em lần cuối trong mưa
										Để nắm tay đưa em đi về
										Chốn mộng mơ...
										
										Có hôm mây gió chợt ca vang
										Nụ cười em như nắng mùa thu sang
										Làm lòng tôi xao xuyến mà lang thang
										Nghĩ về em...
										
										Mình tôi thao thức
										mình tôi day dứt
										Cớ sao em không về với tôi 
										Mình tôi thao thức
										mình tôi day dứt
										Cớ sao em không cười với tôi
										Gió mang câu ca về nơi đây
										gió mang câu ca về với đời em
										Nắng mang câu thơ về nơi đây
										chính em mang thơ về với tình ta ...
										
										Chiếc radio của em
										Và từng ly trà đá ly kem
										Cùng hát lên câu ca êm đềm
										giữa mùa yêu
										
										Những bông hoa xanh ngoài hiên
										Vào buổi chiều tràn nắng an nhiên
										Ta ngồi bên cạnh nhau 
										ngắm mùa thu sang...
#listening to her music while coding is great
*/
