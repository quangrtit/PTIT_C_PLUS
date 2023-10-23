#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        long long f[n + 1];
        f[0] = 0;
        f[1] = a[1];
        for(int i = 2; i <= n; i++)
        {
            f[i] = f[i - 1] + a[i];
        }
        double average = LLONG_MIN * 1.0;
        for(int i = k; i <= n; i++)
        {
            average = max(average, (f[i] - f[i - k]) / (k * 1.0));
        }
        int location = -1;
        for(int i = k; i <= n; i++)
        {
            if((f[i] - f[i - k]) / (k * 1.0) == average)
            {
                location = i;
                break;
            }
        }
        for(int i = location - k + 1; i <= location; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}