// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#define tab _M_w
using namespace std;
using biti = typename remove_reference<decltype(bitset<400>().tab[0])>::type;
const int SIZE = 8 * sizeof(biti);
const int LOG = __builtin_ctz(SIZE);
#define clz(x) __builtin_clz(x)
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
// #define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) ((a >> i) & 1LL)
#define pb push_back
#define el '\n'
#define all(v) v.begin(), v.end()
#define odd(i) (i & 1LL)
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
const ll INF = 1e18, base = 160001, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
template <size_t N> int find_prev(const bitset<N> &x, int v) {
	int start = v >> LOG;
	int first_bits = v & (SIZE - 1);
	if (first_bits) {
		biti curr = x.tab[start];
		curr = curr << (SIZE - first_bits) >> (SIZE - first_bits);
		if (curr)
			return start << LOG | (SIZE - clz(curr) - 1);
	}
	fok(i, start - 1, 0) {
		biti curr = x.tab[i];
		if (curr) return (i << LOG) | (SIZE - clz(curr) - 1);
	}
	return -1;
}
int n, m, a[405][405], pre[405];
void inp(){
    cin >> n >> m;
    fod(i,0,n-1) fod(j,0,m-1) cin >> a[i][j];
}
bitset <400> bit[base];
namespace sub_task1{
    void solve(){

        int res = 1;
        fod(top,0,n-1){
            if(top > 0) memset(bit, 0, sizeof bit);
            memset(pre, -1, sizeof pre);
            fod(bot,top,n-1){
                fod(r,0,m-1){
                    int val = a[bot][r];
                    auto &x = bit[val];
                    if(x[r] == 1) pre[r] = r;
                    else{
                        int j = x._Find_next(r);
                        maxi(pre[j], r);
                        int j2 = find_prev(x,r);
                        maxi(pre[r], j2);
                        x[r] = 1;
                    }
                }
                int st = -1;
                fod(r,0,m-1){
                    maxi(st, pre[r]);
                    maxi(res, (r - st) * (bot - top + 1));
                }
            }
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
        sub_task1 :: solve();
    }
    kill();
}