#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int kiemtra(int a,int b,int c){
    int aq=0,bq=0; int step=0;
    int t;
    if (c<=a||c<=b){
        if (c%__gcd(a,b)==0){
            while(aq!=c &&bq!=c){
                if (aq==0){
                    aq=a;
                    step++;
                }
                else if(bq==b){
                    bq=0;
                    step++;
                }
                else{
                    t=min(aq,b-bq);
                    bq=bq+t;
                    aq=aq-t;
                    step++;
                }
            }
            return step;
        }
        else return -1;
    }

    else {
        return -1;
    }

}
int main(){
    cin>>a>>b>>c;
    cout<<min(kiemtra(a,b,c),kiemtra(b,a,c));
    return 0;

}
