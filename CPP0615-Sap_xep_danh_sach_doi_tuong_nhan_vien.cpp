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
    long long time = 0;
    static int cnt;
    NhanVien(){}
    void create_day()
    {
        long long day = (this->birth[0] - '0') * 10 + this->birth[1] - '0'; day = day * 30;
        long long month = (this->birth[3] - '0') * 10 + this->birth[4] - '0'; 
        long long year = ((this->birth[6] - '0') * 1000) + (this->birth[7] - '0') * 100 + (this->birth[8] - '0') * 10 + this->birth[9] - '0'; year = year * 365;
        this->time = this->time + day + month + year;
        //cout << cnt << "->" << this->time << endl;
    }
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
        other.create_day();
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
bool cmp(NhanVien a, NhanVien b)
{
    return a.time < b.time;
}
void sapxep(NhanVien* ds, int n)
{
    sort(ds, ds + n, cmp);
}
int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    sapxep(ds, N);
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}