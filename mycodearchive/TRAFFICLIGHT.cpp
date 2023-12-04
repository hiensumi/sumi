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
const ll INF = 1e18, base = 1e5 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name "TRAFFICLIGHT"
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n, k, t[base];
struct TL{
    int tr, tg;
    char st;
}a[base];
ii store[base];
int calc(int tm){
    int x  = 0;
    fod(i,1,tm){

    }
    return x;
}
void inp(){
    cin >> n >> k;
    fod(i,1,n-1) cin >> t[i];
    fod(i,1,n){
        int r, g;
        char c;
        cin >> r >> g >> c;
        a[i] = {r,g,c};
    }
}

namespace sub_task1{
    void solve(){
        int cur = 1, tm = 0;
        while(cur <= n){
            int light = calc(tm);
            if(light == 0){

            }
        }


    }	
    
}
namespace sub_task3{
    int dp[base][mask(5) + 5];
    void solve(){
        vector <int> tp(n + 5), shop(n + 5);
        fod(i,1,n){
            cin >> tp[i];
            int sz; cin >> sz;
            fod(j,1,sz){
                int x; cin >> x;
                x--;
                shop[i] = shop[i] xor mask(x);
            }
        }

        // dp i mask
        memset(dp, 0x3f, sizeof dp);
        dp[1][0] = 0;
        int tt = mask(k) - 1;
        fod(i,1,n) fod(x,0,tt){
            int p = x xor shop[i];
            mini(dp[i][p], dp[i][x] + tp[i]);
            // cout << p << el;
            int tot = dp[i][x] % (a[i].tr + a[i].tg);
			int tmp = dp[i][x];
            // cout << tot << " " << tmp << el;
            tot++;
            
            if (a[i].st == 'G' and (tot - a[i].tg) > 0) tmp += a[i].tr - (tot - a[i].tg - 1);
            else if (a[i].st == 'R' and (tot - a[i].tr) <= 0) tmp += a[i].tr - tot + 1;
            
            // cout << tmp << el;
            mini(dp[i+1][x], tmp + t[i]);
        }
        
        // fod(i,1,n){
        //     fod(x,0,tt){
        //         cout << dp[i][x] << " ";
        //     }
        //     cout << el;
        // }

        int res = dp[n+1][tt];
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
        sub_task3 :: solve();
    }
    kill();
}