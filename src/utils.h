/**
 *  File with utilities
 */
#include <Eigen/Dense>

bool if_square(Eigen::MatrixXd& A);

/**
 *  @param A matrix for rank computation
 *  @param lu_decomp (optional) object of LU decomposition computed with rank
 */
bool is_full_rank(Eigen::MatrixXd& A, Eigen::FullPivLU<Eigen::MatrixXd>* lu_decomp = nullptr);