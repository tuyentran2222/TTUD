#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int n,m,k;
int dem=0;
int comb(int n, int m)
{
    std::string bitmask(m, 1); // K leading 1's
    bitmask.resize(n, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do {
        dem++;
        if (dem==k){
            for (int i = 0; i < n; ++i) // [0..N-1] integers
            {
                if (bitmask[i]) std::cout << i+1<<" ";
            }
            return 1;
        }

    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
    return 0;
}
int main()
{
    cin>>n>>m>>k;
    int res=comb(n,m);
    if (res==0) cout<<-1;
}
