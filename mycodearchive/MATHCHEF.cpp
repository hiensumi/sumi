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
#define name "MATHCHEF"
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
struct TRI{
    int type1, type2, type3, type4;
}b[55][55][55];

int n, m, a[500][500], f[1005][1005], g[1005][1005];
bool nt(int x, int y){
    return (1 <= x and x <= n and 1 <= y and y <= m);
}
void inp(){
    cin >> n >> m;
    fod(i,1,n) fod(j,1,m) cin >> a[i][j];
    fod(i,0,n+1) fod(j,0,m+1) f[i][j] = g[i][j] = 1;
    fod(i,1,n) fod(j,1,m) f[i][j] = (f[i-1][j-1] % MOD * a[i][j] % MOD) % MOD;
    fod(i,1,n) fok(j,m,1) g[i][j] = (g[i-1][j+1] % MOD * a[i][j] % MOD) % MOD;
    fod(i,1,n) fod(j,1,m){
        // b[i][j].type1 = b[i][j].type2 = b[i][j].type3 = b[i][j].type4 = 1;
        fod(len,1,min(n,m)){
            int x = i, y = j + len - 1;
            int nx = i - len + 1, ny = j;
            if(nt(x,y) and nt(nx,ny)){
                b[i][j][len].type1 = max(1ll, b[i][j][len-1].type1 % MOD) * max(1ll, f[x][y] % MOD * Inv(f[nx-1][ny-1]) % MOD);
                b[i][j][len].type1 %= MOD;   
            }

            x = i; y = j - len + 1;
            nx = i - len + 1, ny = j;
            if(nt(x,y) and nt(nx,ny)){
                b[i][j][len].type2 = max(1ll,b[i][j][len-1].type2 % MOD) * max(1ll, g[x][y] % MOD * Inv(g[nx-1][ny+1]) % MOD) % MOD;
                b[i][j][len].type2 %= MOD;
            }

            x = i + len - 1; y = j;
            nx = i; ny = j - len + 1;
            if(nt(x,y) and nt(nx,ny)){
                b[i][j][len].type3 = max(1ll, b[i][j][len-1].type3 % MOD) * max(1ll, f[x][y] % MOD * Inv(f[nx-1][ny-1]) % MOD) % MOD;
                b[i][j][len].type3 %= MOD;
            }

            x = i + len - 1; y = j;
            nx = i; ny = j + len - 1;
            if(nt(x,y) and nt(nx,ny)){
                b[i][j][len].type4 = max(1ll, b[i][j][len-1].type4 % MOD) * max(1ll, g[x][y] % MOD * Inv(g[nx-1][ny+1] % MOD)) % MOD;
                b[i][j][len].type4 %= MOD;
            }
        }

    }
}
struct bg{ point x1, x2, x3; };
bg find(point x1, point x2, point x3){
    vector <point> tri; tri.pb(x1); tri.pb(x2); tri.pb(x3);
    fod(i,0,2){
        fod(j,0,2) fod(k,0,2){
            if(i != j and j != k and i != k){
                point x1 = tri[i], x2 = tri[j], x3 = tri[k];
                if(x1.x == x2.x and x1.y == x3.y){
                    bg p = {x1,x2,x3};
                    return p;
                }
                if(x1.x == x3.x and x1.y == x2.y){
                    bg p = {x1,x3,x2};
                    return p;
                }
            }   
        }
    }
}
int calc(point x1, point x2, point x3){
    bg p = find(x1,x2,x3);
    x1 = p.x1; x2 = p.x2; x3 = p.x3;
    int mix = min({x1.x, x2.x, x3.x});
    int miy = min({x1.y, x2.y, x3.y});
    int len = 0; maxi(len, max({abs(x1.x - x2.x), abs(x1.x - x3.x), abs(x1.y - x2.y), abs(x1.y - x3.y)}));
    len++;
    // cout << x1.x << " " << x1.y << el;
    if(x1.x == mix){
        if(x1.y == miy){
            // cout << 4 << el;
            return b[x1.x][x1.y][len].type4;
        }
        else{
            // cout << 3 << el;
            return b[x1.x][x1.y][len].type3;
        }
    }
    else{
        if(x1.y == miy){
            // cout << 1 << el;
            return b[x1.x][x1.y][len].type1;
        }
        else{
            // cout << 2 << el;
            return b[x1.x][x1.y][len].type2;
        }
    }
    
}
namespace sub_task1{
    void solve(){
        int q; cin >> q;
        while(q--){
            point x1, x2, x3;
            cin >> x1.x >> x1.y >> x2.x >> x2.y >> x3.x >> x3.y;
            cout << calc(x1,x2,x3) << el;
        
            // calc(x1,x2,x3);
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