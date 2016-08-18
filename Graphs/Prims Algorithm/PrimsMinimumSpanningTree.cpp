#include<bits/stdc++.h>
#define MAX 10001
#define pb(n) push_back(n)
#include<algorithm>

using namespace std;


pair<long long,pair<long ,long >> p[MAX];
int nodes,edges;
long long cost,min_cost;
vector<long> node;

void prims(pair<long long,pair<long,long>> p[]);
bool v_contains(long num);

int main(){
    int A,B;
    long long weight;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++){
        cin>>A>>B>>weight;
        p[i] = make_pair(weight,make_pair(A,B));   // make_pair() is the function in C++ that makes pairs nd returns reference
    }
    sort(p,p+edges);
    prims(p);

}

void prims(pair<long long,pair<long,long>> pi[]){

    min_cost = 0;
    for(int i=0;i<edges;i++){
        long A = pi[i].second.first;
        long B = pi[i].second.second;
        long W = pi[i].first;
        if(node.empty()){
            node.pb(A);
            node.pb(B);
            min_cost += W;
            cout<<"Edge "<<A<<"-"<<B<<" added"<<endl;
        }else if(v_contains(A) && v_contains(B)){
            continue;
        }else{
            if(v_contains(A)){
                node.pb(B);
            }
            if(v_contains(B)){
                node.pb(A);
            }
            cout<<"Edge "<<A<<"-"<<B<<" added"<<endl;
            min_cost += W;
        }

    }
    cout<<"MinCost = "<<min_cost<<endl;
}

bool v_contains(long num){
    if(find(node.begin(),node.end(),num)!=node.end()){
        return true;
    }else{
        return false;
    }
}


