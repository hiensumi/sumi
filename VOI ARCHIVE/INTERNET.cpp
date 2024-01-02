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
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
#define name "INTERNET"
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 0; int endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n ,s , k;
int lab[base];
int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u; return 1;} 
point a[base];
int ok2 = 1, ok3 = 1;
void inp(){
	int MIX = INF, MAX = -INF;
	int MIY = INF, MAY = -INF;
	cin >> n >> s >> k;
	fod(i,1,n){
		cin >> a[i].x >> a[i].y; 
		maxi(MAX, a[i].x); mini(MIX, a[i].x);
		maxi(MAY, a[i].y); mini(MIY, a[i].y);
		if(a[i].x > 1000 or a[i].y > 1000) ok3 = 0;
	}
	
	if(MAX == MIX) ok2 = 1;
	else if(MAY == MIY) ok2 = 2;
	else ok2 = 0;
		
}

namespace sub1{
   ve <edge> e;
    void solve(){
    	fod(i,1,n) fod(j, i + 1,n){
    		e.pb(edge{i,j, abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y)});
    	}
    	
    	sort(all(e), [&] (edge a, edge b){
    		return a.c < b.c;
    	});
    	int res =0 ;
    	memset(lab, -1, sizeof lab);
    	for(auto [u,v,c] : e){
    		if(join(u,v) and c > s){
    			res += c;
    			k--;
    			if(k == 0) break;
    		}
    	}
    	
    	cout << res;
    }	
}

namespace sub2{
		
	ve <edge> e;
    void solve(){
    	if(ok2 == 1){
    		sort(a + 1, a + n + 1, [&] (point a, point b){
    			return a.y < b.y;	
    		});
    	}
    	else{
    		sort(a + 1, a + n + 1, [&] (point a, point b){
    			return a.x < b.x;	
    		});
    	}
    	
		fod(i,2,n) e.pb(edge{i,i-1,abs(a[i].x - a[i-1].x) + abs(a[i].y - a[i-1].y)});
    	
    	sort(all(e), [&] (edge a, edge b){
    		return a.c < b.c;
    	});
    	int res =0 ;
    	memset(lab, -1, sizeof lab);
    	for(auto [u,v,c] : e){
    		if(join(u,v) and c > s){
    			res += c;
    			k--;
    			if(k == 0) break;
    		}
    	}
    	cout << res;
    }
}
namespace sub3{
	template <typename T>
	vector<tuple<T, int, int>> manhattan_mst(vector<T> xs, vector<T> ys) {
	    const int n = xs.size();
	    vector<int> idx(n);
	    iota(idx.begin(), idx.end(), 0);
	    vector<tuple<T, int, int>> ret;
	    for (int s = 0; s < 2; s++) {
	        for (int t = 0; t < 2; t++) {
	            auto cmp = [&](int i, int j) { return xs[i] + ys[i] < xs[j] + ys[j]; };
	            sort(idx.begin(), idx.end(), cmp);
	            map<T, int> sweep;
	            for (int i : idx) {
	                for (auto it = sweep.lower_bound(-ys[i]); it != sweep.end(); it = sweep.erase(it)) {
	                    int j = it->second;
	                    if (xs[i] - xs[j] < ys[i] - ys[j]) break;
	                    ret.emplace_back(abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]), i, j);
	                }
	                sweep[-ys[i]] = i;
	            }
	            swap(xs, ys);
	        }
	        for (auto &x : xs) x = -x;
	    }	
	    sort(ret.begin(), ret.end());
	    return ret;
	}
	void solve(){
		vi xs, ys;
		fod(i,1,n) xs.pb(a[i].x), ys.pb(a[i].y);
		
		auto ret = manhattan_mst(xs,ys);
		memset(lab, 255, sizeof lab);
		int res = 0;
		for(auto [c, u , v] : ret){
			if(join(u,v) and c > s){
				res += c;
				k--;
				if(k == 0) break;
			}
		}
		
		cout << res;	
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
        sub3 :: solve();
        // if(n <= 2000)sub1 :: solve(), kill();
        // if(ok3) sub3 :: solve(), kill();
        // assert(ok2 > 0);
        // sub2 :: solve();
        if(endless) endless--;
    }
    kill();
}