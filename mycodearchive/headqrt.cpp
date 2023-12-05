// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
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
//int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
//bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u; return 1;}
const ll INF = 1e18, base = 1e6 + 5, multitest = 1;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n; point a[base];
int ccw(point a, point b, point c){
	return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
int kc(point a, point b){
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}
vector <point> comp[2];
vector <point> hull(vector <point> p){
	int m = 2;
	vector <point> h(p.size() + 2), res;
	
	sort(all(p), [&](point a, point b){
		if(a.y == b.y) return a.x < b.x;
		return a.y < b.y;
	});
	
	point p1 = p[0];
	
	sort(p.begin() + 1, p.end(), [&](point a, point b){
		if(ccw(p1,a,b) == 0) return kc(p1, a) < kc(p1,b);
		return ccw(p1,a,b) > 0;
	});
	
	int sz = p.size();
	p.pb(p[0]);
	// for(point a : p) cout << a.x << " " << a.y << el;
	h[1] = p[0]; h[2] = p[1];
	
	fod(i,2,sz){
		// cout << p[i].x << " " << p[i].y << el;
		while(m > 2 and ccw(h[m-1],h[m],p[i]) <= 0) m--;
		h[++m] = p[i];
	}
	m--;
	fod(i,1,m) res.pb(h[i]);
	return res;
}
void inp(){
	comp[0].clear();
	comp[1].clear();
	cin >> n;
	fod(i,1,n){
		int x,y,t; cin >> x >> y >> t;
		comp[t].pb({x,y});
	}
}

namespace sub_task1{
    int dist(vector <point> a, vector<point> b){
    	int res = -INF;
    	for(point x : a) for(point y : b){
    		maxi(res, (int)(kc(x,y)));
    	}	
    	res = sqrt(res);
    	return res;
    }
    void solve(){
 		cout << dist(hull(comp[0]), hull(comp[1])) << el;
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