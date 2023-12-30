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
int n, m, a[503][503];
ve <pii> dir = {
	{-1,0}, {1,0}, {0,1}, {0,-1}
};
void inp(){
	cin >> n >> m;
	fod(i,1,n) fod(j,1,m){
		char c; cin >> c;
		a[i][j] = (c == '#');
	}
}

namespace sub1{
   	struct DL{
   		int val;
   		int x, y;
   		set <pii> broken;
   	};
   	struct cmp{
   		bool operator() (DL a, DL b){
   			return a.val > b.val;
   		}
   	};
   	int dis[701][701];
   	bool nt(int x, int y){
   		return 1 <= x and x <= n and 1 <= y and y <= m;
   	}
    void dji(int u, int v){
    	fod(i,1,n) fod(j,1,m) dis[i][j] = INF;
    	dis[u][v] = 0;
    	priority_queue <DL, ve <DL>, cmp> pq;
    	pq.push({0,u,v,set<pii>()});
    	
    	while(!pq.empty()){
    		DL X = pq.top(); pq.pop();
    		int u = X.x, v = X.y, val = X.val;
    		if(dis[u][v] < val) continue;
    		for(pii go : dir){
    			int x = u + go.fi, y = v + go.se;
    			if(!nt(x,y)) continue;
    			int flag = (X.broken.find(mp(x,y)) != X.broken.end());
    			
    			if((a[x][y] == 0 or flag == 1) and mini(dis[x][y], dis[u][v])){
    				pq.push({dis[x][y], x, y, X.broken});
    				continue;
    			}
    			if(flag == 0 and a[x][y]){
    				set <pii> tmp;
    				tmp.insert(mp(x,y));
    				
    				set <pii> nbr = tmp;
    				
    				int x1 = x + 0, y1 = y + 1;
    				int x2 = x + 1, y2 = y + 1;
    				int x3 = x + 1, y3 = y + 0;
    				
    				if(a[x1][y1] and nt(x1,y1)) nbr.insert(mp(x1,y1));
    				if(a[x2][y2] and nt(x2,y2)) nbr.insert(mp(x2,y2));
    				if(a[x3][y3] and nt(x3,y3)) nbr.insert(mp(x3,y3));
    				if(mini(dis[x][y], dis[u][v] + 1)) pq.push({dis[x][y], x, y, nbr});
    				if(mini(dis[x1][y1], dis[u][v] + 1) and nt(x1,y1)) pq.push({dis[x1][y1], x1, y1, nbr});
    				if(mini(dis[x2][y2], dis[u][v] + 1) and nt(x2,y2)) pq.push({dis[x2][y2], x2, y2, nbr});
    				if(mini(dis[x3][y3], dis[u][v] + 1) and nt(x3,y3)) pq.push({dis[x3][y3], x3, y3, nbr});
    				
    				nbr = tmp;
    				x1 = x - 1, y1 = y + 0; 
    				x2 = x - 1, y2 = y + 1;
    				x3 = x + 0, y3 = y + 1;
    				
    				if(a[x1][y1] and nt(x1,y1)) nbr.insert(mp(x1,y1));
    				if(a[x2][y2] and nt(x2,y2)) nbr.insert(mp(x2,y2));
    				if(a[x3][y3] and nt(x3,y3)) nbr.insert(mp(x3,y3));
    				if(mini(dis[x][y], dis[u][v] + 1)) pq.push({dis[x][y], x, y, nbr});
    				if(mini(dis[x1][y1], dis[u][v] + 1) and nt(x1,y1)) pq.push({dis[x1][y1], x1, y1, nbr});
    				if(mini(dis[x2][y2], dis[u][v] + 1) and nt(x2,y2)) pq.push({dis[x2][y2], x2, y2, nbr});
    				if(mini(dis[x3][y3], dis[u][v] + 1) and nt(x3,y3)) pq.push({dis[x3][y3], x3, y3, nbr});	
    			
    				nbr = tmp;
    				x1 = x - 1, y1 = y - 1; 
    				x2 = x - 0, y2 = y - 1;
    				x3 = x - 1, y3 = y - 0;
    				
    				if(a[x1][y1] and nt(x1,y1)) nbr.insert(mp(x1,y1));
    				if(a[x2][y2] and nt(x2,y2)) nbr.insert(mp(x2,y2));
    				if(a[x3][y3] and nt(x3,y3)) nbr.insert(mp(x3,y3));
    				if(mini(dis[x][y], dis[u][v] + 1)) pq.push({dis[x][y], x, y, nbr});
    				if(mini(dis[x1][y1], dis[u][v] + 1) and nt(x1,y1)) pq.push({dis[x1][y1], x1, y1, nbr});
    				if(mini(dis[x2][y2], dis[u][v] + 1) and nt(x2,y2)) pq.push({dis[x2][y2], x2, y2, nbr});
    				if(mini(dis[x3][y3], dis[u][v] + 1) and nt(x3,y3)) pq.push({dis[x3][y3], x3, y3, nbr});	
    			
    				nbr = tmp;
    				x1 = x - 0, y1 = y - 1; 
    				x2 = x + 1, y2 = y - 1;
    				x3 = x + 1, y3 = y + 0;
    				
    				if(a[x1][y1] and nt(x1,y1)) nbr.insert(mp(x1,y1));
    				if(a[x2][y2] and nt(x2,y2)) nbr.insert(mp(x2,y2));
    				if(a[x3][y3] and nt(x3,y3)) nbr.insert(mp(x3,y3));
    				if(mini(dis[x][y], dis[u][v] + 1)) pq.push({dis[x][y], x, y, nbr});
    				if(mini(dis[x1][y1], dis[u][v] + 1) and nt(x1,y1)) pq.push({dis[x1][y1], x1, y1, nbr});
    				if(mini(dis[x2][y2], dis[u][v] + 1) and nt(x2,y2)) pq.push({dis[x2][y2], x2, y2, nbr});
    				if(mini(dis[x3][y3], dis[u][v] + 1) and nt(x3,y3)) pq.push({dis[x3][y3], x3, y3, nbr});	
    			}
    		}
    	}
    }
    void solve(){
    	dji(1,1);
    	
    	cout << dis[n][m];
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