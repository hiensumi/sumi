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
int n, a[base], m, l[base], r[base], b[base];
int solve(int a[], int n){
	stack <int> s;
	fod(i,1,n){
		while(!s.empty() and a[s.top()] >= a[i]) s.pop();
		if(s.empty()) l[i] = 1;
		else l[i] = s.top() + 1;
		s.push(i);
	}
	while(!s.empty()) s.pop();
	fok(i,n,1){
		while(!s.empty() and a[s.top()] >= a[i]) s.pop();
		if(s.empty()) r[i] = n;
		else r[i] = s.top() - 1;
		s.push(i);
	}
	int res = -1e18;
	fod(i,1,n){
		res = max(res, a[i] * (r[i] - l[i] + 1));
	}
	int le = 1e18, ri = 1e18;
	fod(i,1,n){
		if(res == a[i] * (r[i] - l[i] + 1)){
			if(le > l[i]){
				le = l[i];
				ri = r[i];
			}
		}
	}
	return res;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> m;
	fod(i,1,m) cin >> a[i], b[i] = n - a[i];
	cout << max(solve(a,m), solve(b,m));
	return 0;
}
