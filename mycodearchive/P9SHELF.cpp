// hiensumi is on the sky
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<time.h>
#include<utility>
#include<vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define name ""
#define non 5000+1
#define pog 1000000000+7
#define db double
#define mask(i) (1LL<<(i))
#define pb push_back
#define el '\n'
using namespace std;
void read(){}
void read(long long& a){scanf("%lld",&a);}
void read(long& a){scanf("%ld",&a);}
void read(double& a){scanf("%lf",&a);}
void read(float& a){scanf("%f",&a);}
void read(string& a){cin>>a;}
template<typename x,typename y>void read(pair<x,y>& a){ read(a.first),read(a.second);}
template<typename x>void read(x& a){for(auto  &i : a) read(i);}
template<typename x,typename... y>void read(x& a,y&... b){read(a);read(b...);}
const int oo = 1e18 + 1 + 2 + 3 + 4 + 5 + 12345678910;
typedef pair<int, int> ii;
struct point{
	int x, y;
	point operator- (const point& a)const{
		return {(x - a.x), (y - a.y)};
	}
	int operator* (const point& a)const{
		return x * a.y - y * a.x;
	}
};
struct edge{
	int u, v, c;
};
/*int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}
bool join(int u, int v) {
    int paru = find(u), parv = find(v);
    if (paru == parv) return false;
    par[parv] = paru;
    return true;
}*/	
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e6 + 5;
// dont use write like write("abc"). use it like write(x). x is the string variable
// dont use write like write(5). use it like write((int) 5). write(1e18) or any other float variables is fine
int n, height[base];
// struct shelf{
// 	int x, y;
// }a[base];
struct line{
	int x1, x2 , y;
}b[base];
set <ii> a;
bool cmp1(line a, line b){
	return a.y < b.y;
}
vector <int> v;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	else if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	int m = 0;
	cin >> n;
	fod(i,1,n){
		int x1,x2,y; cin >> x1 >> x2 >> y;
		b[i] = {x1,x2,y};
		// a[++m] = {x1,y};
		// a[++m] = {x2,y};
		a.insert({y,x1});
		a.insert({y,x2});
	}	
	sort(b+1,b+n+1,cmp1);
	b[0] = {(int)-2e9,(int)2e9,0};
	int res = 0;
	// fod(i,1,m){
	// 	int id = lower_bound(height+1,height+n+1,a[i].y) - height - 1;
	// 	fok(j,id,0){
	// 		if(b[j].x1 <= a[i].x and a[i].x <= b[j].x2){
	// 			res += a[i].y - b[j].y;
	// 			break;
	// 			// cout << a[i].y << " " << b[j].y << el;
	// 		}
	// 	}
	// }
	fod(i,1,n){
		// int id = upper_bound(height + 1, height + n + 1, b[i].y) - height;
		auto it = a.upper_bound({b[i].y,0});
		// fod(j,id,m){
		// 	if(b[i].x1 <= a[j].x <= b[i].x2){
		// 		res += a[j].y - b[i].y;
		// 	}
		// }
		while(it != a.end()){
			ii x = *it;
			if(x.fi > b[i+1].y) break; 
			if(b[i].x1 <= x.se and x.se <= b[i].x2){

			}
		}
	}
	cout << res;
	// auto it = a.upper_bound({0,0});
	// a.erase(it);
	// for(ii x : a){
	// 	cout << x.fi << " " << x.se << el;
	// }
	kill();
}
