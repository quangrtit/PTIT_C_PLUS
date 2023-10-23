#include<iostream>
#include<string.h>
#include<ctype.h>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
class KhachHang 
{
public:
    friend class HoaDon;
    static int kt;
    int stt; string key_person = "";
    string name, sex, birth, adress;
    KhachHang(){}
    KhachHang(int stt, string key_person, string name, string sex, string birth, string adress)
    {
        this->stt = stt;
        this->key_person = key_person;
        this->name = name;
        this->sex = sex;
        this->birth = birth;
        this->adress = adress;
    }
    friend istream& operator >> (istream& in, KhachHang& other);
};
vector<KhachHang> KH;
istream& operator >> (istream& in, KhachHang& other)
{
    other.kt++; other.stt = other.kt;
    if(other.stt < 10) other.key_person = other.key_person + "KH00" + to_string(other.stt);
    else other.key_person = other.key_person + "KH0" + to_string(other.stt);
    if(other.kt == 1) in.ignore();
    getline(in, other.name);
    getline(in, other.sex);
    getline(in, other.birth);
    KH.push_back(KhachHang(other.stt, other.key_person, other.name, other.sex, other.birth, other.adress));
    return in;     
}
int KhachHang::kt = 0;
class MatHang
{
public:
    friend class HoaDon;
    static int kt1; int stt; string key_invoice = "";
    string name, unit; 
    int cost_buy, cost_sell;
    int money = 0;
    MatHang(){}
    MatHang(int stt, string key_invoice, string name, string unit, int cost_buy, int cost_sell)
    {
        this->stt = stt;
        this->key_invoice = key_invoice;
        this->name = name;
        this->unit = unit;
        this->cost_buy = cost_buy;
        this->cost_sell = cost_sell;
    }
    friend istream& operator >> (istream& in, MatHang& other);
};
vector<MatHang> MH;
istream& operator >> (istream& in, MatHang& other)
{
    other.kt1++; other.stt = other.kt1; 
    if(other.stt < 10) other.key_invoice = other.key_invoice + "MH00" + to_string(other.stt);
    else other.key_invoice = other.key_invoice + "MH0" + to_string(other.stt);
    in.ignore();   
    getline(in, other.name);
    getline(in, other.unit);
    in >> other.cost_buy;
    in >> other.cost_sell;
    other.money += other.cost_sell - other.cost_buy;
    MH.push_back(MatHang(other.stt, other.key_invoice, other.name, other.unit, other.cost_buy, other.cost_sell));
    return in;
}
int MatHang::kt1 = 0;
class HoaDon 
{
public:
    static int kt2; int stt;
    string key_invoice = "", key_person, key_goods;
    int sl = 0;
    friend istream& operator >> (istream& in, HoaDon& other)
    {
        in.ignore();
        kt2++; other.stt = kt2;
        if(other.stt < 10) other.key_invoice = other.key_invoice + "HD00" + to_string(other.stt);
        else other.key_invoice = other.key_invoice + "HD0" + to_string(other.stt);
        getline(in, other.key_person);
        getline(in, other.key_goods);
        in >> other.sl;
        return in;
    }
    friend ostream& operator << (ostream& out, HoaDon& other)
    {
        out << other.key_invoice << " ";
        for(int i = 0; i < KH.size(); i++)
        {
            if(KH[i].key_person == other.key_person)
            {
                out << KH[i].name << " " << KH[i].adress << " ";
                break;
            }
        }
        for(int i = 0; i < MH.size(); i++)
        {
            if(MH[i].key_invoice == other.key_invoice)
            {
                out << MH[i].name << " " << MH[i].unit << " " << MH[i].cost_buy << " " << MH[i].cost_sell << " " << other.sl << " " << MH[i].cost_sell * other.sl << endl;
            }
        }   
        return out;
    }
};
int HoaDon::kt2 = 0;
int main(){
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N,M,K,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> dskh[i];
    cin >> M;
    for(i=0;i<M;i++) cin >> dsmh[i];
    cin >> K;
    for(i=0;i<K;i++) cin >> dshd[i];
    //cout << "ok: " << MH.size() << " " << KH.size() << endl;
    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}