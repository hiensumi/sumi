// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
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
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name "gcd-graph"
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n, k, q, lab[base], a[base], ma = -2e9;
int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u; return 1;}
const int N = 1e7 + 5;
vector <int> v[N];
void inp(){
    cin >> n >> k >> q;
    fod(i,1,n) cin >> a[i], maxi(ma, a[i]), v[a[i]].pb(i);
    
}
namespace sub_task1{
    
    void solve(){
        fod(i,1,n) lab[i] = -1;
        fod(i,1,n) fod(j,i+1,n){
            if(__gcd(a[i], a[j]) > k) join(i,j);
        }
        while(q--){
            int u, v; cin >> u >> v;
            int paru = find(u);
            int parv = find(v);
            if(paru == parv) cout << 'Y';
            else cout << 'N';
        }
    }
}
namespace sub_task2{
    int dd[N + 5];
    void solve(){
    	memset(lab, - 1, sizeof lab);
        fod(d,k+1,ma) if(dd[d] == 0) {
            int t = -1;
            for(int j = d; j <= ma; j += d){
                dd[j] = 1;
                if(v[j].size()){
                    for(int x : v[j]){
                      if(t == -1) t = x;
                      else join(t,x);
                    }
                }
            }
        }
        while(q--){
            int u, v; cin >> u >> v;
            int paru = find(u);
            int parv = find(v);
            if(paru == parv) cout << 'Y';
            else cout << 'N';
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
        sub_task2 :: solve();
    }
    kill();
}
