// By: @shariquemohd

#include<iostream>

using namespace std;
const int MAX=1005;

int fib[MAX];

void pre(){
    fib[0]=0; fib[1]=1;
    for(int i=2;i<MAX;i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
}

int main(){
    // your code goes here
    pre();
    
    return 0;
}
