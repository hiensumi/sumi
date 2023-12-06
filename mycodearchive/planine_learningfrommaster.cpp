#include <bits/stdc++.h>

using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << " ]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define     deb(x...)             cerr << "[ in " <<__func__<< "() : line " <<__LINE__<< " ] : [ " << #x << " ] = [ "; _print(x); cerr << '\n';

typedef     long long             ll;
typedef     unsigned long long    ull;
typedef     double                db;
typedef     long double           ld;
typedef     pair<db, db>          pdb;
typedef     pair<ld, ld>          pld;
typedef     pair<int, int>        pii;
typedef     pair<ll, ll>          pll;
typedef     pair<ll, int>         plli;
typedef     pair<int, ll>         pill;

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
#define     int                   long long

const int MAX_N = 1e6 + 5;

int n;
db h;

struct Vec {
    int a, b;

    Vec(int _a = 0, int _b = 0) {
        a = _a;
        b = _b;
    }
};

using Point = Vec;

Vec operator - (const Point& A, const Point& B) {
    return Vec(B.a - A.a, B.b - A.b);
}

int l[MAX_N], r[MAX_N];
Point a[MAX_N];

db intersectLine(const Point& A, const Point& B) {
    db a = double(A.b - B.b) / (A.a - B.a);
    db b = A.b - a * A.a;
    return (h - b) / a;
}

bool xoayTrai(const Point& A, const Point& B, const Point& C) {
    Vec BA = A - B;
    Vec BC = C - B;
    return BA.a * BC.b < BA.b * BC.a;
}

bool xoayPhai(const Point& A, const Point& B, const Point& C) {
    Vec BA = A - B;
    Vec BC = C - B;
    return BA.a * BC.b > BA.b * BC.a;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b;
    }

    vector<int> up;
    up.pb(2);

    for (int i = 3; i < n; i++) {
        while (up.size() >= 2 && xoayTrai(a[up[up.size() - 2]], a[up.back()], a[i])) {
           up.pop_back();
        }

        if (i & 1) {
            l[i] = up.back();
           // cout << i << " " << l[i] << endl;
        }

        up.pb(i);
    }

    up.clear();
    up.pb(n - 1);
    for (int i = n - 2; i > 1; i--) {
        while (up.size() >= 2 && xoayPhai(a[up[up.size() - 2]], a[up.back()], a[i])) {
           up.pop_back();
        }

        if (i & 1) {
            r[i] = up.back();
//            cout << i << " " << r[i] << endl;
        }

        up.pb(i);
    }

    vector<pdb> seg;
    for (int i = 3; i < n; i += 2) {
        cout << i << " " << l[i] << " ";
        cout << setprecision(4) << fixed << intersectLine(a[l[i]], a[i]) << endl;
        // seg.pb({intersectLine(a[l[i]], a[i]), intersectLine(a[r[i]], a[i])});
    }

    sort(all(seg));
    int ans = 0;
    db curr = -1e18;
    for (auto it : seg) {
        if (curr < it.fi) {
            ans++;
            curr = it.se;
        }
        else {
            minimize(curr, it.se);
        }
    }

    cout << ans;

	return 0;
}

/*


*/
