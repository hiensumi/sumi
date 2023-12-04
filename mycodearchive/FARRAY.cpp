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
const int N = 2e5 + 5;
int n, x, a[base];
void inp(){
    cin >> n >> x;
    fod(i,1,n) cin >> a[i];
}
namespace sub_task1{
    int s[base], dp[base];
    
    void solve(){
        fod(i,1,n) s[i] = s[i-1] + a[i];
        int res = INF;
        fod(i,1,n){
            fod(j,i,n) if( (s[j] - s[i-1]) >= x){
                mini(res, j - i + 1);
            }
        }
        if(res == INF) cout << -1;
        else cout << res;
    }	
}
int st[4*base];
void upd(int i, int l, int r, int u, int v, int x){
    if(r < u or v < l) return;
    if(u <= l and r <= v){
        st[i] = x;
        return;
    }
    int mid = l + r >> 1;
    upd(2*i,l,mid,u,v,x);
    upd(2*i+1,mid+1,r,u,v,x);
    st[i] = max(st[2*i], st[2*i+1]);
}
int get(int i, int l, int r, int u, int v){
    if(r < u or v < l) return -INF;
    if(u <= l and r <= v) return st[i];
    int mid = l + r >> 1;
    int getl = get(2*i,l,mid,u,v);
    int getr = get(2*i+1,mid+1,r,u,v);
    return max(getl, getr);
}
namespace sub_task2{
    int s[base], id[base];
    vector <ii> v;
    void solve(){
        fod(i,1,n) s[i] = s[i-1] + a[i];
        v.pb(ii(-INF,-INF));
        v.pb(ii(0,1));
        v.pb(ii(x,2));
        int cnt = 2;
        fod(i,1,n){
            v.pb(ii(s[i],1));
            cnt++;
            id[cnt] = i;
            v.pb(ii(s[i] + x, 2));
            cnt++;
            id[cnt] = i;
        }
        int sz = 2 * n + 2;
        map <int,int> mp;
        int d = 0;
        fod(i,1,sz) mp[v[i].fi] = 0;
        for(ii x : mp) mp[x.fi] = ++d;
        fod(i,1,sz) v[i].fi = mp[v[i].fi];
        // fod(i,1,sz){
            // cout << v[i].fi << " " << v[i].se << " " << id[i] << el;
        // }
        int res = INF, pos = 0;
        memset(st, -0x3f, sizeof st);
        // upd(1,1,N,4,4,0);
        // cout << get(1,1,N,1,3);
        fod(i,1,sz){
            if(v[i].se == 1 and i > 2){
                int j = get(1,1,N,1,v[i].fi);
                if(mini(res, id[i] - j)){
                    // if(i == 3) cout << v[i].fi << " " << j << el;
                }
            }
            else if(v[i].se == 2){
                upd(1,1,N,v[i].fi, v[i].fi, id[i]);
            }
        }
        // cout << pos << el;
        if(res == INF) cout << -1;
        else cout << res;
        // cout << res;
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