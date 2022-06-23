#include<bits/stdc++.h>
using namespace std;
int n;
int dem=INT_MAX;
int main(){
    cin>>n;
    for (int i=0;i<=1000/500;i++){
        int j1=(1000-500*i)/100;
        for (int j=0;j<=j1;j++){
            int z1=(1000-500*i-100*j)/50;
            for (int z=0;z<=z1; z++){
                int x1=(1000-500*i-100*j-50*z)/10;
                for (int x=0;x<=x1; x++){
                    int y1=(1000-500*i-100*j-50*z-10*x)/5;
                        for (int y=0;y<=y1; y++){
                             int u1=(1000-500*i-100*j-50*z-10*x-5*y);
                            for (int u=0;u<=u1;u++){
                                if (i*500+j*100+x*10+y*5+z*50+u==1000-n){
                                    dem=min(dem,i+j+x+y+z+u);
                                }
                            }
                        }
                }
            }
        }
    }
    cout<<dem;
}
