//
// Created by windyear_office on 18-1-28.
//

#include "Cycle.h"

Cycle::Cycle(Graph g) {
    marked = new bool[g.V()];
    has_cycle = false;
    //因为不知道图中有多少个连通分量，所以使用一个for循环来遍历递归。
    for(int v = 0; v < g.V(); v++){
        //还没有访问的就遍历访问
        if(!marked[v]){
            DFS(g, v, v);
        }
    }
}

Cycle::~Cycle() {
    delete[] marked;
}

bool Cycle::HasCycle() {
    return has_cycle;
}

void Cycle::DFS(Graph g, int v, int neighbor_point) {
    marked[v] = true;
    for(int s: g.Adj(v)){
        if(!marked[s]){
            //这里的第二个参数应该填v,之后递归遍历ｖ的邻边的邻边，邻接点已经访问过的只能是v。
            DFS(g, s, v);
        }else if(s != neighbor_point){
            has_cycle = true;
        }
    }
}