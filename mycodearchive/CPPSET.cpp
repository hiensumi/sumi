// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
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
class SplayTree {
    struct Node {
        Node * child[2], * parent;
        int key;
    } * root, * nil;

    void setChild(Node * x, Node * y, int d) {
        x->child[d] = y;
        y->parent = x;
    }

    int getDirection(Node * x, Node * y) {
        return x->child[0] == y ? 0 : 1;
    }

    void rotate(Node * x, int d) {
        Node * y = x->child[d];
        Node * z = x->parent;
        setChild(x, y->child[d ^ 1], d);
        setChild(y, x, d ^ 1);
        setChild(z, y, getDirection(z, x));
    }

    Node * splay(Node * x) {
        if(x == nil) return nil;
        while(x->parent != nil) {
            Node * y = x->parent;
            Node * z = y->parent;
            int dy = getDirection(y, x);
            int dz = getDirection(z, y);
            if(z == nil) {
                rotate(y, dy);
            } else if(dy == dz) {
                rotate(z, dz);
                rotate(y, dy);
            } else {
                rotate(y, dy);
                rotate(z, dz);
            }
        }
        return x;
    }

    Node * leftMost(Node * x) const {
        if(x == nil) return nil;
        while(x->child[0] != nil)
            x = x->child[0];
        return x;
    }

    Node * rightMost(Node * x) const {
        if(x == nil) return nil;
        while(x->child[1] != nil)
            x = x->child[1];
        return x;
    }

    public:
    SplayTree() {
        root = nil = new Node();
        nil->child[0] = nil->child[1] = nil->parent = nil;
        nil->key = INF;
    }

    void insert(int key) {
        Node * curr = root;
        Node * last = nil;
        int dir = -1;
        while(curr != nil) {
            last = curr;
            if(key == curr->key) {
                root = splay(curr);
                return;
            } else if(key < curr->key) {
                curr = curr->child[0];
                dir = 0;
            } else {
                curr = curr->child[1];
                dir = 1;
            }
            // just
        }
        Node * u = new Node();
        u->key = key;
        u->child[0] = u->child[1] = nil;
        setChild(last, u, dir);
        root = splay(u);
    }

    void erase(int key) {
        if(!contain(key)) return;
        Node * left = root->child[0];
        Node * right = root->child[1];
        left->parent = right->parent = nil;
        delete root;
        if(left == nil) {
            root = right;
        } else {
            left = splay(rightMost(left));
            setChild(left, right, 1);
            root = left;
        }
    }

    bool isEmpty() const {
        return root == nil;
    }

    int minimum() {
        return (root = splay(leftMost(root)))->key;
    }

    int maximum() {
        return (root = splay(rightMost(root)))->key;
    }

    bool contain(int key) {
        Node * curr = root;
        while(curr != nil) {
            if(key == curr->key) {
                root = splay(curr);
                return true;
            }
            else if(key < curr->key) curr = curr->child[0];
            else curr = curr->child[1];
        }
        return false;
    }

    int greater(int x) {
        Node * curr = root;
        Node * res = nil;
        while(curr != nil) {
            if(x >= curr->key) {
                curr = curr->child[1];
            } else {
                if(res == nil || curr->key < res->key) res = curr;
                curr = curr->child[0];
            }
        }
        if(res != nil) root = splay(res);
        return res->key;
    }

    int smaller(int x) {
        Node * curr = root;
        Node * res = nil;
        while(curr != nil) {
            if(x <= curr->key) {
                curr = curr->child[0];
            } else {
                if(res == nil || curr->key > res->key) res = curr;
                curr = curr->child[1];
            }
        }
        if(res != nil) root = splay(res);
        return res->key;
    }
};
void inp(){

}

namespace sub_task1{
    void solve(){
    	SplayTree stree;
    	int type;
    	while(cin >> type){
    		if(type == 0) break;
    		if(type == 1){
    			int x; cin >> x;
    			stree.insert(x);
    		}
    		if(type == 2){
    			int x; cin >> x;
    			if(stree.contain(x)){
    				stree.erase(x);
    			}
    		}
    		if(stree.isEmpty() and type > 2){cout << "empty" << el; continue;}
    		if(type == 3){
    			cout << stree.minimum() << el;
    		}
    		if(type == 4){
    			cout << stree.maximum() << el;
    		}
    		if(type == 5){
    			int x; cin >> x;
    			int ret = stree.greater(x); 
    			if(ret == INF) cout << "no" << el;
    			else cout << ret << el;
    		}
    		if(type == 6){
    			int x; cin >> x;
    			int ret = stree.greater(x-1);
    			if(ret == INF) cout << "no" << el;
    			else cout << ret << el;
    		}
    		if(type == 7){
    			int x; cin >> x;
    			int ret = stree.smaller(x);
    			if(ret == INF) cout << "no" << el;
    			else cout << ret << el;
    		}
    		if(type == 8){
    			int x; cin >> x;
    			int ret = stree.smaller(x + 1 );
    			if(ret == INF) cout << "no" << el;
    			else cout << ret << el;
    		}
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