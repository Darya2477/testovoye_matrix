#pragma once

#include <vector>
#include <iostream>

class MatrixMultiplier{
public:
    MatrixMultiplier(): matrix_1{}, matrix_2{}, result{} {};
    ~MatrixMultiplier() = default;
    inline std::pair<std::vector<std::vector<int64_t>>, std::vector<std::vector<int64_t>>> get_input_matrix() {return std::make_pair(matrix_1, matrix_2);};
    inline std::vector<std::vector<int64_t>> get_result_matrix() {return result;};
    void run();

private:

    void print_matrix(const std::vector<std::vector<int64_t>> &);
    void write_matrix(std::vector<std::vector<int64_t>> &, uint32_t, uint32_t);
    void multiply_matrix(const std::vector<std::vector<int64_t>> &, const std::vector<std::vector<int64_t>> &);
    std::vector<std::vector<int64_t>> matrix_1, matrix_2, result;
};