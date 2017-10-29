#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>




class node{
private:
    int value;
    node *next;
    node(int inValue,node* inNext = NULL): value(inValue) , next(inNext) {}
    friend class graph;
    friend class iterator;
    
};

class iterator{
    public:
        iterator(node* in):point(in){}
        iterator next(){
            return point->next;
        }
        iterator end(){
            return NULL;
        }
        bool operator==(iterator &other){
            return point == other.point;
        }
        iterator operator++(){
            point = point->next;
            return *this;
        }
        int& operator*()const {
            return point ->value;
        }

    private:
        node* point;
};




class graph{
    std::vector<node*> elements;

    public:
        iterator operator[] (const int index){
            return elements[index-1];
        }
        bool isNeighbour(int indexOfNode, int indexOfNeighbour){
            bool neighbour = false;
            node *current = elements[indexOfNode-1];
            do{
                neighbour = current->value == indexOfNeighbour;
                current = current->next;
            }
            while(current != NULL && neighbour != true);
            return neighbour;
        }
        void addNeighbour(int index, int element){
            elements[index-1] = new node(element,elements[index-1]);
        }
        void addNode(int element=0){
             elements.push_back(new node(element));
        }
        void changeNode(int index, int element){
            node* old = elements[index-1];
            elements[index-1] = new node(element,old->next);
            deleteNode(old);
        }
        void printNeighbours(int index){
            node *current = elements[index-1];
            do{
                std::cout << current->value <<std::endl;;
                current = current->next;
            }
            while(current != NULL);
        }
        node* neighbour(int index)const{
            return elements[index-1];
        }
        int numberOfNodes() const {
            return elements.size();
        }
        bool isZeroNode(int index){
            return elements[index-1]->value == 0;
        }

        ~graph(){
            while(!elements.empty()){
                node* deleted = elements.back();
                deleteNode(deleted);
                elements.pop_back();

            }

        }
        void MB(int colors[],int beginIndex){
            colors[beginIndex-1]= 1;
            for(node* current = elements[beginIndex-1];current!=NULL;current=current->next){
                if(colors[(current->value)-1]==0){
                    MB(colors,current->value);
                }
            }
                
        }
        void MB2(int colors[],int beginIndex,int nodeOfJerry,bool &canMeet, bool &circlePath){
            if(!canMeet && !circlePath){
                colors[beginIndex-1] = 2;
                for(node* current = elements[beginIndex-1];current!=NULL;current=current->next){
                    switch(colors[(current->value)-1]){

                        case 0 : MB2(colors,current->value,nodeOfJerry,canMeet,circlePath);
                        break;
                        
                        case 1 : canMeet = true;
                        break;

                        case 2 : 
                            if(current->value == nodeOfJerry && beginIndex != nodeOfJerry){
                                circlePath = true;
                            };
                        break;
                    }
                }
            }
        }
        void deleteNode(node* current){
            if(current->next != NULL){
                deleteNode(current->next);
            }
            delete current;
            return;
        }
};




#endif /*GRAPH_H*/