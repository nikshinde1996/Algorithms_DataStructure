
#include "_GrahamScan_algo.h"
#include <iostream>
#include <stack>
#include <cstdlib>

struct Point{
    int x,y;
};

void convexHull(Point p[],int n);
int dis_square(Point p1,Point p2);
int orientation(Point p1,Point p2,Point p3);
void swap(Point &p1,Point &p2);
Point next_to_top(stack<Point> s);
int compare();

int main(){
    Point p[] = {{0,3},{1,1},{2,2},{4,4},{0,0},{1,2},{3,1},{3,3}};
    int n = sizeof(p)/ sizeof(p[0]);
    convexHull(p,n);
}