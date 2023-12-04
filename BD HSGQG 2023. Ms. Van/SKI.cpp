
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
 	int n, T, h[505][505], f[base], sz[base], par[base], m, res = 0;
 	vector <ii> v;
 	vector <ii> adj[base];
 	vector <edge> e;
	int d1[] = {-1,0,0,1};
	int d2[] = {0,-1,1,0};
	bool nt(int x, int y){
		return 1 <= x and x <= n and 1 <= y and y <= m;
	}
	int find(int u) {
		if (par[u] == u) return u;
		return par[u] = find(par[u]);
	}
	bool join(int u, int v, int w) {
		int paru = find(u), parv = find(v);
		if (paru == parv) return false;
		sz[paru] += sz[parv];
		f[paru] += f[parv];
		par[parv] = paru;
		if(sz[paru] >= T){
			res += w * f[paru];
			f[paru] = 0;
 		}
		return true;
	}
	bool cmp(edge a, edge b){
		return a.c < b.c;
	}
	void inp(){
		cin >> n >> m >> T;
		fod(i,1,n) fod(j,1,m) cin >> h[i][j];
		fod(i,1,n) fod(j,1,m){
			int x; cin >> x;
			if(x){
				f[(i-1) * m + j] = 1;
				// v.pb({i,j});
			}
		}
		fod(i,1,n) fod(j,1,m){
			int id = (i - 1) * m + j;
			fod(k,0,3){
				int x = i + d1[k], y = j + d2[k];
				int id2 = (x - 1) * m + y;
				int w = abs(h[i][j] - h[x][y]);
				if(nt(x,y)){
					adj[id].pb({id2, w});
					adj[id2].pb({id,w});
					e.pb({id,id2,w});
				}
			} 
		}
		fod(i,1,n * m) par[i] = i, sz[i] = 1;
		sort(e.begin(), e.end(), cmp);
		for(edge a : e){
			if(join(a.u, a.v, a.c)){
				// int ma = x;
			}
		}	
		cout << res;		
	}
	void sub1(){
		
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