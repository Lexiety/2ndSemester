#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int pos1, pos2;
    
    string tmp, dmp,aaa;
    bool fl=false;
    fstream F1("F1.txt", ios::in);
    fstream F2("F2.txt", ios::out);
    while (getline(F1, tmp))
    {
        dmp = tmp;
        while (dmp.length() > 1) {
            pos1 = dmp.find(" ");
            cout << pos1 << endl;
            aaa.assign(dmp, 0, pos1);
            cout << aaa << endl;
            pos2= dmp.rfind(aaa);
            cout << pos2 << endl;
            if (0 != pos2) { fl = true; break; }
            dmp.erase(0, pos1 + 1);
        }
        if (fl==true) { F2 << tmp << endl; }
        
    }
    F1.close();
    F2.close();
    return 0;
}
