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
int n, m, dis[2005][2005], dd[2005][2005];
char a[2005][2005], b[2005][2005];
ii tr[2005][2005];
ii start, ed;
int di1[] = {0,-1,1,0};
int di2[] = {-1,0,0,1};
struct bg{
	ii u;
	int val;
};
struct cmp{
	bool operator() (bg x, bg y){
		return x.val > y.val;
	}
};
void djikstra(int u, int v){
	memset(dis, 0x3f, sizeof dis);
	dis[u][v] = 0;
	priority_queue<bg, vector <bg>, cmp> pq;
	bg x = {make_pair(u,v), 0};
	pq.push(x);
	while(!pq.empty()){
		bg t = pq.top();
		ii p = t.u;
		int u = p.fi, v = p.se;
		int wei = t.val;
		pq.pop();
		if(dd[u][v]) continue;
		dd[u][v] = 1;
		fod(k,0,3){
			int x = u + di1[k], y = v + di2[k], w = 0;
			if(!(1 <= x and x <= n and 1 <= y and y <= m)) continue;
			if(a[u][v] == k) w = 0;
			else w = 1;
			if(u == start.fi and start.se == v) w = 0;
			if(dis[x][y] > dis[u][v] + w){
				tr[x][y] = {u,v};
				dis[x][y] = dis[u][v] + w;
				pq.push({make_pair(x,y), dis[x][y]});
			}
		}
	}
}
int convert(char c){
	int val;
	if(c == '>') val = 3;
	if(c == '<') val = 0;
	if(c == '^') val = 1;
	if(c == 'v') val = 2;
	if(c == '.') val = 4;
	return val;
}
char conv(int u){
	char c;
	if(u == 3) return '>';
	if(u == 0) return '<';
	if(u == 1) return '^';
	if(u == 2) return 'v';
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
	cin >>  n >> m;
	fod(i,1,n) fod(j,1,m){
		char c;
		cin >> c;
		b[i][j] = c;
		if(c == 'o') start = {i,j}, a[i][j] = 5;
		if(c == 'x') ed = {i,j}, a[i][j] = 5;
		if(c == '>') a[i][j] = 3;
		if(c == '<') a[i][j] = 0;
		if(c == '^') a[i][j] = 1;
		if(c == 'v') a[i][j] = 2;
		if(c== '.') a[i][j] = 4;
	}
	djikstra(start.fi, start.se);
	cout << dis[ed.fi][ed.se] << el;
	int x = ed.fi, y = ed.se;
	while(1){
		int u = tr[x][y].fi, v = tr[x][y].se;
		if(u == start.fi and v == start.se) break;
		int val = convert(b[u][v]);
		int diff1 = x - u, diff2 = y - v, id = 0;
		fod(i,0,3){
			if(diff1 == di1[i] and diff2 == di2[i]){
				id = i;
				break;
			}
		}
		if(val != id) b[u][v] = conv(id);
		x = u;
		y = v;
	}
	fod(i,1,n){
		fod(j,1,m) cout << b[i][j];
		cout << el;
	}
	kill();
}