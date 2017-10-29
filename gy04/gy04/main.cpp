#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph2.h"

std::stringstream readFile();
int feltmakxker(std::vector<std::pair<int,bool>> &d);
int feladat(Graph &graph,int sizeOfGraph);

int main(int argc, const char * argv[]) {
    std::stringstream data = readFile();
    int size;
    data >>size;
    for(int i=0;i<size;++i)
    {
        int N;
        int M;
        data >>N;
        data >>M;
        Graph graph(N);
        for(int j=0;j< M ;++j)
        {

            int X;
            int Y;
            int Z;

            data >>X;
            data >>Y;
            data >>Z;
            graph.addEdge(X, Y, Z);
            graph.addEdge(Y, X, Z);
        }
        
        
        std::set<int> verticles;
        int result = feladat(graph, N);

        std::cout << result <<std::endl;

       

    }
    


    return 0;
}




int feladat(Graph &graph,int sizeOfGraph){
    std::vector<std::pair<int,bool>> d(sizeOfGraph,std::pair<int,bool>(-1,false));
    int s = 0;
    d[s].first = 0;
    int n = 0;
    int u = -1;
    while(n < sizeOfGraph){
        u = feltmakxker(d);
        d[u].second = true;
        if(u != -1 &&!(d[u].first == -1)){
            for(Graph::NeighbourList::iterator it = graph.neigboursOf(u+1).begin();it!= graph.neigboursOf(u+1).end();++it)
            {
                if(!d[(it->vertex)-1].second)
                {
                    if(d[(it->vertex)-1].first<it->bandWidth)
                    {
                        d[(it->vertex)-1].first = it->bandWidth;
                    }
                }
            }
        }
        else{
            return 0;
        }
       
        ++n;
        
    }
    
    int min = d[1].first;
    for(int i = 2;i < d.size();++i){
        if(min>d[i].first){
            min = d[i].first;
        }
    }
    return min;
    
    
}

int feltmakxker(std::vector<std::pair<int,bool>> &d){
    int max = -1;
    int maxIndex = -1;
    for(int i = 0;i<d.size();i++)
    {
       // std::cout << d[i].first << std::endl;
        if(!d[i].second && max <d[i].first){
            max = d[i].first;
            maxIndex = i;
        }
    }
    return maxIndex;
}



std::stringstream readFile(){
    std::string filename;
    std::ifstream file;
    bool error;
    std::stringstream output;
    std::cout << "Name of File:" << std::endl;
    do
    {
        std::cin >> filename;
        file.open(filename.c_str());
        error = file.fail();
        if(error)
        {
            std::cout << "Error" << std::endl;
            exit(1);
        }
    }while(error);
    output << file.rdbuf();
    return output;
    
}
