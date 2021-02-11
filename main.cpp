/**
 * 3. diff between inverse and pseudeinverse
 * 4. read input matrices from file
 * 
 * 
 */
#include <iostream>
#include <Eigen/Dense>

int main(int argc, char *argv[]){
    
    // generating data
    Eigen::MatrixXd A(3,3);
    Eigen::VectorXd b(3);
    Eigen::VectorXd x(3);

    A << 1, 3, -2,
        2, 6, -4,
        2, 4, 3;
    b << 5, 7, 8;

    if(A.rows() != A.cols() ||  A.rows() < 2){
        std::cerr << "Cannot process rectangular or single element matrices" << std::endl;
        return -1;
    }

    Eigen::FullPivLU<Eigen::MatrixXd> lu_decomp(A);
    if(lu_decomp.rank() != A.rows()){
        std::cerr << "Cannot process not a full rank matrix" << std::endl;
        return -1;
    }



    // solving
    if(lu_decomp.isInvertible()){
        x = lu_decomp.inverse() * b;
    } else {
        x = A.completeOrthogonalDecomposition().pseudoInverse() * b; // todo: that should be used when matrix
    }
    

    // check solution
    Eigen::VectorXd x_hat = A*x;
    bool result = x_hat.isApprox(b);

    // printing out results
    if(result){
        std::cout << "Solution is CORRECT!" << std::endl;
    } else {
        std::cout << "Solution is INCORRECT!" << std::endl;
    }

    return 0;
}