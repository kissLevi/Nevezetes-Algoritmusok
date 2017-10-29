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
#include <algorithm>




struct Edge{
    Edge(int _vertex1,int _vertex2,int _bandWidth) : vertex1(_vertex1),vertex2(_vertex2),bandWidth(_bandWidth){}
    int vertex1;
    int vertex2;
    int bandWidth;
};

bool operator<(const Edge& l,const Edge& r)
{
    return l.vertex1 > r.vertex1;
}

struct sortBybandWidthess : std::binary_function <Edge,Edge,bool>
{
    bool operator() (const Edge& x, const Edge& y) const {return x.bandWidth>y.bandWidth;}
};

bool sortBybandWidth(Edge l,Edge r)
{
    return l.bandWidth < r.bandWidth;
}


//Graph
class Graph
{
    public:
    
   
    typedef std::multiset<Edge, sortBybandWidthess> sortedEdgeList;
    typedef std::multiset<Edge> edgeList;
    
//    const std::vector<Vertex> &verticlesSortedByBandWight()
//    {
//        if(sortedBybandWidths.empty())
//        {
//            sortByWeights();
//        }
//        return sortedBybandWidths;
//
//    }
    

    
//    const std::set<Vertex> &verticlesCanReacfFrom(int index)const
//    {
//        return graph[index-1];
//    }
//
    
    void addEdge(int index1,int index2,int bandWidth)
    {
        Edge newEdge = Edge(index1,index2,bandWidth);
        Edge reverseNewEdge = Edge(index2,index1,bandWidth);
        edgeList::iterator oldEdge = graph.find(newEdge);
        edgeList::iterator reverseOldEdge = graph.find(reverseNewEdge);
        if(oldEdge != graph.end())
        {
            if(oldEdge->vertex2 == index2 && oldEdge->bandWidth < bandWidth )
            {
                graph.erase(oldEdge);
                graph.insert(newEdge);
                
            }
            else
            {
                graph.insert(newEdge);
            }
        }
        else if(reverseOldEdge != graph.end())
        {
            if(oldEdge->vertex1 == index1 && oldEdge->bandWidth < bandWidth )
            {
                graph.erase(oldEdge);
                graph.insert(newEdge);
            }
        }
        else
        {
            graph.insert(newEdge);
        }
        
//        std::pair<edgeList::iterator,bool> it = graph.insert(Edge(index1,index2,bandWidth));
//        if(it.second== false){
//            if(it.first->bandWidth < bandWidth)
//            {
//                graph.erase(it.first);
//                graph.insert(Edge(index1,index2,bandWidth));
//            }
//
//        }
//
    }
    
    
    
    sortedEdgeList edgesOrdedByWeigth() const{
        sortedEdgeList output;
        for(edgeList::iterator it = graph.begin();it != graph.end();++it)
        {
            output.insert(*it);
        }
        
        return output;
    }
    
    unsigned long numberOfVerticles() const {
        return graph.size();
    }
    
    
    private:
    
   
    
    
//    typedef std::vector<std::multiset<Vertex, sortBybandWidthss>> sortedGraphByWeights;
//    typedef std::vector<std::set<Vertex>> bandWidthGraph;
//
    edgeList graph;
    
//    std::vector<Vertex> sortedBybandWidths;
    
//    void sortByWeights(){
//        //std::vector<Vertex> asd;
//
//
//        sortedBybandWidths = std::vector<Vertex>(0,Vertex(0,0));
//        for(int i= 0;i<graph.size();++i){
//            for(vertexIterator it = graph[i].begin();it != graph[i].end();++it)
//            {
//                sortedBybandWidths.push_back(*it);
//                //sortedBybandWidths[i].insert(*it);
//            }
//        }
//        std::sort(sortedBybandWidths.begin(), sortedBybandWidths.end(), sortBybandWidth);
//        for(std::vector<Vertex>::iterator it = sortedBybandWidths.begin();it!= sortedBybandWidths.end();++it){
//           // std::cout << it->index << " "<<it->bandWidth <<std::endl;
//        }
//    }
//
//    
   

};


    



#endif /* Graph_h */
