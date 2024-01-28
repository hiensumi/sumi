#include <bits/stdc++.h>
using namespace std;
#define fod(i,a,b) for(int i = a; i <= b; i++)
#define int long long
#define el "\n"
int rd(int l, int r){
	// assert(l <= r);
	if(l > r) swap(l,r);
	return  l + 1ll * rand() * rand() % (r - l + 1);
}
const int NTest = 100;
const string name = "lice";
vector<int> gen(int N) { // sinh hoan vi
    vector<int> numbers(N);
    for(int i = 0; i < N; i++) {
        numbers[i] = i+1;
    }
    srand(time(NULL));
    random_shuffle(numbers.begin(), numbers.end());
    return vector<int>(numbers.begin(), numbers.begin() + N);
}
int a[100005];

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	srand(time(0));
	system( ("g++ -std=gnu++14 " + name + ".cpp " + "-o " + name).c_str());
	system( ("g++ -std=gnu++14 " + name + "_good.cpp " + "-o " + name + "_good").c_str());
	fod(i,1,NTest){
		ofstream cout((name + ".inp").c_str());
		// gen
		int L = rd(1,1000);
		int n = min(L, rd(1,1000));
		cout << L << " " << n << el;
		fod(i,1,n) a[i] = rd(0,L);
		sort(a + 1, a + n + 1);
		fod(i,1,n) cout << a[i] << " ";
		
		cout.close();
		system(("./" + name).c_str());
		system(("./" + name + "_good").c_str());
		
		if(system(("diff " + name + ".out " + name + ".ans").c_str()) != 0){
			cerr << "Test " << i << ": WA!\n";
			return 0;
		}
		cerr << "Test " << i << ": AC!\n";
	}
	
	
	return 0;
}
