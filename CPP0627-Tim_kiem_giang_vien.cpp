#include<iostream>
#include<string.h>
#include<ctype.h>
#include<iomanip>
#include<vector>
#include<algorithm>

using namespace std;

class teacher
{
public:
    int stt; string subject, name; 
    string key = "";
    vector<string> name_compact;
    string check_name = "";
    string subject_compact = "";
    void compact();
};
void teacher::compact()
{
    // fix name
    for(int i = 0; i < this->name.size(); i++)
    {
        check_name += tolower(this->name[i]);
    }
    string s = this->name;
    string tmp;
    stringstream ss(s);
    while(ss >> tmp)
    {
        for(int i = 0; i < tmp.size(); i++)
        {
            if(i == 0) tmp[0] = toupper(tmp[0]);
            else tmp[i] = tolower(tmp[i]);
        }
        this->name_compact.push_back(tmp);
    }
    string s1 = this->subject;
    string cnp;
    stringstream sss(s1);
    while(sss >> cnp)
    {
        subject_compact += toupper(cnp[0]);
    }
    if(stt < 10) this->key = this->key + "GV0" + to_string(stt);
    else this->key = this->key + "GV" + to_string(stt);
}
bool cmp(teacher a, teacher b)
{
    if(a.name_compact[a.name_compact.size() - 1] != b.name_compact[b.name_compact.size() - 1]) return a.name_compact[a.name_compact.size() - 1] < b.name_compact[b.name_compact.size() - 1];
    else return a.stt < b.stt;
}
int main()
{
    int n; cin >> n; cin.ignore();
    vector<teacher> uni(n);
    for(int i = 0; i < n; i++)
    {
        getline(cin, uni[i].name);
        getline(cin, uni[i].subject);
        uni[i].stt = i + 1;
        uni[i].compact();
    }
    //sort(uni.begin(), uni.end(), cmp);
    int q; cin >> q; cin.ignore();
    while(q--)
    {
        string tmp; getline(cin, tmp);
        string in_put = tmp;
        for(int i = 0; i < n; i++) in_put[i] = tolower(in_put[i]);
        cout << "DANH SACH GIANG VIEN THEO TU KHOA " << tmp << ":\n";
        for(auto x: uni)
        {
            if(x.check_name.find(in_put) != string::npos)
            {
                cout << x.key << " ";
                for(auto y: x.name_compact)
                {
                    cout << y << " ";
                }
                cout << x.subject_compact << endl;
            }
        }
    }
}