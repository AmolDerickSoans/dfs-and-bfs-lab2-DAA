// A C++ program to print topological sorting of a DAG 
#include <iostream> 
#include <list> 
#include <stack> 
using namespace std; 

class Graph{
    int V;
    list<int> *adj;
    void topoSortUtil(int v, bool visited[], Stack<int> &Stack);

    public:
    Graph(int V);
    void AddEdge(int src , int dest);
    void TopologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj  new list<int>[V];
}

void Graph::AddEdge(int src , int dest)
{
    adj[src].push_back(dest);

}

void Graph::topSortUtil(int v , bool visited[] , stack<int> &Stack)
{
    visited[v] = true ; //set v as visited

    list<int>::iterator i;

    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if( !visited[*i])
        {
            topSortUtil(*i,visited,Stack); //recursive call till vertex has no child

        }
        Stack.push(v);
    }
}

void Graph :: TopologicalSort()
{   
    stack<int> Stack;
    bool *visited = new bool[V];
    for(int i = 0 ; i < V ; i++)
    {
        visited[i]  = false;
    }

    for(int i = 0; i <V ; i++)
    {
        if(visited == false)
        topoSortUtil(i,visited,Stack);
    }

    while( Stack.empty() == false)
    {
        cout<< Stack.top()<<" "<<"\n";
        Stack.pop();
    }
}

int main() 
{ 
	
	int n,v1,v2;
	cin>>n;
	Graph g(n); 
	for(int i=1;i<=n;i++)
    {	cin>>v1>>v2;
	g.addEdge(v1, v2);} 
	

	cout << " Topological Sort of the given graph \n"; 
	g.topologicalSort(); 

	return 0; 
}
