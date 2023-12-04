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
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
	
}
struct BIT2D{
	int n, m, b1[1005][1005][2], b2[1005][1005][2];
	
	void init(int _n, int _m){
		n = _n;
		m = _m;
	}
	void add(int b[][1005][2], int x, int y, int val1, int val2){
		while(x <= n){
			int k = y;
			while(k <= m){
				b[x][k][0] += val1;
				b[x][k][1] += val2;
				
				k += k & -k;
			}
			x += x & -x;
		}
	}
	
	void add_sp(int x, int y1, int y2, int val1, int val2){
		add(b1, x, y1, val1, -val1 * (y1 - 1));
		add(b1, x, y2, -val1, val1 * y2);
		add(b2, x, y1, val2, -val2 * (y1 - 1));
		add(b2, x, y2, -val2, val2 * y2);
		
	}
	
	void range_add(int x, int y, int u, int v, int val){
		add_sp(x, y, v, val, - val * (x - 1));
		add_sp(u, y, v, - val, val * u);
	}
	
	int getpoint(int b[][1005][2], int x, int y){
		int val1 = 0, val2 = 0, tmp = y;
		while(y){
			val1 += b[x][y][0];
			val2 += b[x][y][1];
			y -= y & -y;
		}
		
		return val1 * tmp + val2;
	}
	
	int getpoint(int x, int y){
		int val1 = 0, val2 = 0, tmp = x;
		
		while(x){
			val1 += getpoint(b1, x, y);
			val2 += getpoint(b2, x, y);
			x -= x & -x;
		}
		
		return val1 * tmp + val2;
	}
	
	int get(int x, int y, int u, int v){
		if(!(u >= x and v >= y)) return 0;
		if(x == 0 or y == 0) return 0;
		return getpoint(u, v) - getpoint(x - 1, v) - getpoint(u, y - 1) + getpoint(x - 1, y - 1);
	}
}BIT2D;
int n, m, a[1005][1005];

void inp(){
	cin >> n >> m;
	fod(i,1,n) fod(j,1,m) cin >> a[i][j];
}

namespace sub_task1{
	void solve(){
		BIT2D.init(n,m);
		fod(i,1,n) fod(j,1,m) BIT2D.range_add(i,j,i,j, a[i][j]);
		
		BIT2D.range_add(1,1,3,5, 10);
		
		fod(i,1,n){
			fod(j,1,n) cout << BIT2D.get(i,j,i,j) << " ";
			cout << el;
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
		sub_task1 :: solve();
	}
	kill();
}