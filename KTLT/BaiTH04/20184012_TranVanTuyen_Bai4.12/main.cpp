#include <iostream>
#include<vector>
#include<utility>
#include <bits/stdc++.h>
int n;
int max1=0;
using namespace std;
vector<pair<int,int>> c;
void input(){
  cin>>n;
  int a;//a:chieu cao
  for (int i=0;i<n;i++){
    cin>>a;
    c.push_back(make_pair(a,1));
  }
}
int main()
{   int j=0;
    input();
    for (int i=0;i<n;i++){
        j=i-1;
        while (j>=0){
             if(c[i].first<=c[j].first) {
                c[i].second++;
                //cout<<"i="<<i<<" ,"<<c[i].second<<" am" <<endl;
                j--;
             }
            else break;
        }
        j=i+1;
        while (j<n){
            if(c[i].first<=c[j].first){
             c[i].second++;
             //cout<<"i="<<i<<" ,"<<c[i].second<<" duong "<<endl;
             j++;
            }
            else break;
        }
    }

    for (int i=0;i<n;i++){
         if (max1<c[i].first*c[i].second) max1=c[i].first*c[i].second;
        //cout<<"pair="<<c[i].first<<","<<c[i].second<<endl;
    }
    cout<<max1;
    return 0;
}
