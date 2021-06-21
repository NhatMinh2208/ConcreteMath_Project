#include "MathRR.hpp"

int main()
{
	FILE* fin=fopen("robot.txt","r");

	int num,vertex;
	int r;
	int a,b;
	int c,d;
	fscanf(fin,"%d",&num);

	fscanf(fin,"%d",&vertex);


	int graph[255][255];
	for(int i=0;i<vertex;i++){
		fscanf(fin,"%d",&a);
		fscanf(fin,"%d",&b);
		fscanf(fin,"%d",&r);
		graph[a][b]=r;
		graph[b][a]=r;
	}

	fclose(fin);
 
    kruskalMST(graph,num);
    printf("\n");
	greedycoloring(graph,num);
	printf("\n");
	int tree[max][2];

   int dinh;
	printf("Nhap vao so dinh: "); scanf("%d", &dinh);
   int n2 = dinh -2 ;
   int prufer[2][max];
  randomPruferCode(n2, prufer);
  pruferConstruction(n2, prufer);
  printDot(n2+2, prufer, tree);
  makeprufercode(tree,n2);
  return 0;

}