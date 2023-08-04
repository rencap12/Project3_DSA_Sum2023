#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <iterator>
#include <chrono>
#include <algorithm>
#include <exception>
using namespace std;

int main(){
    priority_queue<pair<int, string>> MaxHeap;
    unordered_map<int, vector<string>> hashMap;

    vector<pair<string, string>> houseData;

    //Open spreadsheet and write 101,000 tuples to houseData
    fstream file (R"(Real_Estate_Sales_2001-2020_GL.csv)", ios::in);
    string searchAddy;
    vector<string> row;
    string line;
    string word;
    getline(file, line); //skips first line
    if (file.is_open())
    {
        cout << "Enter address to find its sale price: " << endl;
        getline(cin,searchAddy);
        for (int i = 0; i < 101000; i++) {
            getline(file, line);
            row.clear();
            stringstream str(line);

            while (getline(str, word, ',')) {
                row.push_back(word);
            }

            bool check = false;
            pair<string, string> data;
            if (row.size() == 14) { //valid entry
                for (char temp : row[6]) {
                    if (!isdigit(temp) || temp == ' ') { //no letters or space in price
                        check = true;
                        break;
                    }
                }
            }
            if (!check) {
                data.first = row[6]; //price
                data.second = row[4];  //address
                houseData.push_back(data);
            }
        }
    }

    //Add all houseData to MaxHeap and to hashMap
    for (auto & d : houseData)
    {
        int temp = 0;
        try {
            temp = stoi(d.first);
        } catch (exception& e){
            continue;
        }
        if (temp != 0) { // invalid price point if 0
            // no duplicate addresses at same price
            if (find(hashMap[temp].begin(), hashMap[temp].end(), d.second) == hashMap[temp].end()) {
                MaxHeap.emplace(temp, d.second);
                hashMap[temp].emplace_back(d.second);
            }
        }
    }

    auto start_HM = std::chrono::high_resolution_clock::now(); //hash map
    bool found = false;
    for (auto & k : hashMap) {
          for (int m = 0; m < k.second.size(); m++) {
              if (k.second[m] == searchAddy) {
              cout << "Sale Price for " << searchAddy << ": " << k.first << endl;
              auto stop_HM = std::chrono::high_resolution_clock::now();
              auto duration_HM = std::chrono::duration_cast<std::chrono::microseconds>(stop_HM - start_HM);
              cout << "Hash Map (microseconds): " << duration_HM.count() << endl;
              found = true;
              break;
            }
        }
          if(found){
              break;
          }
    }

    auto start_Heap = std::chrono::high_resolution_clock::now(); //heap
    while (!MaxHeap.empty()) {
        string temp = MaxHeap.top().second;
        if (temp == searchAddy) {
            cout << "Sale Price for " << searchAddy << ": " << MaxHeap.top().first << endl;
            auto stop_Heap = std::chrono::high_resolution_clock::now();
            auto duration_Heap = std::chrono::duration_cast<std::chrono::microseconds>(stop_Heap - start_Heap);
            cout << "Max Heap (microseconds): " << duration_Heap.count() << endl;
            break;
        }
        MaxHeap.pop();
    }

 return 0;
}