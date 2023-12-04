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
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
int n, d, ans = 0, mark[3005][3005], dd[3005][3005], dis[3005][3005];
int di1[] = {0,-1,1,0};
int di2[] = {-1,0,0,1};
void djikstra(int u, int v){
	memset(dis, 0x3f, sizeof dis);
	dis[u][v] = 0;
	queue <ii> pq;
	pq.push({u,v});
	while(!pq.empty()){
		ii p = pq.front();
		int u = p.fi, v = p.se;
		pq.pop();
		if(dd[u][v]) continue;
		dd[u][v] = 1;
		fod(k,0,3){
			int x = u + di1[k], y = v + di2[k], w = 1;
			if(!(0 <= x and x <= 2005 and 0 <= y and y <= 2005) or mark[x][y]) continue;
			if(dis[x][y] > dis[u][v] + w){
				dis[x][y] = dis[u][v] + w;
				pq.push(make_pair(x,y));
			}
		}
	}
}
int calc(int x){
	return max(0LL,x * (x-1) >> 1);
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
	cin >> n >> d;
	fod(i,1,n){
		int x, y; cin >> x >> y;
		x += 1000;
		y += 1000;
		mark[x][y] = 1;
	}
	djikstra(1000,1000);
	fod(i,0,2000) fod(j,0,2000){
		if(dis[i][j] <= d) ans++;
	}
	fod(i,0,2000){
		ans += (max(0LL, d - dis[0][i])) + (max(0LL, d - dis[2000][i]));
		ans += (max(0LL, d - dis[i][0])) + (max(0LL, d - dis[i][2000]));
	}
	ans += calc(max(0LL, d - dis[0][0]));
	ans += calc(max(0LL, d - dis[0][2000]));
	ans += calc(max(0LL, d - dis[2000][0]));
	ans += calc(max(0LL, d - dis[2000][2000]));
	cout << ans;
	kill();
}
