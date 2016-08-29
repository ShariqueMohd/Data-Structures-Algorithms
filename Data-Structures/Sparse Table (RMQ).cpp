// Sparse Table for Range Minimum Query.

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>

using namespace std;
const int MAX = 1025;
const int LOGMAX = 11;

/* A is the input array, while
   M is the sparse table for RMQ */

int M[MAX][LOGMAX], A[MAX];
int N;      // size of the input

void process(){

    for(int i=0;i<N;i++){
        M[i][0] = i;
    }
    for(int j=1; (1<<j) <= N; j++){
        for(int i=0; i+(1<<j)-1 < N; i++){
            if(A[M[i][j-1]] < A[M[i + (i+1<<(j-1))][j-1]])
                M[i][j] = M[i][j-1];
            else
                M[i][j] = M[i +(1<<(j-1))][j-1];
        }
    }
}

int query(int i, int j){
    int diff = j-i+1,k=0;
    while( (1<<(k+1)) <= diff)
        k += 1;
    return min(M[i][k],M[j-(1<<k)+1][k];
}

int main(){
    // your code goes here

    return 0;
}
