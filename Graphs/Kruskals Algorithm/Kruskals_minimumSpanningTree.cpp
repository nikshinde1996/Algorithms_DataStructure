#include <bits/stdc++.h>
#include <algorithm>
#define  MAX 10001

using namespace std;
pair<long long ,pair<long , long >> p[MAX];
long edges,nodes;

long id[MAX],MinCost=0;

void initialise(){
    for(int i=0;i<MAX;i++){
        id[i] = i;
    }
}

long root(long x){
    while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(long A,long B){
    long P = root(A);
    long Q = root(B);
    id[P] = id[Q];
}

void kruskals(pair<long long ,pair<long , long >> pi[]){
    long A,B,W;
    for(long i=0;i<edges;i++){
        A = pi[i].second.first;
        B = pi[i].second.second;
        W = pi[i].first;

        if(root(A)!=root(B)){
            MinCost += W;
            union1(A,B);
            cout<<"Edge added : "<<A<<"->"<<B<<endl;
        }
    }
    cout<<"MinCost : "<<MinCost<<endl;
}

int main(){
    long A,B,W;
    initialise();
    cin>>nodes>>edges;
    for(long i=0;i<edges;i++){
        cin>>A>>B>>W;
        p[i] = make_pair(W,make_pair(A,B));
    }
    sort(p,p+edges);
    kruskals(p);
}
