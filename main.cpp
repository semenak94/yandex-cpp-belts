//#include "sorted_strings.h"
//#include "persons1.h"
//#include "reversible_string.h"
//#include "incognizable.h"
//#include "week4\lecture_title.h"
//#include "week4\invertible_function.h"
#include "week4\week4.h"
#include "week5\final.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;

void Queue();
void DailyPlanner();
void BusStops1();
void BusStops3();

set<string> BuildMapValuesSet(const map<int, string>& m)
{
    set<string> s;
    for (auto i : m) {
        s.insert(i.second);
    }

    return s;
}

bool Compare(int& x, int& y)
{
    return abs(x) < abs(y);
}

void SortByModule()
{
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(begin(v), end(v), Compare);

    for (auto& i : v) {
        cout << i << " ";
    }
}

bool CharCompare(char& a, char&b) {
    return tolower(a) < tolower(b);
}

void CaseInsensitiveSort()
{
    int N;
    cin >> N;
    vector<char> s(N);

    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }

    sort(begin(s), end(s), CharCompare);

    for (auto i : s) {
        cout << i << " ";
    }
}


int main()
{
    //Queue();
    //DailyPlanner();
    //BusStops1();
    //BusStops3();
    //SortByModule();
    //CaseInsensitiveSort();
/******************************************************/
// Week 3 tasks
    //SortedStringsTask();
    //PersonsTask1();
    //ReversibleStringTask();
    //IncognizableTask();
/******************************************************/
/******************************************************/
// Week 4 tasks
    //LectureTitleTask();
    //InvertibleFunction();
    //FileWorksTask();
    //PrecesionOutputTask();
    //TableWorkTask();
    //StudentListTask();
    //RationalTasks();
    //EnsureEqualTask();
    //RationalCalc();
    //DBTask();
/******************************************************/
    //map<int, string> m = { { 1, "odd" },
    //                       { 2, "even" },
    //                       { 3, "odd" },
    //                       { 4, "even" },
    //                       { 5, "odd" } };
    //
    //set<string> values = BuildMapValuesSet(m);
    //
    //for (const string& value : values) {
    //    cout << value << endl;
    //}

    return 0;
}

void BusStops3()
{
    int Q;
    cin >> Q;
    set<string> stops;
    map<int, set<string> > routes;
    vector<string> output;
    int busNumber = 1;

    for (int i = 0; i < Q; i++) {
        int N;
        cin >> N;
        for (int j = 0; j < N; j++) {
            string s;
            cin >> s;
            stops.insert(s);
        }

        bool route_found = false;
        int found_bus_number;
        for ( auto s : routes ) {
            if (s.second == stops) {
                route_found = true;
                found_bus_number = s.first;
                break;
            }
        }

        if (route_found) {
            output.push_back("Already exists for " + to_string(found_bus_number));
        }
        else {
            output.push_back("New bus " + to_string(busNumber));
            routes[busNumber] = stops;
            busNumber++;
        }

        stops.clear();
    }

    for (auto i : output) {
        cout << i << endl;
    }
}


void BusStops1()
{
    int Q;
    cin >> Q;

    map<string, vector<string> > routes;
    vector<string> output;

    for (int i = 0; i < Q; i++) {
        string request;
        cin >> request;

        if (request == "ALL_BUSES") {
            if (routes.empty()) {
                output.push_back("No buses");
            }
            else {

            }
        }

        if (request == "BUSES_FOR_STOP") {
            string busStop;
            cin >> busStop;
            auto it = routes.find(busStop);
            if (it != routes.end()) {
            }
            else {
            }
        }

        if (request == "STOPS_FOR_BUS") {
            string busNumber;
            cin >> busNumber;


        }

        if (request == "NEW_BUS") {
            string busNumber;
            cin >> busNumber;
            int stopCount;
            cin >> stopCount;
            for (int i = 0; i < stopCount; i++) {
                string stopName;
                cin >> stopName;
                routes[busNumber].push_back(stopName);
            }
        }
    }
}


void DailyPlanner()
{
    int Q;
    cin >> Q;
    vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int toNextMonth = 0;
    vector<string> tasks(daysInMonths[0]);

    for (int i = 0; i < Q; i++) {
        string action;
        string taskName;
        int taskDay;
        cin >> action;
        if (action != "NEXT") {
            cin >> taskDay;
        }

        if (action == "ADD") {
            cin >> taskName;
            tasks[taskDay - 1] = taskName;
        }

        if (action == "NEXT") {
            size_t currentSize = tasks.size();
            //tasks.resize(currentSize + daysInMonths[]);
        }

        if (action == "DUMP") {
        }
    }
}

void Queue()
{
    int Q;
    cin >> Q;
    vector<bool> queue;
    vector<int> count;
    int counter = 0;
    for (int i = 0; i < Q; i++) {
        string s; int n;
        cin >> s;
        if (s != "WORRY_COUNT") {
            cin >> n;
        }

        if (s == "COME") {
            if (n > 0) {
                queue.resize(queue.size() + n, false);
            }
            else {
                for (auto j = 0; j < abs(n); j++) {
                    queue.pop_back();
                }
            }
        }

        if (s == "WORRY") {
            queue[n] = true;
        }

        if (s == "QUIET") {
            queue[n] = false;
        }

        if (s == "WORRY_COUNT") {
            count.push_back(0);
            for (auto c : queue) {
                if (queue[c] == true) {
                    count[counter]++;
                }
            }
            counter++;
        }
    }

    for (auto s : count) {
        cout << s << endl;
    }
}
