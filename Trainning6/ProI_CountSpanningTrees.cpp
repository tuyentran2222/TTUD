#include<bits/stdc++.h>
using namespace std;

int n,m;
float mt[20][20];
float mt1[21][21];
vector<int> ds[21];
float tinh(float a[][20], int n)
{
 //khai báo biến và mảng
 int i, j, k, dem = 0,kt=0;
 float b[20], c[20], h, det = 1;
 for (i = 0; i < n - 1; i++)
 {
  //nếu số ở đường chéo chính =0 thì biến đổi để mất số 0 đó đi
  if (a[i][i] == 0)
  {
   //tìm 1 số khác không trên hàng i
   for (j = 0; j < n; j++)
   if (a[i][j] != 0)
   {
    //tiến hành đổi chổ 2 cột i và j
    for (k = 0; k < n; k++)
    {
     c[k] = a[k][i];
     a[k][i] = a[k][j];
     a[k][j] = c[k];
    }
    //sau khi đổi xong thì đếm số lần đổi và thoát khỏi vòng for,if
    dem++;
    kt++;
    break;
   }
   if (kt == 0) return 0;

  }
  //dùng mảng b[i] để lưu lại những số ta đã chia
  b[i] = a[i][i];
  //tạo số 1 ở dòng i cột i
  for (j = 0; j < n; j++) a[i][j] = a[i][j] / b[i];
  //tiến hành biến đổi để có các số 0 tạo thành ma trận tam giác
  for (j = i + 1; j < n; j++)
  {
   h = a[j][i];
   for (k = 0; k < n; k++) a[j][k] = a[j][k] - h*a[i][k];
  }
 }
 //vì số thứ [n][n] ta không thể biến nó thành số 0 do nó là hàng cuối cùng
 b[n - 1] = a[n - 1][n - 1];
 //giá trị của định thức là tích các số mà ta đã chia, tức là b[i]
 for (i = 0; i < n; i++) det *= b[i];
 // nếu số lần đổi cột là số lẻ thì ta cần thêm dấu trừ vào định thức đã tính ở trên
 if (dem % 2 == 0) return det; else return -det;
}
int main(){
    cin>>n>>m;
    int a,b;
    for (int i=1;i<=m;i++){
        cin>>a>>b;
        ds[a].push_back(b);
        ds[b].push_back(a);
        mt1[a][b]=-1;
        mt1[b][a]=-1;
    }
    for (int i=1;i<=n;i++){
        mt1[i][i]=ds[i].size();
    }

    for (int i=1;i<=n-1;i++){
        for (int j=1;j<=n-1;j++){
            mt[i-1][j-1]=mt1[i+1][j+1];
        }
    }
    cout<<tinh(mt,n-1);
}
