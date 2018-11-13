#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void debug(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    } cout << endl;
}

int findContentChildren(vector<int>& g, vector<int>& s) {
    vector<int> g_replica = g;
    vector<int> s_replica = s;

    int g_replica_size = g.size();
    int s_replica_size = s.size();

    // handling boundary conditions:
    // If the number of children equals to zero, or the number of cookies equals to zero, 
    // none of the children will be satisfied.
    if (g_replica_size == 0 || s_replica_size == 0) return 0;

    // sorting the children based on gi
    sort(g_replica.begin(), g_replica.end());
    // sorting the cookies based on sj
    sort(s_replica.begin(), s_replica.end());

    // debug(g_replica);
    // debug(s_replica);

    // the index variables for iterating the two arrays
    int children_index = 0;
    int cookies_index = 0;

    // the number of content children (the answer)
    int num = 0;

    // scheduling procedure for allocating cookies:
    // For each cookie, we determine whether it can satisfy current child or not.
    // If so, we add 1 to num and ask the next child; 
    // otherwise, we "drop" this cookie since this cookie cannot satisfy any child.
    for (int i = 0; i < s_replica_size; i++) {
        // If we have iterated all the children, we end up this loop
        if (children_index >= g_replica_size) break;

        int gi = g_replica[children_index];
        int sj = s_replica[cookies_index];

        if (sj >= gi) {
            num++;
            children_index++;
            cookies_index++;
        } else {
            cookies_index++;
        }
    }

    return num;
}

int main() {
    vector<int> children_1{1,2,3};
    vector<int> cookies_1{1,1};

    cout << "=====test1=====" << endl;
    cout << findContentChildren(children_1, cookies_1) << endl;

    vector<int> children_2{1,2};
    vector<int> cookies_2{1,2,3};

    cout << "=====test2=====" << endl;
    cout << findContentChildren(children_2, cookies_2) << endl;

    return 0;
}