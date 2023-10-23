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
    long long tu, mau;
    PhanSo(){this->tu = 1; this->mau = 1;}
    // friend istream& operator >> (istream& in, PhanSo& other)
    // {
    //     in >> other.tu >> other.mau;
    //     return in;
    // }
    void compact()
    {
        long long gcd = __gcd(this->tu, this->mau);
        this->tu /= gcd;
        this->mau /= gcd;
    }
    friend PhanSo operator + (PhanSo a, PhanSo b)
    {
        PhanSo result;
        result.tu = a.tu * b.mau + a.mau * b.tu;
        result.mau = a.mau * b.mau;
        result.compact();
        return result;
    }
    friend PhanSo operator * (PhanSo a, PhanSo b)
    {
        PhanSo result;
        result.tu = a.tu * b.tu;
        result.mau = a.mau * b.mau;
        result.compact();
        return result;
    }
    friend ostream& operator << (ostream& out, PhanSo& other)
    {
        out << other.tu << "/" << other.mau << " ";
        return out;
    }
    ~PhanSo(){}
};
void process(PhanSo &a, PhanSo& b)
{
    PhanSo x1 = a + b;
    PhanSo C =  x1 * x1;
    PhanSo x2 = a * b;
    PhanSo D = x2 * C;
    cout << C;
    cout << D;
    cout << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		PhanSo A;
		PhanSo B;
		cin >> A.tu >> A.mau >> B.tu >> B.mau;
		process(A, B);
	}
}
/*AUTHOR: KHỔNG VĂN QUẢNG - PTIT*/