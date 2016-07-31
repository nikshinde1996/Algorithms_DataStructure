
#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

struct Point{
    int x,y;
};

Point _p_;  // global Point needed for sorting.

void convexHull(Point p[],int n);
int dis_square(Point p1,Point p2);
int orientation(Point p1,Point p2,Point p3);
int swap(Point &p1,Point &p2);
Point next_to_top(stack<Point> &s);
int compare();

int main(){
    Point p[] = {{0,3},{1,1},{2,2},{4,4},{0,0},{1,2},{3,1},{3,3}};
    int n = sizeof(p)/ sizeof(p[0]);
    convexHull(p,n);
}

Point next_to_top(stack<Point> &s){
    Point p = s.top();
    s.pop();
    Point res = s.top();
    s.push(p);
    return res;
}

int swap(Point &p1,Point &p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int dis_square(Point p1,Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int orientation(Point p1,Point p2,Point p3){
    int val = (p2.y-p1.y)*(p3.x-p2.x) - (p2.x-p1.x)*(p3.y-p2.y);
    if(val == 0){
        return 0;   // Points are collinear
    }else{
        return (val > 0)?1:2;  // clockwise or anti-clockwise
    }
}

int compare(const void *vp1,const void *vp2){
  Point *p1 = (Point*) vp1;
  Point *p2 = (Point*) vp2;

  int o = orientation(_p_,*p1,*p2);
  if(o == 0){
      return ((dis_square(_p_,*p2)>=dis_square(_p_,*p1)) ? -1:1);
  }
    return (o==2)?-1:1;
}

void convexHull(Point p[],int n){
   int ymin = p[0].y,min=0;
   for(int i=1;i<n;i++){
       int y = p[i].y;
       if(ymin > y || (ymin==y && p[i].x < p[min].x)){
           ymin = p[i].y,min = i;
       }
   }

   swap(p[0],p[min]);
   _p_ = p[0];

   // swap first point w.r.t.x first point or _p_

    qsort(&p[1],n-1, sizeof(Point),compare);    // sort the array as per _p_ reference point
    int m = 1;  // Initial size of modified array
    for(int i=1;i<n;i++){
        while(i<n-1 && orientation(p[0],p[i],p[i+1])==0){
            i++;
        }
        p[m] = p[i];
        m++;
    }

    if(m<3)return;
    stack<Point> s;
    s.push(p[0]);s.push(p[1]);s.push(p[2]);
    for(int i=3;i<m;i++){
        while(orientation(next_to_top(s),s.top(),p[i])!=2){
            s.pop();
        }
        s.push(p[i]);
    }

    while(!s.empty()){
        Point p = s.top();
        cout<<"("<<p.x<<","<<p.y<<")"<<endl;
        s.pop();
    }
}


