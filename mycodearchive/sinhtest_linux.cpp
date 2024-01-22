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
const string name = "CHEFCCYL";
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
		int t = rd(1,1);
		cout << t << endl;
		
		while(t--){
			int n = rd(2,5), q = rd(1,3);
			cout << n << " " << q << endl;
			for(int i = 1; i <= n; i++){
				a[i] = rd(2,10);
				cout << a[i] << " ";
				for(int j = 1; j <= a[i]; j++) cout << rd(1,10) << " ";
				
				cout << endl;
			}
			
			for(int i = 1; i <= n; i++){
				int x = a[i], y = a[i % n + 1];
				cout << rd(1,x) << " " << rd(1,y) << " " << rd(1,10) << endl;
			}
			
			for(int i = 1; i <= q; i++){
				int v1 = 0 , c1 = 0 , v2 = 0, c2 = 0;
				c1 = rd(1,n-1);
				c2 = rd(c1+1,n);
				
				cout << rd(1,a[c1]) << " " << c1 << " " << rd(1,a[c2]) << " " << c2 << endl;
			}
		}
		
		
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
