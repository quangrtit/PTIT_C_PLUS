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
#define PI 3.141592653589793238
#define fast() ios::sync_with_stdio(false); cin.tie(0);

class NhanVien
{
public:
    string key = "", name, sex, birth, address, key_x, day;
    static int cnt;
    NhanVien(){}
    friend istream& operator >> (istream& in, NhanVien& other)
    {
        cnt++; 
        if(cnt == 1) in.ignore();
        if(cnt < 10) other.key = other.key + "0000" + to_string(cnt);
        else other.key = other.key + "000" + to_string(cnt);
        getline(in, other.name);
        getline(in, other.sex);
        getline(in, other.birth);
        getline(in, other.address);
        getline(in, other.key_x);
        getline(in, other.day);
        return in;
    }
    friend ostream& operator << (ostream& out, NhanVien& other)
    {
        out << other.key << " " << other.name << " " << other.sex << " " << other.birth << " " << other.address << " " << other.key_x << " " << other.day << endl;
        return out; 
    }
    ~NhanVien(){}
};
int NhanVien::cnt = 0;
int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}