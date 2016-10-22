#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 1e3+5;
int ST[MAX*4];
int Lazy[MAX*4];
int A[MAX];

void build(int node,int start,int last){
    if(start==last){
        ST[node] = A[start];
        return;
    }

    int mid = (start+last)>>1;
    build(node*2,start,mid);
    build(node*2+1,mid+1,last);

    ST[node] = max(ST[node*2], ST[node*2+1]);
}

/* Increment range in [i..j] */
void rangeUpdate(int node,int start,int last,int i,int j,int val){
    if(Lazy[node] != 0){
        ST[node] += Lazy[node];
        if(start != last){
            Lazy[node*2+1] += Lazy[node];
            Lazy[node*2] += Lazy[node];
        }
        Lazy[node] = 0;
    }

    if(start>last || start>j || last<i)
        return;

    if(start>=i && last<=j){
        ST[node] += val;
        if(start!=last){
            Lazy[node*2] += val;
            Lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start+last)>>1;
    rangeUpdate(node*2, start, mid, i, j, val);
    rangeUpdate(node*2+1, mid+1, last, i, j, val);

    ST[node] = max(ST[node*2], ST[node*2+1]);
}

/* Query in range [i...j] */
int query(int node, int start, int last, int i, int j){
    if(start>last || start>j || last<i){
        return -1;
    }

    if(Lazy[node] != 0){
        ST[node] += Lazy[node];
        if(start != last){
            Lazy[node*2] += Lazy[node];
            Lazy[node*2+1] += Lazy[node];
        }
        Lazy[node] = 0;
    }

    if(start>=i || last<=j)
        return ST[node];

    int mid = (start+last)>>1;
    int Q1 = query(node*2, start, mid, i, j);
    int Q2 = query(node*2+1, mid+1, last, i, j);

    int ans = max(Q1, Q2);
    return ans;
}

int main(){

    // your code goes here
    return 0;
}
