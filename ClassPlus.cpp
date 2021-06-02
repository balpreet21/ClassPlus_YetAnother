#include <iostream>
using namespace std;
#define INF 1000000

int main() {
	// your code goes here
	int n,h,x;	cin>>n>>h>>x;
	int arr[h];for(int i=0;i<h;i++)cin>>arr[i];
	
	int mx[n+1][n+1];
	//Initialising the matrix
	for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++){
        	if(i==j)mx[i][j]=0;
        	else mx[i][j]=INF;
        }
    
	//Filling the matrix
	for(int i=1;i<n;i++){
		int u,v;	cin>>u>>v;
		mx[u][v]=mx[v][u]=1;
	}
	
	int dist[n+1][n+1]; //Distance Matrix
	for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            dist[i][j]=mx[i][j];
			
	//Floyd Warshall Algorithm
	for (int k=1;k<=n;k++) {
        for (int i=1; i<=n;i++) {      
            for (int j=1;j<=n;j++) {
                	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
	int count=0;//Counting the possible epicentre
	for(int j=1;j<=n;j++){
		int flag=1;
		for(int i=0;i<h;i++){
			if(dist[j][arr[i]]>x || dist[arr[i]][j]>x)
				flag=0;
		}
		if(flag==1){
		count++;
		}
	}
	
	cout<<count<<endl;//Output
	
	return 0;
}
