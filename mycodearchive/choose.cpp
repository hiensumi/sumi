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
	// remember to reset value for multitestcase
	int n, a[505][505], m, lg[505], ma[505][505][11];	
	void inp(){
		cin >> n >> m;
		fod(i,1,n) fod(j,1,m) cin >> a[i][j];
	}
	int getma(int col, int l, int r){
		int k = lg[r-l+1];
		return max(ma[col][l][k], ma[col][r - mask(k) + 1][k]);
	}
	void init(){
		fod(i,2,n) lg[i] = lg[i/2] + 1;
		fod(col,1,m){
			fod(j,1,n) ma[col][j][0] = a[j][col];
			fod(j,1,lg[n]) fod(i,1,n - mask(j) + 1){
				ma[col][i][j] = max(ma[col][i][j-1], ma[col][i + mask(j-1)][j-1]);
			}
		}	
	}
	void sub1(){
		int res = -INF;
		fod(i,0,n) a[0][i] = -INF, a[i][0] = -INF;
		fod(i,1,m-1) fod(j,i+1,m){
			int pos1 = 0, pos2 = 0;
			fod(k,1,n){
				if(a[pos1][i] + a[pos1][j] < a[k][i] + a[k][j]){
					pos2 = pos1;
					pos1 = k;
					continue;
				}
				if(a[pos2][i] + a[pos2][j] < a[k][i] + a[k][j]){
					pos2 = k;
				}
			}
			res = max(res, a[pos1][i] + a[pos1][j] + a[pos2][i] + a[pos2][j]);
		}
		cout << max(res,0ll);
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
	int Test = 1; if(multitest) cin >> Test;
	while(Test--) solution :: solve();
	kill();
}