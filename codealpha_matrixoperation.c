#include<stdio.h>
int main(){
  int a[10][10],b[10][10],c[10][10];
  int r1,c1,r2,c2;
 
  printf("Enter the rows and columns of a:\n");
  scanf("%d %d",&r1,&c1);
  printf("Enter the elements of matrix a:\n");
  for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
      scanf("%d",&a[i][j]);
    }
  }
  printf("Enter the rows and columns of b:\n");
  scanf("%d %d",&r2,&c2);
  printf("Enter the elements of matrix b:\n"); 
  for(int i=0;i<r2;i++){
    for(int j=0;j<c2;j++){
      scanf("%d",&b[i][j]);
    }
  }
  //Matrix addition
  int sum[10][10];
  if(r1==r2 && c1==c2){
    printf("\nAddition-Resultant matrix:\n");
    for(int i=0;i<r1;i++){
      for(int j=0;j<c1;j++){
        c[i][j]=a[i][j]+b[i][j];
        printf("%d\t",c[i][j]);
      }
      printf("\n");
    }
  }
  else{
    printf("Matrix addition is not possible");
  }
  //Matrix multiplication
  int mul[10][10];
  if(c1==r2){
    for(int i=0;i<r1;i++){
      for(int j=0;j<c2;j++){
        mul[i][j]=0;
      }
    }
    for(int i=0;i<r1;i++){
      for(int j=0;j<c2;j++){
        for(int k=0;k<c1;k++){
          mul[i][j]+=a[i][k]+b[k][j];
        }
      }
    }
    printf("\nMultiplication-Resultant matrix:\n");
    for(int i=0;i<r1;i++){
      for(int j=0;j<c2;j++){
        printf("%d\t",mul[i][j]);
      }
       printf("\n");
    }
  }
  else{
    printf("\nMatrix multiplication is not possible\n");
  }
 
  //Transpose
  int T1[10][10],T2[10][10];
  for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
     T1[j][i]=a[i][j];
     T2[j][i]=b[i][j];
    }
  }
  printf("\nTransposed Matrix of a:\n");
  for(int i=0;i<r1;i++){
   for(int j=0;j<c1;j++){
      printf("%d\t",T1[i][j]);
    }
    printf("\n");
  }
  printf("\nTransposed Matrix of b:\n");
  for(int i=0;i<r2;i++){
    for(int j=0;j<c2;j++){
      printf("%d\t",T2[i][j]);
    }
    printf("\n");
  }
  return 0;
}
