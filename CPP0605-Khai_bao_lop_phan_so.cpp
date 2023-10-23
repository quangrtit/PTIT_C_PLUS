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
    PhanSo(long long son, long long mom){this->son = son; this->mom = mom;}
    void rutgon()
    {
        long long gcd = __gcd(this->son, this->mom);
        this->son /= gcd;
        this->mom /= gcd;
    }
    friend istream& operator>>(istream& in, PhanSo& other)
    {
        in >> other.son >> other.mom;
        return in;  
    }
    friend ostream& operator<<(ostream& out, PhanSo& other)
    {
        out << other.son << "/" << other.mom << endl;
        return out;
    }
    ~PhanSo(){}
};
int main() {
	PhanSo p(1,1);
	cin >> p;
	p.rutgon();
	cout << p;
	return 0;
}