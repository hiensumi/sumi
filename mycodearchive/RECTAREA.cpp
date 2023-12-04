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
struct rect{
	point left, right;
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
int n;
rect a[base];
int check(point a, point b){
	int ax = a.x;
	if(a.x < b.x and a.y < b.y) return 1;
	if(ax < b.x and a.y > b.y) return 2;
}
rect trans(rect a){
	int c = check(a.left, a.right);
	if(c == 1) return a;
	else{
		rect b = {{a.left.x,a.right.y}, {a.right.x, a.left.y}};
		return b;
	}
}
int calc(rect& rectangle1, rect& rectangle2) {
    int x_overlap = max(0LL, min(rectangle1.right.x, rectangle2.right.x) - max(rectangle1.left.x, rectangle2.left.x));
    int y_overlap = max(0LL, min(rectangle1.right.y, rectangle2.right.y) - max(rectangle1.left.y, rectangle2.left.y));
    int intersectionArea = x_overlap * y_overlap;
    return intersectionArea;
}
bool cmp(rect a, rect b){
	return a.left.x < b.left.x;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,n){
		cin >> a[i].left.x >> a[i].left.y >> a[i].right.x >> a[i].right.y;
		a[i] = trans(a[i]);
		a[i].left.x += (int) 1e9;
		a[i].left.y += (int) 1e9;
		a[i].right.x += (int) 1e9;
		a[i].right.y += (int) 1e9;
	}
	int sum = 0;
	sort(a+1,a+n+1,cmp);
	
	int res = 0;
	fod(i,1,n){
		res += calc(a[i], a[i]);
	}
	cout << res - sum;
	// cout << calc(a[1],a[1]);
	return 0;
}
