import subprocess
import unittest

DEFAULT_STRING = "ПРОГРАММА ДЛЯ ПЕРЕМНОЖЕНИЯ МАТРИЦ: \n\nВведите количество строк матрицы 1: Введите количество столбцов матрицы 1: Введите количество строк матрицы 2: Введите количество столбцов матрицы 2: "

class TestMatrixMultiplier(unittest.TestCase):

    def run_binary(self, input_data):
        process = subprocess.run(['./matrix_multiplier'], input=input_data, capture_output=True, text=True)
        return process.stdout

    def test_valid_multiplication(self):
        """Проверка умножения корректных матриц"""
        input_data = "2\n3\n3\n2\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n"
        output = self.run_binary(input_data)
        expected_output = DEFAULT_STRING + "Введите элементы матрицы 1:\nВведите элементы матрицы 2:\nПЕРВАЯ МАТРИЦА:\n1 2 3 \n4 5 6 \nВТОРАЯ МАТРИЦА:\n7 8 \n9 10 \n11 12 \nРЕЗУЛЬТИРУЮЩАЯ МАТРИЦА:\n58 64 \n139 154 \n"
        self.assertEqual(output, expected_output)

    def test_invalid_dimensions(self):
        """Проверка обработки несовместных матриц."""
        input_data = "2\n3\n5\n1\n"
        output = self.run_binary(input_data)
        self.assertIn(DEFAULT_STRING+"Несовместные матрицы.", output)

    def test_zero_dimensions(self):
        """Проверка обработки нулевого размера матриц."""
        input_data = "3\n0\n3\5"
        output = self.run_binary(input_data)
        self.assertIn(DEFAULT_STRING+"Ширина и высота матрицы должны быть положительными числами.", output)

    def test_negative_dimensions(self):
        """Проверка обработки отрицательного размера матриц."""
        input_data = "3\n-4\n3\5"
        output = self.run_binary(input_data)
        self.assertIn(DEFAULT_STRING+"Ширина и высота матрицы должны быть положительными числами.", output)

if __name__ == '__main__':
    unittest.main()