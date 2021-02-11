#include "utils.h"

bool if_square(Eigen::MatrixXd& A){
    if(A.rows() != A.cols()){ // TODO: that fuction not only checks for square-ish. That is bad practice
        return false;
    }
    return true;
}