#include<bits/stdc++.h>
using namespace std;
int n,k;

typedef struct PosMan{
     long long x;
     long long m;
} PS;
vector<PS> a,b;

bool compare1(PS a,PS b){
     return (a.x)>(b.x);
}

long long posManTime(vector<PS> a){
    int i=0,j=0;
    long long time=0;
    int conlai=0;
    for (i=0;i<a.size();i++){
        int solan=a[i].m/k;
        if (a[i].m%k) solan++;
        time=solan*a[i].x*2+time;
        conlai=solan*k-a[i].m+conlai;
        if (conlai>0){
            if (i<a.size()-1){
                if (conlai<=a[i+1].m){

                    a[i+1].m=a[i+1].m-conlai;
                    conlai=0;
                }
                else {

                    conlai=conlai-a[i+1].m;
                    a[i+1].m=0;

                }
            }
        }
    }
    return time;
}

int main(){
    cin>>n>>k;
    int dem=0;
    long long x,m;

    while (dem!=n){
        cin>>x>>m;
        PS ps;

        if (x>0) {
            ps.x=x;
            ps.m=m;
            a.push_back(ps);
            dem++;
        }
        else{
            ps.x=-x;
            ps.m=m;
            b.push_back(ps);
            dem++;
        }
    }
    sort(a.begin(),a.end(),compare1);
    sort(b.begin(),b.end(),compare1);

    cout<<posManTime(a)+posManTime(b);
}
