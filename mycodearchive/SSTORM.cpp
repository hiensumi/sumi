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
template<class T> bool maxi(T& a, T& b){return (a>=b) ? a = b, 1 :  0;}
template<class T> bool mini(T& a, T& b){return (a<=b ? a = b, 1 : 0);}
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
int n, m , q, k, a[505][505];
void init(){
	
}

void inp(){
	cin >> n >> m >> q >> k;
	fod(i,1,n) fod(j,1,m) cin >> a[i][j];
}
vector <ii> dir = {
	{-1,0}, {1,0}, {0,-1}, {0,1}
};

namespace sub_task1{
	struct bg{
		int w, r1, r2, x, y;
	}storm[base];
	point forecast[base];
	void solve(){
		fod(i,1,q) cin >> forecast[i].x >> forecast[i].y;
		int res = 0;
		fod(i,1,k){
			cin >> storm[i].w >> storm[i].r1 >> storm[i].r2 >> storm[i].x >> storm[i].y;
			int x = storm[i].x, y = storm[i].y;
			fod(u,1,n) fod(v,1,m){
				int dist = abs(x - u) + abs(y - v);
				if(storm[i].r2 <= dist and dist <= storm[i].r1){
					int down = min(storm[i].w, a[u][v]);
					a[u][v] -= down;
					res += down;
				}
			}
		}
		cout << res << el;
	}	
	
}
namespace sub_task2{
	map <ii,int> mp;
	ii v[base];
	int b[9][2005];
	void solve(){
		fod(i,1,q){
			int x, y; cin >> x >> y;
			mp[ii(x,y)] = i;
			v[i] = ii(x,y);
		}
		fod(i,1,k){
			int w, r1 , r2 , x, y;
			cin >> w >> r1 >> r2 >> x >> y;
			int id = mp[ii(x,y)];
			b[id][r2] += w;
			b[id][r1 + 1] -= w;
		}
		fod(i,1,q) fod(j,1,1001){
			b[i][j] += b[i][j-1]; 
		}
		int res = 0;
		fod(i,1,n) fod(j,1,m) fod(id,1,q){
			int dist = abs(v[id].fi - i) + abs(v[id].se - j);
			// cout << dist << " ";
			int down = min(a[i][j], b[id][dist]);
			// cout << down << el;
			a[i][j] -= down;
			res += down;
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
		// sub_task1 :: solve();
		sub_task2 :: solve();
	}
}