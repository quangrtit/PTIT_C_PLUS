#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<set>
#include<limits.h>
#include<map>
#include<queue>
#include<algorithm>
#include<iomanip>
using namespace std;
#define MOD 1000000007
#define endl '\n'
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
int sum_digit(int n)
{
    int result = 0;
    while(n > 0)
    {
        result += n % 10;
        n = n / 10;
    }
    return result;
}
void solve()
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        while(n >= 10)
        {
            n = sum_digit(n);
        }
        printf("%d\n", n);
    }
}
int main()
{
    fast();
    solve();
}