// hiensumi is on the sky
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
#include<time.h>
#include<utility>
#include<vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define name ""
#define non 5000+1
#define db double
#define mask(i) (1LL<<(i))
#define pb push_back
#define el '\n'
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
const int base = 1e6 + 5;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
int di1[] = {0,-1,1,0};
int di2[] = {-1,0,0,1};
int n, a[1005][1005], f[1005][1005][3], g[1005][1005][3];
ii st, ed;
bool nt(int x, int y){
	return 1 <= x and x <= n and 1 <= y and y <= n;
}
struct bg{
	int u, v, dir;
};
void bfs1(ii pog){
	deque <bg> q;
	fod(i,1,n) fod(j,1,n) fod(k,0,3) f[i][j][k] = 1e18;
	fod(i,1,4) q.pb({pog.fi, pog.se,i-1});
	fod(i,0,3) f[pog.fi][pog.se][i] = 0;
	while(q.size()){
		bg x = q.front();
		q.pop_front();
		int u = x.u, v = x.v, dir = x.dir;
		cout << u << " " << v << " " << dir << " " << f[u][v][dir] << el;
		if(a[u][v]) continue;
		fod(i,0,3){
			int x = u + di1[i], y = v + di2[i], w = (i != dir);
			if(!nt(x,y)) continue;
			if(f[x][y][i] > f[u][v][dir] + w){
				f[x][y][i] = f[u][v][dir] + w;
				if(w) q.pb({x,y,i});
				else q.push_front({x,y,i});
			}
		}
	}
}
void bfs2(ii pog){
	deque <bg> q;
	memset(g, 0x3f, sizeof g);
	fod(i,1,4) q.pb({pog.fi, pog.se, 1});
	fod(i,0,3) g[pog.fi][pog.se][i] = 0;
	while(q.size()){
		bg x = q.front();
		q.pop_front();
		int u = x.u, v = x.v, dir = x.dir;
		if(a[u][v]) continue;
		fod(i,0,3){
			int x = u + di1[i], y = v + di2[i], w = 0;
			if(!nt(x,y)) continue;
			if(i == dir) w = 0;
			else w = 1;
			if(u == pog.fi and v == pog.se) w = 0;
			if(g[x][y][i] > g[u][v][dir] + w){
				g[x][y][i] = g[u][v][dir] + w;
				if(w) q.pb({x,y,i});
				else q.push_front({x,y,i});
			}
		}
	}
}
int conv(int v){
	int dir1 = di1[v], dir2 = di2[v];
	if(dir1 == 0 and dir2 == -1) return 3;
	if(dir1 == -1 and dir2 == 0) return 2;
	if(dir1 == 1 and dir2 == 0) return 1;
	return 0;
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
	cin >> n;
	fod(i,1,n) fod(j,1,n) cin >> a[i][j];
	cin >> st.fi >> st.se >> ed.fi >> ed.se;
	bfs1(st);
	bfs2(ed);
	int res1, res2, res3 = 0;
	res1 = res2 = 1e18;
	fod(i,0,3) res1 = min(res1, f[ed.fi][ed.se][i]);
	fod(i,0,3) cout << f[1][2][i] << " ";
	// fod(i,1,n) fod(j,1,n){
	// 	if(a[i][j] == 0) continue;
	// 	fod(u,0,3) fod(v,0,3){
	// 		int t = conv(v);
	// 		int w = (u == t);
	// 		if(f[i][j][u] + g[i][j][t] + w == 0){
	// 			cout << i << " " << j << " " << u << " " << t << el;
	// 		}
	// 		res2 = min(res2, f[i][j][u] + g[i][j][v] + w);
	// 	}
	// }
	// cout << res1 << " " << res2;
 	kill();
}
