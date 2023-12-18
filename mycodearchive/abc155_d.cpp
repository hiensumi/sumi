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
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 0, endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, k , a[base];
void inp(){
	cin >> n >> k;
	fod(i,1,n) cin >> a[i];
}
int pos[base], neg[base], zero[base], szpos, szneg, szzero;
int x, y , z;
namespace sub1{
	bool check1(int mid){
		reverse(pos + 1, pos + szpos + 1);
		int j = szneg, cnt = 0;
		fod(i,1,szpos){
			while(j >= 1 and pos[i] * neg[j] >= mid) j--;
			if(j < 1) break;
			cnt += j;
		}
		reverse(pos + 1, pos + szpos + 1);
		return cnt < k;
	}
	bool check2(int mid){
		int cnt = y, j = szpos;
		fod(i,1,szpos){
			while(j >= 1 and pos[i] * pos[j] >= mid) j--;
			if(j <= i) break;
			cnt += j - i;
		}
		j = szneg;
		reverse(neg + 1, neg + szneg + 1);
		fod(i,1,szneg){
			while(j >= 1 and neg[i] * neg[j] >= mid) j--;
			if(j <= i) break;
			cnt += j - i;
		}
		reverse(neg + 1, neg + szneg + 1);
		return cnt < k;
	}
    void solve(){
   		fod(i,1,n){
   			if(a[i] > 0) pos[++szpos] = a[i];
   			if(a[i] < 0) neg[++szneg] = a[i];
   			if(a[i] == 0) zero[++szzero] = a[i];
   		}
   		sort(pos + 1, pos + szpos + 1);
   		sort(neg + 1, neg + szneg + 1);
   		x = szneg * szpos, y = szzero * (szpos + szneg) + szzero * (szzero - 1) / 2, z = szneg * (szneg - 1)/2 + szpos * (szpos - 1)/2;
   		y += x;
   		z += y;
   		if(k > x and k <= y){ cout << 0; kill();}
    	if(k <= x){
    		int l = -INF, r = -1, ans = 0;
    		while(l <= r){
    			int mid = l + r >> 1;
    			if(check1(mid)) l = mid + 1, ans = mid;
    			else r = mid - 1;
    		}
    		cout << ans << el;
    	}
    	
    	else if(k > y and k <= z){
    		// cout << check2(6);
    		int l = 1, r = INF, ans = 0;
    		while(l <= r){
    			int mid = l + r >> 1;
    			if(check2(mid)) l = mid + 1, ans = mid;
    			else r = mid - 1;
    		}	
    		cout << ans << el;
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