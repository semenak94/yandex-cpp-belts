#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<char, int> CountLetters(const string& word)
{
    map<char, int> m;
    for (auto c : word) {
        int letter_count = count(word.begin(), word.end(), c);
        m[c] = letter_count;
    }

    return m;
}

void Anagrams()
{
    int N;
    cin >> N;
    vector<string> out;

    for (int i = 0; i < N; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        map<char, int> m1, m2;
        m1 = CountLetters(s1);
        m2 = CountLetters(s2);

        if (m1 == m2) {
            out.push_back("YES");
        }
        else {
            out.push_back("NO");
        }
    }

    for (auto i : out) {
        cout << i << endl;
    }

}
