#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

void UniqueTask()
{
    int N;
    cin >> N;
    set<string> unique;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        unique.insert(s);
    }

    cout << unique.size() << endl;
}
