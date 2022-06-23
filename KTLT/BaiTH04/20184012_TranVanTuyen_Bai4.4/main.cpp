#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    vector<int> m;

    int length=int(a.size());
    for (int i=0;i<length;i++){
        if (a.at(i)%2!=0){
            m.push_back(a.at(i));
        }
    }
    a.clear();
    for(int i=0;i<int(m.size());i++){
        a.push_back(m.at(i));
    }


}

void sort_decrease(vector<int> &a) {
    sort(a.begin(),a.end(),greater<int>());
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> c;
    for (int i=0;i<int(b.size());i++){
        c.push_back(b.at(i));
    }
    for (int i=0;i<int(a.size());i++){
        c.push_back(a.at(i));
    }

    sort_decrease(c);
    return c;
}

int main() {
    cout<<"Ho va ten:Tran Van Tuyen"<<endl;
    cout<<"MSSV:20184012"<<endl;
    int m, n, u;
    std::vector<int> a, b;

    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
