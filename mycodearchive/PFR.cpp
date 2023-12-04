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
const int base = 1e6 + 5;
int n, a[base], f[base], dd[base];
int lcm(int a, int b){
	return (a * b)/(__gcd(a,b));
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,n) cin >> a[i], dd[a[i]] = i;
	fod(i,1,n){
		// cout << dd[a[i]] << endl;
		int cnt = 0, curi = i;
		while(cnt == 0 or curi != i){
			curi = dd[curi];
			cnt++;
		}
		f[i] = cnt;
	}
	int ans = f[1];
	fod(i,2,n) ans = lcm(f[i], ans);
	cout << ans;
	return 0;
}
