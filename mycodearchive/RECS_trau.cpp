#include <bits/stdc++.h>
using namespace std;

void cl () {
	cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}

long long a[3], b[3];

struct info {
	long long c[2], r[2];
} hcn[3];

void build () {
	for (int i(0); i < 3; ++i) {
		hcn[i].c[0] = hcn[i].r[1] = a[i];
		hcn[i].c[1] = hcn[i].r[0] = b[i];
	}
}

const long long INF = (long long)9e18;
long long sz;

void d0 (int i, int t1, int j, int t2) {
	int o = 0;
	if (o == i) ++o;
	if (o == j) ++o;

	if (hcn[i].r[t1] > hcn[j].r[t2]) {
		for (int t3(0); t3 < 2; ++t3) {
			long long szc = hcn[i].c[t1] + max(hcn[j].c[t2], hcn[o].c[t3]);
			long long szr = max(hcn[i].r[t1], hcn[j].r[t2] + hcn[o].r[t3]);
			sz = min(sz, szc * szr);
		}
	} else {
		for (int t3(0); t3 < 2; ++t3) {
			long long szc = max(hcn[i].c[t1], hcn[o].c[t3]) + hcn[j].c[t2];
			long long szr = max(hcn[i].r[t1] + hcn[o].r[t3], hcn[j].r[t2]);
			sz = min(sz, szc * szr);
		}
	}
}

void d1 (int i, int t1, int j, int t2) {
	int o = 0;
	if (o == i) ++o;
	if (o == j) ++o;

	if (hcn[i].c[t1] > hcn[j].c[t2]) {
		for (int t3(0); t3 < 2; ++t3) {
			long long szr = hcn[i].r[t1] + max(hcn[j].r[t2], hcn[o].r[t3]);
			long long szc = max(hcn[i].c[t1], hcn[j].c[t2] + hcn[o].c[t3]);
			sz = min(sz, szr * szc);
		}
	} else {
		for (int t3(0); t3 < 2; ++t3) {
			long long szr = max(hcn[i].r[t1], hcn[o].r[t3]) + hcn[j].r[t2];
			long long szc = max(hcn[i].c[t1] + hcn[o].c[t3], hcn[j].c[t2]);
			sz = min(sz, szr * szc);
		}
	}
}

void d2 (int i, int t1, int j, int t2) {
	int o = 0;
	if (o == i) ++o;
	if (o == j) ++o;

	for (int t3(0); t3 < 2; ++t3) {
		long long szc = hcn[i].c[t1] + hcn[j].c[t2] + hcn[o].c[t3];
		long long szr = max({hcn[i].r[t1], hcn[j].r[t2], hcn[o].r[t3]});
		sz = min(sz, szc * szr);
	}
}

void d3 (int i, int t1, int j, int t2) {
	int o = 0;
	if (o == i) ++o;
	if (o == j) ++o;

	for (int t3(0); t3 < 2; ++t3) {
		long long szr = hcn[i].r[t1] + hcn[j].r[t2] + hcn[o].r[t3];
		long long szc = max({hcn[i].c[t1], hcn[j].c[t2], hcn[o].c[t3]});
		sz = min(sz, szr * szc);
	}
}

void solve () {
	build();
	for (int i(0); i < 3; ++i) for (int t1(0); t1 < 2; ++t1) {
		for (int j(i + 1); j < 3; ++j) for (int t2(0); t2 < 2; ++t2) {
			for (int d(0); d < 4; ++d) {
				if (d == 0) d0(i, t1, j, t2);
				if (d == 1) d1(i, t1, j, t2);
				if (d == 2) d2(i, t1, j, t2);
				if (d == 3) d3(i, t1, j, t2);
			}
		}
	}
	cout << sz << '\n';
}

int main () {
	#define PHILE "RECS"
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen(PHILE".inp", "r")) {
		freopen(PHILE".inp", "r", stdin); freopen(PHILE".ans", "w", stdout);
	}

	int t; cin >> t;
	while (t--) {
		for (int i(0); i < 3; ++i) cin >> a[i] >> b[i];
		sz = INF;
		solve();
	}

	cl();
	return 0;
}