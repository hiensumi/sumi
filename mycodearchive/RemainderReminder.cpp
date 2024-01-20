#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	if (k == 0) {cout << n*n; return 0;}
	for (ll i = k+1; i <= n; i++) {
		ll tmp = n;
		ans += (i - k)*(tmp/i);
		tmp -= n/i*i;
		if (tmp >= k) {ans += tmp - k + 1;}
	}
	cout << ans;
	
	return 0;
}