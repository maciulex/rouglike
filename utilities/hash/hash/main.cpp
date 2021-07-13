#include <iostream>

using namespace std;

int main()
{
    while (true) {
        string txt;
        cin >> txt;
        cout << hash<string>{}(txt) << endl;
        if (cin.fail()) {
            return 0;
        }
    }
}
