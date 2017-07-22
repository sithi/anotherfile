#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int node =6;
int visit[100];
int dis[100];
int visited_seq[100];
int n,a,source;
vector<int>v[100];

void BFS(int source){
     queue<int>q;
     q.push(source);

     while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++){
            int y=v[x][i];
            if(visit[y]==0){
                q.push(y);

            }
        }

     }

}
int main(){
    for(int i=0;i<node;i++){
        printf("how many adjacent:");
        scanf("%d",& n);
        for(int j=0; j<n ;j++){
            printf("Enter values:");
            scanf("%d",& a);
            v[i].push_back(a);
        }
    }
    for(int i=0;i<node;i++){
        printf("%d->",i+1);
        for(int j=0;j<v[i].size();j++){
            printf("%d",v[i][j]);

        }
 printf("\n");
    }

return 0;
}

