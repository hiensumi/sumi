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
#define name "INCOME"
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = mask(20) + 10, INF = 1e18, multitest = 0; int endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, a[base];
pii qr[base];
void inp(){
	cin >> n;
	fod(i,1,n) cin >> a[i];
	fod(i,1,n) cin >> qr[i].fi >> qr[i].se;
}

namespace sub1{
	int b[505][505];
   	bool check(int mid){
   		fod(i,1,n) b[i][0] = a[i];
   		
   		fod(j,1,mid) fod(i,1,n){
   			b[i][j] = b[i][j-1];
   			
   			fod(k,qr[i].fi, qr[i].se) maxi(b[i][j], b[k][j-1]);
   		}
   		
   		fod(i,1,n) if(b[i][mid] != b[i][mid - 1]) return 0;
   		return 1;
   	}
    void solve(){
 		int l = 0, r = n, ans = 0;
 		
 		fod(mid,1,n) if(check(mid)) return void(cout << mid);
    }	
}
namespace sub2{
	
}
namespace sub3{
	ve <vi> g;
	int dis[base], dd[base];
	void bfs(vi x){
		queue <int> q;
		for(int y : x){
			dd[y] = 1;
			q.push(y);
		}
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int v : g[u]) if(!dd[v]){
				dis[v] = dis[u] + 1;
				q.push(v);
				dd[v] = 1;
			}
		}
	}
	ve <vi> pos;
	void solve(){
		g.resize(n+1);
		pos.resize(n + 1);
		fod(i,1,n){
			fod(j,qr[i].fi, qr[i].se) g[j].pb(i);
		}
		vi v; fod(i,1,n) v.pb(a[i]); uni(v);
		fod(i,1,n){
			int j = UB(all(v), a[i]) - v.begin();
			pos[j].pb(i);
		}
		
		fok(i,n,1) bfs(pos[i]);
		
		int res = 0;
		fod(i,1,n) maxi(res, dis[i]);
		cout << res + 1;
	}
}
namespace sub5{
	int pos[base];
	ve <pii> g[base];
	vi poss[base];
	void build(int i, int l, int r){
		if(l == r){
			pos[l] = i;
			return ;
		}
		g[2*i].pb(mp(i,0));
		g[2*i+1].pb(mp(i,0));
		int mid = l + r >> 1;
		build(2*i,l,mid);
		build(2*i+1,mid+1,r);
	}	
	
	void add(int i, int l, int r, int u, int v, int id){
		if(r < u or v < l) return;
		if(u <= l and r <= v){
			g[i].pb(mp(id,1));
			return ;
		}
		int mid = l + r >> 1;
		add(2*i,l,mid,u,v,id);
		add(2*i+1,mid+1,r,u,v,id);	
	}
	int dd[base], dis[base];
	void bfs(vi v){
		deque <int> dq;
		for(int x : v){
			dq.push_front(x);
			dd[x] = 1;
		}
		while(!dq.empty()){
			int u = dq.front();
			dq.pop_front();
			for(auto [v,w] : g[u]) if(!dd[v]){
				dd[v] = 1;
				if(w == 0){
					dis[v] = dis[u];
					dq.push_front(v);
				}
				else{
					dis[v] = dis[u] + 1;
					dq.pb(v);
				}
			}
		}
	}
	
	void solve(){
		build(1,1,n);
		fod(i,1,n){
			add(1,1,n,qr[i].fi,qr[i].se,pos[i]);
		}
		vi v; fod(i,1,n) v.pb(a[i]); uni(v);
		fod(i,1,n){
			int j = UB(all(v), a[i]) - v.begin();
			poss[j].pb(pos[i]);
		}
		
		fok(i,n,1){
			bfs(poss[i]);
		}
		
		int res = 0;
		fod(i,1,n) maxi(res, dis[pos[i]] + 1);
		
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
        // if(n <= 500) sub1 :: solve();
        // else sub3 :: solve();
        sub5 :: solve();
        if(endless) endless--;
    }
    kill();
}