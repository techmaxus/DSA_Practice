#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    //list of pointer to list starter
    list<int> *l;
public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j,bool undir=true){
        l[i].push_back(j);
        if(undir==true)   l[j].push_back(i);
    }
    
    
    void BFS(int source, vector<bool> &visit){
        if(visit[source]==true) return;
        visit[source]=true;
        cout<<source<<endl;
        for(auto i :l[source])
            BFS(i,visit);
    }
};

int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    vector<bool>visit(7,false);
    g.BFS(1,visit);
}