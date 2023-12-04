#include <bits/stdc++.h>
#define SSS "TRAFFICLIGHT"

using namespace std;

const int N = (int)1e5;

int n, k;
long long t[N];
struct bg {
	long long r, g; char c;
	void input () {
		cin >> r >> g >> c;
	}
} a[N + 1];
long long p[N + 1];
int s[N + 1];

namespace sub3 {
	long long f[N + 1][1 << 5];

	void solve(){
		memset(f, 0x3f, sizeof(f));
		f[1][0] = 0;
		for (int i(1); i <= n; ++i) for (int mask = 0; mask < (1 << k); ++mask) {
			long long best = f[i][mask];
			f[i][mask | s[i]] = min(f[i][mask | s[i]], best + p[i]);

			long long cur = best % (a[i].r + a[i].g) + 1;
			if (a[i].c == 'G' && cur > a[i].g) best += a[i].r - (cur - 1 - a[i].g);
			else if (a[i].c == 'R' && cur <= a[i].r) best += a[i].r - (cur - 1);
			f[i + 1][mask] = min(f[i + 1][mask], best + t[i]);
		}

		cout << f[n + 1][(1 << k) - 1];
	}
}

int main () {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	if(fopen(SSS".inp", "r")) freopen(SSS".inp","r",stdin), freopen(SSS".out","w",stdout);

	cin >> n >> k;
	for (int i(1); i < n; ++i) cin >> t[i];
	for (int i(1); i <= n; ++i) a[i].input();
	for (int i(1); i <= n; ++i) {
		cin >> p[i];
		int siz; cin >> siz;
		for (int j(1); j <= siz; ++j) {
			int x; cin >> x;
			s[i] |= (1 << (x - 1));
		}
	}

	sub3 :: solve();

	cerr << "Time used: " << clock() << "ms ";

	return 0;
}