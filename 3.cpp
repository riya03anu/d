#include<bits/stdc++.h>
using namespace std ;

struct Edge
{
	int source,dest,weight ;
};

struct Graph
{
	int V,E ;
	
	struct Edge* edge ;
};

struct Graph* createGraph(int V,int E)
{
	struct Graph* graph = new Graph;
	graph->V = V ;
	graph->E = E ;
	graph->edge = new Edge[E];
	
	return graph ;
};

void printArr(int data[],int V)
{

	for (int i = 0; i < V; i++)
	{
		cout << "\t" << data[i] ;
	}

	cout << "\n" ;
}

void bellmanFord(struct Graph* graph,int source) 
{
	int V = graph->V ;
	int E = graph->E ;
	int dist[V] ;
	
	for(int i = 0 ; i < V ; i++)
	{
		dist[i] = INT_MAX ; 
	}
	dist[source] = 0;
	
	int i = 0 ;

	for(i = 0 ; i < V-1 ; i++)
	{
		cout << "Iteration " << i << ": " ;
		printArr(dist,V) ;
		for(int j = 0 ; j < E ; j++)
		{
			int u = graph->edge[j].source ;
			int v = graph->edge[j].dest ;
			int weight = graph->edge[j].weight ;
			
			if(dist[u] != INT_MAX && dist[u]+weight < dist[v])
			{
				dist[v] = dist[u]+weight ;
			}
		} 
	}
	
	for(int j = 0 ; j < E ; j++)
	{
		int u = graph->edge[i].source ;
		int v = graph->edge[i].dest ;
		int weight = graph->edge[i].weight ;
			
		if(dist[u] != INT_MAX && dist[u]+weight < dist[v])
		{
			cout<<"Graph Has Negative Cycle" ;
			cout << "Final Iteration: " ;
			printArr(dist,V) ;
			return ;
		}
	}	
	
	cout << "Final Iteration: " ;
	printArr(dist,V) ;
	return ;
}


int main()
{

	int V , E , source;
	
	cout<<"\nEnter The No of Vertices: " ;
	cin >> V ;
	cout<<"\nEnter The No. Edges: " ;
	cin >> E ;
	
	struct Graph* graph = createGraph(V,E) ;
	
	for(int i = 0 ; i < E ; i++)
	{
		cout<<"\nEnter Source of "<< i <<" Edge: " ;
		cin>>graph->edge[i].source ;
		cout<<"\nEnter dest of "<< i <<" Edge: " ;
		cin>>graph->edge[i].dest;
		cout<<"\nEnter weight of "<< i <<" Edge: " ;
		cin>>graph->edge[i].weight ;
	}
	
	source = graph->edge[0].source ;
	
	bellmanFord(graph,source);
	
	return 0 ;
}


/*
OUTPUT
--------------------------------------------------------------------------------------------------------------------------------

student@studentg++ bellman-ford.cpp 
student@student:~$ ./a.out

Enter The No of Vertices: 6

Enter The No. Edges: 9

Enter Source of 0 Edge: 0

Enter dest of 0 Edge: 1

Enter weight of 0 Edge: 6

Enter Source of 1 Edge: 0

Enter dest of 1 Edge: 2

Enter weight of 1 Edge: 4

Enter Source of 2 Edge: 0

Enter dest of 2 Edge: 3

Enter weight of 2 Edge: 5

Enter Source of 3 Edge: 2

Enter dest of 3 Edge: 1

Enter weight of 3 Edge: -2

Enter Source of 4 Edge: 2

Enter dest of 4 Edge: 4

Enter weight of 4 Edge: 3

Enter Source of 5 Edge: 3

Enter dest of 5 Edge: 2

Enter weight of 5 Edge: -2
