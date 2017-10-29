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


int numberOfNodes;
int nodeOfTom;
int nodeOfJerry;

const char* out = "output.txt";

void fillGraphsFromFile(graph &graph1,graph &graph2);
void printResault(const bool &canMeet,const bool &circlePath);
void MB(graph &inGraph,int colors[],int beginIndex);
void MB2(const graph &inGraph,int colors[],int beginIndex,int nodeOfJerry,bool &canMeet, bool &circlePath);

int main(int argc, const char * argv[]) {
    
    
    graph tompaths;
    graph jerrypaths;
    
    fillGraphsFromFile(tompaths,jerrypaths);
    
    std::cout << "read in completed" << std::endl;
    int colors[numberOfNodes] ;
    for(int i = 0;i<numberOfNodes;i++){
        colors[i] =0;
    }
    
    MB(tompaths,colors,nodeOfTom);
    
    if(colors[nodeOfJerry-1]==1){
        printResault(true,false);
    }
    else{
        bool canMeet = false;
        bool circlePath = false;
        MB2(jerrypaths,colors,nodeOfJerry,nodeOfJerry,canMeet,circlePath);
        printResault(canMeet,circlePath);
        
    }
    
    
    return 0;
}
void MB(graph &inGraph,int colors[],int beginIndex){
    colors[beginIndex-1]= 1;
    for(constIterator it = inGraph[beginIndex];it!=inGraph.end();++it){
        
        if(colors[*it-1]==0){
            MB(inGraph,colors,*it);
        }
    }
    
}

void MB2(const graph &inGraph,int colors[],int beginIndex,int nodeOfJerry,bool &canMeet, bool &circlePath){
    
    colors[beginIndex-1] = 2;
    constIterator it = inGraph[beginIndex];
    while(it!= NULL && *it!=0){
        //std::cout << beginIndex << " " << *it << " ";
        
        if(colors[(*it)-1]==0)
        {
            MB2(inGraph,colors,*it,nodeOfJerry,canMeet,circlePath);
        }
        if(colors[(*it)-1]==1)
        {
            canMeet = true;
        }
        if(colors[(*it)-1]==2)
        {
            if(*it == nodeOfJerry && beginIndex != nodeOfJerry){
                circlePath = true;
            }
        }
        
        //std::cout << canMeet << " "<< circlePath<<std::endl;
        ++it;
        
        
    }
}


void printResault(const bool &canMeet,const bool &circlePath){
    std::ofstream ot(out);
    std::string result = canMeet ?"Igen \n":"Nem \n";
    result += circlePath ? "Igen \n":"Nem \n";
    std::cout << result;
    ot << result;
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


