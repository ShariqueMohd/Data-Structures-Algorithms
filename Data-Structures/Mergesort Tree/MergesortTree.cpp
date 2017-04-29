/*
    Problem: Given an array of N elements. Answer Q queries of following type:
            - Count the numbers smaller than K in range [L,R]
*/


#include<bits/stdc++.h>

#define pb push_back
using namespace std;

const int N = 1e5+5;

int A[N];
vector<int> MST[5*N];   // Mergesort Tree

vector<int> Merge(vector<int>& A, vector<int>& B){
    vector<int> res;
    int N = (int)A.size(); int M = (int)B.size();

    int i=0,j=0;
    while(i<N && j<M){
        if(A[i]<=B[j]){
            res.pb(A[i]); i += 1;
        }
        else{
            res.pb(B[j]); j += 1;
        }
    }

    while(i<N){
        res.pb(A[i]); i+=1;
    }

    while(j<M){
        res.pb(B[j]); j+=1;
    }

    return res;
}

void build(int node, int L, int R){
    if(L==R){
        MST[node].pb(A[L]);
        return;
    }
    int mid = (L+R)>>1;
    build(2*node, L, mid);
    build(2*node+1, mid+1, R);
    MST[node] = Merge(MST[2*node], MST[2*node+1]);  // Merge two sorted arrays
}

int query(int node, int L, int R, int x, int y, int K){
    if(R < x || L > y)
        return 0;

    if(x <= L && R <= y){
        return upper_bound(MST[node].begin(), MST[node].end(), K) - MST[node].begin();
    }

    int mid =  (x+y)>>1;
    return query(2*node, L, R, x, mid, K ) + query(2*node+1, L, R, mid+1, y, K);
}

int main(){

    // Use Data Structure

    return 0;
}
