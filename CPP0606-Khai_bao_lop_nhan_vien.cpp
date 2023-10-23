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

class NhanVien
{
public:
    string name, sex, birth, address, key, day;
    string keyx = "00001";
    NhanVien(){}
    friend istream& operator>>(istream& in, NhanVien& other)
    {
        getline(in, other.name);
        getline(in, other.sex);
        getline(in, other.birth);
        getline(in, other.address);
        getline(in, other.key);
        getline(in, other.day);
        return in;  
    }
    friend ostream& operator<<(ostream& out, NhanVien& other)
    {
        out << other.keyx << " " << other.name << " " << other.sex << " " << other.birth << " " << other.address << " " << other.key << " " << other.day << endl;
        return out;
    }
    ~NhanVien(){}
};
int main(){
    NhanVien a;
    cin >> a;
    cout << a;
    return 0;
}