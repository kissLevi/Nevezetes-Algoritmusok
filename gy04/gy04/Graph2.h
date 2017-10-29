

#ifndef Graph2_h
#define Graph2_h


#include <set>
#include <vector>
#include <algorithm>




struct Vertex{
    Vertex(int _vertex,int _bandWidth) : vertex(_vertex),bandWidth(_bandWidth){}
    int vertex;
    int bandWidth;
};

bool operator<(const Vertex& l,const Vertex& r)
{
    return l.vertex > r.vertex;
}

struct sortBybandWidthess : std::binary_function <Vertex,Vertex,bool>
{
    bool operator() (const Vertex& x, const Vertex& y) const {return x.bandWidth>y.bandWidth;}
};

//bool sortBybandWidth(Vertex l,Vertex r)
//{
//    return l.bandWidth < r.bandWidth;
//}


//Graph
class Graph
{
public:
    
    
    typedef std::vector<std::set<Vertex>> VerticleList;
    typedef std::set<Vertex> NeighbourList;
    typedef std::multiset<Vertex, sortBybandWidthess > SortedNeighboutList;
    
    Graph(int size){
        graph = VerticleList(size,NeighbourList());
    }
    
    
    void addEdge(int vertexFrom,int vertexTo,int bandWidth)
    {
        
        std::pair<NeighbourList::const_iterator,bool> oldVertex= graph[vertexFrom-1].insert(Vertex(vertexTo,bandWidth));
        if(!oldVertex.second)
        {
            if(oldVertex.first->bandWidth< bandWidth)
            {
                graph[vertexFrom-1].erase(oldVertex.first);
                graph[vertexFrom-1].insert(Vertex(vertexTo,bandWidth));
            }
        }
    }
    
    const NeighbourList& neigboursOf(Vertex& vertex) const
    {
        return graph[(vertex.vertex)-1];
    }
    
    const NeighbourList& neigboursOf(int index) const
    {
        return graph[index-1];
    }
    
    const SortedNeighboutList &orederedNeigboursOf(int index)
    {
        if(orderedList.empty()){
            orderedList = std::vector<SortedNeighboutList>(graph.size());
            for(int i = 0;i < orderedList.size(); ++i)
            {
                for(NeighbourList::iterator it = graph[i].begin();it != graph[i].end();++it)
                {
                    orderedList[i].insert(*it);
                }
                
            }
            
        }
        return orderedList[index-1];
    }
    
    
    
private:
    std::vector<SortedNeighboutList> orderedList;
    VerticleList graph;
    
    
    
};

#endif /* Graph2_h *///
