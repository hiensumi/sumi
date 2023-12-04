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
int n, m, q, dist[1005][1005], dd[1005][1005];
ii a[1005][1005];
int di1[] = {-1,0,1,0};
int di2[] = {0,-1,0,1};
int nt(int x, int y){
	return 1 <= x and x <= n and 1 <= y and y <= m;
}
struct bg{
	int x, y, wei;
};
struct cmp{
	bool operator() (bg x, bg y){
		return x.wei > y.wei;
	}
};
int solve(int x, int y, int u, int v){
	int id1 = min({x,y,u,v}) - 10, id2 = max({x,y,u,v}) + 10;
	fod(i,id1,id2) fod(j,id1,id2) if(nt(i,j)) dist[i][j] = 1e16, dd[i][j] = 0;
	// memset(dist, 0x3f, sizeof dist);
	// memset(dd, 0, sizeof dd);
	dist[x][y] = 0;
	priority_queue<bg, vector<bg>, cmp> pq;
	pq.push({x,y,0});
	while(!pq.empty()){
		bg p = pq.top();
		pq.pop();
		int x = p.x, y = p.y, wei = p.wei;
		if(dd[x][y]) continue;
		dd[x][y] = 1;
		fod(i,0,3){
			int u = x + di1[i];
			int v = y + di2[i];
			if(id1 <= u and u <= id2 and id1 <= v and v <= id2 and nt(u,v)){
				int dis = 0;
				if(di1[i] == a[x][y].fi and di2[i] == a[x][y].se) dis = 1;
				else if(di1[i] != a[x][y].fi and di2[i] != a[x][y].se) dis = 2;
				else dis = 3;
				if(dist[u][v] > dist[x][y] + dis){
					dist[u][v] = min(dist[x][y] + dis, dist[u][v]);
					pq.push({u,v,dist[u][v]});
				}
			}
		}
	}
	return dist[u][v];	
}
signed main(){
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	else if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	scanf("%lld %lld %lld", &n, &m, &q);
	fod(i,1,n) fod(j,1,m){	 
		char c;
		scanf(" %c", &c);
		if(c == 'N') a[i][j] = {-1,0};
		if(c == 'W') a[i][j] = {0,-1};
		if(c == 'E') a[i][j] = {0,1};
		if(c == 'S') a[i][j] = {1,0};
	}
	while(q--){
		int x, y, u, v;
		scanf("%lld %lld %lld %lld", &x, &y, &u, &v);
		// cout << solve(x,y,u,v) << el;
		printf("%lld\n", solve(x,y,u,v));
	}
	kill();
	return 0;
}