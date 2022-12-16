#include "matrix.h"
#include <stdio.h>

/* Create a new matrix
 * Arguments
 *     row - number of row in the matrix
 *     col - number of column in the matrix
 * Returns the pointer to the matrix or NULL if row or col <= 0
 */
MATRIX_T *matrixCreate(int row, int col)
{
    MATRIX_T *mat = calloc(1, sizeof(MATRIX_T));
    mat->data = calloc(row, sizeof(double *));
    for (int i = 0; i < row; i++)
    {
        mat->data[i] = calloc(col, sizeof(double));
    }
    mat->numRow = row;
    mat->numColumn = col;
    return mat;
}

/* Get number of row in the matrix
 * Arguments
 *     m    - the input matrix
 * Returns number of row in the matrix or -1 if the matrix has not been
 * initialized
 */
int matrixRowCount(MATRIX_T *m)
{
    if (m == NULL)
    {
        return -1;
    }
    return m->numRow;
}

/* Get number of column in the matrix
 * Arguments
 *     m    - the input matrix
 * Returns number of column in the matrix or -1 if the matrix has not been
 * initialized
 */
int matrixColumnCount(MATRIX_T *m)
{
    if (m == NULL)
    {
        return -1;
    }
    return m->numColumn;
}

/* Assign value into the matrix
 * Arguments
 *     m         - the input matrix
 *     row       - number of row in the matrix
 *     col       - number of column in the matrix
 *     contents  - integers to be added in matrix
 * Returns  1 if the contents can be assigned successfully, otherwise -1.
 */
int matrixSet(MATRIX_T *m, int row, int col, double content)
{
    if (m == NULL || m->numRow == 0 || m->numColumn == 0)
    {
        return -1;
    }
    m->data[row][col] = content;
    return 1;
}

/* Display matrix content
 * Arguments
 *     m    - the input matrix
 * Returns  1 if the matrix can be displayed successfully, otherwise -1.
 */
int matrixDisplay(MATRIX_T *m)
{
    int i = 0;
    int j = 0;
    if (m == NULL || m->numRow == 0 || m->numColumn == 0)
    {
        return -1;
    }
    for (i = 0; i < m->numRow; i++)
    {
        for (j = 0; j < m->numColumn; j++)
        {
            printf("%.2lf ", m->data[i][j]);
        }
        printf("\n");
    }
    return 1;
}

/* Adding two matrices and store result in the another matrix
 * Arguments
 *     out  - matrix to store the result (can be the same as m1 or m2)
 *     m1   - the first input matrix
 *     m2   - the second input matrix
 * Returns  1 if the matrix can be added successfully
 *         -1 if the matrix hasn't been initialize
 *         -2 if the matrix can't be added e.g. incompatible dimension etc.
 */
int matrixAdd(MATRIX_T *out, MATRIX_T *m1, MATRIX_T *m2)
{
    int i = 0;
    int j = 0;
    if (m1 == NULL || m2 == NULL || m1->numRow == 0 || m1->numColumn == 0 || m2->numRow == 0 || m2->numColumn == 0)
    {
        return -1;
    }
    else if ((m1->numRow != m2->numRow) || (m1->numColumn != m2->numColumn))
    {
        return -2;
    }
    for (i = 0; i < m1->numRow; i++)
    {
        for (j = 0; j < m1->numColumn; j++)
        {
            out->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    return 1;
}

/* Multiply two matrices and store result in the another matrix
 * Arguments
 *     out  - matrix to store the result (can be the same as m1 or m2)
 *     m1   - the first input matrix
 *     m2   - the second input matrix
 * Returns  1 if the matrix can be added successfully
 *         -1 if the matrix hasn't been initialize
 *         -2 if the matrix can't be added e.g. incompatible dimension etc.
 */
int matrixMultiply(MATRIX_T *out, MATRIX_T *m1, MATRIX_T *m2)
{
    int i = 0;
    int j = 0;
    int p = 0;
    int q = 0;
    int m = 0;
    int n = 0;
    int add = 0;
    int count = 0;

    if (m1 == NULL || m2 == NULL || m1->numRow == 0 || m1->numColumn == 0 || m2->numRow == 0 || m2->numColumn == 0)
    {
        return -1;
    }
    if (m1->numColumn != m2->numRow)
    {
        return -2;
    }

    while (count < m1->numColumn)
    {
        for (i = 0; i < m1->numRow; i++)
        {
            add = 0;
            p = 0;

            for (j = 0; j < m1->numColumn; j++)
            {
                add += m1->data[i][j] * m2->data[p][q];
                p++;
            }

            out->data[m][n] = add;

            if (m == (m1->numRow) - 1)
            {
                m = 0;
                n++;
            }
            else
            {
                m++;
            }
        }
        q++;
        count++;
    }

    return 1;
}

/* Flips a matrix over its diagonal
 * Arguments
 *     out - matrix to store the result (can be the same as m)
 *     m   - the input matrix
 * Returns  1 if the matrix can be tranposed successfully
 *         -1 if the matrix hasn't been initialize
 */
int matrixTranspose(MATRIX_T *out, MATRIX_T *m)
{
    int i = 0;
    int j = 0;
    if (m == NULL || m->numRow == 0 || m->numColumn == 0)
    {
        return -1;
    }
    for (i = 0; i < m->numRow; i++)
    {
        for (int j = 0; j < m->numColumn; j++)
        {
            out->data[j][i] = m->data[i][j];
        }
    }
    return 1;
}
