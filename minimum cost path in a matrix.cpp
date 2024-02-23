#include <iostream>
using namespace std;

void showPath(int **matrix, int m, int n)
{
    cout << "\nPath\n";
    int i = 0;
    int j = 0;
    cout << "(" << i + 1 << "," << j + 1 << ")-->";
    while (i != m && j != n)
    {
        if (i == m)
        {
            j++;
        }
        else if (j == n)
        {
            i++;
        }
        else if (matrix[i + 1][j] <= matrix[i][j + 1] && matrix[i + 1][j] <= matrix[i + 1][j + 1])
        {
            i++;
        }
        else if (matrix[i][j + 1] <= matrix[i + 1][j] && matrix[i][j + 1] <= matrix[i + 1][j + 1])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
        cout << "(" << i + 1 << "," << j + 1 << ")-->";
    }
    cout << "(" << m + 1 << "," << n + 1 << ")";
    return;
}

void minPath(int **grid, int rows, int cols)
{
    int **m = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        m[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 && j == 0)
            {
                m[i][j] = grid[i][j];
            }
            else if (i == 0)
            {
                m[i][j] = m[0][j - 1] + grid[i][j];
            }
            else if (j == 0)
            {
                m[i][j] = m[i - 1][j] + grid[i][j];
            }
            else
            {
                int temp = min(m[i - 1][j], m[i][j - 1]);
                m[i][j] = grid[i][j] + min(m[i - 1][j - 1], temp);
            }
        }
    }
    int result = m[rows - 1][cols - 1];
    cout << "The minimum path sum is: " << result << endl;
    showPath(m, rows - 1, cols - 1);

    // Deallocate memory
    for (int i = 0; i < rows; i++)
    {
        delete[] m[i];
    }
    delete[] m;

    // return result;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        cout << "Row " << i << " : ";
        for (int j = 0; j < cols; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    minPath(matrix, rows, cols);

    return 0;
}
