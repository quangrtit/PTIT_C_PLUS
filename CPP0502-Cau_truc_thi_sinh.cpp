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

struct ThiSinh
{
    string name, birth;
    float score1, score2, score3;
    float sum_score = 0;
};
void nhap(ThiSinh& A)
{
    getline(cin, A.name);
    getline(cin, A.birth);
    cin >> A.score1 >> A.score2 >> A.score3;
    A.sum_score = A.score1 + A.score2 + A.score3;
}
void in(ThiSinh A)
{
    cout << A.name << " " << A.birth << " " << setprecision(1) << fixed << A.sum_score << endl;
}
int main(){
    struct ThiSinh A;
    nhap(A);
    in(A);
    return 0;
}