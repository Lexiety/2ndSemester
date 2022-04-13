#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int pos1, pos2;
    
    string tmp, dmp,aaa,bbb;
    bool fl=false;
    fstream F1("F1.txt", ios::in);
    fstream F2("F2.txt", ios::out);
    while (getline(F1, tmp))
    {
        dmp = tmp;
        while (dmp.length() > 1) {
            pos1 = dmp.find(" ");
            aaa.assign(dmp, 0, pos1);
            pos2 = dmp.rfind(aaa);
            if (0 != pos2) { fl = true; break; }
            dmp.erase(0, pos1 + 1);
        }
        if (fl == true) { F2 << tmp << endl; }
    }


    F1.clear();
    F1.seekg(0, ios::beg);

    int count = 0;
    int maxc = 0;
    int imax = 0;
    fl = false;
    string answer;
    while (getline(F1, tmp))
    {
        dmp = tmp;
        cout << dmp << endl;
        int count = 0;
        int i = 0;
        fl = false;

        while (dmp.length() != (i + 1))
        {
            if ((dmp[i] == 'a') or (dmp[i] == 'A')) { count++; }
            if ((dmp[i] == ' ') && (maxc < count)) { maxc = count; count = 0; imax = i; fl = true; }
            if ((dmp[i] == ' ') && (maxc > count)) {count = 0; }
            i++;

           
        }

        if (fl = true) 
        {
            pos1 = imax;
            pos2 = dmp.rfind(" ", pos1-1);
            cout << pos2 << endl;
            cout << pos1 << endl;

            answer.assign(dmp, pos2+1, pos1-pos2-1);
        }


    }

    F2 << answer << endl;
    F1.close();
    F2.close();
    return 0;
}
