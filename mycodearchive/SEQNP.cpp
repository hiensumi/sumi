#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define base 1000000+5
#define name ""
#define non 5000+1
#define pog 1000000000+7
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
struct point{
	int x, y;
};
int n, a[base], f[base], l[base], r[base];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,n) cin >> a[i];
	f[1] = a[1]; l[1] = 1;
	fod(i,2,n) f[i] = 2e9, l[i] = 0;
	fod(i,2,n){
		int j = lower_bound(f+1,f+n+1,a[i]) - f;
		f[j] = a[i];
		l[i] = max(l[i-1], j);
	}
	fod(i,1,n) f[i] = 2e9, r[i] = 0;
	r[n] = 1; f[1] = a[n];
	fok(i,n-1,1){
		int j = lower_bound(f+1,f+n+1,a[i]) - f;
		f[j]= a[i];
		r[i] = max(r[i+1], j);
	}
	int res = 0;
	fod(i,1,n) res = max({res, l[i], r[i], l[i] + r[i]-1});
	cout << res;
	return 0;
}