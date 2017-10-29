//
//  Graph.h
//  Graph
//
//  Created by Kiss Levente on 2017. 09. 27..
//  Copyright © 2017. Kiss Levente. All rights reserved.
//

#ifndef Graph_h
#define Graph_h


#include <set>
#include <vector>




//private:
//node* point;
//
//template<class T>
//class Const_Iterator{
//    const T& operator=(const)
//
//
//    private:
//    Graph<T>* graph;
struct Vertex{
   
    Vertex(int _index,int _befok,int _kifok) : index(_index),befok(_befok),kifok(_kifok){}
    int index;
    int befok;
    int kifok;
   
    friend bool operator<(const Vertex& l,const Vertex& r)
    {
        return l.index < r.index;
    }
};


class Graph
{
    public:
    Graph(int size){ graph.resize(size); }
    Graph(){}
    void resize(int size)
    {
        graph.clear();
        graph.resize(size);
    }
    std::set<int> verticlesCanReacfFrom(int index)const{ return graph[index-1]; }
    void addVertex(int index,int vertex)
    {
        if(index <= graph.size())
        {
            graph[index-1].insert(vertex);
        }
    }
    unsigned long numberOfVerticles() const {
        return graph.size();
    }
    private:
    std::vector<std::set<int>> graph;
    
    

};


    



#endif /* Graph_h */
