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
int n, m;
string te;
string password;
void inp(){
    cin >> n >> m >> te >> password;
}
namespace sub_task1{
    int dd[base], dp[base];
    int f[base][31];
    void solve(){
        te = "#" + te;
        password = "#" + password;
        string _s;
        vector <int> hng;
        hng.pb(-INF);
        int sz = te.size() - 1;
        for(int i = 1; i < sz; i += 2){
            char x = te[i] - 'a';
            int cnt = te[i+1] - '0';
            dd[x] += cnt;
            _s += x;
            hng.pb(cnt);
        }
        _s = "#" + _s;
        int _n = _s.size() - 1;
        
        
        fod(i,1,_n){
            fod(j,1,m) f[i][j] = f[i-1][j];
            if(_s[i] == password[1]) f[i][password[1] - 'a'] += hng[i];
            fod(j,2,m-1){
                if(_s[i] == password[j]){
                    int x = password[j] -  'a';
                    int y = password[j-1] - 'a';
                    f[i][x] += (f[i-2][y] * hng[i]);
                }
            }            
        }

        fod(i,0,26) cout << f[_n][i] << el;
	}	
    // failed algo
}
namespace teacher_sol{
    const int N = 1e5 + 5;
    int dp[N][35], fact[base];
    int comb(int k, int n){
        if(k > n) return 0;
        return ( (fact[n]  * Inv(fact[k]) % MOD) * (Inv(fact[n-k]) % MOD) % MOD);
    }
    void solve(){
        te = "#" + te;
        password = "#" + password;
        vector <pair<char,int>> HN;
        int sz = te.size() - 1;
        fact[0] = 1;

        fod(i,1,1e6) fact[i] = (fact[i-1] * i)  % MOD;


        HN.pb(make_pair('@',-INF));
        fod(i,1,sz-1){
            char x = te[i];
            int pos = i + 1;
            int num = 0;
            while(!isalpha(te[pos]) and pos <= sz){
                num *= 10;
                num += te[pos] - '0';
                pos++;
            }
            i = pos - 1;
            HN.pb(make_pair(x, num));
        }
        
        n = HN.size() - 1;
        dp[0][0] = 1;
        fod(i,1,n){
            dp[i][0] = 1;
            fod(j,1,m){
                dp[i][j] = dp[i-1][j];
                fok(k,j,1){
                    if(HN[i].fi == password[k]){
                        (dp[i][j] += dp[i-1][k-1] * comb(j - k + 1, HN[i].se)) %= MOD;
                    }
                    else break;
                }
            }
        }
        cout << dp[n][m] << el;
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
	    teacher_sol :: solve();
	}
	kill();
}