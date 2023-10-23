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

vector<int> a(1000001);
void sang()
{
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i <= sqrt(1000000); i++)
    {
        if(a[i] == 0)
        {
            for(int j = i * i; j <= 1000000; j += i)
            {
                a[j] = 1;
            }
        }
    }
}
int sum_digit(int n)
{
    int sum_tmp = 0;
    while(n > 0)
    {
        sum_tmp += n % 10;
        n = n / 10;
    }
    return sum_tmp;
}
long long ucl_prime(int n)
{
    long long sum_tmp = 0;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                sum_tmp += sum_digit(i);
                n = n / i;
            }
        }
    }
    if(n != 1) sum_tmp += sum_digit(n);
    return sum_tmp;
    // if(sqrt(n) == (int)sqrt(n))
    // {
    //     if(a[(int)sqrt(n)] == 0)
    //     {
    //         sum_tmp -= sum_digit((int)sqrt(n));
    //     }
    // }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    sang();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        if(a[n] == 1)
        {
            if(sum_digit(n) == ucl_prime(n))
            {
                cout << "YES" << endl;
            }
            else 
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;   
        }
    }
}