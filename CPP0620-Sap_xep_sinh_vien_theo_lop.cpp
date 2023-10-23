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

class Student
{
public:
    string key, name, grade, email;
    Student(){}
    friend istream& operator >> (istream& in, Student& other)
    {
        getline(in, other.key);
        getline(in, other.name);
        getline(in, other.grade);
        getline(in, other.email);
        return in;
    }
    friend ostream& operator << (ostream& out, Student& other)
    {
        out << other.key << " " << other.name << " " << other.grade << " " << other.email << endl;
        return out;
    }
    ~Student(){}
};
bool cmp(Student a, Student b)
{
    if(a.grade != b.grade) return a.grade < b.grade;
    else return a.key < b.key;
}
void solve()
{
    fast();
    int n; cin >> n; cin.ignore();
    vector<Student> uni(n);
    for(int i = 0; i < n; i++) cin >> uni[i];
    sort(uni.begin(), uni.end(), cmp);
    for(int i = 0; i < n; i++) cout << uni[i];
}
int main()
{
    solve();
}