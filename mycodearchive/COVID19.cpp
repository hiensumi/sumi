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
const ll INF = 1e16, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
	
}
int n, m;
void inp(){
    cin >> n >> m;
}

namespace sub_task1{
    map <int,int> mp;
    void solve(){
<<<<<<< HEAD
        vector <int> divs;
        int _n = n;
        for(int i = 2; i * i <= n; i++){
            if(_n % i == 0){
                divs.pb(i);
                while(_n % i == 0) _n /= i;
            }
=======
        queue <HN> q;
        dp[0][0] = n;
        q.push({0,0,n});
        while(!q.empty()){
            HN t = q.front();
            q.pop();
            int x = t.x, y = t.y, cur = t.val;
            if(cur >= 2e9) continue;
            dp[x][y] = cur;
            q.push({t.x + 1, t.y, cur * cur});
            q.push({t.x, t.y + 1, cur - p});
>>>>>>> b4657fbd6e3c5891d6623fbe4c8fea05f4103ec4
        }
        if(_n > 1) divs.pb(_n);
        queue <int> q;
        q.push(n);
        mp[n] = 0;
        while(!q.empty()){
            int t = q.front(); q.pop();
            if(t == m){
                cout << mp[t];
                kill();
            }
            if(t < INF/ t){
                int x = t * t;
                if(mp.find(x) == mp.end()){
                    mp[x] = mp[t] + 1;
                    q.push(x);
                }
            }
            for(int x : divs){
                if(t % x == 0){
                    int y = t / x;
                    if(mp.find(y) == mp.end()){
                        mp[y] = mp[t] + 1;
                        q.push(y);
                    }
                }
            }
        }
        cout << mp[m] << el;
	}	
	
}
// adadadada
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