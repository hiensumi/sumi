// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
// #define int long long
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
struct point{double x, y;};
struct edge{int u, v, c;};
//int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
//bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u; return 1;}
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
// This code is learned from Asamai
int n, h;
point a[base];
ld ccw(point a, point b, point c){
	return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
ld LeftCut(point left, point right){
	ld AC = fabs(left.y - right.y);
	ld BC = fabs(left.x - right.x);
	ld DE = fabs((h - AC - right.y) * BC / AC);
	ld E = left.x - DE;
	return E;
}
ld RightCut(point left, point right){
	ld AB = fabs(right.y - left.y);
	ld BC = fabs(right.x - left.x);
	ld DE = (h - AB - left.y) * BC / AB;
	ld E = right.x + DE;
	return E;
}
ld Cut(point A, point B) {
    ld a = (ld) (A.y - B.y) / (A.x - B.x); // => AB / BC 
    ld b = A.y - a * A.x; // => AB - AB * FB / BC
    return (h - b) / a;
}
void inp(){
	cin >> n >> h;
	fod(i,1,n) cin >> a[i].x >> a[i].y;	
}
#define pld pair<ld, ld>
namespace sub_task1{
	int l[base] , r[base];
    void solve(){
    	vector <int> left, right;
    	left.pb(2); // khi xet (2,3,4), (3,4,5)...
    	right.pb(n-1); // tuong tu
    	fod(i,2,n-1){
    		while(left.size() >= 2 and ccw(a[left.rbegin()[1]], a[left.back()], a[i]) > 0){
    			left.pop_back();
    		}
    		if(odd(i)){
    			l[i] = left.back();
    		}
    		left.pb(i);
    	}
    	
    	fok(i,n-1,2){
    		while(right.size() >= 2 and ccw(a[right.rbegin()[1]], a[right.back()], a[i]) < 0){
    			right.pop_back();
    		}
    		if(odd(i)){
    			r[i] = right.back();
    		}
    		right.pb(i);
    	}
    	vector <pld> seg;
    	fod(i,2,n-1) if(odd(i)){
    		seg.pb(pld(LeftCut(a[l[i]], a[i]), RightCut(a[i], a[r[i]])));
    	}
    	
    	sort(all(seg));
    	ld cur = -INF;
    	int res = 0;
    	for(auto x : seg){
    		if(cur < x.fi){
    			res++;
    			cur = x.se;
    		}
    		else{
    			mini(cur, x.se);
    		}
    	}
    	
    	cout << res;
    	// This solution is learned from Asamai's code
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