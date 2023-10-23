#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string.h>
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
#define fast() ios::sync_with_stdio(false); cin.tie(0);
void demo()
{
    fast();
    int n; cin >> n;
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i != j)
            {
                if(a[i].find(a[j]) != string::npos)
                {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}
int main()
{
    demo();
}