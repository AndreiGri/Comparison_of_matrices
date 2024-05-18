#include <iostream>

void matrices(int(*matrix)[4])                                                      // Метод проверяет корректность ввода значений
{                                                                                   // матрицы и записывает их в матрицу
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int n;
            std::cout << ' ';
            std::cin >> n;
            if (std::cin.fail() || std::cin.peek() != '\n')                         // если предыдущее извлечение оказалось неудачным,
            {
                std::cerr << " Incorrectly entered data!\n Try again!" << std::endl;
                std::cin.clear();                                                   // то возвращаем cin в 'обычный' режим работы
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // и удаляем значения предыдущего ввода из входного буфера
                j--;
            }
            else
            {
                matrix[i][j] = n;                                                   // иначе записываем данные в ячейку
            }
        }
    }
}

void show_matrix(int(*matrix)[4])                                        // Метод выводит матрицу в консоль
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j < 3)
            {
                std::cout << ' ' << matrix[i][j] << '\t';
            }
            else
            {
                std::cout << ' ' << matrix[i][j] << '\t' << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

void diagonal_matrix(int(*matrix)[4])                                    // Метод приводит матрицу к диагональному виду
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != j)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void comparison_matrices(int(*matrix1)[4], int(*matrix2)[4])             // Метод приводит матрицу к диагональному виду если
{                                                                        // матрицы одинаковы иначе выводит сообщение о том что матрицы
    for (int i = 0; i < 4; i++)                                          // не одинаковы
    {
        for (int j = 0; j < 4; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
            {
                std::cout << " The matrices are not the same!" << std::endl;
                return;
            }
        }
    }
    diagonal_matrix(matrix1);
    show_matrix(matrix1);
}

int main()
{
    int matrix1[4][4];                                                    // Объявляем массивы для записи матриц
    int matrix2[4][4];

    std::cout << " Enter the values of the first matrix:" << std::endl;   // Запрашиваем значения первой матрицы
    matrices(matrix1);                                                    // Вводим значения
    std::cout << " Enter the values of the second matrix:" << std::endl;  // Запрашиваем значения второй матрицы
    matrices(matrix2);                                                    // Вводим значения

    std::cout << std::endl;

    show_matrix(matrix1);                                                 // Показываем первую матрицу

    show_matrix(matrix2);                                                 // Показываем вторую матрицу

    comparison_matrices(matrix1, matrix2);                                // Приводим матрицу к диагональному виду и выводим в консоль 
}                                                                         // либо выводим сообщение о разнице в матрицах