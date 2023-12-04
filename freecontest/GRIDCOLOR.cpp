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
#define name "GRIDCOLOR"
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n, total = 0, m ,k;
char H[1001][1001], V[1001][1001];
int a[1001][1001];
void inp(){
    cin >> n >> m >> k;
    total = (n - 1) * m + n * (m - 1);
}

namespace sub_task1{
    void solve(){
        fod(i,1,n) fod(j,1,m-1) cin >> H[i][j];

        fod(i,1,n-1) fod(j,1,m) cin >> V[i][j];
        
        if(k == 1){
            int cnt = 0, d = 0 ;
            fod(i,1,n) fod(j,1,m-1) if(H[i][j] == 'E') cnt++;
            fod(i,1,n-1) fod(j,1,m) if(V[i][j] == 'E') cnt++;
            if( cnt * 4 >= 3 * total){
                fod(i,1,n){ 
                    fod(j,1,m) cout << 1 << " "; 
                    cout << el;
                }
            }
            else cout << -1;

            kill();
        } 



        if(n*(m-1) > (n-1)*m){
            fod(i,1,n){
                a[i][1] = 0;
                fod(j,2,m) a[i][j] = (a[i][j-1] ^ (H[i][j-1] == 'N'));
                
                int cnt = 0;

                if(i > 1){
                    fod(j,1,m) if( (a[i][j] ^ a[i-1][j]) == (V[i-1][j] == 'N')) cnt++;
                    if(cnt * 2 < m) fod(j,1,m) a[i][j] ^= 1;
                }
            
            }
        }
        else{
            fod(j,1,m){
                a[1][j] = 0;
                fod(i,2,n) a[i][j] = a[i-1][j] ^ (V[i-1][j] == 'N');
                int cnt = 0;
                if(j > 1){
                    fod(i,1,n) if( (a[i][j] ^ a[i][j-1]) == (H[i][j-1] == 'N') ) cnt++;

                    if(cnt * 2 < n) fod(i,1,n) a[i][j] ^= 1;
                }
            }
        }
        fod(i,1,n){
            fod(j,1,m) cout << a[i][j] + 1 << " ";
            cout << el;
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