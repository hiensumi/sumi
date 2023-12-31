// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
using namespace std; 
// #define            int  long long
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
#define name "ADN"
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 0; int endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n;
string s;
void inp(){
	cin >> s;
	n = SZ(s) - 1;
}

namespace sub1{
   	int calc(){
   		map <char, int> mp;
   		int l = 0, res = 0;
   		fod(r,0,n){
   			mp[s[r]]++;
   			while(mp.size() >= 2 and l <= r){
   				mp[s[l]]--;
   				if(mp[s[l]] <= 0) mp.erase(s[l]);
   				res += n - r + 1;
   				l++;
   			}
   			
   		}
   		return res;
   	}
   	
   	int dd[22];
    void solve(){
    	vi pos;
    	int cnt = 0;
    	fod(i,0,n) if(s[i] == '?') cnt++, pos.pb(i), dd[i] = 1;
    	if(cnt == n or cnt == n + 1) return void(cout << 0);
    	if(cnt == 0) return void(cout << calc());
    	
    	int tt = mask(cnt) - 1, res = INF;
    	fod(msk,0,tt){
    		
    		auto run = [&](int msk) -> int {
    			int poss = 0;
	    		for(int x : pos){
	    			if(x == 0 and BIT(msk, poss) == 0) return INF; 
	    			if(x == n and BIT(msk, poss) == 1) return INF;
	    			
	    			if(BIT(msk,poss) == 0){
	    				int cur = x - 1;
	    				while(cur >= 0){
	    					if(dd[cur] == 0) break;
	    					cur --;
	    				}
	    				
	    				if(cur == -1) return INF;
	    				
	    				s[x] = s[cur];
	    			}
	    			
	    			else{
	    				int cur = x + 1;
	    				while(cur <= n){
	    					if(dd[cur] == 0) break;
	    					cur++;
	    				}
	    				
	    				if(cur == n + 1) return INF;
	    				
	    				s[x] = s[cur];
	    			}
	    			
	    			poss++;
	    			if(poss == cnt) break;
	    		}
	    		
	    		// cout << s << " " << calc() << el;
	    		return calc();
    		};
    		
    		if(mini(res, run(msk))){
    			// cout << s << el;
    		}
    	}
    	
    	cout << res << el;
    }	
}
namespace sub2{
	int dp[5001][5001][4];
	ve <char> v = { 'A', 'T', 'G', 'X'};
	void solve(){
		fod(i,0,n) fod(j,1,i + 1){
			fod(p,0,3){
				char x = v[p];
				if(i and (s[i] == x or s[i] == '?')) dp[i][j][p] = dp[i-1][j-1][p] + j;
				
				fod(q,0,3){
					char y = v[q];
					if(x != y and s[i] == x){
						dp[i][1][p] = dp[i-1][j][q] + 1;
					}	
					else if(x != y and s[i] != x){
						dp[i][0][p] = dp[i-1][j][q] + 1;
					}
				}
			}
		}
		int res = 0 ;
		fod(j,1,n + 1) fod(c,0,3) maxi(res, dp[n][j][c]);
		n++;
		cout << n * (n + 1) / 2 - res << el; 
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
        // sub1 :: solve();
        sub2 :: solve();
        if(endless) endless--;
    }
    kill();
}