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
#define name "milktea"
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n, m, k, ts[base], home[base];
vector <ii> adj[base];
void inp(){
    cin >> n >> m >> k;
    fod(i,1,m){
        int u, v, c; cin >> u >> v >> c;
        adj[u].pb(ii(v,c));
        adj[v].pb(ii(u,c));
    }
    fod(i,1,k){
        int x , t ;cin >> x >> t;
        ts[x] = 1;
        home[x] = (t ^ 1);
    }
}
namespace sub_task1{
    int d1[base], d2[base];
    struct node{
        int u, val;
    };
    struct cmp{
        bool operator() (node a, node b){
            return a.val > b.val;
        }
    };
    int dd[base], trace[base];
    void dji(){
        priority_queue <node, vector <node>, cmp > pq;
        fod(i,1,n){
            if(ts[i]){
                pq.push({i,0});
                d1[i] = 0;
                d2[i] = INF;
                trace[i] = i;
            }
            else{
                d1[i] = d2[i] = INF;
                trace[i] = 0;
            }
        }
        while(pq.size()){
            int u = pq.top().u, d = pq.top().val; pq.pop();
            if(d != d1[u]) continue;
            // cout << d << " " << d1[u] << " " << d2[u] << el;
            if(ts[u] == 0) d2[u] = d;
            dd[u] = 1;
            for(auto [v,w] : adj[u]){
                if(mini(d1[v], d + w)){
                    pq.push({v, d1[v]});
                    trace[v] = trace[u];
                }
                else if(trace[v] != trace[u] and dd[v] == 1){
                    int sewe = d1[u] + w + d1[v];
                    // cout << sewe ; kill();
                    mini(d2[trace[v]], sewe);
                    mini(d2[trace[u]], sewe);
                }
            }
        }
    }
    void solve(){
        dji();
        fod(i,1,n){
            if(ts[i] == 0) cout << d1[i] << " ";
            else{
                if(home[i] == 0) cout << d2[i] << " ";
                else cout << 0 << " ";
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
        sub_task1 :: solve();
    }
    kill();
}