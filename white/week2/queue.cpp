#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

void QueueTask()
{
    int Q;
    cin >> Q;
    vector<bool> queue;
    vector<int> count;
    for (int i = 0; i < Q; i++) {
        string s; int n;
        cin >> s >> n;

        if (s == "COME") {
            if (n > 0) {
                queue.resize(n, false);
            }
            else {
                for (auto j = 0; j < abs(n); j++ ) {
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
                    count[i]++;
                }
            }
        }
    }

    for (auto s : count) {
        cout << s << endl;
    }

}
