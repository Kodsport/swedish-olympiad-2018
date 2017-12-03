#include <stdio.h>

int now[10][15],n,min;

void MLX(int nr) {
  int i,k;
  for(i=0;i<n;i++) if(now[nr][i]) break;
  if(i==n) {
    min=nr;
    //for(k=0;k<=nr;k++) {
    //  for(i=0;i<n;i++) printf("%d", now[k][i]);
    //  printf("\n");
    // }
    // printf("\n");
  }
  if(nr<min-1) {
    for(i=0;i<n-1;i++) {
      for(k=0;k<n;k++)
	now[nr+1][k]=(k<2) ? (1-now[nr][i+k]) : ((k-2<i) ? now[nr][k-2] : now[nr][k]);
      MLX(nr+1);
      for(k=0;k<n;k++)
	now[nr+1][k]=(k>=n-2) ? (1-now[nr][i+k-(n-2)]) : ((k<i) ? now[nr][k] : now[nr][k+2]);
      MLX(nr+1);
    }
  }
}

	  
int main() {
  char ch[20];
  scanf("%s", ch);
  for(n=0;ch[n];n++) now[0][n]=(ch[n]=='S');
  min=9;
  MLX(0);
  printf("%d\n", min);
  return 0;
}
