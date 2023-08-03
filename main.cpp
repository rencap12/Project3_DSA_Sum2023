#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <iterator>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(){
    priority_queue<pair<int, string>> MaxHeap;
    unordered_map<string, vector<string>> hashMap;

    vector<pair<string, string>> houseData;

    //Open spreadsheet and write 101,000 tuples to houseData
    fstream file (R"(Real_Estate_Sales_2001-2020_GL.csv)", ios::in);
    vector<string> row;
    string line;
    string word;
    getline(file, line); //skips first line
    if (file.is_open())
    {
        for(int i = 0; i < 101000; i++)
        {
            getline(file, line);
            row.clear();
            stringstream str(line);

            while(getline(str, word, ','))
            {
                row.push_back(word);
            }
            pair<string, string> data;
            data.first = row[6]; //price
            data.second = row[4];  //address
            houseData.push_back(data);
        }
    }

    //cout << houseData[50000].first << endl;;

    //Add all houseData to MaxHeap and to hashMap
    for (int i = 0; i < houseData.size(); i++)
    {
        stringstream ss(houseData[i].first);
        int num = 0;
        ss >> num;
        MaxHeap.emplace(make_pair(num, houseData[i].second));
        hashMap[houseData[i].first].push_back(houseData[i].second);
    }

    auto start_HM = high_resolution_clock::now();
    for(auto k = hashMap.begin(); k != hashMap.end(); ++k){
        stringstream ss(k->first);
        int temp = 0;
        ss >> temp;
        if(temp > 1000000){
          //  cout << "price: " << k->first << " " << endl;
            for(int m = 0; m < k->second.size(); m++){
             //   cout << k->second[m] << " " ;
            }
           // cout << "\n";
        }
    }
    auto stop_HM = high_resolution_clock::now();
    auto duration_HM = duration_cast<microseconds>(stop_HM - start_HM);
    cout << "Hash Map: " << duration_HM.count() << endl;

    auto start_Heap = high_resolution_clock::now();
    while(!MaxHeap.empty()){
        long int temp = MaxHeap.top().first;
        if(temp > 1000000){
           // cout << "price: " << temp  << " " << endl;
            for(int m = 0; m < MaxHeap.top().second.size(); m++){
               // cout << MaxHeap.top().second[m] << " " ;
            }
            //cout << "\n";
        }
        MaxHeap.pop();
    }
    auto stop_Heap = high_resolution_clock::now();
    auto duration_Heap = duration_cast<microseconds>(stop_Heap - start_Heap);
    cout << "Max Heap: " << duration_Heap.count() << endl;


 return 0;
}