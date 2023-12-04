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
//const int oo = 1e18 + 1 + 2 + 3 + 4 + 5 + 12345678910;
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
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e6 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
namespace solution{
 	int n, m = 0, water[base], tour[base], st[base], en[base], par[base];
 	struct SegmentTree{
	int n, st[2*base], lz1[2*base];
	// lz1: assign
	// lz2: add
	void init(int n){
		this -> n = n;
		memset(lz1, -1, sizeof lz1);
		// fod(i,1,n) this -> a[i] = a[i];
	}
	void reset(){
		memset(st, 0, sizeof st);
		memset(lz1, -1, sizeof lz1);
		//memset(lz2, 0, sizeof lz2);
	}
	void pull(int i, int l, int r){
		int mid = l + r >> 1;
		if(lz1[i] != -1){
			st[2*i] =  (mid - l + 1) * lz1[i];
			st[2*i+1] = (r - mid) * lz1[i];
			lz1[2*i] = lz1[2*i+1] = lz1[i];
			lz1[i] = -1;
			//lz2[2*i] = lz2[2 * i + 1] = lz2[i] = 0;
		}
		//if(lz2[i]){
			//st[2*i] += (mid - l + 1) * lz2[i];
			//st[2*i+1] += (r - mid) * lz2[i];
		//	lz2[2*i] += lz2[i];
		//	lz2[2*i+1] += lz2[i];
		//	lz2[i] = 0;
		//}
	}
	void upd1(int i, int l, int r, int u, int v, int val){
		if(r < u or v < l) return;
		if(u <= l and r <= v){
			st[i] = (r - l + 1) * val;
			lz1[i] = val;
			//lz2[i] = 0;
			return;
		}
		pull(i,l,r);
		int mid = l + r >> 1;
		upd1(2 * i, l ,mid, u, v, val);
		upd1(2 * i + 1, mid + 1, r, u, v, val);
		st[i] = st[2*i] + st[2*i+1];
	}
	void assign(int l, int r, int x){
		upd1(1,1,n,l,r,x);
	}
	
	int get(int i, int l, int r, int u, int v){
		if(r < u or v < l) return 0;
		if(u <= l and r <= v) return st[i];
		pull(i,l,r);
		int mid = l + r >> 1;
		return get(2*i,l,mid,u,v) + get(2*i+1,mid+1,r,u,v);
	}
	int get(int l, int r){
		return get(1,1,this -> n,l,r);
	}
}ST;
 	vector <int> adj[base];
 	void dfs(int u,int p){
 		tour[++m] = u;
 		st[u] = m;
 		for(int v : adj[u]){
 			if(v == p) continue;
 			par[v] = u;
 			dfs(v,u);
 		}
 		en[u] = m;
 	}
	void inp(){
		cin >> n;
		fod(i,1,n - 1){
			int u, v; cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
	}
	void sub1(){
		dfs(1,0);
		ST.init(n);
		int q; cin >> q;
		while(q--){
			int type, u;
			cin >> type >> u;
			if(type == 1 or type == 3){
				bool ch = 1;
				// fod(v, st[u], en[u]) if(water[tour[v]] == 0){
					// ch = 0;
					// break;
				// }
				int sum = ST.get(st[u], en[u]);
				if(sum != en[u] - st[u] + 1) ch = 0;
				// if(ch == 0) water[tour[st[par[u]]]] = 0;
				if(type == 1){
					if(ch == 0) ST.assign(st[par[u]],st[par[u]], 0);
					// fod(v, st[u], en[u]) water[tour[v]] = 1;
					ST.assign(st[u], en[u], 1);
				}
				else{
					cout << ch << el;
				}
			}
			if(type == 2){
				// water[tour[st[u]]] = 0;
				ST.assign(st[u], st[u], 0);
			}
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