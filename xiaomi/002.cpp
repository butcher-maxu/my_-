#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;
/*
题目大意：
    给n个课程，编号 0~n-1，判断其是否符合要求

    输入示例：
    2
    1：0，0：1

    做法： 图，，队列，根据入度来做
*/
bool isProcessValid(int n, const vector<pair<int, int>> &prerequisites) {
    unordered_map<int, vector<int>> g;
    vector<int> indegree(n, 0); // 表示入度

    for (const auto &prerequisite : prerequisites) {
        int processA = prerequisite.first;
        int processB = prerequisite.second;
        g[processB].push_back(processA);
        indegree[processA]++;
    }

    // 将度为0的点放入队列中
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int f = 0; // f表示已经出队的点的个数
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        f++; 
        for (int neib : g[t]) {
            indegree[neib]--;
            if (indegree[neib] == 0)
                q.push(neib);
        }
    }

    return f == n;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<pair<int, int>> prerequisites;
    string input;
    getline(cin, input);

    stringstream ss(input);
    string pairStr;
    while (getline(ss, pairStr, ',')) {
        stringstream pairSS(pairStr);
        string astr, bstr;
        getline(pairSS, astr, ':');
        getline(pairSS, bstr, ':');

        int a = stoi(astr);
        int b = stoi(bstr);
        prerequisites.push_back({a, b});
    }

    bool ret = isProcessValid(n, prerequisites);
    if (ret)
        cout << "1" << endl;
    else
        cout << "0" << endl;

    return 0;
}