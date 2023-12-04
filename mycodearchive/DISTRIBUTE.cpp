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
int n, m, val[base],nc[base], a[base], dp[base];
vector <int> adj[base], b;
void inp(){
    cin >> n;
    fod(i,1,n-1){
        int u, v; cin >> u >> v ; 
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fod(i,1,n) nc[i] = 1;
    cin >> m;
    fod(i,1,m) cin >> a[i];
    sort(a+1,a+m+1);
    b.pb(-INF);
}
void dfs(int u, int p){
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v,u);
        nc[u] += nc[v];
        b.pb(nc[v] * (n - nc[v]));
    }
}
namespace sub_task1{
    void solve(){
        dfs(1,0);
        sort(all(b));
        if(m > n - 1){
            int res = 0;
            fod(i,1,n-2) add(res, b[i] * a[i]);
            int x = b[n-1];
            fod(i,n-1,m) mul(x, a[i]);
            add(res, x);
            cout << res; 
        }else{
            b[0] = INF;
            sort(all(b), greater<int>());
            sort(a + 1, a + m + 1,greater<int>());
            int res = 0;
            fok(i,m,1) add(res, b[i] * a[i]);
            fod(i,m+1,n-1) add(res, b[i]);
            cout << res;
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