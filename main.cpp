/**
 * 0. We need to solve Ax=b for cases where only a unique solution exists i.e if A.shape = [m,n] then m=n and A is full rank matrix
 * 2. hardcode input A and b
 * 1. create CMakeLists.txt, add Eigen as dependency
 * 3. write simplest solution (x=A_(-1)*b)
 * 4. check that solution is correct
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
        3, 5, 6,
        2, 4, 3;
    b << 5, 7, 8;

    // solving
    x = A.completeOrthogonalDecomposition().pseudoInverse() * b;

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