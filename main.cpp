// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0
#include<vector>
#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int** data;       // Pointer to 2-D array that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);//"""""""""""""""""""""""""""""""""""""""

void releaseMemory ( vector < matrix >& sm );
vector < matrix > selected_memory;
// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2);// Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

/* Student #2 with the middle ID (e.g., 20170082)
 The last operator >> takes an istream and a matrix and return the
 the same istream so it is possible to cascade input like
 cin >> matrix1 >> matrix2 << endl;*/
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);  //""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8,9,10,11,12};
  int data2 [] = {10,20,30,40,50,60,70,80,90,100,110,120};
  int data3 [] = {10,100,10,100,10,100,10,100};
    int data4[]={0,0,0,0,0,0,0,0,0};
  matrix mat1, mat2, mat3,mat4;
  createMatrix (2, 4, data1, mat1);
  createMatrix (3, 4, data2, mat2);
  createMatrix (2, 4, data3, mat3);
createMatrix(3,3,data4,mat4 );
 // cout << mat1 << endl;
  //cout << mat2 << endl;
  //cout<< mat1*mat2 ;
  cout << mat1 << endl;
  cout << mat3 << endl<<endl;
  mat1+=mat3;
  cout<<mat1;
 // cout << mat1=mat2 << endl<<endl;
  //mat1+= mat3 += mat3;

  // Add more examples of using matrix
  // .......
releaseMemory( selected_memory );
  return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int* [row];

  for (int i = 0; i < row; i++)
    mat.data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat.data[i][j] = num[i * col + j];
 selected_memory.push_back( mat );}

//-------------------------------------------------------------
void releaseMemory ( vector < matrix >& sm )
{
    for ( int i = 0; i < sm.size(); i++ )
    {
        for ( int row = 0; row < sm[i].row; row++ ) delete[] sm[i].data[row];
        delete[] sm[i].data;
    }
}
//-------------------------------------------------------------

ostream& operator<< (ostream& out, matrix mat) {
   for(int i = 0;i < mat.row;i++){
    for(int j = 0;j < mat.col;j++){
  out << mat.data[i][j] << " "; }
  out << endl; }
  return out;
   }
//-------------------------------------------------------------

istream& operator>> (istream& in, matrix& mat){
in >> mat.row >> mat.col;
 for(int i=0;i<mat.row;i++){
    for(int j=0;j<mat.col;j++){
        in>>mat.data[i][j];}}
       return in;}
//--------------------------------------------------------------

matrix operator+  (matrix mat1, matrix mat2){
    matrix mat4;
if(mat1.row==mat2.row && mat2.col==mat2.col){
int data4[mat1.row*mat1.col];
createMatrix(mat1.row,mat1.col,data4,mat4);
for(int i=0;i<mat1.row;i++){
    for(int j=0;j<mat1.col;j++){
        mat4.data[i][j]= mat1.data[i][j]+ mat2.data[i][j];}}
return mat4;}
else
    cout<<"Invalid"<<endl;}
//-------------------------------------------------------------
matrix operator-  (matrix mat1, matrix mat2){
matrix mat4;
if(mat1.row==mat2.row && mat2.col==mat2.col){
int data4[mat1.row*mat1.col];
createMatrix(mat1.row,mat1.col,data4,mat4);
for(int i=0;i<mat1.row;i++){
    for(int j=0;j<mat1.col;j++){
        mat4.data[i][j]= mat1.data[i][j]- mat2.data[i][j];}}
return mat4;}
else
    cout<<"Invalid"<<endl;
    }

//-------------------------------------------------------------
matrix operator *  (matrix mat1, matrix mat2){
matrix mat; int sum;
if(mat1.col == mat2.row ){
int data1[ mat1.row * mat2.col ];
createMatrix(mat1.row , mat2.col , data1 , mat);

for(int i = 0;i < mat1.row;i++){
    for(int j = 0;j < mat2.col;j++){
            sum = 0;
            for(int k = 0;k < mat1.col;k++){
        sum = sum + mat1.data[i][k] * mat2.data[k][j]; }
        mat.data[i][j] = sum;
    }
}
return mat;
}
else
    cout<<"Invalid"<<endl;
}

//-------------------------------------------------------------
matrix operator+  (matrix mat1, int scalar){
matrix mat4;
int data4[mat1.row*mat1.col];
createMatrix(mat1.row,mat1.col,data4,mat4);
for(int i=0;i<mat1.row;i++){
    for(int j=0;j<mat1.col;j++){
        mat4.data[i][j]= mat1.data[i][j]+scalar;}}
return mat4;
}

//-------------------------------------------------------------
matrix operator-  (matrix mat1, int scalar){
matrix mat4;
int data4[mat1.row*mat1.col];
createMatrix(mat1.row,mat1.col,data4,mat4);
for(int i=0;i<mat1.row;i++){
    for(int j=0;j<mat1.col;j++){
        mat4.data[i][j]= mat1.data[i][j]-scalar;}}
return mat4;
}

//-------------------------------------------------------------
matrix operator*  (matrix mat1, int scalar){
matrix mat4;
int data4[mat1.row*mat1.col];
createMatrix(mat1.row,mat1.col,data4,mat4);
for(int i=0;i<mat1.row;i++){
    for(int j=0;j<mat1.col;j++){
        mat4.data[i][j]= mat1.data[i][j]*scalar;}}
return mat4;
}


//-------------------------------------------------------------
matrix operator+= (matrix& mat1, matrix mat2){
    if(mat1.row == mat2.row && mat1.col == mat2.col){
for(int i=0;i<mat1.row;i++){
    for(int j=0;j<mat1.col;j++){
        mat1.data[i][j]= mat1.data[i][j]+ mat2.data[i][j];
        }}
}
else cout<<"Invalid"<<endl;
}
//--------------------------------------------------------------
matrix operator-= (matrix& mat1, matrix mat2){
    if(mat1.row == mat2.row && mat1.col == mat2.col){
    for(int i=0;i<mat1.row;i++){
    for(int j=0;j<mat1.col;j++){
        mat1.data[i][j]= mat1.data[i][j]- mat2.data[i][j];
        }}
return mat1;}
else cout<<"Invalid"<<endl;
}

//--------------------------------------------------------------
matrix operator+= (matrix& mat, int scalar){
    for(int i=0;i<mat.row;i++){
    for(int j=0;j<mat.col;j++){
        mat.data[i][j]= mat.data[i][j]+ scalar;}}
return mat;
}

//--------------------------------------------------------------
matrix operator-= (matrix& mat, int scalar){
    for(int i=0;i<mat.row;i++){
    for(int j=0;j<mat.col;j++){
        mat.data[i][j]= mat.data[i][j]- scalar;}}
return mat;
}

//--------------------------------------------------------------
void   operator++ (matrix& mat){
for(int i = 0;i < mat.row;i++){
    for(int j = 0;j < mat.col;j++){
        mat.data[i][j] = mat.data[i][j] +1;}}
}

//--------------------------------------------------------------
void  operator-- (matrix& mat){
for(int i=0;i<mat.row;i++){
    for(int j=0;j<mat.col;j++){
mat.data[i][j]--;
}}
}

//---------------------------------------------------------------

bool operator == (matrix mat1, matrix mat2){
    int indicator = 0;
if(mat1.row==mat2.row && mat2.col==mat2.col)
    {
       for(int i = 0;i < mat1.row;i++){
    for(int j = 0 ;j < mat1.col;j++) {
        if(mat1.data[i][j] != mat2.data[i][j]){
            indicator = 1;break;}
    }}
}
else indicator = 1;
if(indicator == 1)return false;
else return true;
}

//---------------------------------------------------------------
bool   operator != (matrix mat1, matrix mat2){
    char indicator=0;
if(mat1.row == mat2.row && mat2.col == mat2.col)
    {
       for(int i = 0;i < mat1.row;i++){
    for(int j = 0;j < mat1.col;j++) {
        if(mat1.data[i][j] != mat2.data[i][j]){
            indicator = 1;break;}
    }}
}
else indicator = 1;
if(indicator == 1 )return true;
else return false;
}

//-------------------------------------------------------------
bool   isSquare   (matrix mat){
if(mat.row == mat.col)
    return true;
else
    return false;

}
//--------------------------------------------------------------
bool   isSymetric (matrix mat){
    char indicator = 0;
if(mat.row != mat.col)
    indicator = 1;
for(int i = 0;i < mat.row ;i++){
    for(int j = 0;j < mat.row ;j++){
            if(i != j){
        if(mat.data[i][j] != mat.data[j][i] )
            indicator = 1;
        }
    }}
    if (indicator == 0) return true;
    else return false;
}
//--------------------------------------------------------------
bool isIdentity (matrix mat){
   char indicator=0;
if(mat.row == mat.col){
for (int i = 0 , j = 0 ; i < mat.row , j < mat.col  ;i++ , j++){
    if(mat.data[i][j] != 1){
    indicator = 1;break;}
}
for(int i = 0; i < mat.row; i++){
    for(int j = 0; j < mat.row; j++){
        if(i != j ){
            if(mat.data[i][j] != 0)
                indicator = 1 ;
        }
    }}
}
else indicator = 1;
if(indicator==1)return false;
else return true;
}
//--------------------------------------------------------------
matrix transpose(matrix mat){
    matrix trans;
    int data1[mat.row*mat.col];
    createMatrix(mat.col ,mat.row ,data1 ,trans);
for(int i = 0; i < mat.row; i++){
    for(int j = 0; j < mat.col; j++){
        trans.data[j][i]=mat.data[i][j];
    }}
    return trans;
}
