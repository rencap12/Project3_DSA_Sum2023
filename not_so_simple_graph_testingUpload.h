#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

class Graph
{
private:
    // TODO: Graph structure that supports parallel edges and self-loops
    map<int, vector<pair<int,int>>> adJList;

public:
    void insertEdge(int from, int to, int weight);
    bool isEdge(int from, int to);
    int sumEdge(int from, int to);
    std::vector<int> getWeight(int from, int to);
    std::vector<int> getAdjacent(int vertex);
};

void Graph::insertEdge(int from, int to, int weight)
{
    /*
         TODO: insertEdge() adds a new edge between the from
         and to vertex.
    */
    pair<int, int> temp(to, weight);
    adJList[from].push_back(temp);
}

bool Graph::isEdge(int from, int to)
{
    /*
        TODO: isEdge() returns a boolean indicating true
        if there is an edge between the from and to vertex
    */
    for(auto it = adJList.begin(); it != adJList.end(); ++it){
        if(!it->second.empty()){
            for(int k = 0; k < it->second.size(); k++){
                if(it->first == from && it->second[k].first == to){
                    return true;
                }
            }
        }
    }
    return false;
}

int Graph::sumEdge(int from, int to)
{
    /*
        TODO: sumEdge() returns the sum of weights of all edges
        connecting the from and to vertex. Returns 0 if no edges
        connect the two vertices.
    */
    int sum = 0;
    int temp = to;
    if(!isEdge(from, to)){
        return sum;
    }
    for(auto it = adJList.begin(); it != adJList.end(); ++it){
        if(!it->second.empty()){
            for(int k = 0; k < it->second.size(); k++){
                if(it->second[k].first == temp){
                    sum += it->second[k].second;
                }
            }
        }
    }
    return sum;
}

std::vector<int> Graph::getWeight(int from, int to)
{
    /*
        TODO: getWeight() returns a sorted vector containing all
        weights of the edges connecting the from and to vertex
    */
    vector<int> holder;
    int temp = to;
    for(auto it = adJList.begin(); it != adJList.end(); ++it){
        if(!it->second.empty()){
            for(int k = 0; k < it->second.size(); k++){
                if(it->second[k].first == temp){
                    holder.push_back(it->second[k].second);
                }
            }
        }
    }
    return holder;
}

std::vector<int> Graph::getAdjacent(int vertex)
{
    /*
        TODO: getAdjacent() returns a sorted vector of all vertices
        that are connected to a vertex
    */
    vector<int> holder;
    for(auto it = adJList.begin(); it != adJList.end(); ++it){
        if(!it->second.empty() && it->first == vertex){
            for(int k = 0; k < it->second.size(); k++){
                holder.push_back(it->second[k].first);
            }
        }
    }
    return holder;
}
// testing to see change in github desktop after first commit
// green is new change




