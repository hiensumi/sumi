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
const int MAX_CHAR = 26;
int n, t[base][27], f[base];
string a[base];
int node = 1, counter = 0;
struct Node{
    int exist, cnt;
    Node* child[MAX_CHAR];
    Node(){
        cnt = exist = 0;
        fod(i,0,MAX_CHAR-1){
            child[i] = nullptr;
        }
    }
};
void insert(Node* root, const string& s) {
    Node* cur = root;
    for (char c : s){
        int idx = c - 'a';
        if (cur->child[idx] == nullptr) {
            cur->child[idx] = new Node();
        }
        cur = cur->child[idx];
        cur->cnt++;
    }
    cur->exist++;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	int ma = 0;
	fod(i,1,n){
		cin >> a[i];
		int len = a[i].size(); ma = max(ma, len);
	}
	fod(i,0,base-1) fod(j,0,26) t[i][j] = -1; 
	fod(i,1,n){
		Add(a[i]);
	}
	node--;
	cout <<  node * 2 +n - ma;
	return 0;
}
