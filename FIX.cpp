// #include<iostream>
// #include<math.h>
// #include<cmath>
// #include<string.h>
// #include<ctype.h>
// #include<unistd.h>
// #include<set>
// #include<limits.h>
// #include<map>
// #include<queue>
// #include<algorithm>
// #include<iomanip>
// #include<deque>
// #include<bitset>
// using namespace std;
// #define MOD 1000000007
// #define endl '\n'
// #define fast() ios::sync_with_stdio(false); cin.tie(0);


// long long sgn(long long n, long long s)
// {
//     return min(n, s);
// }
// void task1()
// {
//     long long n, s; cin >> n >> s;
//     long long cnt = 0;
//     while(s > 0 && n > 0)
//     {
//         cnt += s / sgn(s, n);
//         s = s - (s / sgn(s, n)) * sgn(s, n);
//         n = s;
//         //cout << sgn(s, n) << endl;
//     }
//     cout << cnt << endl;
// }
// int tv(char x)
// {
//     if(x == 'I') return 1;
//     else if(x == 'V') return 5;
//     else if(x == 'X') return 10;
//     else if(x == 'L') return 50;
//     else if(x == 'C') return 100;
//     else if(x == 'D') return 500;
//     else return 1000;
// }
// long long minx(long long a, long long b)
// {
//     if(a < b) return a;
//     else return b;
// }
// void task2()
// {
//     long long k2, k3, k5, k6; cin >> k2 >> k3 >> k5 >> k6;
//     long long check = minx(k2, minx(k5, k6));
//     long long tmp = minx(k2 - check, k3);
//     cout << (long long)(256 * (long long)check) + (long long)(32 * (long long)tmp);
// }
// int main()
// {
//     fast();
//     task2();
// }
#include<iostream>
#include<math.h>
#include<cmath>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<set>
#include<limits.h>
#include<map>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<deque>
#include<bitset>
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);


long long sgn(long long n, long long s)
{
    return min(n, s);
}
void task1()
{
    long long n, s; cin >> n >> s;
    long long cnt = 0;
    while(s > 0 && n > 0)
    {
        cnt += s / sgn(s, n);
        s = s - (s / sgn(s, n)) * sgn(s, n);
        n = s;
        //cout << sgn(s, n) << endl;
    }
    if(cnt != 0) cout << cnt << endl;
    else cout << "IMPOSSIBLE" << endl;
}
int main()
{
    fast();
    task1();
}
