//
//  main.cpp
//  1gyak
//
//  Created by Kiss Levente on 2017. 09. 18..
//  Copyright © 2017. Kiss Levente. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "graph.h"
#include <set>


int numberOfNodes;
int nodeOfTom;
int nodeOfJerry;






void fillGraphsFromFile(graph &graph1,graph &graph2);
void printResault(bool canMeet, bool circlePath);

int main(int argc, const char * argv[]) {

    
    graph tompaths;
    graph jerrypaths;
    
    fillGraphsFromFile(tompaths,jerrypaths);
    std::cout << "read in completed" << std::endl;
    int colors[numberOfNodes] ;
    for(int i = 0;i<numberOfNodes;i++){
        colors[i] =0;
    }

    tompaths.MB(colors,nodeOfTom);
    if(colors[nodeOfJerry]==1){
        std::cout <<"Igen"<<std::endl <<"Nem" << std::endl;
    }
    else{
        bool canMeet = false;
        bool circlePath = false;
        jerrypaths.MB2(colors,nodeOfJerry,nodeOfJerry,canMeet,circlePath);
        printResault(canMeet,circlePath);
        
    }
    
    
    return 0;
}

void printResault(bool canMeet, bool circlePath){
    std::string result = canMeet ?"Igen \n":"Nem \n";
    result += circlePath ? "Igen" : "Nem";
    std::cout << result << std::endl;
}

void fillGraph(graph &graph){
    
}

void fillGraphsFromFile(graph &graph1,graph &graph2)
{
    std::fstream file;
    std::string filename;
    bool error;
    bool endOfFirstGraph = false;
    bool firstLine = true;
    int number;
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
    
    
    while(!file.fail()){
        std::string row;
        std::stringstream opened;
        getline(file,row);
        opened<<row;
        opened >> number;
        while(!opened.fail()){
            if(firstLine){
                numberOfNodes = number;
                opened >> nodeOfTom;
                opened >> nodeOfJerry;
                opened >> number;
                firstLine = false;
            }
            else if(number == -1){
                endOfFirstGraph = true;
                break;
            }
            else if(endOfFirstGraph){
                if(number>=graph2.numberOfNodes()){
                    while(graph2.numberOfNodes()<=number){
                        graph2.addNode();
                    }
                }
                else{
                    int index = number;
                    opened >> number;
                    if(graph2.isZeroNode(index)){
                        graph2.changeNode(index,number);
                    }
                    if(!graph2.isNeighbour(index,number)){
                        graph2.addNeighbour(index,number);
                    }
                    opened >> number;
                }
            }
            else if(!endOfFirstGraph){
                if(number>=graph1.numberOfNodes()){
                    while(graph1.numberOfNodes()<=number){
                        graph1.addNode();
                    }
                }
                else{
                    int index = number;
                    opened >> number;
                    if(graph1.isZeroNode(index)){
                        graph1.changeNode(index,number);
                    }
                    if(!graph1.isNeighbour(index,number)){
                        graph1.addNeighbour(index,number);
                    }
                    opened >> number;
                }
            }



        }
        
    }
}
   