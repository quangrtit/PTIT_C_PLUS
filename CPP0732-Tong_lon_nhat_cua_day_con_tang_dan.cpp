#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string>
#include<cctype>
#include<set>
#include<limits.h>
#include<map>
#include<queue>
#include<algorithm>
#include<iomanip>
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define PI 3.141592653589793238
#define fast() ios::sync_with_stdio(false); cin.tie(0);

int main()
{
    fast();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // vector<int> f(n, 0);
        int f[n] = {0}; f[0] = a[0];
        for(int i = 1; i < n; i++)
        {
            f[i] = a[i];
            for(int j = 0; j < i; j++)
            {
                if(a[i] > a[j])
                {
                    f[i] = max(f[j] + a[i], f[i]);
                }
            }
        }
        int check_max = 0;
        for(int i = 0; i < n; i++)
        {
            check_max = max(check_max, f[i]);
        }
        cout << check_max << endl;
    }
}
//f[i] = f[j] + a[i] neu a[i] >= a[j]
// f[i] = f[i - 1]