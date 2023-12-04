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
int t, f[202][202][202], dd[202][202][202];
// gọi f[i][j][l] là tổng điểm lớn nhất khi xóa đoạn i,j và liền sau j có l thằng liên tiếp = s[j]
string s;
int calc(int i, int j, int l){
	if(i > j) return f[i][j][l] = 0;
	if(i == j and l == 0) return f[i][j][l] = -1e18;
	int sum = -1e18;
	if(dd[i][j][l] == 1) return f[i][j][l];
	dd[i][j][l] = 1;
	if(l >= 2) sum = max(sum, l * l + calc(i,j,0));
	if(l >= 1) sum = max(sum, (l+1)*(l+1) + calc(i,j-1,0));
	fod(k,i,j-1) if(s[k] == s[j]){
		sum = max(sum, calc(k+1,j-1,0) + calc(i,k,l+1));
	}
	return f[i][j][l] = sum;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> t;
	while(t--){
		cin >> s;
		int n = s.size();
		s = "#" + s;
		fod(i,1,n) fod(j,1,n) fod(l,0,n) dd[i][j][l] = 0;
		fod(i,1,n) fod(j,1,n) fod(l,0,n) f[i][j][l] = -1e18;
		cout << max(0LL,calc(1,n,0)) << endl;
	}
	return 0;
}