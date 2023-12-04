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
#define name "formation"
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
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
int n, m, a[2005][2005], k;
vector<ii> soldier;
int get(ii x, ii y){
	return abs(x.fi - y.fi) + abs(x.se - y.se);
}
vector<int> ppp[2005];
void sub1(){
	int res = 0;	
	fod(i,1,n) fod(j,1,m){
		multiset <int> dist;
		for(ii x : soldier){
			int d = get(x,{i,j});
			if(dist.size() < k){
				dist.insert(d);
			}
			else{
				auto it = dist.end();
				--it;
				int p = *it;
				if(d < p){
					dist.erase(it);
					dist.insert(d);
				}
			}
		}
		for(int x : dist){
			res += x;
		}
	}
	cout << res;
}
int dis(int c, int r){
	if(!ppp[r].size()) return 1e14;
	int j = lower_bound(ppp[r].begin(), ppp[r].end(), c) - ppp[r].begin();
	int res = 1e14;
	if(j > 0) res = min(res, c - ppp[r][j-1]);
	if(j < ppp[r].size()) res = min(res, (int)ppp[r][j] - c);
	return res;
}
void sub2(){
	int res = 0;
	fod(x,1,n) fod(y,1,m){
		if(a[x][y]) continue;
		int dist = 1e14;
		fod(r,1,n){
			if(dist == 1) break;
			dist = min(dist, dis(y,r) + abs(r - x));
		}
		res += dist;
	}
	cout << res;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	else if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	cin >> n >> m >> k;
	fod(i,1,n) fod(j,1,m){
		cin >> a[i][j];
		if(a[i][j]){
			soldier.pb(make_pair(i,j));
			ppp[i].pb(j);
		}
	}
	if(max(n,m) <= 50 and k == 1){
		sub2();
		kill();
	}
	sub1();
	kill();
}
