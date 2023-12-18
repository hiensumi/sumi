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
#define pra(a,n) fod(_i,1,n)cout<<a[_i]<<el;cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<el; cout<<el; 
struct point{int x, y;};
struct edge{int u, v, c;};
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 0, endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, q, a[base], k;
int b1[base], b2[10][base];
void add1(int idx, int val){
	while(idx <= n){
		b1[idx] += val;
		idx += idx & -idx;
	} 
}
int get1(int idx){
	int res = 0;
	while(idx){
		res += b1[idx];
		idx -= idx & -idx;
	}
	return res;
}
void add2(int idx, int k, int val){
	while(idx <= n){
		b2[k][idx] += val;
		idx += idx & -idx;
	} 
}
int get2(int idx, int k){
	int res = 0;
	while(idx){
		res += b2[k][idx];
		idx -= idx & -idx;
	}
	return res;
}
bool check(int a, int k){
	if(k == 0) return 0;
	if(k == 1) return 1;
	int res = 0;
	string n = to_string(a);
	for(char c : n){
		int val = c - '0';
		if(val == k) return 1;
		res = ( (res * 10) % k + val) % k;
	}
	return res == 0;
}
void inp(){
	cin >> n >> k >> q;
	fod(i,1,n) a[i] = i, add1(i,a[i]);
	fod(i,1,n){
		if(check(i,k)) add2(i,k,a[i]);
	}
	
}

namespace sub1{
   
    void solve(){
    	while(q--){
    		int type;  cin >> type;
    		if(type == 1){
    			int id, c; cin >> id >> c;
    			if(check(id,k)){
    				int x = get2(id, k);
    				if(id > 1) x -= get2(id-1,k);
    				add2(id, k, c - x);
    			}
    			int x = get1(id); if(x > 1) x -= get1(id-1);
    			add1(id, c - x);
    		}
    		else{
    			int l, r; cin >> l >> r;
    			int res = get1(r); if(l > 1) res -= get1(l-1);
    			int add = get2(r,k); if(l > 1) add -= get2(l-1,k);
    			
    			cout << res + add << el;
    		}
    	}
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
    }
    kill();
}