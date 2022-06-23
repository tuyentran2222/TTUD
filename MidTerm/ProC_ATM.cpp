#include<bits/stdc++.h>
using namespace std;
int a[12];//so cach
int b[12];//so to tien
int n;
unsigned long long W;
int c;
int main(){
    cin>>n;
    a[0]=1;a[1]=1;a[2]=1;a[3]=1;
    a[4]=2;a[5]=1;a[6]=2;a[7]=1;
    a[8]=1;a[9]=3;a[10]=1;a[11]=1;

    b[0]=0;b[1]=b[2]=1;b[3]=1;
    b[4]=2;b[5]=1;b[6]=2;b[7]=2;
    b[8]=2;b[9]=3;b[10]=1;b[11]=2;
    while(n--){
        int soToTien=0;
        int soCach=1;
        //int res=0;
        int hs=1;
        cin>>W>>c;
        W=W/1000;
        unsigned long long temp=(pow(10,c));
        for (int i=c;i>=0;i--){
            double v= (double) W*1.0/(pow(10,i));
            unsigned long long u=W/(pow(10,i));
            cout<<"u1= "<<u<<" "<<"temp= "<<temp<<endl;
            if (u>=10*temp){
                hs=u/temp;
                u=u%temp;
            }
            cout<<"u2= "<<u<<" "<<"temp= "<<temp<<endl;

            W=W%(unsigned long long)(pow(10,i));
            //cout<<"u= "<<u<<"  W= "<<W<<endl;
            soToTien+=b[u]*hs;
            soCach*=a[u]*hs;


        }

        cout<<soToTien<<" "<<soCach<<endl;
    }

}
