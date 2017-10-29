#include <iostream>
#include "graph.h"
#include <fstream>
#include <sstream>

void fillGraphsFromFile();

int main(int argc, const char * argv[]) {

    
    fillGraphsFromFile();
    
    
    return 0;
}

void fillGraphsFromFile()
{
    std::fstream file;
    std::string filename;
    bool error;
    
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
    
    
    while(!file.fail())
    {
        std::string row;
        std::stringstream opened;
        graph currentGraph;
        getline(file,row);
        opened<<row;
        int numberOfParticipants;
        int number = -1;
        int number1 = 0;
        bool newInput = true;
        //int number2 = 0;
        //if(opened >> number1 && opened >> number2){
            while(opened >> number)
            {
                if(newInput)
                {
                    numberOfParticipants = number;
                    std::cout << numberOfParticipants << std::endl;
                    newInput = false;
                }
                else if (newInput == false && number == 0 && number != -1)
                {
                    opened >> number;
                    if(number == 0 )
                    {
                        newInput = true;
                    }
                    else 
                    {
                        return;
                    }
                }
                else if(number != -1)
                {
                    while(opened >> number){
                        opened >> number;
                        std::cout << number << " ";

                    }
                    
                    // std::cout << number1 <<" "<< number2 << std::endl;
                    // opened>> number1;
                    // opened>> number2;

                }    

            }
        //}
        // else if (number1 != 0){
        //     std::cout << number1 << std::endl;
            
        // } 
    }
}
   