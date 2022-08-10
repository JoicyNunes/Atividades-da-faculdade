#include <stdio.h>
int somaBorda (int L, int C, int mat[L][C]) 
{
    int res;
    
    for (int i=0;i<L;i++) 
    {
        for (int x=0;x<C;x++) 
        {
            if (i==0 && x==0 || (i + 1)==L && (x+1)==C || i==0 && (x+1)==C || (i+1)==L && x==0) 
            {
                res+=mat[i][x];
            }
        }
    }
    
    return res;
}

int main() 
{
    int l=10, c=3;
    int matriz[l][c];
    
    for (int i=0;i<l;i++) 
    {
      for (int x=0;x<c;x++) 
      {
          matriz[i][x] += 1;
      }
    
    }
    
    printf("A soma é %i", somaBorda(l, c, matriz));

    return 0;
}
