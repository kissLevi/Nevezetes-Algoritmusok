//
//  main.cpp
//  gy03
//
//  Created by Kiss Levente on 2017. 10. 02..
//  Copyright © 2017. Kiss Levente. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <stack>
#include "Graph.h"

struct Fokok
{
    Fokok(int _kifok = 0,int _befok = 0): kifok(_kifok),befok(_befok){}
    int kifok;
    int befok;
};

std::stringstream readFile();
void TopSort(std::stack<int> &stack,const Graph &graph);
void MB(const Graph &inGraph,std::stack<int> &stack,std::vector<int> &colors,int index);

int main(int argc, const char * argv[]) {
    std::stringstream data = readFile();
    int numberOfpoints;
    int startPoint;
    int endPoint;
    data >> numberOfpoints;
    data >> startPoint ;
    data >> startPoint;
    data >> endPoint;
    
    Graph graph(numberOfpoints);
    std::stack<int> stack;
    std::vector<Fokok> fokok(numberOfpoints);
    
    int A = 0;
    int B = 0;
    
    
    while(data >> A && data >> B)
    {
        graph.addVertex(A,B);
        fokok[A-1].kifok+= 1;
        fokok[B-1].befok += 1;
    }
    
    TopSort(stack, graph);
    int result = 0;
    int c = 0;
    std::string criticalPoints = "";
    while(!stack.empty())
    {
        int u = stack.top();
        stack.pop();
       
        c -= fokok[u-1].befok;
        if(c == 0 && u != startPoint && u!= endPoint)
        {
            criticalPoints += std::to_string(u)+" ";
            result++;
        }
        c += fokok[u-1].kifok;
        
    }
    criticalPoints += "\n";
    
    std::cout << result <<std::endl <<criticalPoints;
    
    
    return 0;
}

void TopSort(std::stack<int> &stack,const Graph &graph){
    unsigned long size = graph.numberOfVerticles();
    std::vector<int> colors(size,0);
    for(int i=0;i<size;++i)
    {
        if(colors[i]==0)
        {
            MB(graph, stack, colors, i);
        }
    }
}
void MB(const Graph &inGraph,std::stack<int> &stack,std::vector<int> &colors,int index){
    colors[index]= 1;
    std::set<int> current = inGraph.verticlesCanReacfFrom(index+1);
    for(std::set<int>::const_iterator it = current.begin();it!=current.end();++it){
        
        if(colors[*it-1]==0){
            MB(inGraph,stack,colors,*it-1);
        }
    }
    colors[index] = 2;
    stack.push(index+1);
    
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
