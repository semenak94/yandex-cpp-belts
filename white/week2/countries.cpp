#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

void Countries()
{
    int Q;
    cin >> Q;

    map<string, string> countries;
    vector<string> output;

    for (int i = 0; i < Q; i++) {
        string request;
        cin >> request;
        if (request == "DUMP") {
            if (countries.empty()) {
                output.push_back("There are no countries in the world");
            }
            else {
                string pair;
                for (auto j = countries.begin(); j != countries.end(); ++j) {
                    pair += j->first + "/" + j->second + " ";
                }
                output.push_back(pair);
            }
            continue;
        }

        string country_name;
        cin >> country_name;
        if (request == "CHANGE_CAPITAL") {
            string capital;
            cin >> capital;
            auto it = countries.find(country_name);
            if (it != countries.end()) {
                if (capital == it->second) {
                    output.push_back("Country " + country_name + " hasn't changed its capital");
                }
                else {
                    output.push_back("Country " + country_name +
                        " has changed its capital from " + it->second + " to " + capital);
                    countries[country_name] = capital;
                }
            }
            else {
                output.push_back("Introduce new country " + country_name
                                 + " with capital " + capital);
                countries[country_name] = capital;
            }
        }

        if (request == "RENAME") {
            string new_country_name;
            cin >> new_country_name;
            auto it = countries.find(country_name);
            if ((new_country_name == country_name) ||
                (it == countries.end())) {
                output.push_back("Incorrect rename, skip");
                continue;
            }
            else {
                output.push_back("Country " + country_name + " with capital " +
                        it->second + " has been renamed to " + new_country_name);
                countries[new_country_name] = it->second;
                countries.erase(it->first);
            }
        }

        if (request == "ABOUT") {
            auto it = countries.find(country_name);
            if ( it != countries.end()) {
                output.push_back("Country " + country_name + " has capital " + it->second);
            }
            else {
                output.push_back("Country " + country_name + " doesn't exist");
            }
        }
    }

    for (auto i : output) {
        cout << i << endl;
    }

}
