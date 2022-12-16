#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

/* Create a new matrix
 * Arguments
 *     row - number of row in the matrix
 *     col - number of column in the matrix
 * Returns the pointer to the matrix or NULL if row or col <= 0
 */
MATRIX_T *matrixCreate(int row, int col)
{
    if (row <= 0 || col <= 0)
    {
        return NULL;
    }
    MATRIX_T *pMatrix = malloc(sizeof(MATRIX_T));
    pMatrix->numRow = row;
    pMatrix->numColumn = col;
    pMatrix->data = malloc(sizeof(double) * row);
    for (int i = 0; i < row; i++)
    {
        pMatrix->data[i] = malloc(sizeof(double) * col);
    }
    return pMatrix;
}

/* Get number of row in the matrix
 * Arguments
 *     m    - the input matrix
 * Returns number of row in the matrix or -1 if the matrix has not been
 * initialized
 */
int matrixRowCount(MATRIX_T *m)
{
    if (m != NULL)
    {
        return m->numRow;
    }
    else
    {
        return -1;
    }
}

/* Get number of column in the matrix
 * Arguments
 *     m    - the input matrix
 * Returns number of column in the matrix or -1 if the matrix has not been
 * initialized
 */
int matrixColumnCount(MATRIX_T *m)
{
    if (m != NULL)
    {
        return m->numColumn;
    }
    else
    {
        return -1;
    }
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
    int i = 0;
    int j = 0;
    int count = 0;
    if (m == NULL)
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
    if (m == NULL)
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

/* Create a matrix from text file
 * Arguments
 *     filename    - the input filename
 * Returns a matrix
 */
MATRIX_T *matrixCreateFromFile(char *filename)
{
    int row, col;
    FILE *fp = fopen(filename, "r");
    fscanf(fp, "%d %d", &row, &col);
    
    MATRIX_T *mat = matrixCreate(row, col);
    int i, j;
    for (i = 0; i < mat->numRow; i++)
    {
        for (j = 0; j < mat->numColumn; j++)
        {
            fscanf(fp, "%lf ", &mat->data[i][j]);
        }
        fscanf(fp, "\n"); // newline
    }
    fclose(fp);
    return mat;
}

/* Write matrix information to text file
 * Arguments
 *     m         - the input matrix
 *     filename  - output file name
 * Returns  1 if write file successfully,
 *         -1 if matrix is not initialized.
 *         -2 if the file cannot be accessed.
 */
int matrixSaveToFile(MATRIX_T *m, char *filename)
{
    int i, j;
    if (m == NULL)
    {
        return -1;
    }
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Can't open file\n");
        return -2;
    }
    fprintf(fp, "%d %d",m->numRow, m->numColumn);
    fprintf(fp, "\n"); // newline
    for (i = 0; i < m->numRow; i++)
    {
        for (j = 0; j < m->numColumn; j++)
        {
            fprintf(fp, "%lf ", m->data[i][j]);
        }
        fprintf(fp, "\n"); // newline
    }
    fclose(fp);
    return 1;
}

/* Create a matrix from binary file
 * Arguments
 *     filename  - output file name
 * Returns a matrix.
 */
MATRIX_T *matrixCreateFromBinaryFile(char *filename)
{
    // fread
    int i = 0;
    int j = 0;
    int row, column;
    char space;
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Can't open file2\n");
    }
    fread(&row, sizeof(int), 1, fp);
    fread(&space,sizeof(char),1,fp); // space
    fread(&column, sizeof(int), 1, fp);
    fread(&space,sizeof(char),1,fp); // newline
    MATRIX_T *mat = matrixCreate(row, column);
    for (i = 0; i < row; i++)
    {
      for (j = 0; j < column; j++)
      {
        fread(&mat->data[i][j], sizeof(double), 1, fp);
        fread(&space, sizeof(char), 1, fp); // space
      }
      fread(&space,sizeof(char),1,fp); // newline
    }

    fclose(fp);
    return mat;
}

/* Write matrix information to binary file
 * Arguments
 *     mat       - the input matrix
 *     filename  - output file name
 * Returns  1 if write successfully, otherwise -1.
 */
int matrixSaveToBinaryFile(MATRIX_T *m, char *filename)
{
    // fwrite
    int i = 0;
    int j = 0;
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("Can't open file3\n");
        return -1;
    }
    fwrite(&m->numRow, sizeof(int), 1, fp);
    fwrite(" ",sizeof(char), 1, fp); // space
    fwrite(&m->numColumn, sizeof(int), 1, fp);
    fwrite("\n", sizeof(char), 1, fp); //newline
    for (i = 0; i < m->numRow; i++)
    {
      for (j = 0; j < m->numColumn; j++)
      {
        fwrite(&m->data[i][j], sizeof(double), 1, fp);
        fwrite(" ", sizeof(char), 1, fp);
      }
      fwrite("\n", sizeof(char), 1, fp);
    }
    if (j != m->numColumn || i != m->numRow)
    {
      fclose(fp);
      return -1;
    }
    fclose(fp);
    return 1;
}

/* Compare that 2 matrixes are the same
 * Arguments
 *     m1    - first matrix
 *     m2    - second matrix
 * Returns  1 if the matrixes are the same, otherwise 0.
 */
int matrixCompare(MATRIX_T *m1, MATRIX_T *m2)
{

    if (m1->numRow != m2->numRow || m1->numColumn != m2->numColumn)
    {
        return 0;
    }

    int i, j;
    for (i = 0; i < m1->numRow; i++)
    {
        for (j = 0; j < m1->numColumn; j++)
        {
            if (m1->data[i][j] != m2->data[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}
