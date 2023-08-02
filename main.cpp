#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

int main(){
    std::priority_queue<std::pair<int, std::string>> MaxHeap; 

    std::vector<std::pair<int, std::string>> houseData;

    //Open spreadsheet and write 101,000 tuples to houseData
    std::fstream file ("./Real_Estate_Sales_2001-2020_GL.csv", std::ios::in);
    std::vector<std::string> row;
    std::string line;
    std::string word;
    if (file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();    
            std::stringstream str(line);

            while(getline(str, word, ','))
            {
                row.push_back(word);
            }
            std::pair<int, std::string> data;
            data.first = stoi(row[6]);
            data.second = row[4];
            houseData.push_back(data);
        }
    }

}