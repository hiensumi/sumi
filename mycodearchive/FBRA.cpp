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
int n;
string s;
void init(){
	
}

void inp(){
	cin >> s;
	if(odd(s.size())){
		cout << 0;
		kill();
	}
}
char pa = ')';
char pap = '}';
char papp = ']';
namespace sub_task1{
	int dp[505][505];
	int val(int i, int j){
		if(s[i] == '?' and s[i] == s[j]) return 3;
		if(s[i] == '?' and (s[j] == 41 or s[j] == 93 or s[j] == 125)) return 1;
		if(s[j] == '?' and (s[i] == 40 or s[i] == 91 or s[i] == 123)) return 1;
		if(s[i] == 40 and s[j] == 41) return 1;
		if(s[i] == 91 and s[j] == 93) return 1;
		if(s[i] == 123 and s[j] == 125) return 1;
		return 0;
	}
	int rec(int i, int j){
		if(odd(j - i + 1)) return dp[i][j] = 0;
		if(j < i) return dp[i][j] = 1;
		if(dp[i][j] != - 1) return dp[i][j];
		if(j == i + 1){
			return dp[i][j] = val(i,j);
		}
		int res= 0 ;
		fod(k,i,j){
			if(!odd(k - i + 1)){
				(res += val(i,k) * rec(i+1,k-1) * rec(k+1,j)) %= MOD;
			}
		}
		return dp[i][j] = res;
	}
	// là số cách biến đổi s[i...j] thành dãy ngoặc đúng
	void solve(){
		n = s.size();
		memset(dp, -1, sizeof dp);
		s = "#" + s;
		// cout << pa << " " << pap << " " << papp << el;
		// fod(i,1,n){
			// fod(j,1,n) cout << dp[i][j] << " ";
			// cout << el;
		// }
		cout << rec(1,n) << el;	
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