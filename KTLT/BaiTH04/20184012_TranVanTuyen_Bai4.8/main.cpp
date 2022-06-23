#include <iostream>
#include <map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
        map<T,double> c;
        for (const auto &x : a) {
             if(b.count(x.first)==0){
                c.insert(pair<T,double>(x.first,x.second));
             }
             else{
                double s=b.find(x.first)->second;
                if(s>x.second){
                    c.insert(pair<T,double>(x.first,b.find(x.first)->second));

                }
                else{
                     c.insert(pair<T,double>(x.first,x.second));
                }
             }
     }
      for (const auto &x : b) {
        if(a.count(x.first)==0){
                c.insert(pair<T,double>(x.first,x.second));
        }
      }
     return c;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
        map<T,double> c;
        for (const auto &x : a) {
             if(b.count(x.first)==0){

             }
             else{
                double s=b.find(x.first)->second;
                if(s<x.second){
                    c.insert(pair<T,double>(x.first,b.find(x.first)->second));

                }
                else{
                     c.insert(pair<T,double>(x.first,x.second));
                }
             }
       }

     return c;
}

 template<class T>
 void print_fuzzy_set(const std::map<T, double> &a) {
     cout << "{ ";
     for (const auto &x : a) {
         std::cout << "(" << x.first << ", " << x.second << ") ";
     }
     cout << "}";
     std::cout << std::endl;
 }

 int main() {
     cout<<"Ho va ten:Tran van Tuyen"<<endl;
     cout<<"MSSV:20184012"<<endl;
     std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
     std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
     std::cout << "A = "; print_fuzzy_set(a);
     std::cout << "B = "; print_fuzzy_set(b);
     std::map<int, double> c = fuzzy_set_union(a, b);
     std::map<int, double> d = fuzzy_set_intersection(a, b);
     std::cout << "Union: "; print_fuzzy_set(c);
     std::cout << "Intersection: "; print_fuzzy_set(d);
}
