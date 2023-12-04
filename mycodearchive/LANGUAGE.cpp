// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include "bits/stdc++.h"
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) ((a >> i) & 1LL)
#define pb push_back
#define el '\n'
#define all(v) v.begin(), v.end()
#define odd(i) (i & 1LL)
using namespace std;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { int tmp = x; mul(tmp, Inv(y, mod), mod); return tmp;}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
struct point{int x, y;};
struct edge{int u, v, c;};
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true; }*/ 
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
	
}
const int MAX_CHAR = 26;
struct Node{
    int exist, cnt;
    Node* child[MAX_CHAR];
    Node(){
        cnt = exist = 0;
        fod(i,0,MAX_CHAR-1){
            child[i] = NULL;
        }
    }
};
void insert(Node* root, const string& s) {
    Node* cur = root;
    for (char c : s){
        int idx = c - 'a';
        if (cur->child[idx] == NULL) {
            cur->child[idx] = new Node();
        }
        cur = cur->child[idx];
        cur->cnt++;
    }
    cur->exist = 1;
}
int find(Node* root, int id, string s, vector <int> dp){
    int res = 0;
    Node* cur = root;
    fod(i,id,s.size() - 1){
        int idx = s[i] - 'a';
        if(cur->child[idx] == NULL) return res;
        cur = cur->child[idx];
        if(cur->exist == 1){
            res = (res + dp[i+1]) % MOD;
        }
    }
    return res;
}
int n, m;
void inp(){
    cin >> n >> m;
}

namespace sub_task1{
	bool check(Node* root, int id, string s){
        string x = "#";
        fod(i,1,id) x += s[i];
        int n = id;
        vector <int> dp(n + 1);
        dp[n + 1] = 1;
        fok(i,n,1){
            int res = 0;
            Node* cur = root;
            fod(j,i,n){
                int idx = x[j] - 'a';
                if(cur->child[idx] == NULL) break;
                cur = cur->child[idx];
                if(cur->exist == 1){
                    res = (res + dp[j+1]);
                }
            }
            dp[i] = res;    
        }
        if(dp[1] > 0) return 1;
        else return 0;
    }   
    void solve(){
        Node* root = new Node();
        fod(i,1,n){
            string x; cin >> x;
            insert(root, x);
        }

        fod(j,1,m){
            string s; cin >> s;
            int res = 0, n = s.size();

            s = "#" + s;
            int l = 1, r = n;
            while(l <= r){
                int mid = l + r >> 1;
                if(check(root, mid, s)) l = mid + 1, res = mid;
                else r = mid - 1;
            }
            cout << res << el;            
        }
	}	
	
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	  freopen(name".inp", "r", stdin);
	  freopen(name".out", "w", stdout);
	}
	int Test = 1; if(multitest) cin >> Test;
	init();
	while(Test--){
		inp();
		sub_task1 :: solve();
	}
	kill();
}