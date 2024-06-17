#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> d2vector_init()
{
    int lines, columns; //rows, cols
    cout << "Ведите количество строк и количество столбиков массива ";
    cin >> lines >> columns;
    vector<vector<int>> d2vector(lines, vector<int>(columns));

    for (int i = 0; i != lines; ++i)
    {
        for (int j = 0; j != columns; ++j)
        {
            cin >> d2vector[i][j];
        }
    }

    return d2vector;
} 

void d2vector_cout(vector<vector<int>> const& d2vector)
{
    for (auto const& lin : d2vector) // row : d2vector
    {
        for (auto col : lin) // el : row
        {
            cout << col << " ";
        }
        cout << endl;
    }
}
bool IsElementInMatrix(vector<vector<int>> const& matrix, int element)
{
    for (const auto& lin : matrix)
    {
        if (find(lin.begin(), lin.end(), element) != lin.end())
        {
            return true;
        }
    }
    return false;
}
int main()
{
    setlocale(LC_ALL, "ru");

    cout << "---массив A---\n";
    vector < vector<int>> A = d2vector_init();
    d2vector_cout(A);

    cout << "---массив B---\n";
    vector < vector<int>> B = d2vector_init();
    d2vector_cout(A);

    cout << "---массив C---\n";
    vector < vector<int>> C = d2vector_init();
    d2vector_cout(A);

    vector<int> common_ABC;
    for (auto const& lin : A)
    {
        for (int col : lin)
        {
            if (find(common_ABC.begin(), common_ABC.end(), col) == common_ABC.end() && IsElementInMatrix(B, col) && IsElementInMatrix(C, col))
            {
                common_ABC.push_back(col);
            }
        }
    }
    cout << "---общие элементы---\n";
    for (int col : common_ABC)
    {
        cout << col << " ";
    }
    cout << "\n";
    return 0;
}
