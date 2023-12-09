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
#define name "PASSWORD"
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n, k, a[base], b[base];
void rotate(){
    int tmp = b[1];
    fod(i,1,n-1) b[i] = b[i+1];
    b[n] = tmp;
}
void inp(){
    cin >> n >> k;
    fod(i,1,n) cin >> a[i];
    fod(i,1,n) cin >> b[i];
}

namespace sub_task1{
    void solve(){
        int res = 0;
        fod(rot,1,k){
            fod(i,1,n) (res += (a[i] % MOD * b[i] % MOD) % MOD) %= MOD;
            rotate();
        }

        cout << res;
    }	
}
namespace sub_task2{
    void solve(){
        int s = 0;
        fod(i,1,min(k,n)){
            fod(j,1,n){
                (s += (a[j] % MOD * b[j] % MOD) % MOD) %= MOD;
            }
            rotate();
        }
        if(k > n){
            int left = k % n;
            int x = k / n;
            s = (s % MOD * x % MOD) % MOD;
            fod(rot, 1, left){
                fod(i,1,n){
                    s += (a[i] % MOD * b[i] % MOD) % MOD;
                    s %= MOD;
                }
                rotate();
            }
        }
        
        cout << s;
    }
}
namespace sub_task3{
    void solve(){
        int res = 0;
        int mul1 = 0; fod(i,1,n) (mul1 += a[i]) %= MOD;
        int mul2 = 0; fod(i,1,n) (mul2 += b[i]) %= MOD;
        if(k >= n) res = (mul1 % MOD * mul2 % MOD) % MOD;
        int left = k % n, x = k / n;
        if(x > 0) res = (res % MOD * max(1ll, x) % MOD) % MOD;

        fod(i,n+1,2*n) b[i] = b[i - n];
        fod(i,1,2*n) (b[i] += b[i-1]) %= MOD;

        fod(i,1,n) (res += (a[i] % MOD * (b[i + left - 1] - b[i-1]) % MOD) % MOD + MOD) %= MOD;

        cout << res;
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
        if(n <= 1e3 and k <= 1e3) sub_task1 :: solve();
        else if(n <= 1e3 and k > 1e3) sub_task2 :: solve();
        else sub_task3 :: solve();
    }
    kill();
}