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
#define fast() ios::sync_with_stdio(false); cin.tie(0);

struct PhanSo
{
    long long son = 1, mom = 1; 
    void compact()
    {
        long long tmp = __gcd(son, mom);
        son /= tmp; mom /= tmp;
    }
};
void nhap(PhanSo& a)
{
    cin >> a.son >> a.mom;
}
PhanSo tong(PhanSo a, PhanSo b)
{
    long long tmp = __gcd(a.mom, b.mom);
    long long lcm = (a.mom * b.mom) / tmp;
    PhanSo result; 
    result.son = a.son * (lcm / a.mom) + b.son * (lcm / b.mom);
    result.mom = lcm;
    result.compact();
    return result;
}
void in(PhanSo& a)
{
    cout << a.son << "/" << a.mom << endl;
}
int main() {
	struct PhanSo p,q;
	nhap(p); nhap(q);
	PhanSo t = tong(p,q);
	in(t);
	return 0;
}
/*AUTHOR: KHỔNG VĂN QUẢNG - PTIT*/