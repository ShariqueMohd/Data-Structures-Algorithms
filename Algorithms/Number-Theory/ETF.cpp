#include<iostream>
#include<cstdio>
#include<math.h>

#define lli long long int
using namespace std;

lli phi(lli N){
    lli ans = N,root;
    root = (lli)sqrt(N);
    for(lli i = 2; i <= N; i++){
        if(i>root)
            break;
        if(!(N % i)){
            ans -=(lli)(ans/i);
        }
        while(N%i == 0){
            N /= i;
        }
    }
    if(N>1)
        ans -= ans/N;
    return ans;
}

int main(){
    // your code goes here
    cout<<phi(2LL)<<"\n";
}

