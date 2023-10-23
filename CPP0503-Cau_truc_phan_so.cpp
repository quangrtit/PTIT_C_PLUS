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
    friend istream& operator>>(istream& in, PhanSo& other)
    {
        in >> other.son >> other.mom; return in;
    }
    friend ostream& operator<<(ostream& out, PhanSo& other)
    {
        out << other.son << "/" << other.mom << endl;
        return out;
    }
    void compact()
    {
        long long gcd = __gcd(son, mom);
        son = son / gcd;
        mom = mom / gcd;
    }
};
void nhap(PhanSo& a)
{
    cin >> a;
}
void rutgon(PhanSo& a)
{
    a.compact();
}
void in(PhanSo& a)
{
    cout << a;
    //a.son != 0 ? cout << a : cout << 0 << endl;
}
int main() {
	struct PhanSo p;
	nhap(p);
	rutgon(p);
	in(p);
	return 0;
}