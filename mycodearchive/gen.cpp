#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {

    // quicktest passes a seed as an argument: $ ./gen seed testcase
    int seed = stoi(string(argv[1]));
    srand(seed);

    const int N = int(1e3);
    const int T = int(1e9);
    const int Ai = int(1e9);
    const int Bi = int(1e9);

    // int n = N, t = 1e4;
    int n = rand() % N + 1;
    int t = rand() % T + 1;
    cout << n << " " << t << endl;

    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, Ai);

    // for(int i = 1; i <= t; i ++){
    //     int a = distribution(generator);
    //     int b = distribution(generator);

    // }
    for(int i = 1; i <= n; i ++){
        int a= distribution(generator);
        cout << a << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i ++){
        int a= distribution(generator);
        cout << a << " ";
    }
    return 0;
}