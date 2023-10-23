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
class PhanSo
{
public:
    long long son, mom;
    PhanSo(long long son1, long long mom1){this->son = son1; this->mom = mom1;}
    friend istream& operator>>(istream& in, PhanSo& other)
    {
        in >> other.son >> other.mom; return in;
    }
    void fix()
    {
        long long tmp = __gcd(this->son, this->mom);
        this->son /= tmp;
        this->mom /= tmp;
    }
    PhanSo &operator+(PhanSo& a)
    {
        long long tmp = __gcd(a.mom, this->mom);
        long long lcm = a.mom * this->mom / tmp;
        this->son = a.son * (lcm / a.mom) + this->son * (lcm / this->mom);
        this->mom = lcm;
        this->fix();
        return *this;
    }
    friend ostream& operator<<(ostream& out, PhanSo& other)
    {
        out << other.son << "/" << other.mom; return out;
    }
    ~PhanSo(){}
};
int main() {
	PhanSo p(1,1), q(1,1);
	cin >> p >> q;
    cout << p + q;
	return 0;
}
/*AUTHOR: KHỔNG VĂN QUẢNG - PTIT*/