#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

std::string findTheDigits(std::string x, std::string y) {
    // Write your code here
    map<int, string> holder; //ordered
    bool one_pass = false;
    for (int i = 0; i < y.length(); i++) {
        for (int j = 0; j < x.length(); j++) {
            if (y.at(i) == x.at(j)) { //check x at each y
                y.erase(y.begin() + i);
                if (j == x.length() - 1) {
                    one_pass = true;
                    break;
                }
            }
        }
        if (one_pass) {
            break;
        }
    }
    sort(y.begin(), y.end());
    int count = 0;
    for (int k = 0; k < y.length(); k++) {
            holder[count] = y.at(k);
            ++count;
    }

    string to_return = "";
    for (auto it = holder.begin(); it != holder.end(); it++) {
        to_return += it->second;
    }
    return to_return;
}