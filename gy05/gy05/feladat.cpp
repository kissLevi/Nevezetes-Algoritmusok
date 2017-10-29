////
////  main.cpp
////  gy05
////
////  Created by Kiss Levente on 2017. 10. 16..
////  Copyright © 2017. Kiss Levente. All rights reserved.
////
//
//#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <vector>
//
//struct Bridge{
//    int a;
//    int b;
//    int price;
//};
//
//
//
//std::stringstream readFile();
//int feladat(std::vector<std::vector<int>> &bridges);
//
//int main(int argc, const char * argv[]) {
//    std::stringstream data = readFile();
//    int numberOfData;
//    int numberOfPoints;
//    int numberOfBridges;
//    std::vector<std::vector<int>> bridges;
//    data >>numberOfData;
//    for(int i= 0;i<numberOfData;++i){
//        data >>numberOfPoints;
//        data >>numberOfBridges;
//        bridges = std::vector<std::vector<int>>(numberOfBridges,std::vector<int>(numberOfBridges,0));
//        for(int j = 0;j<numberOfBridges;++j){
//            int a;
//            int b;
//            int price;
//            data >> a;
//            data >> b;
//            data >> price;
//            //std::cout << a << " " << b << " " << price << std::endl;
//            
//            bridges[a-1][b-1] = price;
//        }
//        //int asd = feladat(bridges);
//        //std::cout << feladat(bridges) << std::endl;
//        
//    }
//    return 0;
//}
//
//int feladat(std::vector<std::vector<int>> &bridges){
//    int a = 0;
//    int b = 0;
//    for(int i = 0;i<bridges.size();++i){
//        
//        for(int j =0;j<bridges[i].size();++j){
//            if(i+j < bridges[j].size()){
//                a+= bridges[j][i+j];
//                //std::cout << j <<" "<<i+j<< " "<<bridges[j][i+j]<<std::endl;;
//            }
//        }
//        if(a>= b){
//            b = a;
//            a = 0;
//        }
//        
//    }
//    int a1 = 0;
//    int b1 = 0;
//    for(int i = 1;i<bridges.size();++i){
//        
//        for(int j =0;j<bridges[i].size();++j){
//            if(i+j < bridges[j].size()){
//                a1+= bridges[i+j][j];
//                //std::cout << j <<" "<<i+j<< " "<<bridges[j][i+j]<<std::endl;;
//            }
//        }
//        if(a1>= b1){
//            b1 = a1;
//            a1 = 0;
//        }
//        
//    }
//    if(b1>b){
//        b = b1;
//        a1=0;
//        
//    }
//    a1 = 0;
//    b1 = 0;
//    
//    for(int i = bridges.size()-1;i>=0;--i){
//        for(int j =0;j<=bridges[i].size();++j){
//            if(i-j >= 0){
//                a1+= bridges[i-j][i];
//                //std::cout << i-j <<" "<<i<< " "<<bridges[i-j][i]<<std::endl;;
//            }
//        }
//        if(a1>= b1){
//            b1 = a;
//            a1 = 0;
//        }
//        
//    }
//    
//    if(b1>b){
//        b = b1;
//    }
//    a1 = 0;
//    b1 = 0;
//    //std::cout << "2"<<"1" <<bridges[1][0] << std::endl;
//    for(int i = bridges.size()-1;i>=0;--i){
//        
//        for(int j =0;j<=bridges[i].size();++j){
//            if(i-j >= 0){
//                a1+= bridges[i][i-j];
//                //std::cout << i <<" "<<i-j<< " "<<bridges[j][i-j]<<std::endl;;
//            }
//        }
//        if(a1>= b1){
//            b1 = a;
//            a1 = 0;
//        }
//        
//    }
//    if(b1>b){
//        b = b1;
//    }
//    
//    //std::cout << b << std::endl;
//    //    for(int i = 0;i<bridges.size();++i){
//    //        for(int j = 0;j<bridges[i].size();++j){
//    //            std::cout << bridges[i][j] << std::endl;
//    //        }
//    //    }
//    //    std::cout << "size: " << bridges.size() << std::endl;
//    //    for(int i = 0;i<bridges.size();++i){
//    //        //std::cout << "add: " << bridges[i][i]<<std::endl;
//    //        a += bridges[i][i];
//    //    }
//    //    for(int i = 0;i<bridges.size()-1;++i){
//    //        for(int j =0;j<bridges[i].size()-1;++j){
//    //            int max = bridges[i][j] > bridges[j][i]?bridges[i][j]:bridges[j][i];
//    //        }
//    //    }
//    return b;
//}
//
//
//std::stringstream readFile(){
//    std::string filename;
//    std::fstream file;
//    bool error;
//    std::stringstream output;
//    std::cout << "Name of File:" << std::endl;
//    do
//    {
//        std::cin >> filename;
//        file.open(filename.c_str());
//        error = file.fail();
//        if(error)
//        {
//            std::cout << "Error" << std::endl;
//            exit(1);
//        }
//    }while(error);
//    while(!file.fail()){
//        std::string row;
//        std::stringstream currentLine;
//        getline(file,row);
//        currentLine << row;
//        int numberOfData;
//        currentLine >> numberOfData;
//        for(int i=0;i<numberOfData;++i){
//            int numberOfPoints;
//            int numberOfBridges;
//            getline(file, row);
//            currentLine <<row;
//            currentLine >> numberOfPoints;
//            currentLine >> numberOfBridges;
//            for(int j = 0;j<numberOfBridges;++j){
//                int a;
//                int b;
//                int value;
//                getline(file, row);
//                currentLine << row;
//                currentLine >> a;
//                currentLine >> b;
//                currentLine >> value;
//                std::cout << a << " " << b << " " << value << std::endl;
//            }
//        }
//        
//    }
//    return output;
//    
//}
//
