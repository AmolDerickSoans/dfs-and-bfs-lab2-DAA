#include<iostream>
using namespace std;

#define MAX 30

//adjacenecy matrix class

class AdjMatrix{

    private:
    int n;
    int **adj;
    bool *visited;

    public:
    AdjMatrix(int n){
        this->n = n;
        visited  = new bool[n];
        adj  = new int*[n];
        for(int i =0 ; i < n; i++)
        {
            adj[i] = new int[n];
            for(int j =0 ; j<n ; j++)
            {
                adj[i][j] = 0;
            }
            
        }

    }

    //adding edges to the graph
    void add_edge(int origin, int destin){
        if(origin > n || destin> n|| origin < 0|| destin < 0)
        {
            cout<<"Invalid edge!  ";


        }
        else 
        {
            adj[origin-1][destin -1]  = 1;
        }
    }

    //print the graph
    void display(){
        int i ,j;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<adj[i][j]<<"  ";
                
            }
            cout<<"\n";
        }
    }
    



//code for bfs
void bfs(int src){
    //mat[][] is the adjecency matrix 
    //int n is the number of nodes , int src is the starting point fo rthe search

    int visited[MAX] = {0}; //visited initlialised to zero '0'

    int u, v, i;
    int Q[MAX], f = -1 , r = -1; //making a queue wtih front = rear = -1
    Q[++r] = src;
    //adding source node to the q first
    visited[src] = 1;
    //adding src to visited

    while(f<r)
    {
        u = Q[++f];// deleting Q element into u
        for(v = 1; v<=n;v++){
            if (adj[u][v] == 1 && visited[v] == 0)
           { visited[v] = 1;//setting v to visited 
                Q[++r] = v; //adding v to Q
           }
        }
        cout<<u<<" ";

    }




}
};

int main()
{
    int nodes, max_edges, origin ,destin;
    cout<<"Enter the number of nodes: \n";
    cin >> nodes;

    AdjMatrix am(nodes); //using the cinstructor that we created above
    max_edges   =  nodes *(nodes - 1);

    for(int i = 0 ; i < max_edges  ; i++)
    {
        cout<<"Enter the edges (-1 -1 to exit) \n";
        cin >> origin >> destin;

        if(origin == -1 && destin == -1){
            break;
        }

        else 
        am.add_edge(origin,destin);
    }
   am.display();


    


    // code for bfs
    
    cout<<"enter the source : \n";
    int srcc;
        am.bfs(srcc);

    return 0;

    }

