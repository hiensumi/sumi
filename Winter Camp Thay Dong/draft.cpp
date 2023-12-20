// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
#include <cassert>
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
int n, q, a[base], k, cnt1 = 0;
int b1[base], b2[10][base];
struct DL{
	int type, id, c, l, r;
}qr[base];
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
vi pos; int m;

void inp(){
	cin >> n >> k >> q;
	if(n <= 1e6){
		fod(i,1,n) a[i] = i, add1(i,a[i]);
		fod(i,1,n){
			if(check(i,k)) add2(i,k,a[i]);
		}
	}
	fod(i,1,q){
		int type; cin >> type;
		if(type == 1){
			qr[i].type = 1;
			cin >> qr[i].id >> qr[i].c;
			cnt1++;
			pos.pb(qr[i].id);
		}
		else{
			qr[i].type = 2;
			cin >> qr[i].l >> qr[i].r;
			pos.pb(qr[i].l-1);
			pos.pb(qr[i].r);
		}
	}
	
	uni(pos);
	m = SZ(pos);
}

namespace sub1{
    void solve(){
    	fod(i,1,q){
    		int type = qr[i].type;
    		if(type == 1){
    			int id = qr[i].id, c = qr[i].c;
    			if(check(id,k)){
    				int x = get2(id, k);
    				if(id > 1) x -= get2(id-1,k);
    				add2(id, k, c - x);
    			}
    			int x = get1(id); if(x > 1) x -= get1(id-1);
    			add1(id, c - x);
    		}
    		else{
    			int l = qr[i].l, r = qr[i].r;
    			int res = get1(r); if(l > 1) res -= get1(l-1);
    			int add = get2(r,k); if(l > 1) add -= get2(l-1,k);
    			
    			cout << res + add << el;
    		}
    	}
    }	
}
namespace sub2{
	struct DL{
		int sl, sum;
	}dp[19][2][11];
	string s;
	int pw[base], sz = 0;
	DL calc(int i, int ok, int rem, int used){
	    if(i == sz + 1){
	    	if(rem == 0 or used){
	    		return {1,0};
	    	}
	    	else{
	    		return {0,0};
	    	}
	    }
	    if(dp[i][ok][rem].sl != -1) return dp[i][ok][rem];
	    int lim = ok ? 9 : s[i] - '0';
	    int cnt = 0, tong = 0;
	    fod(j,0,lim){
	    	DL ret = calc(i+1,ok || j < lim, (rem * 10 % k + j) % k, used || (j == k));
	    	cnt += ret.sl;
	    	tong += ret.sum + j * ret.sl * pw[sz-i]; 
	    }
	    return dp[i][ok][rem] = {cnt, tong};
	}
	int call(int id){
		fod(i,0,18) fod(j,0,1) fod(k,0,10) dp[i][j][k] = {-1,0};
		s = "#" + to_string(id);
		sz = SZ(s) - 1 ;
		return calc(1,0,0,0).sum;
	}
	void solve(){
		pw[0] = 1;
		fod(i,1,18) pw[i] = pw[i-1] * 10;	
		fod(i,1,q){
			int l = qr[i].l, r = qr[i].r;
			l--;
			cout << call(r) - call(l) + r * (r + 1)/2 - l * (l + 1)/2  << el;
		}
	}
}

namespace sub3{
	struct DL{
		int sl, sum;
	}dp[19][2][11][2];
	int bit[base], val[base], pw[19];
	void add(int idx, int x){
		int rem = x - val[idx];
		val[idx] = x;
		while(idx <= m){
			bit[idx] += rem;
			idx += idx & - idx;
		}
	}
	int get(int idx){
		int res = 0;
		while(idx){
			res += bit[idx];
			idx -= idx & -idx;
		}
		return res;
	}
	
	string s;
	int sz = 0;
	
	DL calc(int i, int ok, int rem, int used){
	    if(i > sz){
	    	if(rem == 0 or used == 1){
	    		return {1,0};
	    	}
	    	else{
	    		return {0,0};
	    	}
	    }
	    if(dp[i][ok][rem][used].sl != -1) return dp[i][ok][rem][used];
	    int lim = ok ? 9 : s[i] - '0';
	    int cnt = 0, tong = 0;
	    fod(j,0,lim){
	    	DL ret = calc(i+1,ok or j < lim, (rem * 10 % k + j) % k, used or (j == k));
	    	cnt += ret.sl;
	    	tong += ret.sum + j * ret.sl * bp(10,sz-i); 
	    }
	    return dp[i][ok][rem][used] = {cnt, tong};
	}
	
	int call(int id){
		fod(i,0,18) fod(j,0,1) fod(k,0,10) fod(h,0,1) dp[i][j][k][h] = {-1,0};
		s = "#" + to_string(id);
		sz = SZ(s) - 1 ;
		//+ get(vt )
		return calc(1,0,0,0).sum;
	}
	void solve(){
		pw[0] = 1;
		fod(i,1,18) pw[i] = pw[i-1] * 10;
		fod(i,1,q){
			int type = qr[i].type;
			if(type == 1){
				int id = qr[i].id, c = qr[i].c;
				int rem = c - id, vt = UB(all(pos), id) - pos.begin();
				if(check(id,k)) rem *= 2;
				add(vt , -rem);
			}
			else{
				int l = qr[i].l, r = qr[i].r;
				l--;
				//+ r * (r + 1) / 2 - l * (l + 1) / 2 
				int vt1 = UB(all(pos), r) - pos.begin();
				int vt2 = UB(all(pos), l) - pos.begin();
				cout << call(r) - call(l) + r * (r + 1) / 2 - l * (l + 1) / 2  << el;
			}
		}	
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
        // sub2 :: solve();
        // if(cnt1 > 0) sub1 :: solve();
        // else sub2 :: solve();
    	sub3 :: solve();
    }
    kill();
}
