#include <iostream>
#include<string>
using namespace std;
int a[1000001];
int sum(string s){
  int result = 0;
  int tong=0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i]=='1') tong++;
    a[i]=tong;
  }
  int length=s.length();
  for (int i = 0; i < length; i++){
        for (int j = i+1; j < length; j=j+1){
            if (((j-i+1)*0.5)==a[j]) result++;
            if(s[i]=='1') a[j]--;
        }
  }

  return result;
 }

int main()
{   string s;
    cin>>s;

cout<<sum(s);
    return 0;
}
