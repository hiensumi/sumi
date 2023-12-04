#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define name ""
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
struct point{
	int x, y;
};
struct edge{
	int u, v;
    vector<int> par;
    void init(int n) {
        par.resize(n + 5, 0);
        fod(i,1,n) par[i] = i;
    }
    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    bool join(int u, int v) {
        int paru = find(u), parv = find(v);
        if (paru == parv) return false;
        par[parv] = paru;
        return true;
    }	
};
const int base = 1e6 + 5;
vector <int> adj[base];
int f[base], lowest = 0, way = 0, h[base];
void dfs(int u, int p){
	for(int x : adj[u]){
		if(x == p) continue;
		h[x] = h[u] + 1;
		if(h[x] > h[lowest]) lowest = x;
		dfs(x,u);
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	string s; cin >> s;
	s = "#" + s;
	int n = s.size() - 1;
	deque <int> dq;
	int node = 0;
	fod(i,1,n){
		if(s[i] == '('){
			dq.push_back(++node);
		}
		else{
			// node++;
			int x = dq.back(), xx = 0 ;
			dq.pop_back();
			if(dq.size() > 0){
				// dq.pop_back();
				xx = dq.back();
			}
			if(xx != 0) adj[x].pb(xx), adj[xx].pb(x);
			// cout << x << " " << node << endl;
			// a[x][node] = 1;
			// a[node][x] = 1;
		}
	}
	dfs(1,0);
	fod(i,1,node) h[i] = 0;
	dfs(lowest,0);
	cout << h[lowest]; 
	return 0;
}
