#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    double x1=sqrt(pow((a.first-b.first),2)+pow(a.second-b.second,2));
    double x2=sqrt(pow((a.first-c.first),2)+pow(a.second-c.second,2));
    double x3=sqrt(pow((c.first-b.first),2)+pow(c.second-b.second,2));
    double p=(x1+x2+x3)/2;
    return sqrt((p-x1)*(p-x2)*(p-x3)*p);
}

int main() {
	cout<<"Ho va ten:Tran Van Tuyen"<<endl;
	cout<<"MSSV:20184012"<<endl;
     cout << setprecision(2) << fixed;
     cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
     return 0;
}
