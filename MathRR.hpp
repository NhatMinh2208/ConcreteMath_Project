#include <bits/stdc++.h>
#include <queue>
#include <iterator>
#include <map>
#include <list>
#define max 10001

int parent[10000];
using namespace std;

extern void PRIM(int matrix[][10000], int n, int  start);
extern void dijkstra(int matrix[][10000], int start, int  end, int n);
extern void BFS(int matrix[][10000], int n, int start);
extern void Ghep_cap(long nu[][max],long nam[][max],long chong[max],int n);
extern void DFS(int u,int u2,int d, int output[], int n,int *h,long a[][max]);
extern void tinhpost(int u,int d,int dd[],long a[][max],long post[], long pre[]);
extern int TPLT(int d,long a[][max],long post[]);
extern int find(int i);
extern int findmin(int arr[], int n);
extern void union1(int i, int j);
extern void kruskalMST(int cost[][255], int V);
extern void greedycoloring(int graph[][255], int V);
extern void pruferConstruction(int n2, int prufer[2][max]);
extern void printDot(int n, int tree[2][max], int a[][2]);
extern void randomPruferCode (int n2, int prufer[2][max]);
extern void randomPruferCode (int n2, int prufer[2][max]);


void PRIM(int matrix[][10000], int n, int  start)
{
	unordered_set <int> Connected, Unconnected;
	int totalweight = 0;
	// them cac dinh tren do thi vao tap chua co tren cay
	for(int i = 0; i < n; i++)
	{
		Unconnected.insert(i);
	}
	Connected.insert(start);
	Unconnected.erase(start);
	int c, u, minc, minu;

	int min;
	while(!Unconnected.empty())
	{
		min = 99999;
		// can tim canh co trogn so nho nhat ma 1 dinh thuoc C và dinh thuoc U
		for (auto itr = Connected.begin(); itr != Connected.end(); ++itr) {
			c = *itr;

			for (int i=0; i<n; i++){
				if(matrix[i][c] != 0){
					if(Unconnected.find(i) != Unconnected.end())
					{
						int edgeweight = matrix[i][c];
						if(min>edgeweight)
						{
							min = edgeweight;
							minc = c;
							minu = i;
						}
					}
				}

			}
		}
		printf(" %d -- %d;   weight %d\n",minu,minc,min);
		// bo sung them canh (minc, minu)
		totalweight = totalweight + min;
		Connected.insert(minu);
		Unconnected.erase(minu);
	}
	printf("}\nTotal weight : %d\n",totalweight);
}

void dijkstra(int matrix[][10000], int start, int  end, int n){

	// khoang cach tu start đen y[i] laf x[i], và di qua step[i] buoc.
	int x[10000];
	int y[10000];
	int step[10000];

	int visit[10000]; 		// danh dau dinh  da tham
	int cnt = 0;    		// dùng dem buoc
	int l = 0;

	step[start] = 0;
	for(int i = 0; i < n; i++){
		visit[i] = 0;
	}

	typedef pair<int, int> pi;

	priority_queue<pi, vector<pi>, greater<pi> > Q;
	Q.push(make_pair(0,start));
	int v;
//	unordered_set <int> visitedList ;

	int currentWeight;
	while(!Q.empty())
	{
		pair<int, int> top = Q.top();
		v = top.second;

		Q.pop();
		if(visit[v]!= 0) continue;
		visit[v]= 1;

		currentWeight = top.first;
//		printf("%d %5d--> , total weight %d\n",step[v], v, currentWeight);
		{
			step[l] = step[v];
			x[l] = currentWeight;
			y[l] = v;
			l++;
		}
		if(v == end)
		{
			printf("Total : %d  \n", currentWeight);
			printf("Road: %d to %d:   ",start , end);

			int total =  step[l-1];
			int  s; 	  		// lưu vao mangr đuòng đi ngắn nhất
			s = end;
			printf("%d <-  ", end);

			int h = 1;

			while(total){
				for(int i = 1; i < l; i++){

					if((step[i] == total-1) && (matrix[y[i]][s] != 0 )){

						printf("%d <- ", y[i]);
						s = y[i];
						break;
					}
				}
				total--;
		    }
			printf("%d", start);

			printf("\n");

			return;
		}

		for (int i = 0; i < n; i++) {
			if(matrix[v][i] != 0 && visit[i] == 0)
			{
				int edgeweight = matrix[v][i];
				Q.push(make_pair(currentWeight+edgeweight, i ));
				step[i] = step[v] + 1;
			}
		}
	}
}

void BFS(int matrix[][10000], int n, int start)
{
	queue<int> Q;
	Q.push(start);
	int v;
	unordered_set <int> visitedList ;

	visitedList.insert(start);

	while(!Q.empty())
	{
		v = Q.front();
		printf("\n\t");
		Q.pop();

		for (int i=0; i<n; i++){
			if(matrix[i][v] != 0){
				if(visitedList.find(i) == visitedList.end())
				{
					printf("%d -- %d; \t", v, i);
					Q.push(i);
					visitedList.insert(i);
				}
			}
		}
	}
}
int check(int m, int n,int k, long chong[],long nu[][max])
{
	int i,j;
	int vt1, vt2;
	int dem=0;
	for(i=1; i<=n; i++)
	{
		if(nu[m][i]==k) {vt1 = i;dem++;}
		if(nu[m][i]==chong[m]){vt2=i;dem++;}
		if(dem==2) break;
	}
	if(vt1<vt2) return 1;
	else return -1;
}
void Ghep_cap(long nu[][max],long nam[][max],long chong[max],int n) {
int d_nam[max]={0};
int next[max]={1};
int i,j;
	for(i=1; i<= n; i++){ chong[i]=-1;next[i]=1;}
      int d=n;
	  while(d!=0)
	  {
	  	for(i=1; i<=n; i++)
	  	{
	  		if(d_nam[i]==0)
	  		{
	  			int k = next[i];
	  				if(chong[nam[i][k]]==-1)//neu ban nu chua co chong
                        {
                            d--;
                            chong[nam[i][k]]=i;//chong cua ban nu la ban nam i
                            d_nam[i]=1; // ban nam i da xet
                        }
                    else
                         {
                            if(check(nam[i][k],n,i,chong,nu)==1)
                               {
                                    int h = chong[nam[i][k]];
                                    d_nam[h]=0;
                                    chong[nam[i][k]]=i;
                                    d_nam[i]=1;
                                }
                        }
			    next[i]++;
			  }}}}
int dd[max];
void DFS(int u,int u2,int d, int output[], int n,int *h,long a[][max])
{ dd[u]=1;
  output[n] = u;
  if(u==u2)
  {
    *h = n;
    return;
  }
  int i;
  for(i=1; i<d; i++)
  {if(dd[i]==0&&a[i][u]==1) if(*h==-1)DFS(i,u2,d,output,n+1,h,a);}
}
int clock_dem=0;
void pref(int u,long pre[])
{
	clock_dem++;
	pre[u]= clock_dem;
}
void postt(int u,long post[])
{
	clock_dem++;
	post[u]=clock_dem;
}
void tinhpost(int u,int d,int dd[],long a[][max],long post[], long pre[])
{
  dd[u]=1;
  pref(u,pre);
  int i;
  for(i=1; i<d; i++)
  { if(dd[i]==0&&a[i][u]==1) tinhpost(i,d,dd,a,post,pre);}
  postt(u,post);
}
void DAG (int u,int d,int dd[],int* ts,long a[][max])
{
	dd[u]=1;
	(*ts)++;
    int i;
  for(i=1; i<d; i++)
  { if(dd[i]==0&&a[u][i]==1) DAG(i,d,dd,ts,a);}
}
int TPLT(int d,long a[][max],long post[])
{
	int i,j;
    int tong=0;
    int dem =d-1;
    int dd[max]={0};
    while(dem>0)
	{
         int maxx=0;
         int k;
         int ts=0;
         for(j=1;j<d;j++) if(post[j]>maxx&&dd[j]==0) { maxx=post[j];k=j;}
         DAG(k,d,dd,&ts,a);
         tong++;
         dem=dem-ts;
    }
	return tong;

}


int find(int i){
	while(parent[i]!=i){
		i=parent[i];
	}
	return i;
}

void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
  

void kruskalMST(int cost[][255], int V)
{
    int mincost = 0; 
  
    for (int i = 0; i < V; i++)
        parent[i] = i;
  
    int edge_count = 0;
    while (edge_count < V - 1) {
        int min = max, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && cost[i][j] < min && cost[i][j]!=0) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
  
        union1(a, b);
        printf("Edge %d:(%d, %d) cost:%d \n",
               edge_count++, a, b, min);
               
        mincost += min;
    }
    printf("\n Minimum cost= %d \n", mincost);
}
  
void greedycoloring(int graph[][255], int V)
{
	

    int result[V];
 
   
    result[0]  = 0;
 
    
    for (int u = 1; u < V; u++)
        result[u] = -1; 
 
  
    int available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = 0;
 
  
    for (int u = 1; u < V; u++)
    {
      

        for (int i = 0; i < V; ++i){
        	if(graph[u][i]!=0){
        		if (result[i] != -1)
                available[result[i]] = 1;
			}
		}
   
        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == 0)
                break;
 
        result[u] = cr; 
 
   
        for (int i = 0; i < V; ++i){
        	if(graph[u][i]!=0){
        		if (result[i] != -1)
                available[result[i]] = 0;
			}
		}
	}
  
    for (int i = 0; i < V; i++){
    	switch(result[i])
        	{
        		case 0:
        			{
        				printf("%d [fillcolor=red, style=filled];\n",i);
        				break;
					}
				case 1:
        			{   
        				printf("%d [fillcolor=green, style=filled];\n",i);
        				break;
					}
				case 2:
        			{
        				printf("%d [fillcolor=blue, style=filled];\n",i);
        				break;
					}
				case 3:
        			{
        				printf("%d [fillcolor=yellow, style=filled];\n",i);
        				break;
					}
				case 4:
        			{
        				printf("%d [fillcolor=pink, style=filled];\n",i);
        				break;
					}
				case 5:
        			{
        				printf("%d [fillcolor=while, style=filled];\n",i);
        				break;
					}
				case 6:
        			{
        			printf("%d [fillcolor=black, style=filled];\n",i);
        				break;
					}
				case 7:
        			{
        				printf("%d [fillcolor=orange, style=filled];",i);
        				break;
					}
				case 8:
        			{
        				printf("%d [fillcolor=purple, style=filled];\n",i);
        				break;
					}
				case 9:
        			{
        				printf("%d [fillcolor=brown, style=filled];\n",i);
        				break;
					}				
			}
	}

       
        

}

void pruferConstruction(int n2, int prufer[2][max])
{
  int phantu[n2+2] = {0};       

  prufer[1][n2] = 0;          
  
  for (int i = 0; i < n2+1; i++) phantu[prufer[1][i]] ++;    


  int min = 0;  while (phantu[min] > 0) min++;              
  int x = min;                                              
  
  for (int i = 0; i < n2+1; i++)                            
    {      
      prufer[0][i] = x;                                      
      
      phantu[prufer[1][i]] --;                               

      
                                                             
      if (phantu[prufer[1][i]] == 0 && min > prufer[1][i])
	{
	  x = prufer[1][i];	  
	}
      else{
	do min++; while (phantu[min] > 0) ;                 
	x = min;
      }
    }
}


void printDot(int n, int tree[2][max], int a[][2])
{
  cout<<"graph tree {"<<endl;
  cout<<"label=\" Prufer code = [ ";

  for (size_t i = 0; i < n-3; i++)
  {
    cout<<tree[1][i]<<", ";
  }
  cout<<tree[1][n-3]<<" ";

  cout<<"]\"; "<<endl;
  for (int i = 0; i < n-1; i++){
    cout<<tree[0][i]<<" -- "<<tree[1][i]<<";"<<endl;
    a[i][0]=tree[0][i];
    a[i][1]=tree[1][i];
}
  cout<<"}"<<endl;
  
}

void randomPruferCode (int n2, int prufer[2][max])
{
  srand (time(NULL));  
  for (int i = 0; i < n2; i++)
    {
      prufer[1][i] = rand() % (n2 + 2) ;
    }
}

int findmin(int arr[], int n){
	int check=0;
	int min;
	if(n!=1){
	while(arr[check]!=0){
		min=arr[check];
		check++;
	}
	for(int i=0;i<n;i++){
		if(arr[i]<min && arr[i]!=0) min=arr[i];
	}
	return min;
}
}
void makeprufercode(int a[][2], int n2){
  for(int i=0; i<n2+1; i++){
  	for(int j=0; j<2; j++){
  		printf("%d ", a[i][j]);
	  }
	  printf("\n");
  }
  int n=n2+1;
	int b[10000]={}; 
	int c[10000];
	int d[10000];
	int p=0;
	int k=0;

	for(int i=0;i<n;i++){
		for(int j=0; j<2; j++){
			b[a[i][1-j]]++;
		}
	}

	printf("\n");
	for(int m=0;m<n;m++){
		p=0;
		for(int i=0;i<n;i++){

			for(int j=0; j<2; j++){
				
				if(b[a[i][j]]==1 && a[i][j]!=-1){
					c[p]=a[i][j];
					p++;
				}
			}
		}

		int min=findmin(c,p);

		for(int i=0; i<n; i++){
			for(int j=0; j<2; j++){
				if(a[i][j]==min){
					b[a[i][1-j]]--;
					b[a[i][j]]--;
					d[k]=a[i][1-j];
					a[i][j]=a[i][1-j]=-1;
					k++;
				}
			}
		}
	}
	printf("\n");
	printf("Output: Prufer Code la: \n");
	for(int i=0;i<k-1;i++){
		printf("%d ", d[i]);
	}
}
