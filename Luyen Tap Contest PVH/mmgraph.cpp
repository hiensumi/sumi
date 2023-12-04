// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
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
#include<ctime>
#include<utility>
#include<vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define non 5000+1
#define pog 1000000000+7
#define db double
#define mask(i) (1LL<<(i))
#define BITpos(a,i) (a & mask(i))
#define pb push_back
#define el '\n'
#define odd(i) (i & 1LL)
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
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 505 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name "mmgraph"
namespace solution{
    int task, n, m, w[base], dis[base], inq[base];
    vector <ii> adj[base];
	void inp(){
		cin >> n >> m;
		fod(i,1,n) cin >> w[i];
		fod(i,1,m){
			int u, v, c;
			cin >> u >>v >> c;
			adj[u].pb({v,c});
			adj[v].pb({u,c});
		}
	}
	void spfa(int s){
		queue <int> q;
		fod(i,1,n) dis[i] = 1e18, inq[i] = 0;
		q.push(s);
		dis[s] = w[s];
		inq[s] = 1;
		while (!q.empty()) {
		    int u = q.front();
		    q.pop();
		    inq[u] = 0;
		    for(auto v : adj[u]) {
		        int to = v.first, we = v.second;
		        if (dis[to] > max(dis[u], w[to])){
		            dis[to] = max(dis[u], w[to]);
		            if (!inq[to]){
		                q.push(to);
		                inq[to] = 1;
		            }
		        }
		    }
		}
	}
	void spfa1(int s){
		queue <int> q;
		fod(i,1,n) dis[i] = 1e18, inq[i] = 0;
		q.push(s);
		dis[s] = 0;
		inq[s] = 1;
		while (!q.empty()) {
		    int u = q.front();
		    q.pop();
		    inq[u] = 0;
		    for(auto v : adj[u]) {
		        int to = v.first, we = v.second;
		        if (dis[to] > max(dis[u], we)){
		            dis[to] = max(dis[u], we);
		            if (!inq[to]){
		                q.push(to);
		                inq[to] = 1;
		            }
		        }
		    }
		}
	}
	int d[base];
	struct path{
		int u;
		set <int> node;
		set <int> pat;
		int manode(){
			if(node.size() == 0) return 0;
			return *node.rbegin();
		}
		int mapath(){
			if(pat.size() == 0) return 0;
			return *pat.rbegin();
		}
		int val(){
			return manode() * mapath();
		}
	};
	struct cmp{
		bool operator() (path a, path b){
			// if(a.manode() * a.mapath() == b.manode() * b.mapath()) return a.manode() > b.manode();
			return a.manode() * a.mapath() > b.manode() * b.mapath();
		}
	};
	int dd[base];
	void spfas(int s){
		fod(i,1,n) d[i] = 1e18 + 2, dd[i] = 0;
		priority_queue <path, vector <path>, cmp> pq;
		// dd[s] = 1;
		d[s] = 0;
		pq.push({s, {w[s]}, {}});
		while(pq.size()){
			path x = pq.top();
			pq.pop();
			if(dd[x.u]) continue;
			dd[x.u] = 1;
			for(auto v : adj[x.u]){
				int to = v.fi, we = v.se;
				int weight = max(w[to], x.manode()) * max(we, x.mapath());
				if(d[to] > weight){
					d[to] = weight;
					path y = x;
					y.u = to;
					y.node.insert(w[to]);
					y.pat.insert(we);
					pq.push(y);
				}
			}
		}
	}
	void sub1(){
		fod(i,1,n){
			int res = 0;
			cout << n - 1 << " ";
		}
	}
	void sub2(){
		fod(i,1,n){
			int res = 0;
			spfa1(i);
			fod(j,1,n) res += dis[j];
			cout << res << " "; 
		}
	}
	void sub3(){
		fod(i,1,n){
			int res = 0;
			spfa(i);
			fod(j,1,n) if(i != j) res += dis[j];
			cout << res << " ";
		}
	}
	void sub4(){
		fod(i,1,n){
			int res = 0;
			spfas(i);
			fod(j,1,n) if(j != i) res += d[j];
			cout << res << " ";
		}
	}
	void solve(){
		cin >> task; inp();
		if(task == 1) sub1();
		else if(task == 2) sub2();
		else if(task == 3) sub3();
		else if(task == 4) sub4();
	}
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
	int Test = 1; if(multitest)cin >> Test; 
	while(Test--)solution :: solve();
	kill();
}