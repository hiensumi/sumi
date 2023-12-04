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
#define name "fishing"
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n, m, b;
struct fish{
    int w, d, a;
}A[base];
struct rod{
    int w, c;
}B[base];
void inp(){
    cin >> n;
    fod(i,1,n) cin >> A[i].w >> A[i].d >> A[i].a;
    cin >> m;
    fod(i,1,m) cin >> B[i].w >> B[i].c;
    cin >> b;
}

namespace sub_task1{
    void solve(){
        int res = 0;

        fod(j,1,m){
            vector <fish> hanhnguyen;
            fod(i,1,n) if(A[i].w <= B[j].w) hanhnguyen.pb(A[i]);
            sort(all(hanhnguyen), [&](fish x, fish y){
                return x.d < y.d;
            });
            int sum = 0;
            for(fish x : hanhnguyen){
                sum += x.a;
                maxi(res, sum - B[j].c - b * x.d);
            }
        }

        cout << res;
    }	
    
}
int st[4 * base], lz[4*base], id[base];
void pull(int i, int l, int r){
    if(lz[i]){
        st[2*i] += lz[i];
        st[2*i+1] += lz[i];
        lz[2*i] += lz[i];
        lz[2*i+1] += lz[i];
        lz[i] = 0;
    }
}
void build(int i, int l, int r){
    if(l == r){
        st[i] = -b * id[l];
        return;
    }
    int mid = l + r >> 1;
    build(2*i,l,mid);
    build(2*i+1,mid+1,r);
    st[i] = max(st[2*i], st[2*i+1]);
}
void upd(int i, int l, int r, int u, int v, int val){
    if(r < u or v < l) return;
    if(u <= l and r <= v){
        st[i] += val;
        lz[i] += val;
        return;
    }
    int mid = l + r >> 1;
    pull(i,l,r);
    upd(2*i,l,mid,u,v,val);
    upd(2*i+1,mid+1,r,u,v,val);
    st[i] = max(st[2*i], st[2*i+1]);
}
int get(int i, int l, int r, int u, int v){
    if(r < u or v < l) return -INF;
    if(u <= l and r <= v) return st[i];
    pull(i,l,r);
    int mid = l + r >> 1;
    int getl = get(2*i,l,mid,u,v), getr = get(2*i+1,mid+1,r,u,v);
    return max(getl, getr);
}
namespace sub_task2{
    void solve(){
        int res = 0;
        sort(A + 1, A + n + 1, [&](fish x, fish y){
                return x.w < y.w;
        });
        sort(B + 1, B + m + 1, [&](rod a, rod b){
            return a.w < b.w;
        });
        map <int,int> mp;
        int hanhnguyen = 0, pt = 0;
        fod(i,1,n) mp[A[i].d] = 0;
        for(ii x: mp) mp[x.fi] = ++hanhnguyen;
        fod(i,1,n) id[mp[A[i].d]] = A[i].d, A[i].d = mp[A[i].d];

        build(1,1,hanhnguyen);

        fod(j,1,m){
            while(A[pt + 1].w <= B[j].w and pt + 1 <= n){
                pt++;
                upd(1,1,hanhnguyen,A[pt].d, hanhnguyen, A[pt].a);
            }
            maxi(res, -B[j].c + st[1]);
        }

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
        sub_task2 :: solve();
    }
    kill();
}