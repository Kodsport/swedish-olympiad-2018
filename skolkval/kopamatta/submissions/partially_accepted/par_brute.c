#include <stdio.h>

int main(){
  int min,max,bh,bw,w,h;
  scanf("%d %d", &min,&max);
  bw=1; bh=min;
  for(w=1;w<=min;w++) for(h=w;h<=max;h++) if(w*h>=min && w*h<=max) {
    //printf("%d %d = %d  (%d)\n", w, h, w*h, h-w);
    if(h-w<bh-bw) {bh=h; bw=w; }
  }
  printf("%d %d\n", bw, bh);
  return 0;
}
