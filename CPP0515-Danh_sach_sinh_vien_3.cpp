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

typedef struct SinhVien 
{
    string key = "B20DCCN", name, grade, birth;
    int cnt = 0;
    vector<string> name_x;
    string birth_x = "";
    float GPA;
} sv;
void nhap(sv *ds, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin.ignore();
        getline(cin, (ds + i)->name);
        cin >> (ds + i)->grade;
        cin >> (ds + i)->birth;
        cin >> (ds + i)->GPA;
        (ds + i)->cnt = i + 1;
    }
}   
void compact(sv &x)
{
    if(x.cnt < 10)
    {
        x.key += "00";
        x.key += to_string(x.cnt);
    }
    else if(x.cnt >= 10)
    {
        x.key += "0";
        x.key += to_string(x.cnt);
    }
}
bool cmp(SinhVien a, SinhVien b)
{
    return a.GPA > b.GPA;
}
void sapxep(sv *ds, int n)
{
    sort(ds, ds + n, cmp);
}
void in(sv *ds, int n)
{
    for(int i = 0; i < n; i++)
    {
        compact(*(ds + i));
        //cout << (ds + i)->key << " ";
        string s1 = (ds + i)->name;
        string sex;
        stringstream sss(s1);
        while(sss >> sex)
        {
            for(int ix = 0; ix < sex.size(); ix++)
            {
                if(ix == 0) sex[ix] = toupper(sex[ix]);
                else sex[ix] = tolower(sex[ix]);
            }
            (ds + i)->name_x.push_back(sex);
        }
        //cout << (ds + i)->grade << " ";
        string s = (ds + i)->birth;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '/') s[i] = ' ';
        }
        stringstream ss(s);
        string tmp;
        while(ss >> tmp)
        {
            if(tmp.size() == 4) (ds + i)->birth_x += tmp;
            else if(tmp.size() == 1) (ds + i)->birth_x = (ds + i)->birth_x + "0" + tmp + "/";
            else (ds + i)->birth_x = (ds + i)->birth_x + tmp + "/";
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << (ds + i)->key << " ";
        for(int ix = 0; ix < (ds + i)->name_x.size(); ix++)
        {
            cout << (ds + i)->name_x[ix] << " ";
        }
        cout << (ds + i)->grade << " " << (ds + i)->birth_x << " ";
        cout << setprecision(2) << fixed << (ds + i)->GPA << endl;
    }
}
int main(){
    struct SinhVien ds[50];
    int N;
    cin >> N;
    nhap(ds, N);
    sapxep(ds,N);
    in(ds, N);
    return 0;
}