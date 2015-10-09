#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <Eigen/SparseCholesky>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace Eigen;
using namespace std;


int main(){
	
 SparseMatrix<double> A((2 * 4), 6);

 ifstream ifs("matrix_A.txt");

 string line;
 double x;
 double y;
 double z;
 double a;
 double b;
 double c;

 vector<double> rowCoordinates (6);
 
 if(ifs.is_open()){
 	
	for(int i = 0; i < 8; i++){
		
		getline(ifs, line);
		if(!line.empty()){
			
			if(stringstream(line) >>x>>y>>z>>a>>b>>c){
				rowCoordinates.at(0) = x;
				rowCoordinates.at(1) = y;
				rowCoordinates.at(2) = z;
				rowCoordinates.at(3) = a;
				rowCoordinates.at(4) = b;
				rowCoordinates.at(5) = c;
	
			}
		}
		
		for(int j = 0; j < 6; j++){

			A.insert(i, j) = rowCoordinates.at(j);
		}
	}

 }


//cout << A << endl;

SparseMatrix<double> new_A (6,6);
new_A = A.transpose()*A; 
cout << new_A << endl;

VectorXd vectb(8);
vectb <<150.0, 455.0, 570.0, 340.0, 550.0, 510.0, 915.0, 570.0;

//cout << vectb << endl; 

//SparseMatrix<double> new_b (6,1);

//new_b  = A.transpose()*vectb;
VectorXd new_b = A.transpose()*vectb;

//cout << new_b << endl;


//Solve Ax = b

SimplicialCholesky<SparseMatrix<double> > chol(new_A);
VectorXd vect_x = chol.solve(new_b);

//cout << "SOLUTION" << endl;
//cout << vect_x << end;;



return 0;

}

