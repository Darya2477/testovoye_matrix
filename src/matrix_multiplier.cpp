#include "./matrix_multiplier.hpp"

void MatrixMultiplier::run()
{
  try {

    std::cout << "ПРОГРАММА ДЛЯ ПЕРЕМНОЖЕНИЯ МАТРИЦ: " << std::endl << std::endl;
    
    uint32_t rows1, cols1, rows2, cols2;

    std::cout << "Введите количество строк матрицы 1: ";
    std::cin >> rows1;
    std::cout << "Введите количество столбцов матрицы 1: ";
    std::cin >> cols1;
    std::cout << "Введите количество строк матрицы 2: ";
    std::cin >> rows2;
    std::cout << "Введите количество столбцов матрицы 2: ";
    std::cin >> cols2;

    if (rows1 <= 0 || cols1 <= 0 || rows2 <= 0 || cols2 <= 0){
        throw std::logic_error("Ширина и высота матрицы должны быть положительными числами.");
    }

    if (cols1 != rows2) {
        throw std::logic_error("Несовместные матрицы.");
    }

    std::cout << "Введите элементы матрицы 1:" << std::endl;
    write_matrix(matrix_1, rows1, cols1);

    std::cout << "Введите элементы матрицы 2:" << std::endl;
    write_matrix(matrix_2, rows2, cols2);

    std::cout << "ПЕРВАЯ МАТРИЦА:" << std::endl;
    print_matrix(matrix_1);

    std::cout << "ВТОРАЯ МАТРИЦА:" << std::endl;
    print_matrix(matrix_2);

    multiply_matrix(matrix_1, matrix_2);

    std::cout << "РЕЗУЛЬТИРУЮЩАЯ МАТРИЦА:" <<std::endl;
    print_matrix(result);

    } catch (const std::exception& error) {
        std::cout << error.what() << std::endl;
    } catch (...){
        std::cerr << "Неизвестная ошибка." << std::endl;
    }

}

void MatrixMultiplier::write_matrix(std::vector<std::vector<int64_t>> & _matrix, uint32_t _rows, uint32_t _cols)
{
    _matrix.resize(_rows, std::vector<int64_t>(_cols));

    for (uint32_t i = 0; i < _rows; ++i) {
        for (uint32_t j = 0; j < _cols; ++j) {
            std::cin >> _matrix[i][j];
        }
    }
}

void MatrixMultiplier::print_matrix(const std::vector<std::vector<int64_t>> & _matrix)
{
    for (const std::vector<int64_t>& row : _matrix) {
        for (int64_t element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

void MatrixMultiplier::multiply_matrix(const std::vector<std::vector<int64_t>> & _matrix_1, const std::vector<std::vector<int64_t>> & _matrix_2)
{
    uint32_t rows1 = _matrix_1.size();
    uint32_t cols2 = _matrix_2[0].size();

    result.resize(rows1, std::vector<int64_t>(cols2));

    for (uint32_t i = 0; i < rows1; ++i) {
        for (uint32_t j = 0; j < cols2; ++j) {
            for (uint32_t k = 0; k < _matrix_1[0].size(); ++k) {
                result[i][j] += _matrix_1[i][k] * _matrix_2[k][j];
            }
        }
    }
}