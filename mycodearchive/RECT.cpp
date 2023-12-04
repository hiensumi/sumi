// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
// #define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) (a & mask(i))
#define pb push_back
#define el '\n'
#define odd(i) (i & 1LL)
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
const ll INF = 1e18;
const int base = 1e6 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
namespace solution{
	int n, m, lg[505];
	ll a[505][505];
	ll f[505][505], mi[505][505][21];
	void inp(){
		cin >> n >> m;
		fod(i,1,n) fod(j,1,m) cin >> a[i][j], f[i][j] = 1ll * f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
	}
	ll calc(int u, int v, int x, int y){
		return f[x][y] - f[x][v-1] - f[u-1][y] + f[u-1][v-1]; 
	}
	ll getmi(int row, int l, int r){
		int k = lg[r-l+1];
		return min(mi[row][l][k], mi[row][r - mask(k) + 1][k]);
	}
	void init(){
		fod(i,2,m) lg[i] = lg[i/2] + 1;
		fod(row,1,n){
			fod(j,1,m) mi[row][j][0] = a[row][j];
			fod(j,1,lg[m]) fod(i,1,m - mask(j) + 1){
				mi[row][i][j] = min(mi[row][i][j-1], mi[row][i + mask(j-1)][j-1]);
			}
		}
	}
	int getmin(int u, int v, int x, int y){
		ll res = 1e18;
		fod(i,u,x) fod(j,v,y){
			res = min(res, a[i][j]);
		}
		return res;
	}
	void brute(){
		ll res = -1e18;
		fod(u,1,n) fod(v,1,m){
			fod(x,u,n) fod(y,v,m){
				res = max(res, getmin(u,v,x,y) * calc(u,v,x,y));
			}
		}
		fod(u,1,n) fod(v,1,m){
			fod(x,u,n) fod(y,v,m){
				// res = max(res, getmin(u,v,x,y) * calc(u,v,x,y));
				if(getmin(u,v,x,y) * calc(u,v,x,y) == res){
					cout << u << " " << v << " " << x << " " << y << el;
				}
			}
		}
		cout << res << el;
	}
	void sub1(){
		init();
		// cout << getmi(2,2,4);
		ll res = -1e18;
		fod(i,1,m) fod(j,i,m){
			fod(k,1,n){
				int l = k, r = k, minrow = getmi(k,i,j);
				while(minrow <= getmi(l-1,i,j) and l > 1) l--;
				while(minrow <= getmi(r+1,i,j) and r < n) r++;
				res = max(res, 1ll * minrow * calc(l,i,r,j));
			}	
		}
		cout << res;
	}
	void init2(){
		fod(i,2,n) lg[i] = lg[i/2] + 1;
		fod(col,1,m){
			fod(j,1,n) mi[col][j][0] = a[j][col];
			fod(j,1,lg[n]) fod(i,1,n - mask(j) + 1){
				mi[col][i][j] = min(mi[col][i][j-1], mi[col][i + mask(j-1)][j-1]);
			}
		}	
	}
	void sub2(){
		init2();
		ll res = -INF;
		fod(i,1,n) fod(j,i,n){
			fod(k,1,m){
				int l = k, r = k, mincol = getmi(k,i,j);
				while(mincol <= getmi(l-1,i,j) and l > 1) l--;
				while(mincol <= getmi(r+1,i,j) and r < m) r++;
				res = max(res, 1ll * mincol * calc(i,l,j,r));
			}
		}
		cout << res;
	}
	void solve(){
		inp();
		// brute();
		if(n > m) sub2();
		else sub1();
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
	int Test = 1; if(multitest) cin >> Test;
	while(Test--) solution :: solve();
	kill();
}