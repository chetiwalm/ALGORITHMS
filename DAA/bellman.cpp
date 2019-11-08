#include<iostream>
#include<climits>
using namespace std;

class edge
{
public :
    int source;
    int dest;
    int weight;

    edge(int s , int d , int w)
    {
        source = s;
        dest = d;
        weight = w;
    }
};

void BellmanFord(edge** arr , int V , int E , int* dist)
{
    for(int i=1 ; i<V ; i++)
    {
        for(int j=0 ; j<E ; j++)
        {
            if(dist[arr[j]->source] + arr[j]->weight < dist[arr[j]->dest])
                dist[arr[j]->dest] = dist[arr[j]->source] + arr[j]->weight;
        }
    }
}

int main()
{
    int V , E;
    cin>>V>>E;

    edge** arr = new edge*[E];
    for(int i=0 ; i<E ; i++)
    {
        int s , d , w;
        cin>>s>>d>>w;
        arr[i] = new edge(s , d , w);
    }
    int *dist = new int[V]{};
    for(int i=1 ; i<V ; i++)
        dist[i] = INT_MAX;

    BellmanFord(arr , V , E , dist);

    cout<<endl;
    for(int i=0 ; i<V ; i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }
    delete[] dist;
    for(int i=0 ; i<V ; i++)
        delete arr[i];
    delete arr;
    return 0;
}