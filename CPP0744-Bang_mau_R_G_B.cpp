#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<limits.h>
#include<iomanip>
#include<string.h>
#include<ctype.h>
#define MOD 1000000007
using namespace std;
vector<long long> factorial(21);
void fac()
{
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i <= 20; i++)
    {
        factorial[i] = factorial[i - 1] * i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    fac();
    int t; cin >> t;
    while(t--)
    {
        int n, r, g, b;
        cin >> n >> r >> g >> b;
        long long count = 0;
        for(int i = r; i <= n; i++)
        {
            for(int j = g; j + i <= n; j++)
            {
                for(int e = b; e + j + i <= n; e++)
                {   
                    //if(i + j + e <= n) cout << i << " " << j << " " << e << endl;
                    if(i + j + e == n) count += factorial[i + j + e] / (factorial[i] * factorial[j] * factorial[e]);
                }
            }
        }
        cout << count << endl;
    }
}