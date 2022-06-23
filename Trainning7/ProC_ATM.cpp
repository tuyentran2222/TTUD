#include<bits/stdc++.h>
using namespace std;

int ways[10]={1,1,1,1,2,1,2,1,1,3};
int cnt[10] ={0,1,1,1,2,1,2,2,2,3};
int t,w,c;
int cx10[16];
int main(){
    cin>>t;
    while(t--){
        cin>>w>>c;
        int soToTien=0;
        int soCach=1;
        int u=w/1000;
        if (w!=1000*u) {
            cout<<0<<endl;
            continue;
        }
        w=u;
        int maxx=pow(10,c+1);
        if (w>=maxx){
            maxx=maxx/2;
            soToTien+=w/maxx;
            w=w-soToTien*maxx;
        }
        if (w<maxx){
            for (int i=c+1;i>=1;i--){
                maxx=pow(10,i-1);
                int q=w/maxx;
                soToTien+=cnt[w/maxx];
                soCach*=ways[w/maxx];
                w=w-q*maxx;
            }
        }
        cout<<soToTien<<" "<<soCach<<endl;
    }
}
