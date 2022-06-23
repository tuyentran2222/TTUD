#include<bits/stdc++.h>
using namespace std;
int N;
pair<int,int> a[50005],b[50005];
int st,en;
bool sapxep(pair<int,int> a,pair<int,int> b){
    return a.first< b.first;
}
double distance1(pair<int,int> l, pair<int,int> r){
    return (double)sqrt( pow((double)(l.first-r.first),2)+pow((double)(l.second-r.second),2));
}
typedef struct return1{
    double res;
    int st;
    int en;
}RE;
RE solve(pair<int,int> *a,int l,int r){
    RE minV;
    minV.res=0;
    if (l==r) {
         minV.res= 1e9;
         return minV;
    }
    if (l==r-1) {
        minV.res=distance1(a[l],a[r]);
        minV.st=l;
        minV.en=r;
        return minV;
    }
    if (l==r-2) {
        double a1=distance1(a[l],a[r]);
        double a2=distance1(a[l+1],a[l]);
        double a3=distance1(a[r],a[r-1]);

        minV.res= min(min(a1,a2),a3);
        if (minV.res==a1) {
            minV.st=l;
            minV.en=r;
        }
        if (minV.res==a2) {
            minV.st=l;
            minV.en=l+1;
        }
        if (minV.res==a3) {
            minV.st=r-1;
            minV.en=r;
        }
        return minV;
    }

        int mid=(l+r)/2;
        RE mR=solve(a,mid+1,r);
        RE mL=solve(a,l,mid-1);
        RE mLR;
        if (mR.res<mL.res){
            mLR=mR;
        }else mLR=mL;

        int i=mid;
        int j=mid;
        if(a[i].first<a[mid].first+mLR.res) i++;
        if(a[j].first>a[mid].first-mLR.res) j--;

        RE mM=solve(a,j,i);

        if (mLR.res<mM.res){
            minV=mLR;
        }else minV=mM;

    return minV;

}

int main(){
    cin>>N;
    for (int i=1;i<=N;i++){
        cin>>a[i].first>>a[i].second;
        b[i].first=a[i].first;
        b[i].second=a[i].second;
    }
    sort(b+1,b+N+1,sapxep);//tang theo x;
    RE r=solve(b,1,N);
    for (int i=1;i<=N;i++){
        if (a[i].first==b[r.st].first&&b[r.st].second==a[i].second){
            cout<<i-1<<" ";
        }
        if (a[i].first==b[r.en].first&&b[r.en].second==a[i].second){
            cout<<i-1<<" ";
        }
    }
    printf("%.6lf",r.res);
}
