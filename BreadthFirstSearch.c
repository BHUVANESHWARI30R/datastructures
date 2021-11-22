// Breadth First Search

//bfs

#include<stdio.h>
#include<stdlib.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v){
    for(i=1;i<=n;i++)
        if(a[v][i]&&!visited[i])
            q[++r]=i;
    if(f<=r){
        visited[q[f]]=1;
        bfs(q[f++]);
    }
}
void main(){
    int v;
    printf("enter the no. of vertices : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        q[i]=0;
        visited[i]=0;
    }
    printf("enter the graph data in matrix form : ");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("enter the starting vertex : ");
    scanf("%d",&v);
    bfs(v);
    printf("the node which are reachable are :\n");
    for(i=1;i<=n;i++){
        if(visited[i])
            printf("%d\t",i);
        else{
            printf("bfs is not possible.not all nodes are reachable");
            break;
        }
    }
}

/*
		OUTPUT
		
	enter the no. of vertices : 4
enter the graph data in matrix form : 0
1
1
1
1
0
0
1
1
0
0
1
1
1
1
0
enter the starting vertex : 1
the node which are reachable are :
1       2       3       4 */
