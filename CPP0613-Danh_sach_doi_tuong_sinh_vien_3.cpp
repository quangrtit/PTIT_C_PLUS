// #include<iostream>
// #include<unistd.h>
// #include<math.h>
// #include<string>
// #include<cctype>
// #include<set>
// #include<limits.h>
// #include<map>
// #include<queue>
// #include<algorithm>
// #include<iomanip>
// using namespace std;
// #define MOD 1000000007
// #define endl '\n'
// #define PI 3.141592653589793238
// #define fast() ios::sync_with_stdio(false); cin.tie(0);

// class SinhVien
// {
// public:
//     string key = "B20DCCN", name, birth, grade;
//     float GPA; int cnt = 0; static int demo;
//     SinhVien(){key = ""; name = ""; birth = ""; grade = ""; GPA = 0; cnt = 0;}
//     friend istream& operator >> (istream& in, SinhVien& other)
//     {
//         demo++; other.cnt = demo;
//         other.key = "B20DCCN";
//         in.ignore();
//         getline(in, other.name);
//         getline(in, other.grade);
//         getline(in, other.birth);
//         in >> other.GPA;
//         return in;
//     }
//     friend ostream& operator << (ostream& out, SinhVien& other)
//     {
//         if(other.cnt < 10)
//         {
//             out << other.key << "00" << to_string(other.cnt) << " ";
//         }
//         else 
//         {
//             out << other.key << "0" << to_string(other.cnt) << " ";
//         }
//         string s1 = other.name, tmp1;
//         stringstream sss(s1);
//         while(sss >> tmp1)
//         {
//             for(int i = 0; i < tmp1.size(); i++)
//             {
//                 if(i == 0) tmp1[i] = toupper(tmp1[i]);
//                 else tmp1[i] = tolower(tmp1[i]);
//             }
//             out << tmp1 << " ";
//         }
//         out << other.grade << " ";
//         string s = other.birth; for(int i = 0; i < s.size(); i++) if(s[i] == '/') s[i] = ' ';
//         string tmp; stringstream ss(s);
//         while(ss >> tmp)
//         {
//             if(tmp.size() == 4) out << tmp << " ";
//             else if(tmp.size() == 2) out << tmp << "/";
//             else out << "0" << tmp << "/";
//         }
//         out << setprecision(2) << fixed << other.GPA << endl;
//         return out;
//     }
//     ~SinhVien(){}
// };
// bool cmp(SinhVien a, SinhVien b)
// {
//     return a.GPA >= b.GPA;
// }
// void sapxep(SinhVien *ds, int n)
// {
//     sort(ds, ds + n, cmp);
// }
// int SinhVien::demo = 0;
// int main(){
//     SinhVien ds[50];
//     int N, i;
//     cin >> N;
//     for(i=0;i<N;i++){
//         cin >> ds[i];
//     }
//     sapxep(ds, N);
//     for(i=0;i<N;i++){
//         cout << ds[i];
//     }
//     return 0;
// }
// /*AUTHOR: KHỔNG VĂN QUẢNG - PTIT*/
//CPP0613 - DANH SÁCH ĐỐI TƯỢNG SINH VIÊN - 3
#include <bits/stdc++.h>
using namespace std;

class SinhVien{
public:
  int id;
  string name;
  string className;
  string birthday;
  static int stt;
  float gpa;
public:
  SinhVien(){
    id = stt++;
    name = "";
    className = "";
    birthday = "";
    gpa = 0;
  }
  friend istream& operator>>(istream &is, SinhVien &sv){
    is.ignore();
    getline(is, sv.name);
    getline(is, sv.className);
    getline(is, sv.birthday);
    is >> sv.gpa;
    return is;
  }
  friend ostream& operator<<(ostream &os, SinhVien &sv){
    for(int i = 0; i < sv.name.length(); i++){
      sv.name[i] = tolower(sv.name[i]);
    }
    string arr[50];
    int k = 0;
    istringstream iss(sv.name);
    while(iss >> arr[k]) k++;
    sv.name = "";
    for(int i = 0; i < k; i++){
      arr[i][0] = toupper(arr[i][0]);
      sv.name += arr[i] + " ";
    }
    if(sv.birthday.length() == 8){
      sv.birthday.insert(0, "0");
      sv.birthday.insert(3, "0");
    }
    else if(sv.birthday.length() == 9){
      if(sv.birthday[1] == '/') sv.birthday.insert(0, "0");
      else if(sv.birthday[2] == '/') sv.birthday.insert(3, "0");
    }
    os << "B20DCCN";
    if(sv.id < 10) os << "00";
    else if(sv.id < 100) os << "0";
    os << sv.id << " " << sv.name << sv.className << " " << sv.birthday << " " << fixed << setprecision(2) << sv.gpa << endl;
    return os;
  }
};

int SinhVien::stt = 1;

bool sap_xep_gpa(SinhVien a, SinhVien b){
  if(a.gpa < b.gpa) return false;
  return true;
}

void sapxep(SinhVien ds[], int n){
  sort(ds, ds + n, sap_xep_gpa);
}


int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> ds[i];
    }
    sapxep(ds, N);
    for(i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}