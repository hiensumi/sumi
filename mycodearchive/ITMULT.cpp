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
int lazy[4*base], st[4*base], a[base], n;
void build(int i, int l, int r){
	if(l == r){
		st[i] = a[l];
		return;
	}
	int mid = (l + r)/2;
	build(2*i,l,mid);
	build(2*i+1,mid+1,r);
	st[i] = st[2*i] + st[2*i+1];
}
void update(int i, int l ,int r, int u, int v, int x){
	// u l r v
	if(lazy[i] != 1){
		st[i] *= lazy[i];
		if(l != r){
			lazy[2*i] *= lazy[i];
			lazy[2*i+1] *= lazy[i];
		}
		lazy[i] = 1;
	}
	if(r < u or v < l) return;
	if(u <= l and r <= v){
		st[i] *= x;
		if(l != r){
			lazy[2*i] *= x;
			lazy[2*i+1] *= x;
		}
		// lazy[i] = 1;
		return;
	}
	int mid = l + r >> 1;
	update(2*i,l,mid,u,v,x);
	update(2*i+1,mid+1,r,u,v,x);
	st[i] = st[2*i] + st[2*i+1];
}
int get(int i, int l, int r, int u, int v){
	// u l r v
	if(lazy[i] != 1){
		st[i] *= lazy[i];
		if(l != r){
			lazy[2*i] *= lazy[i];
			lazy[2*i+1] *= lazy[i];
		}
		lazy[i] = 1;
	}
	if(r < u or v < l) return 0;
	if(u <= l and r <= v) return st[i];
	int mid = l + r >> 1;
	return (get(2*i,l,mid,u,v) + get(2*i+1,mid+1,r,u,v));
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,4*base-1) lazy[i] = 1;
	fod(i,1,n) a[i] = 1;
	build(1,1,n);
	// 1 1 1 1 1 = 5
	// 2 2 2 1 1 = 6 + 2 = 8
	update(1,1,n,1,3,2);
	cout << get(1,1,n,1,n);
	return 0;
}
