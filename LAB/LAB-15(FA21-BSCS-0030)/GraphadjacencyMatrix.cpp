#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 20;

class AdjacencyMatrix{
    private:
        int n;
        int  adj[MAX][MAX];
    public:
        AdjacencyMatrix(int k){
            n = k;
            for (int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    adj[i][j] = 0;
                }
            }
        }
 
        void add_edge(int origin, int destin){
            if( origin > n || destin > n || origin < 0 || destin < 0)
            {   
                cout<<"Invalid edge!\n";
            }
            else
            {
                adj[origin - 1][destin - 1] = 1;
            }
        }
   
        void display(){
            int i,j;
            for(i = 0;i < n;i++)
            {
                for(j = 0; j < n; j++)
                    cout<<adj[i][j]<<"  ";
                cout<<endl;
            }
        }
};

int main()
{
    int nodes, max_edges, origin, destin;
    cout<<"Enter number of nodes: ";
    cin>>nodes;
    AdjacencyMatrix am(nodes);
    max_edges = nodes * (nodes - 1);
    for (int i = 0; i < max_edges; i++)
    {
        cout<<"Enter edge (-1 -1 to exit): ";
        cin>>origin>>destin;
        if((origin == -1) && (destin == -1))
            break;
        am.add_edge(origin, destin);
    }
    am.display();
    return 0;
}
