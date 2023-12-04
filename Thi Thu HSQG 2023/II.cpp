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
#define name "II"
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
	
}
int n, k, s, a[base];
void inp(){
	cin >> n >> k >> s;
	fod(i,1,n) cin >> a[i];
}

namespace sub_task1{
	void solve(){
		if(n == 1){
			int res = 0;
			fod(x,1,s){
				if(x < a[1]) res++;
			}
			cout << res << el;
		}
		if(n == 2){
			int res = 0;
			fod(x1, 1, s) fod(x2, 1, s){
				vector <int> b;
				b.pb(-INF); b.pb(x1); b.pb(x2);
				int cnt = 0;
				fod(l,1,2) fod(r,l,2){
					int ch = 0;
					fod(i,l,r){
						if(a[i] > b[i]){
							ch = 1; break;
						}
						if(a[i] < b[i]){
							ch = 2; break;
						}
					}
					if(ch == 2) cnt++;
				}
				if(cnt == k) res++;
			}
			
			cout << res << el;
		}
		if(n == 3){
			int res = 0;
			fod(x1, 1, s) fod(x2, 1, s) fod(x3, 1, s){
				vector <int> b;
				b.pb(-INF); b.pb(x1); b.pb(x2); b.pb(x3);
				int cnt = 0;
				fod(l,1,3) fod(r,l,3){
					int ch = 0;
					fod(i,l,r){
						if(a[i] > b[i]){
							ch = 1; break;
						}
						if(a[i] < b[i]){
							ch = 2; break;
						}
					}
					if(ch == 2) cnt++;
				}
				if(cnt == k) res++;
			}
			cout << res << el;
		}
		if(n == 4){
			int res = 0;
			fod(x1, 1, s) fod(x2, 1, s) fod(x3,1,s) fod(x4,1,s){
				vector <int> b;
				b.pb(-INF); b.pb(x1); b.pb(x2); b.pb(x3); b.pb(x4);
				int cnt = 0;
				fod(l,1,4) fod(r,l,4){
					int ch = 0;
					fod(i,l,r){
						if(a[i] > b[i]){
							ch = 1; break;
						}
						if(a[i] < b[i]){
							ch = 2; break;
						}
					}
					if(ch == 2) cnt++;
				}
				if(cnt == k) res++;
			}
			cout << res << el;
		}
		if(n == 5){
			int res = 0;
			fod(x1, 1, s) fod(x2, 1, s) fod(x3,1,s) fod(x4,1,s) fod(x5,1,s){
				vector <int> b;
				b.pb(-INF); b.pb(x1); b.pb(x2); b.pb(x3); b.pb(x4); b.pb(x5);
				int cnt = 0;
				fod(l,1,5) fod(r,l,5){
					int ch = 0;
					fod(i,l,r){
						if(a[i] > b[i]){
							ch = 1; break;
						}
						if(a[i] < b[i]){
							ch = 2; break;
						}
					}
					if(ch == 2) cnt++;
				}
				if(cnt == k) res++;
			}
			cout << res << el;
		}
		if(n == 6){
			int res = 0;
			fod(x1, 1, s) fod(x2, 1, s) fod(x3,1,s) fod(x4,1,s) fod(x5,1,s) fod(x6,1,s){
				vector <int> b;
				b.pb(-INF); b.pb(x1); b.pb(x2); b.pb(x3); b.pb(x4); b.pb(x5); b.pb(x6);
				int cnt = 0;
				fod(l,1,6) fod(r,l,6){
					int ch = 0;
					fod(i,l,r){
						if(a[i] > b[i]){
							ch = 1; break;
						}
						if(a[i] < b[i]){
							ch = 2; break;
						}
					}
					if(ch == 2) cnt++;
				}
				if(cnt == k) res++;
			}
			cout << res << el;
		}
		if(n == 7){
			int res = 0;
			fod(x1, 1, s) fod(x2, 1, s) fod(x3,1,s) fod(x4,1,s) fod(x5,1,s) fod(x6,1,s) fod(x7,1,s){
				vector <int> b;
				b.pb(-INF); b.pb(x1); b.pb(x2); b.pb(x3); b.pb(x4); b.pb(x5); b.pb(x6); b.pb(x7);
				int cnt = 0;
				fod(l,1,7) fod(r,l,7){
					int ch = 0;
					fod(i,l,r){
						if(a[i] > b[i]){
							ch = 1; break;
						}
						if(a[i] < b[i]){
							ch = 2; break;
						}
					}
					if(ch == 2) cnt++;
				}
				if(cnt == k) res++;
			}
			cout << res << el;
		}
		if(n == 8){
			int res = 0;
			fod(x1, 1, s) fod(x2, 1, s) fod(x3,1,s) fod(x4,1,s) fod(x5,1,s) fod(x6,1,s) fod(x7,1,s) fod(x8,1,s){
				vector <int> b;
				b.pb(-INF); b.pb(x1); b.pb(x2); b.pb(x3); b.pb(x4); b.pb(x5); b.pb(x6); b.pb(x7); b.pb(x8);
				int cnt = 0;
				fod(l,1,8) fod(r,l,8){
					int ch = 0;
					fod(i,l,r){
						if(a[i] > b[i]){
							ch = 1; break;
						}
						if(a[i] < b[i]){
							ch = 2; break;
						}
					}
					if(ch == 2) cnt++;
				}
				if(cnt == k) res++;
			}
			cout << res << el;
		}
	}	
	
}
namespace sub_task2{

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
		if(n <= 8 and s <= 4){
			sub_task1 :: solve();
			kill();
		}
	}
	kill();
}