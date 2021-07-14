#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int main()
{
//    srand(time(NULL));
//    for (int i = 0; i < 100; i++) {
//        cout << rand()%4*.5<<endl;
//    }
    while (true) {
        string txt;
        cin >> txt;
        cout << hash<string>{}(txt) << endl;
        if (cin.fail()) {
            return 0;
        }
    }
}
