#include "MathRR.hpp"

using namespace std;

int matrix[10000][10000];

int main(){
	int n,m;
	int a, b, c, d;

	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			matrix[i][j] = 0;
		}
	}
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		matrix[a][b] = c;
		matrix[b][a] = c;
	}
	cin >> a >> b;
	cin >> c >> d;

	printf("\n---Dijsktra:\n");
	dijkstra(matrix,a,c,n);
	printf("\n---Prim: \nGraph dothi {\n");
	PRIM(matrix, n, 1);

	printf("\n---BFS: \nGraph dothi {");
	BFS(matrix, n, 1);
	printf("}");
	return 0;
}
