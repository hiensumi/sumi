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
int n, m, h[base], par[base][21], q, a[base];
vector <int> adj[base];
void dfs(int u, int p){
    for(int v : adj[u]){
        if(v == p) continue;
        h[v] = h[u] + 1;
        par[v][0] = u;
        fod(j,1,20){
            par[v][j] = par[par[v][j-1]][j-1];
        }
        dfs(v,u);
    }
}
int lca(int u, int v){
    if(h[u] < h[v]) swap(u,v);
    int k = h[u] - h[v];
    fod(j,0,log2(k)) if(k & mask(j)){
        u = par[u][j];
    }
    if(u == v) return u;
    int d = log2(h[u]);
    fok(j,d,0) if(par[v][j] != par[u][j]){
        u = par[u][j];
        v = par[v][j];
    }
    return par[u][0];
}
void inp(){
    cin >> n >> m >> q;
    fod(i,1,n-1){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(1,0);
    fod(i,1,m) cin >> a[i];
}
namespace sub_task1{
    int b[base];
    void calc(int l, int r, int u){
        fod(j,l,r){
            if(a[j] == u){
                return void(cout << j << " " << j << el);
            }
            if(j > l){
                if(b[j] == u){
                    return void(cout << j-1 << " " << j << el);
                }
            }
        }
        return void(cout << -1 << " " << -1 << el);
    }
    void solve(){
        fod(i,2,m) b[i] = lca(a[i], a[i-1]);
        while(q--){
            int type; cin >> type;
            if(type == 1){
                int i, u ;
                cin >> i >> u;
                a[i] = u;
                b[i] = lca(a[i-1], u);
                b[i+1] = lca(a[i+1],u);
            }
            else{
                int l, r, u;
                cin >> l >> r >> u;
                calc(l,r,u);
            }
        }      
    }	
    
}
namespace sub_task2{
    int b[base];
    set <int> POS_in_A[base], POS_in_B[base];
    void calc(int l, int r, int u){
        auto it = POS_in_A[u].lower_bound(l);
        auto it2 = POS_in_B[u].lower_bound(l+1);
        if(it != POS_in_A[u].end()){
            int posa = *it;
            if(posa <= r) return void(cout << posa << " " << posa << el);
        }
        if(it2 != POS_in_B[u].end()){
            int posb = *it2;
            if(posb <= r) return void(cout << posb - 1 << " " << posb << el);
        }
        return void(cout << -1 << " " << -1 << el);
    }
    void solve(){
        fod(i,2,m) b[i] = lca(a[i], a[i-1]);
        fod(i,1,m) POS_in_A[a[i]].insert(i);
        fod(i,2,m) POS_in_B[b[i]].insert(i);
        while(q--){
            int type; cin >> type;
            if(type == 1){
                int i, u ;
                cin >> i >> u;
                POS_in_A[a[i]].erase(i);
                POS_in_B[b[i]].erase(i);
                POS_in_B[b[i+1]].erase(i+1);
                a[i] = u;
                b[i] = lca(a[i-1], u);
                b[i+1] = lca(a[i+1],u);
                POS_in_A[a[i]].insert(i);
                POS_in_B[b[i]].insert(i);
                POS_in_B[b[i+1]].insert(i+1);
            }
            else{
                int l, r, u;
                cin >> l >> r >> u;
                calc(l,r,u);
            }
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
        // sub_task1 :: solve();
        sub_task2 :: solve();
    }
    kill();
}