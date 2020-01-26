#include<iostream>
using namespace std;

#define MAX 30
class matrix{

 private:
 int n ;
int **adj;
int nodecount = 0;
bool *visited;
 public:

    matrix(int n){
        this ->n = n;
        visited = new bool[n];
        adj  = new int*[n];

        for(int i =0 ;i <n ; i++ )
        {   adj[i] = new int[n];
            for(int j = 0; j<n; j++)
            {
                adj[i][j]  = 0;
            }
        }
    }


    void add_edge(int origin, int destin){
        if(origin > n || origin <0 || destin >n || destin < 0)
        cout<<"Invalid Edge ! \n";
        else
        {
            adj[origin - 1][destin - 1] = 1;
        }
        
    }


    void display(){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j< n ;j++){
                cout<<adj[i][j] << " ";
                
            }
            cout<<endl;

        }
    }

    void dfs(int src){
        int u,v,i; 
        int visited[MAX] = {0}; 
        
        int S[MAX] ;
        int top  =-1;

        S[++top] = src;
        visited[src] = 1 ;

        while(top !=-1){
            u  = S[--top];

            for(v= 0 ; v<=n ; v++){
                if(adj[u][v] == 1 && visited[v] == 0)
                {
                    visited[v]  = 1;
                    S[++top]  = v;

                }
               
            }
             cout<<u<<" "; //prints out what is popped from the stack
                nodecount++;
        }


    }

   
    void check(){
        for(int y = 0 ; y<n ; y++){
        dfs(y);
        if(nodecount == n)
        cout<<"the mother vertex of the graph is:"<<y <<"\n";
        continue;
    }
    }
};

int main()
{
    int nodes, max_edges, origin ,destin;
    cout<<"Enter the number of nodes: \n";
    cin >> nodes;

    matrix am(nodes); //using the cinstructor that we created above
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

    //mother vertex of a graph is the vertex that is has a path to evry other node in the graph 
    //to find the mother vortex
        am.check();
    



    
    cout<<"enter the source : \n";
    int srcc;
        cin >>srcc;
        am.dfs(srcc);

    return 0;

    }