#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 15
void dijikstra(int G[MAX][MAX],int n,int sn);
int i,j;
void main(){
	int a[MAX][MAX],n,s;
	printf("Enter the no. of vertices : ");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d", &a[i][j]);
	printf("\nEnter the starting node: ");
	scanf("%d", &s);
	dijikstra(a,n,s);
}

void dijikstra(int G[MAX][MAX],int n,int sn)
{
	int cost[MAX][MAX],dist[MAX],pred[MAX];
	int visit[MAX],count,mindist,nnode;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	for(i=0;i<n;i++)
	{
		dist[i]=cost[sn][i];
		pred[i]=sn;
		visit[i]=0;
	}
	dist[sn]=0;
	visit[sn]=1;
	count=1;
	while(count<n-1){
		mindist=INFINITY;
		for(i=0;i<n;i++)
			if(dist[i]<mindist && !visit[i])
			{
				mindist=dist[i];
				nnode=i;
			}
		visit[nnode]=1;
		for(i=0;i<n;i++)
			if(!visit[i])
				if(mindist+cost[nnode][i]<dist[i])
				{
					dist[i]=mindist+cost[nnode][i];
					pred[i]=nnode;
				}
			count++;
	}

	for(i=0;i<n;i++)
		if(i!=sn)
		{
			printf("\nDistance of %d = %d", i, dist[i]);
			printf("\nPath = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=sn);
		}
}
