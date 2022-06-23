#include <iostream>
#include<vector>
#include<utility>
#include <bits/stdc++.h>

using namespace std;
int n;//số bức tường
int s;//số lính thủ nhà
vector<pair<int,int>> c;
vector<pair<int,int>> d;
void input(){
  cin>>n>>s;
  int a;//a:so giac tan cong buc tuong i
  int k;//so ten giac ma 1 linh co the tieu diet

  for (int i=0;i<n;i++){
    cin>>a>>k;
    c.push_back(make_pair(a,k));
  }
}

int main()
{   int m1,m2,m3;
    input();
    int kk=0;
    int sd=0;
    for(int i=0;i<c.size();i++){
        m1=c[i].second;
        m2=c[i].first/c[i].second;
        m3=c[i].first-m2*c[i].second;
        d.push_back(make_pair(m1,m2));
        if(m3!=0){
            d.push_back(make_pair(m3,1));
        }
    }

   sort(d.begin(),d.end());
   for(int i=d.size()-1;i>=0;i--){
        if(kk<s){
            kk=kk+d[i].second;
            if(kk>s) {
                sd=(kk-s)*d[i].second;
            }
        }
        else sd=sd+d[i].second*d[i].first;
   }
   cout<<sd;

}
