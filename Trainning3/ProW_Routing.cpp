#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define MAX 100
int n;//so thanh pho
int cmin=INT_MAX;//chi phi nho nhat giua hai diem
int best=INT_MAX;//tong chi phi nho nhat
int mark[MAX];
int x[MAX];
int r;
int curr;
vector<vector<int>> c;
vector<vector<int>> d;
void input(){
    string l;
	string segment;
    cin >> n>> r;
    vector<int> k;
    for (int i=1;i<=n+1;i++){
    	getline(cin, l);
		stringstream test(l);
		while(getline(test, segment, ' '))
		{
		   int x=atoi(segment.c_str());
           k.push_back(x);
		}
		c.push_back(k);
		k.clear();
	}

    for (int i=1;i<=r;i++){
        getline(cin, l);
		stringstream test(l);
		while(getline(test, segment, ' '))
		{
		   int x=atoi(segment.c_str());
           k.push_back(x);
           if (x>0) cmin=min(cmin,x);
		}
		d.push_back(k);
		k.clear();
    }

}

void TRY(int k,int l){
    x[1]=d[l].at(0);
    int length=d[l].size();
    x[length]=d[l].at(length-1);
    for(int i=1;i<d[l].size()-1;i++){
        if (mark[d[l].at(i)]==0){
            mark[d[l].at(i)]=1;
            x[k]=d[l].at(i);
            if (c[x[k-1]].at(x[k]-1)!=0){
                curr=curr+c[x[k-1]].at(x[k]-1);
            }
            else {mark[d[l].at(i)]=0;continue;}
            if(k==length-1){
                    if ((curr+c[x[k]].at(x[length]-1)<best && c[x[k]].at(x[length]-1)>0))
                        {
                            best=curr+c[x[k]].at(x[length]-1);
                        }
            }
            else{
                if (curr+(length-k)*cmin<best) TRY(k+1,l);

            }
            curr=curr-c[x[k-1]].at(x[k]-1);
            mark[d[l].at(i)]=0;
        }

    }

}


int main()
{
   input();
   for(int i=0;i<r;i++){
        curr=0;
        if (d[i].size()==1) cout<<0<<endl;
        else if(d[i].size()==2) cout<<c[d[i].at(0)].at(d[i].at(1)-1);
        else {

            TRY(2,i);

            if(best==INT_MAX) cout<<0<<endl;
            else cout<<best<<endl;

            for (int j=1;j<n+1;j++){
                mark[j]=0;
            }
            best=INT_MAX;
        }
   }
}
