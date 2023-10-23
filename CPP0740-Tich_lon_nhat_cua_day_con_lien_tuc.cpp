#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<iomanip>
#include<string.h>
#include<ctype.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        long long pro_max = LLONG_MIN;
        for(int i = 1; i <= n; i++)
        {
            long long tmp = 1;
            for(int j = i; j <= n; j++)
            {
                tmp *= a[j];
                pro_max = max(pro_max, tmp);
            }
        }
        cout << pro_max << endl;
    }
}