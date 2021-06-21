#include <stdio.h>
#include <stdlib.h>
#include "MathRR.hpp"
#include <string.h>
/*long nu[10001][10001];
long nam[10001][10001];
long chong[10001];
int main() {
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1; i<= n; i++)
{

		for(j=1; j<= n; j++)
	  {
	  	scanf("%d", &nu[i][j]);
	  }

}
	for(i=1; i<=n; i++)
	{

	for(j=1; j<=n; j++)
	  {
	  	scanf("%d", &nam[i][j]);
	  }
   }
   Ghep_cap(nu,nam,chong,n);
   printf("%-8s %-8s\n","nu","nam");
	  for(i=1; i<=n;i++)
	  {
	  	printf("%-8d %-8d\n", i,chong[i]);
	  }
	  return 0;
}
*/
long a[10001][10001];
int ktra(char s1[], char s2[])
{
	int i,d=0;
	for(i=0; i<5; i++)
	 if(s1[i]==s2[i]) d++;
	 if(d==4) return 1;
}

int timkiem(char s[],int d,char b[][255])
{
	int i;
	for(i=1; i<d;i++)
	if(strcmp(b[i],s)==0) return i;
	return 0;
}
int main()
{

	FILE *inp = fopen("dulieu.txt","r");
	FILE *dothi = fopen("dothi.dot","w+");
	if(inp==NULL) printf("khong mo duoc file\n");
	if(dothi==NULL) printf("khong mo duoc file\n");
	int d=1;
	//long a[10001][10001];
	char b[10001][255];
	fprintf(dothi,"graph dothi\n");
	fprintf(dothi,"{\n");
	while(fscanf(inp,"%s",b[d])!=EOF)
	{
		fprintf(dothi,"%d;\n",d);
		d++;
	}
		fclose(inp);
	int i,j;
	for(i=1; i<d-1; i++)
	for(j=i+1; j<d; j++)
	{
	     a[i][j]=0;
	     a[j][i]=0;
		if(ktra(b[i],b[j])==1)
		{
			a[i][j]=1;
			a[j][i]=1;
			fprintf(dothi,"%d--%d;\n",i,j);

		}
	}
	//fprintf(dothi,"}");
	//fclose(dothi);
	printf("\nNhap hai tu:\n");
	char s1[6], s2[6];
	scanf("%s %s",s1,s2);
	int v1, v2;
	v1 = timkiem(s1,d,b);
	v2 = timkiem(s2,d,b);
	printf("%d %d\n",v1,v2);
	int output[10001], n=-1;
	int dd[10001] ={0};
    DFS(v1,v2,d,output,0,&n,a);
	if(n==-1) {
	fprintf(dothi, "%d [fillcolor=red, style=filled];\n",v1);
	fprintf(dothi, "%d [fillcolor=red, style=filled];\n",v2);
	fprintf(dothi,"}");
	fclose(dothi);
	printf("khong co duong di\n"); return 0;}
	printf("quang duong theo dinh:\n");

	for(i=0; i<=n; i++)
	{
	  printf("%d ",output[i]);
	 fprintf(dothi, "%d [fillcolor=red, style=filled];\n",output[i]);
	}
	fprintf(dothi,"}");
	fclose(dothi);
	printf("\n");
	for(i=0; i<=n; i++)
	{
	  printf("%s ",b[output[i]]);
	}
	printf("\n");

}
/*long post[max],pre[max];
char b[10001][10];
long a[10001][10001];
int ktra(char s1[], char s2[])
{
	int i,j,d=0;
	int kt[6]={0};
	for(i=1; i<5; i++)
	 for(j=0; j<5;j++)
	  if(s1[i]==s2[j]&&kt[j]==0)
	  {
	  	d++;
	  	kt[j]=1;
	  	break;
	  }
	 if(d==4) return 1;
	 else return 0;

}
int timkiem(char s[],int d)
{
	int i;
	for(i=1; i<d;i++)
	if(strcmp(b[i],s)==0) return i;
	return 0;
}
int main() {
	FILE *inp = fopen("dulieu2.txt","r");
	//FILE *dothi = fopen("dothi2.dot","w");
	//fprintf(dothi,"digraph dothi\n");
	//fprintf(dothi,"{\n");
	int d=1;
	char s1[6], s2[6];
	while(fscanf(inp,"%s",b[d])!=EOF)
	{
		//fprintf(dothi,"%d;\n",d);
		d++;
	}
		fclose(inp);
	int i,j;
	for(i=1; i<d-1; i++)
	for(j=i+1; j<d; j++)
	{
		if(ktra(b[i],b[j])==1)
		{
			a[i][j]=1;
			//fprintf(dothi,"%d->%d;\n",i,j);

		}
		if(ktra(b[j],b[i])==1)
		{
			a[j][i]=1;
			//fprintf(dothi,"%d->%d;\n",j,i);
		}
	}
	int dd1[max]={0};
	for(i=1; i<d; i++)
	if(dd1[i]==0)
      tinhpost(i,d,dd1,a,post,pre);
     printf("\nso thanh phan lien thong manh cua do thi la: %d\n",TPLT(d,a,post));
	//printf("\nso thanh phan lien thong manh cua do thi la: %d\n",TPLT(d,a,post,dothi));
	//fprintf(dothi,"}");
	//fclose(dothi);
	return 0;
}*/

