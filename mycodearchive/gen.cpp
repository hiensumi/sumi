#include <bits/stdc++.h>
using namespace std;
int a[100005];

int rd(int l, int r){
	assert(l <= r);
	return  l + 1ll * rand() * rand() % (r - l + 1);
}

int main(int argc, char* argv[]) {

    // quicktest passes a seed as an argument: $ ./gen seed testcase
    int seed = stoi(string(argv[1]));
    srand(seed);
    
    cout << rd(1,1e18);
	// int t = rd(1,5);
	// cout << t << endl;
// 	
	// int n = rd(1,10), q = rd(1,10);
	// cout << n << " " << q << endl;
	// for(int i = 1; i <= n; i++){
		// a[i] = rd(1,20/n);
		// cout << a[i] << " ";
		// for(int j = 1; j <= a[i]; j++) cout << rd(1,1e3) << " ";
// 		
		// cout << endl;
	// }
// 	
	// for(int i = 1; i <= n; i++){
		// int x = a[i], y = a[i % n + 1];
		// cout << rd(1,x) << " " << rd(1,y) << " " << rd(1,1e3) << endl;
	// }
// 	
	// for(int i = 1; i <= q; i++){
		// int v1, c1, v2, c2;
		// c1 = rd(1,n-1);
		// c2 = rd(c1+1,n);
// 		
		// cout << rd(1,a[c1]) << " " << c1 << " " << rd(1,a[c2]) << " " << c2 << endl;
	// }
    
    default_random_engine generator;
    uniform_int_distribution<int> distribution(-10, 10);

    // for(int i = 1; i <= n; i ++){
        // int a = distribution(generator);
    	// cout << a << " ";
    // }
    return 0;
}