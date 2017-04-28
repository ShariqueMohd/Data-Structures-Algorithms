#include<bits/stdc++.h>

using namespace std;
const int N =1e7+1;

int LP[N];
vector<int> Prime;

void calc() {
    for(int i = 2; i < N; i++){
        if(LP[i] == 0){
            LP[i] = i;
            Prime.push_back(i);
        }
        for(int j = 0; j < (int)Prime.size() && Prime[j] <= LP[i] && i*Prime[j] < N; j++) {
            LP[i*Prime[j]] = Prime[j];
        }
    }
}

int main(){
    calc();

    cout << LP[12] << " " << LP[45] << "\n";
    return 0;
}
