#include<bits/stdc++.h>
using namespace std;

int main(){
    const int N=1000005;
    int n;
    cin>>n;
    while(n!=0){
        unsigned long long a[N],left[N],right[N];
        a[0]=-1;a[n+1]=-1;
        unsigned long long  top;
        for(int i = 1; i <= n; i++) cin >> a[i];
        stack<int> s;
        for (int i=1;i<=n;i++){
            //cout<<s.empty();
            if (s.empty()){
                left[i]=0;
                s.push(i);
            }
            else{
                top=s.top();
                while (a[i]<=a[top]){
                    s.pop();
                    if (s.empty()){
                        left[i]=0;
                        top=0;
                    }
                    else{
                        top=s.top();
                    }

                }
                s.push(i);

                left[i]=top;
            }
        }
        stack<int> s1;
        for (int i=n;i>=1;i--){
            //cout<<s.empty();
            if (s1.empty()){
                right[i]=n+1;
                s1.push(i);
            }
            else{
                top=s1.top();
                while (a[i]<=a[top]){
                    s1.pop();
                    if (s1.empty()){
                        right[i]=n+1;
                        top=n+1;
                    }
                    else{
                        top=s1.top();
                    }

                }
                s1.push(i);

                right[i]=top;
            }
        }


        unsigned long long  max1=0;
        for (int i=1;i<=n;i++){
            max1=max((right[i]-left[i]-1)*a[i],max1);
        }
        cout<<max1<<endl;
        cin>>n;
    }


}

