// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
using namespace std; 
#define            int  long long
#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     fod(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    fok(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define         all(a)  a.begin(),a.end()  
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        mask(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define pra(a,n) fod(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 
struct point{int x, y;};
struct edge{int u, v, c;};

//int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
//bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u; return 1;}
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 0; int endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, m, G, R, d[base];
void inp(){
	cin >> n >> m;
	fod(i,1,m) cin >> d[i];
	sort(d + 1, d + m + 1);
	cin >> G >> R;
		
}
int dp[10004][1003];
// số lần trải nghiệm đèn đỏ ít nhất để tới i và j là thời gian tới i sau khi mod g
// để ý số lần chờ đèn đỏ = số lần đi đèn xanh
namespace sub1{
   
    void solve(){
    	deque <pii> dq;
    	
    	dq.push_front(mp(1,0));
    	dp[1][0] = 1;
    	int ans = INF;
    	
    	while(!dq.empty()){
    		int u = dq.front().fi, val = dq.front().se;
    		dq.pop_front();
    		
    		fod(x,-1,1) if(x){
    			int v = u + x;
    			if(!(1 <= v and v <= m)) continue;
    			int dis = abs(d[v] - d[u]);
    			if(v == m){
    				if(val + dis <= G){
    					// uống miếng nước ngẫm tí là hiểu
    					// lùi 1 lần đi lại vì mình sẽ đi cả val lẫn dis
    					// nếu k lùi thì số lần đi đỏ và xanh sẽ bị lệch
    					mini(ans, (dp[u][val] - 1) * (G + R) + val + dis);
    				}
    			}
    			else{
    				if(val + dis == G and dp[v][0] == 0){
    					// dựa vào nhận xét 
    					// nếu đã tới vị trí u ở thời điểm i (mod g) thì ta không nên tới lại vào
    					// thời điểm j(mod g) vì khi đó sẽ tạo thành 1 chu trình. => mỗi trạng thái chỉ nên đi 1 lần
    					// ở dưới cũng đi giống thế
    					// phải đứng chờ vì lúc này đèn sang màu đỏ
    					dp[v][0] = dp[u][val] + 1;
    					dq.pb(mp(v,0));
    				}
    				else if(val + dis < G and dp[v][val + dis] == 0){
    					// có thể đi tiếp => chi phí bằng 0
    					dp[v][val + dis] = dp[u][val];
    					dq.push_front(mp(v,val + dis));
    				}
    			}
    		}
    	}
    	
    	if(ans == INF) cout << -1;
    	else cout << ans;	
    }	
}
namespace sub2{
	
	void solve(){
	
	}
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); srand(time(0)); 
    if(fopen(name".inp", "r")){
      freopen(name".inp", "r", stdin);
      freopen(name".out", "w", stdout);
    }
    int Test = 1; if(multitest) cin >> Test;
    init();
    while(Test-- or endless){
        inp();
        sub1 :: solve();
        sub2 :: solve();
        if(endless) endless--;
    }
    kill();
}