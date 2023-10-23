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

typedef class SinhVien
{
public:
    string key = "B20DCCN", name, birth, grade;
    float GPA; int cnt = 0; static int demo;
    SinhVien(){}
    friend istream& operator >> (istream& in, SinhVien& other)
    {
        demo++; other.cnt = demo;
        in.ignore();
        getline(in, other.name);
        getline(in, other.grade);
        getline(in, other.birth);
        in >> other.GPA;
        return in;
    }
    friend ostream& operator << (ostream& out, SinhVien& other)
    {
        if(other.cnt < 10)
        {
            out << other.key << "00" << to_string(other.cnt) << " ";
        }
        else 
        {
            out << other.key << "0" << to_string(other.cnt) << " ";
        }
        string s1 = other.name, tmp1;
        stringstream sss(s1);
        while(sss >> tmp1)
        {
            for(int i = 0; i < tmp1.size(); i++)
            {
                if(i == 0) tmp1[i] = toupper(tmp1[i]);
                else tmp1[i] = tolower(tmp1[i]);
            }
            out << tmp1 << " ";
        }
        out << other.grade << " ";
        string s = other.birth; for(int i = 0; i < s.size(); i++) if(s[i] == '/') s[i] = ' ';
        string tmp; stringstream ss(s);
        while(ss >> tmp)
        {
            if(tmp.size() == 4) cout << tmp << " ";
            else if(tmp.size() == 2) cout << tmp << "/";
            else cout << "0" << tmp << "/";
        }
        out << setprecision(2) << fixed << other.GPA << endl;
        return out;
    }
    ~SinhVien(){}
} sv;
int SinhVien::demo = 0;
int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> ds[i];
    }
    for(i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}
/*AUTHOR: KHỔNG VĂN QUẢNG - PTIT*/