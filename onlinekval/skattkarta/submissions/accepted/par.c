#include <stdio.h>

int main() {
  char map[100][101];
  int taken[100][100];
  int R,C,r,c;
  scanf("%d %d", &R, &C);
  for(r=0;r<R;r++) scanf("%s", map[r]);
  for(r=0;r<R;r++) for(c=0;c<C;c++) taken[r][c]=0;
  r=c=0;
  while(1) {
    if(map[r][c]=='A') {
      printf("sushi\n");
      return 0;
    }
    else if(map[r][c]=='B') {
      printf("samuraj\n");
      return 0;
    }
    else if(taken[r][c]) {
      printf("cykel\n");
      return 0;
    }
    taken[r][c]=1;
    if(map[r][c]=='>') c++;
    else if(map[r][c]=='<') c--;
    else if(map[r][c]=='v') r++;
    else r--;
  }
}
