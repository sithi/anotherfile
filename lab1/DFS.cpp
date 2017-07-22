#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
int node =6;
int visit[100];
int distans[100];
int visited_seq[100];
int head[100];
int n,a,source,destination;

stack<int>q1;
vector<int>v[100];

void DFS_path_length(int source){
     stack<int>q;
     q.push(source);
     while(!q.empty()){
        int x=q.top();
        q.pop();
        for(int i=0;i<v[x].size();i++){
            int y=v[x][i];
            if(visit[y]==0){
                q.push(y);
                distans[y]=distans[x]+1;
                visit[y]=1;
                head[y]=x;
            }
        }

     }
     visit[source]=1;

}
int DFS_print_path(int starting_point,int ending_point){

   if(starting_point == ending_point)
     return 1;
   int parent = head[ending_point];
   q1.push(parent);
   DFS_print_path(starting_point,parent);

}


int main(){
    for(int i=1;i<=node;i++){
        printf("Adjacent of %d parent:",i);
        scanf("%d",& n);
        if(n>0)
        printf("write the child name:");
        for(int j=1; j<=n ;j++){
            scanf("%d",& a);
            v[i].push_back(a);
        }
    }
    for(int i=1;i<=node;i++){
        printf("%d->",i);
        for(int j=0;j<v[i].size();j++){
            printf(" %d ",v[i][j]);

        }
        printf("\n");
    }
    printf("Source : ");
    scanf("%d",&source);
    printf("\n");
    printf("Destination : ");
    scanf("%d",&destination);
    DFS_path_length(source);
    DFS_print_path(source,destination);
    printf("\n");
    printf("Path of length = %d\n",distans[destination]);
    printf("The Path is : ");
    for(int i=0;i<distans[destination];i++){
            int value = q1.top();
            q1.pop();
            printf("%d -> ",value);
    }
    printf("%d\n ",destination);
return 0;
}
