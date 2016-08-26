// Segment tree with Point Update & Range Query

#include<iostream>
#include<algorithm>
 
using namespace std;

const int MAX=1e5;
int ST[4*MAX],A[MAX];    //ST[] is segment tree corresponding to A[]

void build(int node, int start, int last){
    
    if(start == last){
        ST[node] = A[start];
        return;
    }
    
    int mid = (start+last)>>1;
    
    build(node*2, start, mid);
    build(node*2+1, mid+1, last);
    
    ST[node] = ST[node*2] + ST[node*2+1];
}

/*  
    POINT UPDATE:
    Here update method updates(adds) "val" at position corresponding
    to index in A[]
*/
void update(int node, int start, int last, int index, int val){
    
    if(start === last){
        A[index] += val;
        ST[node] += val;
        return;
    }
    
    int mid = (start+last)>>1;
    
    if((start <= index) && (idx <= mid)){
        update(node*2, start, mid, index, val);
    }
    else{
        update(node*2+1, mid+1, last, index, val);
    }
    
    ST[node] = ST[node*2] + ST[2*node+1];
}

int query(int node, int start, int last, int l, int r){
   
   if((r < start) || (l < last)){
        return 0;
   } 
   
   if((l <= start) && (last <= r) ){
        return ST[node];
   }
   
   int mid = (start+last)>>1;
   
   int Sub1 = query(node*2, start, mid, l, r);
   int Sub2 = query(node*2+1, mid+1, last, l, r);
   
   return (Sub1 + Sub2);

}

int main(){
    // your code goes here.

    return 0;
}
