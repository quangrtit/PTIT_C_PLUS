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

bool nt(long long n)
{
    if(n < 2)
    {
        return false;
    }
    else if(n == 2)
    {
        return true;
    }
    else 
    {
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}
void task1()
{
    int t; cin >> t;
    while(t--)
    {
        long long n; cin >> n;
        long long n1 = n;
        long long cnt = 0;
        while(n % 2 == 0)
        {
            cnt++;
            n = n / 2;
        }   
        //cnt++;
        if(n1 == (long long)pow(2, cnt) * ((long long)pow(2, cnt + 1) - 1))
        {
            if(nt((long long)pow(2, cnt + 1) - 1))
            {
                cout << 1 << endl;
            }
            else 
            {
                cout << 0 << endl;
            }
        }
        else 
        {
            cout << 0 << endl;
        }
    }
}
// n = 2 ^ (p - 1) * (2 ^ p - 1) trong đó 2 ^ p - 1 là số nguyên tố
// định lí https://vi.wikipedia.org/wiki/%C4%90%E1%BB%8Bnh_l%C3%BD_Euclid%E2%80%93Euler#:~:text=%C4%90%E1%BB%8Bnh%20l%C3%BD%20Euclid%E2%80%93Euler%20l%C3%A0,1%20l%C3%A0%20s%E1%BB%91%20nguy%C3%AAn%20t%E1%BB%91.
int main()
{
    fast();
    task1();
}