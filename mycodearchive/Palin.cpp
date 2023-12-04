// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
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
// dp i j  la tg it nhat de xoa doan i j
int memo[305][305];
int M = 0;
string s;
bool ispalin(int l, int r){
    fod(i,l,r){
        int len = i - l;
        int j = r - len;
        if(i > j) break;
        // cout << i << " " << j << el;
        if(s[i] != s[j]) return 0;
    }
    return 1;
}
// int dp(int l, int r){
    // if(l > r) return memo[l][r] = 1;
    // if(memo[l][r] != -1) return memo[l][r];
    // if(l == r) return memo[l][r] = 2;
    // int best = 0; 
    // if(s[l] == s[r]) (best = best - dp(l+1,r) + dp(l,r-1) + M) %= M;
	// else{
		// (best += dp(l+1,r-1)) %= M;
	// }
    // return memo[l][r] = best;
// }
void inp(){
	cin >> M; 
}

namespace sub_task1{
	int f[205][205];
    void solve(){
 		while(cin >> s){
 			int n = s.size();
	        s = "#" + s;
	        memset(f, 0, sizeof f);
	        
	        fod(len,0,n) fod(i,1,n){
	        	int j = i + len - 1;
	        	if(i == j) f[i][j] = 2 % M;
	        	else if(i > j) f[i][j] = 1 % M;
	        	else{
	        		(f[i][j] += f[i][j-1] + f[i+1][j]) % M;
	        		if(s[i] != s[j]) f[i][j] = (f[i][j] - f[i+1][j-1] + M) % M;
	        	}
	        }
	        cout << f[1][n] << el;
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
