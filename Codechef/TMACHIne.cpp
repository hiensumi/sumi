// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include "bits/stdc++.h"
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
// #define int long long
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
const int base = 1e3 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
namespace solution{
	// remember to reset value for multitestcase
	
	// là chi phí cho mỗi truy vấn s -> t, kq là dp[t]
	void sub1(){
		
	}
	void solve(){
		sub1();
	}
}
int n, q;
ii dp[base];
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
	cin >> n >> q;
		fod(i,1,n){
		    char c; cin >> c;
		    dp[i].se = c - '0';
		}
		fod(k,1,q){
			int s, t, c; cin >> s >> t >> c;
			if(s > t) swap(s,t);
			if(s == t){
			    cout << dp[s].se << el;
			    continue;
			}
			deque <int> dq;
			fod(i,s,t){
				dp[i].fi = dp[i].se;
				if(!dq.empty()) dp[i].fi += dp[dq.back()].fi;
				while(!dq.empty() and dp[dq.front()].fi > dp[i].fi) dq.pop_front();
				dq.push_front(i);
				if(!dq.empty() and dq.back() <= i - c) dq.pop_back();
			}
			cout << dp[t].fi << el;
		}
}