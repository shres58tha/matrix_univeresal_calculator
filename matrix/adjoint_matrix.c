//#include "./matrix_basic_functions.c"
int adjoint_mat(matrix A, matrix *adj){
    
    
    int adj_row=A.row-1, adj_col=A.row-1;

for (int i=0;i<A.row-1;i++){
            for (int j=0;j<A.col-1;j++){  // these for selcting the matrix[][]
                
                for(int k=0;k<A.row-1;k++){
                    for(int l=0;l<A.col-1;l++){  // these for selectiong elements of matrix[][].mat[][]
                       
                        for (int m=0; m<A.row;m++){  // these for assinging elements for the matrix A to matrix[][].mat
                            if (i==k) continue;
                            for (int n=0; n<A.col;n++){   
                               if(j==m) continue; 
                               
                               (*(*adj+i)+j)->mat[k][l]=A.mat[m][n];
                            }
                        }
                        
                    
                    } 
                } 
    
                
            }
        }
        
return 1; // success
}
