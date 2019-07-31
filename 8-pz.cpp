#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
struct Node 
{ 
    Node* parent; 
    int m[3][3]; 
    int x, y; 
}; 
Node* newNode(Node *nd,int px,int py){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->parent = nd;
    NA(i,0,3){
        NA(j,0,3){
            n->m[i][j] = nd->m[i][j];
        }
    }
    lli t = n->m[px][py];
    n->m[px][py]=-1;
    n->m[nd->x][nd->y]=t;
    return n;
}
Node* opr(Node *nd,lli dir){
    if(dir==1){
        if((nd->x)-1>-1)return newNode(nd,(nd->x)-1,(nd->y));
    } else if(dir==2){
        if((nd->y)-1>-1)return newNOde(nd,(nd->x),(nd->y)-1);
    } else if(dir==3){
        if((nd->y)+1<3) return newNode(nd,(nd->x),(nd->y)+1);
    } else {
        if((nd->x)+1<3) return newNOde(nd,(nd->x)+1,(nd->y));
    }
}
lli check(lli init[3][3],lli fin[3][3]){
    NA(i,0,3){
        NA(j,0,3){
            if(init[i][j]!=fin[i][j]) return 0;
        }
    }
    return 1;
}
void dfs(Node *nd,lli fin[3][3]){
    if(check(nd->m,fin)) return;
    NA(i,1,5){
        dfs(opr(nd,i),fin);
    }
}
int main(){
    lli init[3][3],fin[3][3];
    struct Node *n = (struct Node)malloc(sizeof(struct Node));
    n->parent = NULL;
    cout<<"Enter initial state"<<endl;
    NA(i,0,3){
        NA(j,0,3){
            cin>>n->m[i][j];
            if(n->m[i][j]==-1){
                n->x=i; n->y=j;
            }
        }
    }    
    cout<<"enter final state"<<endl;
    NA(i,0,3){
        NA(j,0,3){
            cin>>fin[i][j];
        }
    }

    return 0;
}