#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;

void Synonyms()
{
    int Q;
    cin >> Q;
    map<string, int> synonyms_dict;
    set<string> requests;
    vector<string> output;

    for (int i = 0; i < Q; i++) {
        string request;
        cin >> request;

        if (request == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            synonyms_dict[word1]++;
            synonyms_dict[word2]++;
            requests.insert(request + " " + word1 + " " + word2);
        }

        if (request == "COUNT") {
            string word;
            cin >> word;
            output.push_back(to_string(synonyms_dict[word]));
        }

        if (request == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            size_t find_requests = requests.count("ADD " + word1 + " " + word2);
            if (find_requests) {
                output.push_back("YES");
            }
            else {
                find_requests = requests.count("ADD " + word2 + " " + word1);
                if (find_requests) {
                    output.push_back("YES");
                }
                else {
                    output.push_back("NO");
                }
            }
        }
    }

    for (auto i : output) {
        cout << i << endl;
    }
}