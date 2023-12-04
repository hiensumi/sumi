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
int mi[base], ma[base], n, a[base], k, l[base], r[base];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> k;
	fod(i,1,n) cin >> a[i];
	ma[n+1] = -1e18;
	fok(i,n,1) ma[i] = max(ma[i+1], a[i]);
	mi[0] = 1e18;
	fod(i,1,n) mi[i] = min(mi[i-1], a[i]);
	int res = -1e18;
	fod(i,2,n) res = max(res, ma[i] - mi[i-1]);
	res = max(res, 0LL);
	if(res == 0){
		cout << 0;
		return 0;
	}
	if(k == 1){
		cout << max(res, 0LL);
	}
	else{
		int res2 = -1e18;
		l[1] = 0;
		fod(i,2,n){
			l[i] = max(l[i-1], a[i] - mi[i-1]);
		}
		fok(i,n-1,1) r[i] = max(r[i+1], ma[i+1] - a[i]);
		fod(i,1,n-1) res2 = max(res2, l[i] + r[i+1]);
		cout << max(res2, 0LL);
	}
	return 0;
}
