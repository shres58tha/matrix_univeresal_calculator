#include<stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
//#include "./adjoint_matrix.c"

#define MAX_LIMIT 1000
#define LIMIT 30
typedef struct matrix_{
    int row;
    int col;
    float **mat; 
}matrix;
matrix nullmatrix={0,0,NULL};

int initialize(matrix *mat_A, int option) { // return 0 = O initalized //1=random //2=scanf //-1=mem error
    if ((mat_A->mat= (float **) malloc(sizeof(float *) * mat_A->row))==NULL) {printf("\nError allocating for rows\n");return -1;}
    for (int i=0;i<mat_A->row;i++){
        if ((*(mat_A->mat+i)= (float *) malloc(sizeof(float ) * mat_A->col))==NULL){printf("\nError allocating for columns\n");return -1;}
        for (int j=0;j<mat_A->col;j++){
            //(*(mat_A->mat+i)+j)=rand()%100;
              mat_A->mat[i][j]=0;;    // this is easy to understand initialized to 0
        }
    } // matrix memory allocation.
    if (option==0) return 0;
    
    if (option==1){
    for (int i=0;i<mat_A->row;i++)
        for (int j=0;j<mat_A->col;j++)
            //(*(mat_A->mat+i)+j)=rand()%100;
              mat_A->mat[i][j]=rand()%100;   // this is easy to understand
            //mat_A->mat[i][j]= (float)(rand()%10)/(rand()%10)*100;  // range nan to infinity

    return 1;
    }
    
    else {
        for (int i=0;i<mat_A->row;i++)
            for (int j=0;j<mat_A->col;j++){
             printf("\nenter number for index %d  %d :", i , j);
             scanf("%f",&mat_A->mat[i][j]);    // just trying to keep it simple other wise one & and * can be eliminated here
            }
    return 2;
    }
}// do not touch code above this  it is working

void free_mat(matrix *mat_A){
    //free memory of matrix c c being used
        for (int i=0; i<mat_A->row;i++){
            free (*(mat_A->mat+i));  // free what the pointer points too row pointer point to
            //printf("\nxyz");
        }
        free (mat_A->mat); // frees the rows of pointer itself
        mat_A->row=0;
        mat_A->col=0;
        
}

void display_mat(matrix *mat_A){
    for (int i=0;i<mat_A->row;i++){
        for (int j=0;j<mat_A->col;j++){
           printf ("%10.8g  ",  *(*(mat_A->mat+i)+j)  );
        }
        printf("\n");
    }

}
    
int add_mat(matrix A, matrix B, matrix C) {  // argument passed by value suceess return 1 failure return -1
    // this returns value in mat as it is a pointer other wise here we would have to pass the reference via passing address
    if (A.row!=B.row && A.col!=B.col){
        printf("two matrix cant be added diff. dimension"); 
        return (-1); // failure // exit needs parenthensis
    }
    
    for (int i=0;i<A.row;i++){
        for (int j=0;j<A.col;j++){
           //printf ("\n %d  %d \n ",i,j);    //debug line
            C.mat[i][j]= A.mat[i][j] + B.mat[i][j];
        }
    }
return (1);  //sucess
}

int sub_mat(matrix A, matrix B, matrix C) {  // argument passed by value suceess return 1 failure return -1
    // this returns value in mat as it is a pointer other wise here we would have to pass the reference via passing address
    if (A.row!=B.row && A.col!=B.col){
        printf("two matrix cant be subtracted diff. dimension"); 
        return (-1); // failure // exit needs parenthensis
    }
    
    for (int i=0;i<A.row;i++){
        for (int j=0;j<A.col;j++){
           //printf ("\n %d  %d \n ",i,j);    //debug line
            C.mat[i][j]= A.mat[i][j] - B.mat[i][j];
        }
    }
return (1);  //sucess
}

int mul_mat(matrix A, matrix B, matrix  C) { // argument passed by value suceess return 1 failure return -1
    if (A.col!=B.row) {
        printf("\ncannot multiply two matrix col1 != row2 \n");
        return (-1);
    }
    for (int i=0;i<A.row;i++){
        for (int j=0;j<B.col;j++){  // produt matrix is of type row1 X col2
            for (int k=0;k<A.col;k++){
                C.mat[i][j]+=A.mat[i][k] * B.mat[k][j];
                //printf (" i %d j %d k %d \n",i,j,k);  // be careful on the variables. copy might save time but also took lot of time to debug
            }
        }

    }
return 1;  // success
}



