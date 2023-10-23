#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<iomanip>
#include<string.h>
#include<ctype.h>
#define MOD 1000000007
using namespace std;


vector<long long> a(1001);
void fibo()
{
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i <= 1000; i++)
    {
        a[i] = (a[i - 1] + a[i - 2]) % MOD;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    fibo();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << a[n] << endl;
    }
}