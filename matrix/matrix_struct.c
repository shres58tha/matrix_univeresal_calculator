#include "./matrix_basic_functions.c"
//#include "./adjoint_matrix.c"
/*
int adjoint_mat(matrix A, int **adj){
    

for (int i=0;i<A.row-1;i++){
    
    //printf("\n\n%d ...........  : \n",*(*(adj+0) +0));
    
    int adj_row=A.row-1, adj_col=A.row-1;
            for (int j=0;j<A.col-1;j++){  // these for selcting the matrix[][]
                
                for(int k=0;k<A.row-1;k++){
                    for(int l=0;l<A.col-1;l++){  // these for selectionf elements of matrix[][].mat[][]
                       
                        for (int m=0; m<A.row;m++){  // these for assinging elements for the matrix A to matrix[][].mat
                            if (i==k) continue;
                            for (int n=0; n<A.col;n++){   
                               if(j==m) continue; 
                               printf("\n\n%g ...........  :",*(adj+i)[j]->mat[m][n]);
                              // *(adj+i)[j].mat[k][l]=A.mat[m][n];
                            }
                        }
                        
                    
                    } 
                } 
    
                
            }
        
        
return 1; // success
}
*/
int main(){
         
         srand(time (0)); // very much needed to generate random number
         matrix a = nullmatrix, b=nullmatrix, c=nullmatrix;  // need initialization at time of declaration .. otherwise free() gives trouble later on
         printf("enter the dimension of first matrix :");
         scanf("%d %d",&a.row,&a.col);
         initialize(&a,1); // takes adress ot matrix type and integer 0 for initialization with 0, 1= rand, 2=user input1
         display_mat(&a);
         
         printf("enter the dimension of second matrix :");
         scanf("%d %d",&b.row,&b.col);
         initialize(&b,1); // takes adress of matrix type and integer 0 for initialization with 0, 1= rand, 2=user input
         display_mat(&b);
         // add sub
         if (a.row!=b.row && a.col!=b.col ){printf("\ntwo matrix cant be added or subtracted diff. dimension \n");}
         
         else {                         // very buggy program would be very easy with c++ constructor and distructor
             c.row=a.row;
             c.col=a.col;
             initialize (&c,0);
             
             if(add_mat(a,b,c) <0) printf("error in add_mat function \n");
             else {
             printf("\n matrix addition sucessful result is : \n");
             display_mat(&c);
             }
             
             
             if(sub_mat(a,b,c) <0) printf("error in add_sub function \n");
             else {
             printf("\n matrix substraction sucessful result is : \n");
             display_mat(&c);
             }
        }
        ///*
        printf(" address of c.mat %p \n",c.mat);
        if(c.mat != NULL)    //c.mat points to null it is not initalized hence no need to free matrix.
            free_mat(&c);
        //*/
        // multiply
        if (a.col!=b.row) printf ("\nCannot multiply matrix as not matching dimension\n");
        else {
            c.row=a.row;
            c.col=b.col;
            if (initialize(&c,0)<0) {printf("Error initialization of matrix c");}
                
            //display_mat(&c);
            
            if(mul_mat(a,b,c) <0) printf("error in multiply function \n");
            else {
            printf("\n matrix multiplication sucessful result is : \n");
            display_mat(&c);
            printf("\n");
            
            }
        }
        
        //cofactor
        printf(" calculating cofactor of matrix a");
        int cf_row,cf_col;
        cf_row=a.row;
        cf_col=a.col;
        printf (" cf_row %d cf_col %d  \n",cf_row, cf_col);  
        matrix cf[cf_row][cf_col], **cf_ptr;
        for (int i=0;i<cf_row;i++){
            for (int j=0;j<cf_col;j++){
                cf[i][j].row=cf_row-1;
                cf[i][j].col=cf_col-1;
                initialize(&cf[i][j],0);
                printf (" i %d j %d  \n",i,j);  // be careful on the variables. copy might save time but also took lot of time to debug
            }
        }
        
        for (int i=0;i<cf_row;i++){
            for (int j=0;j<cf_col;j++){
                 printf("cofactor [%d][%d] \n",i,j);
                 display_mat(&cf[i][j]);
                 printf("\n");
            }
        }
        int cat[cf_row][cf_col], **cat_ptr;
        cat_ptr=&cat[0][0];
        cf_ptr=cf;
        printf("\n\n%f ...........  : \n",(*(cf_ptr+0) +0)->mat[0][0]);
   
        //adjoint_mat(a, cat);
        /*
        for (int i=0;i<cf_row;i++){
            for (int j=0;j<cf_col;j++){
                 printf("cofactor [%d][%d] \n",i,j);
                 display_mat(&cf[i][j]);
                 printf("\n");
            }
        }
        */
        
        //adjoint
        
        //inverse
        
        //divide
        //**/

return 0;
}


