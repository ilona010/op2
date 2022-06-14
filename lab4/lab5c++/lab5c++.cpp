#include "classes.h"
int main()
{
    
    int m;cout << "m=";cin >> m;
    int n;cout << "n=";cin >> n;
    vector<RationalNum> rnum=CreateArrRational(m);
    vector<CompNum> cnum=CreateArrComp(n);
    print(rnum);
    print(cnum);

    for (int i = 0;i < m;i++)
    {
        Num* ptr = &rnum[i];
        ptr->reducing(2);
    }
    for (int i = 0;i < n;i++)
    {
        Num* ptr = &cnum[i];
        ptr->increase(3);
    }
    cout << "modifyed numbers:" << endl;
    print(rnum);
    
    print(cnum);
    double sum = Sum(rnum, cnum);
    cout << "sum=" << sum << endl;
}
