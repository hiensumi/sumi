#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
typedef long long ll;
typedef vector<int> vi;

int numDays, numToys, need, total;
const int N = 2e5+5;
int dol[N], pou[N];
struct Toy {
    int idx, cost;
    bool operator < (Toy const &a) const {
        return cost < a.cost;
    }
};
vector<Toy> t1, t2;
ll sum1[N], sum2[N];
int minDol[N], minPou[N];

void Input() {
    cin >> numDays >> numToys >> need >> total;
    FOR(i, 1, numDays) cin >> dol[i];
    FOR(i, 1, numDays) cin >> pou[i];
    FOR(i, 1, numToys) {
        int t, c; cin >> t >> c;
        if (t == 1) t1.pb({i, c});
        else t2.pb({i, c});
    }
}

int check(int maxDay) {
    int d = dol[minDol[maxDay]];
    int p = pou[minPou[maxDay]];
    if (need <= t2.size() && sum2[need-1]*p <= total) return 0;

    FOR(i, 0, min((int)t1.size(), need)-1) if (need-(i+1) <= t2.size()) {
        ll cost = 1ll*sum1[i]*d;
        if (i+1 < need) cost += 1ll*sum2[need-(i+1)-1]*p;
        if (cost <= total) return i+1;
    }
    return -1;
}

void Solve() {
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());

    FOR(i, 0, (int)t1.size()-1) {
        sum1[i] = t1[i].cost;
        if (i) sum1[i] += sum1[i-1];
    }

    FOR(i, 0, (int)t2.size()-1) {
        sum2[i] = t2[i].cost;
        if (i) sum2[i] += sum2[i-1];
    }

    FOR(i, 1, numDays) {
        minDol[i] = i; minPou[i] = i;
        if (i > 1) {
            if (dol[minDol[i-1]] < dol[i]) minDol[i] = minDol[i-1];
            if (pou[minPou[i-1]] < pou[i]) minPou[i] = minPou[i-1];
        }
    }

    int L = 1, R = numDays;
    int minDay = R+1, numT1 = -1;
    while (L <= R) {
        int mid = (L+R) >> 1;
        int cur = check(mid);
        if (cur != -1) minDay = mid, numT1 = cur, R = mid-1;
        else L = mid+1;
    }

    if (minDay > numDays) cout << -1;
    else {
        cout << minDay << '\n';
        FOR(i, 0, numT1-1) {
            cout << t1[i].idx << ' ' << minDol[minDay] << '\n';
        }
        FOR(i, 0, need-numT1-1) {
            cout << t2[i].idx << ' ' << minPou[minDay] << '\n';
        }
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    Input(), Solve();
    return 0;
}
