#include <Eigen/Sparse>
#include <Eigen/Dense>
#include <Eigen/StdVector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace Eigen;
using namespace std;


int readA(SparseMatrix<double>& A, string filename) {
	double x;
	ifstream file(filename);
	if(file.is_open()) {
		int i = 0;
		int j = 0;
		while (file >> x) {
			if(i < A.rows()) {
				A.insert(i, j) = x;
				j++;


				if (j == A.cols()) {
					i++;
					j=0;
				}
			}
		}
		file.close();

		cout << endl;
		cout << endl;
//		cout << A << endl;
        }
       
	 else {
                cout << "Unable to open file" << endl;
                return 1;
        }


	return 0;
}




int compute(SparseMatrix<double> A, SparseMatrix<double> M, VectorXd& result) {
	cout << "Hello" << endl;	
SparseMatrix<double> test;	
	test = A * M;



cout << test << endl;	
	return 0;
}



int main() {
        int NumberOfPixel = 4;
        int rows = 2*NumberOfPixel;
        int cols = 6;

        SparseMatrix<double> mat(rows, cols);
        mat.reserve(VectorXi::Constant(cols,4));
	
	readA(mat, "coordinates.txt");
	//cout << mat << endl;
	cout << "finish matrix A initialization." << endl;

	


	
	double x;
	//process b
	VectorXd b(2*NumberOfPixel);
	ifstream bfile("b.txt");
	if (bfile.is_open()){
		int i = 0;
                while (bfile >> x) {
			b(i) = x;
			i++;
                }

                bfile.close();
        }
        else {
                cout << "Unable to open file" << endl;
                return 1;
        }


	//cout << b << endl;
	cout << "finish b initialization." << endl;


        SparseMatrix<double> new_mat = mat.transpose() * mat;
        VectorXd new_b = mat.transpose() * b;
	SimplicialCholesky<SparseMatrix<double> > chol(new_mat);
        VectorXd transform = chol.solve(new_b);


	cout << "success" << endl;
	
	ofstream trans;
	trans.open("transformation_matrix");
	trans << transform;
	trans.close();

	//finish calculating the transformation matrix X
	



	VectorXd result;
	SparseMatrix<double> data(11,3);      //dense 
	data.reserve(VectorXi::Constant(3,11));

	readA(data, "test.txt");
	
	cout << endl;
	cout << data << endl;

	
	//build the new b 
	
	SparseMatrix<double> matrix_tran(3,2);
	matrix_tran.reserve(VectorXi::Constant(3,2));
	readA(matrix_tran, "matrix_transform.txt");
	
	cout << endl;
	cout << endl;
	cout << matrix_tran;

	compute(data, matrix_tran, result);

	cout << "finish!!" << endl;


        return 0;
}

