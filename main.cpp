#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

int main(){
    std::priority_queue<std::pair<int, std::string>> MaxHeap; 

    std::vector<std::pair<std::string, std::string>> houseData;

    //Open spreadsheet and write 101,000 tuples to houseData
    std::fstream file ("./Real_Estate_Sales_2001-2020_GL.csv", std::ios::in);
    std::vector<std::string> row;
    std::string line;
    std::string word;
    getline(file, line); //skips first line
    if (file.is_open())
    {
        for(int i = 0; i < 101000; i++)
        {
            getline(file, line);
            row.clear();    
            std::stringstream str(line);

            while(getline(str, word, ','))
            {
                row.push_back(word);
            }
            std::pair<std::string, std::string> data;
            data.first = (row[6]);
            data.second = row[4];
            houseData.push_back(data);
        }
    }

    std::cout << houseData[50000].second;

}