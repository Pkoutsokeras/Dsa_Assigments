#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <fstream>
 using namespace std;
 struct graph{
     int v;
     string *vertex_names;
     int **matrix;
 };
 graph read_graph()
 {
     graph g;
     cin >> g.v;
     g.vertex_names = new string[g.v];
     for(int i=0; i < g.v; i++)
     {
        cin >> g.vertex_names[i];
     }
     g.matrix = new int *[g.v];
     for (int i=0;  i <g.v; i++){
         g.matrix[i] = new int[g.v];
         for(int j=0; j<g.v; j++)
         {
             cin >> g.matrix[i][j];
         }
     }
     return g;
 }


 void print_graph(graph g){
     for(int i=0; i<g.v; i++){
         cout << g.vertex_names[i] << " -> ";
         for (int j = 0; j < g.v; j++){
             if(g.matrix[i][j] == 1)
             {
                 cout<< g.vertex_names[j]<< " ";
             }
         }
         cout << endl;
     }
 }

/* Function for Topologycal Sort */
 void topological_sort(graph g){
     vector<int> in_degree(g.v,0);
     for(int j=0; j < g.v; j++)
         for(int i=0; i< g.v; i++)
             if(g.matrix[i][j])
                 in_degree[j]++;
    queue<int> q;
    for(int i=0; i<g.v; i++)
        if(in_degree[i]==0)
            q.push(i);

    int visited =0;
    vector <int> top_order;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        top_order.push_back(u);
        for (int j=0; j<g.v; j++){
            if (g.matrix[u][j]==1){
                in_degree[j]--;
                if(in_degree[j]==0)
                    q.push(j);
            }
        }
        visited++;
    }
    cout << visited << endl;
    if(visited !=g.v){
        cerr << "cycle exists." << endl;
        return;
    }
    for(int i=0; i< top_order.size(); i++)
        cout << g.vertex_names[top_order[i]] << " ";
    cout << endl;
 }

 
void delete_graph(graph g){
    for(int i=0; i< g.v; i++)
        delete[] g.matrix[i];
    delete[] g.matrix;
    delete[] g.vertex_names;
}


 int main(){
     freopen("dag1.txt", "r", stdin);
     fstream filestr;
     string buffer;
     filestr.open("results.txt",ios::out);
     if(!filestr.is_open()){
         cerr << "File not found!" << endl;
         exit(-1);
     }
     string matrix;
     string vertex;
     graph g = read_graph();
     for(int i=0; i< g.v; i++){
         filestr << g.vertex_names[i] << "-> ";
         for (int j=0; j<g.v; j++){
             if(g.matrix[i][j] == 1){
                 filestr << g.vertex_names[j] << " ";
             }
         }
         filestr << endl;
     }
     filestr.close();
     print_graph(g);
     topological_sort(g);
     
     delete_graph(g);
     cout << "memory freed" << endl;
 }

