#include <iostream>
#include <queue>
using namespace std;
# define V 15

void createEdge(int node1,int node2,int graph[V][V]){
    graph[node2-1][node1-1]=1;
}
void calculateIndegree(int graph[V][V],int indegree[V]){
    int countDeg=0;
    int i = 0;
    while(i<V){
         for(int i=0;i<V;i++){
        countDeg=0;
        for(int j=0;j<V;j++){
            if(graph[i][j]==1){
                countDeg++;
            }
        }
        indegree[i]=countDeg;
        
    } 
        i++;
        
    }
    
   
}

int minSemester(int indegree[V],int graph[V][V]){
    int semesters=0;
    int count=0,final_count=0;
    queue<int> zerodegree_element;
    int i = 0;
    
   for(int i=0;i<V;i++){
        if(indegree[i]==0){
            count++;
            zerodegree_element.push(i);
        }
    }
    while(!zerodegree_element.empty()){
        int k=zerodegree_element.front();
        zerodegree_element.pop();
        int i = 0;
        while(i<V){
             if(graph[i][k]>0){
                indegree[i]--;
                if(indegree[i]==0){
                    final_count++;
                    zerodegree_element.push(i);
                }
            }
            i++;
        }
            
        
       
        count--;
        if(count==0){
            count=final_count;
            final_count=0;
            semesters++;
        }
    }
    return semesters;
}
int main()
{
    int graph[V][V]={};
    createEdge(1,6,graph);
    createEdge(3,6,graph);
    createEdge(2,4,graph);
    createEdge(3,12,graph);
    createEdge(6,8,graph);
    createEdge(6,13,graph);
    createEdge(6,14,graph);
    createEdge(4,5,graph);
    createEdge(4,7,graph);
    createEdge(4,14,graph);
    createEdge(7,9,graph);
    createEdge(5,8,graph);
    createEdge(14,15,graph);
    createEdge(9,10,graph);
    createEdge(8,11,graph);
    int indegree[V]={};
    calculateIndegree(graph,indegree);
    int semester=minSemester(indegree,graph);
    cout<<"minimum semesters required are "<<semester;
    return 0;
}