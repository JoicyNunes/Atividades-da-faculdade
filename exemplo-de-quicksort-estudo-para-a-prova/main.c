/*quickSort*/
#include <stdio.h>
#include <conio.h>

void quick_Sort(char *a, int left, int right){
    int i, j;
    char x, y;
    i = left;
    j = right;
    x = a[(left+right)/2];
    while(i<=j){
        while(a[i] < x && i < right){
            i++;
        }
        while(a[j] > x && j > left){
            j--;
        }
    if(i<=j){
        y=a[i];
        a[i]=a[j];
        a[j]=y;
        i++;
        j--;
        }
    }
    if(j>left){
        quick_Sort(a, left, j);
    }
    if(i<right){
        quick_Sort(a, i, right);
    }
}

int main(void){
    char t[] = {"fatec ipiranga"};
    int tamanho = sizeof(t)/sizeof(char);
    quick_Sort(&t, 0, tamanho-1);
    int x=0;
    for(x=0;x<tamanho;x++){
        printf("\n%c %i", t[x], t[x]);
    }
    return 0;
}
