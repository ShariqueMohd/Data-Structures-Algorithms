// By: @shariquemohd

#include<iostream>

#define li long int
using namespace std;

typedef struct T matrix;

struct T{
    li mat[2][2];
};

li fib[2]={1L,0L};

void init(matrix &a){
    a.mat[0][0] = a.mat[0][1] = a.mat[1][0] = 1L;
    a.mat[1][1] = 0L;
}

matrix mult(matrix a, matrix b,li mod=1e9+7){
    matrix res;
    res.mat[0][0] = (a.mat[0][0]*b.mat[0][0] + a.mat[0][1]*b.mat[1][0])%mod;
    res.mat[0][1] = (a.mat[0][0]*b.mat[0][1] + a.mat[0][1]*b.mat[1][1])%mod;
    res.mat[1][0] = (a.mat[1][0]*b.mat[0][0] + a.mat[1][1]*b.mat[1][0])%mod;
    res.mat[1][1] = (a.mat[1][0]*b.mat[0][1] + a.mat[1][1]*b.mat[1][1])%mod;
    return res;
}

matrix expo(int N){
    matrix a,ans;
    init(a);
    ans.mat[0][0] = ans.mat[1][1] = 1L;
    ans.mat[0][1] = ans.mat[1][0] = 0L;

    while(N){
        if(N&1){
            ans = mult(ans,a);
        }
        a = mult(a,a);
        N >>= 1;
    }
    return ans;
}

int main(){
    int N;
    matrix res;
    cin>>N;
    res = expo(N-1);
    cout<< res.mat[0][0]*fib[0]+res.mat[0][1]*fib[1] <<"\n";

    return 0;
}
