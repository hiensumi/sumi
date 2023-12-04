#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "GRIDCOLOR";
// Số test kiểm tra
const int NTEST = 100;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        // Code phần sinh test ở đây
        int n = Rand(4,10), m = Rand(4,10), k = Rand(1,9);
        inp << n << " " << m << " " << k << endl;
        for(int i =1 ; i <= n; i++){
            for(int j = 1; j < m; j++){
                int x = Rand(123,1234);
                if(x & 1) inp << 'E';
                else inp << 'N';
            }
            inp << endl;
        }

        for(int i =1 ; i <= n - 1; i++){
            for(int j = 1; j <= m; j++){
                int x = Rand(123,1234);
                if(x & 1) inp << 'E';
                else inp << 'N';
            }
            inp << endl;
        }
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}