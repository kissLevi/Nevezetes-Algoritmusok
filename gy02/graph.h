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
    friend class constIterator;
    
};

class constIterator{
    public:
        constIterator(node* in):point(in){}
        bool operator==(constIterator &other)const{
            return point == other.point;
        }
        constIterator operator++(){
            return point = point->next;
            return *this;
        }
        int operator*()const {
            return point ->value;
        }
        bool operator!=(constIterator other) const
        {
           return !(*this == other);
        }

    private:
        node* point;
};




class graph{
    std::vector<node*> elements;

    public:

      
        constIterator operator[] (const int index)const{
            return elements[index-1];
        }
        constIterator end()const{
            return NULL;
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
        void addNeighbour(int index, int element)
        {
            if(!this->isNeighbour(index,element))
            {
                elements[index-1] = new node(element,elements[index-1]);
            }
            if(!this->isNeighbour(element,index))
            {
                elements[element-1] = new node(index,elements[element-1]);
            }

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
        
        void deleteNode(node* current){
            if(current->next != NULL){
                deleteNode(current->next);
            }
            delete current;
            return;
        }
};




#endif /*GRAPH_H*/