//
//  main.cpp
//  gy05
//
//  Created by Kiss Levente on 2017. 10. 16..
//  Copyright © 2017. Kiss Levente. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stack>
#include <list>


struct data{
    
    data(int _c=0,int _t=0,int size = 0):c(_c),t(_t){}
    int c;
    int t;
    std::vector<std::pair<int,int>> parents;
};



std::stringstream readFile();
void maxYx(std::vector<std::vector<data>> &data,int &t,std::vector<std::pair<int,int>> &parents, int x,int y);
void maxXy(std::vector<std::vector<data>> &data,int &t,std::vector<std::pair<int,int>> &parents, int x,int y);
void feladat(std::vector<std::vector<data>> &data);
int main(int argc, const char * argv[]) {
    readFile();
    return 0;
}



std::stringstream readFile(){
    std::string filename;
    std::fstream file;
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

    int numberOfInputs;
    file >> numberOfInputs;
    for(int i=0;i<numberOfInputs;++i){
        int numberOfPoints,numberOfBridges;
        file >> numberOfPoints;
        file >> numberOfBridges;
        std::vector<std::vector<data>> matrix(numberOfPoints+2,std::vector<data>(numberOfPoints+2,data()));
        for(int j = 0;j<numberOfBridges;++j){
            int a,b,size;
            file >> a;
            file >> b;
            file >> size;
            matrix[a][b].c = size;
            matrix[a][b].parents.push_back(std::pair<int,int>(a,b));
            
            //std::cout << size << std::endl;
           
        }
        feladat(matrix);
        
        std::cout << i+1 << ". feladat : " << matrix[numberOfPoints][numberOfPoints].t <<std::endl;
        std::cout << "Hidak :" <<std::endl;
        for(std::vector<std::pair<int,int>>::const_iterator it = matrix[numberOfPoints][numberOfPoints].parents.begin();it != matrix[numberOfPoints][numberOfPoints].parents.end();++it)
        {
            std::cout << it->first << " " << it->second << std::endl;
        }
        std::cout << std::endl;
        
    }
    
    
    return output;
    
}


void feladat(std::vector<std::vector<data>> &data){
    for(int i=1;i<data.size()-1;++i)
    {
        for(int j = 1;j<data[i].size()-1;++j)
        {
           
            
            if(i>j){
                maxXy(data,data[i][j].t,data[i][j].parents, i, j);

            }
            else if(i == j){
                if( data[i][j].c + data[i-1][j-1].t <= data[i][j-1].t && data[i-1][j].t< data[i][j-1].t)
                {
                    data[i][j].t = data[i][j-1].t;
                    data[i][j].parents = data[i][j-1].parents;
                }
                else if(data[i][j].c + data[i-1][j-1].t > data[i][j-1].t && data[i][j].c + data[i-1][j-1].t > data[i-1][j].t)
                {
                    data[i][j].t = data[i][j].c + data[i-1][j-1].t;
                    data[i][j].parents = data[i-1][j-1].parents;
                    data[i][j].parents.push_back(std::pair<int,int>(i,j));
                }
                else
                {
                    data[i][j].t = data[i-1][j].t;
                    data[i][j].parents = data[i-1][j].parents;
                }
            }
            else if(i<j){
                maxYx(data,data[i][j].t,data[i][j].parents, i, j);
            }
             //std::cout << data[i][j].t;
            //std::cout << i <<" "<< j <<" "<< data[i][j].c <<" "<< data[i][j].t << std::endl;ű
           
        }
         //std::cout << std::endl;
    }
    
    
}



void maxYx(std::vector<std::vector<data>> &data,int &t,std::vector<std::pair<int,int>> &parents, int x,int y){
    int max = data[x][y-1].t;
    bool twoParents = false;
    int parentX = x;
    int parentY = y-1;
    for(int i = 1;i<=x;++i)
    {
        int currentMax = data[i][y].c+data[i-1][y-1].t;
        if(max < currentMax)
        {
            max = currentMax;
            twoParents = true;
            parentX = i-1;
            parentY = y-1;
//            parents = (data[i-1][y-1].parents);
//            parents.push_back(std::pair<int,int>(i,y));

        }
    }
    t = max;
    parents = data[parentX][parentY].parents;
    if(twoParents)
    {
        parents.push_back(std::pair<int,int>(parentX+1,parentY+1));
    }

}


void maxXy(std::vector<std::vector<data>> &data,int &t,std::vector<std::pair<int,int>> &parents, int x,int y){
    int max = data[x-1][y].t;
    bool twoParents = false;
    int parentX = x-1;
    int parentY = y;
    for(int i = 1;i<=y;++i)
    {
        int currentMax = data[x][i].c+data[x-1][i-1].t;
        if(max < currentMax)
        {
            max = currentMax;
            twoParents = true;
            parentX = x-1;
            parentY = y-1;
        }
    }
    t = max;
    parents = data[parentX][parentY].parents;
    if(twoParents)
    {
        parents.push_back(std::pair<int,int>(parentX+1,parentY+1));
    }
}
