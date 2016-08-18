#include <bits/stdc++.h>

using namespace std;

struct Point{
  int x,y;
};

int orientation(Point p,Point q,Point r){
   int val = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
   if(val==0){
       return 0;  // collinear
   }return (val>0)?1:2;  // clock or anti-clock wise
}

void convexHull(Point p[],int n){
   if(n<3)return;

    vector<Point> hull;
    // find the left most point.
    int l = 0;
    for(int i=0;i<n;i++){
        if(p[i].x < p[l].x)l = i;
    }
    int m=l,q;
    // Start from the leftmost point and start moving counter clockwise till we reach the starting point again.
    do{
        hull.push_back(p[m]);
        q = (m+1)%n;
        for(int i=0;i<n;i++){
            if(orientation(p[m],p[i],p[q])==2){
                q = i;
            }
        }
        m = q;
    }while(m!=l);

    for(int i=0;i<hull.size();i++){
        cout<<"("<<hull[i].x<<","<<hull[i].y<<")"<<endl;
    }
}

int main(){
    Point p[] = {{0,3},{2,2},{1,1},{2,1},{3,0},{0,0},{3,3}};
    int n = sizeof(p)/ sizeof(p[0]);
    convexHull(p,n);
    return 0;
}
