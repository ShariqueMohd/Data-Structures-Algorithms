#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5;

// T=int
int B1[N], B2[N];
int n;

// Range Query, Range Update
template<typename T>
void update(T *FT,int ind, T val) {
    for(; ind<=n; ind+=ind&(-ind))
        FT[ind] += val;
}

// add val in [a..b]
template<typename T>
void updateRange(int a, int b, T val) {
    update(B1,a,val);
    update(B1,b+1,-val);
    update(B2,a,val*(a-1));
    update(B2,b+1,-val*(b));
}

template<typename T>
T query(T *FT, int ind) {
    T sum = 0;
    for(; ind>0; ind -= ind&(-ind)) {
        sum += FT[ind];
    }
    return sum;
}

auto query(int ind) {
    return query(B1,ind)*ind - query(B2,ind);
}

// query in [a..b]
auto query(int a, int b) {
    return query(b) - query(a-1);
}

int main() {
    n = 5;
    updateRange(1,3,1);
    updateRange(2,3,-1);
    updateRange(3,5,2);
    cout << query(1,3) << "\t3\n";
    cout << query(2,2) << "\t0\n";
    cout << query(3,5) << "\t6\n";

    return 0;
}
