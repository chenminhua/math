/**
 * @ Author: Minhua Chen
 * @ Create Time: 2019-08-24 11:00:32
 * @ Modified by: Minhua Chen
 * @ Modified time: 2019-08-24 15:00:57
 * @ Description: g++ -I eigen -O3 main.cpp
 */

#include <iostream>
#include <Eigen/Dense>
using namespace::Eigen;

#define DEFAULT_SIZE_M 5

typedef Eigen::Matrix<int, Dynamic, Dynamic> IntMatrix;

int main(int argc, char* argv[])
{
    int m_size;
    if (argc > 1) {
        m_size = atoi(argv[1]);
    } else {
        m_size = DEFAULT_SIZE_M;
    }
    
    IntMatrix mat1(m_size,m_size);
    IntMatrix mat2(m_size,m_size);
    IntMatrix result(m_size,m_size);
    mat1.setRandom();
    mat2.setRandom();

    result = mat1 * mat2;
    
    std::cout << "finished" << std::endl;
}