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
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
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
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e5 + 10;
int n, m, h[base], par[base], dd[base], p[base][25], mi[base][25], ma[base][25], f[base];
vector <ii> adj[base];
void dfs(int u, int cha){
    for(auto [v,w] : adj[u]){
        if (v == cha) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        mi[v][0] = ma[v][0] = w;
        fod(j,1,log2(n)){
            p[v][j] = p[p[v][j-1]][j-1];
            mi[v][j] = min(mi[v][j-1], mi[p[v][j-1]][j-1]);
            ma[v][j] = max(ma[v][j-1], ma[p[v][j-1]][j-1]);
        } 
        dfs(v,u);
    }
}
int lca(int u, int v){
    if (h[u] < h[v]) swap(u,v);
    int k = h[u] - h[v];
    for(int j = 0; (1 << j) <= k; j++) if(k & (1 << j)) u = p[u][j];
    if (u == v) return u;
    int d = log2(h[u]);
    fok(j,d,0) if (p[u][j] != p[v][j]){
        u = p[u][j]; v = p[v][j];
    }
    return p[u][0];
}
int getmin(int u, int cha){
    int res = 1e18;
    int k = h[u] - h[cha];
    for(int j = 0; (1 << j) <= k; j++) if(k & (1 << j)){
            res = min(res, mi[u][j]);
            u = p[u][j];
    }
    return res;
}
int getmax(int u, int cha){
    int res = -1e18;
    int k = h[u] - h[cha];
    for(int j = 0; (1 << j) <= k; j++) if(k & (1 << j)){
            res = max(res, ma[u][j]);
            u = p[u][j];
    }
    return res;
}
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
    cin >> n;
    fod(i,1,n-1){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    fod(i,1,n) par[i] = i;
    dfs(1,0);
    // fod(j,1,20) fod(i,1,n){
    //     mi[i][j] = min(mi[i][j-1], mi[p[i][j-1]][j-1]);
    //     ma[i][j] = max(ma[i][j-1], ma[p[i][j-1]][j-1]);        
    //     p[i][j] = p[p[i][j-1]][j-1];
    // }
    cin >> m;
    fod(i,1,m){
        int u, v; cin >> u >> v;
        int x = lca(u,v);
        cout << min(getmin(u,x), getmin(v,x)) << " " << max(getmax(u,x), getmax(v,x)) << endl;
    }
    cerr << "\nTime: " << clock() << "ms\n";
    cerr << "Code now ->قَمَر \n";
    return 0;
}
