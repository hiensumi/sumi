struct FenwickTree {
    int b1[base], b2[base];
    int n;
    void init(int n){
        this-> n = n;
    }
    void add(int b[], int idx, int x){
        while(idx <= n){
            b[idx] += x;
            idx += idx & -idx;
        }
    }
    void range_add(int l, int r, int x){
        add(b1,l,x);
        add(b1,r+1,-x);
        add(b2,l,x*(l-1));
        add(b2,r+1,-x*r);
    }
    void add(int id, int x){
        range_add(id,id,x);
    }
    int sum(int b[], int idx){
        int res = 0;
        while(idx){
            res += b[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    int getall(int idx){
        return sum(b1, idx) * idx - sum(b2, idx);
    }
    int get(int l, int r){
        if(l > r) return 0;
        if(l == 0 or r == 0) return 0;
        return getall(r) - getall(l-1);
    }
}BIT;