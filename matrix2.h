#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
  double **data;
  int numRow;
  int numColumn;
} MATRIX_T;

/* Create a new matrix
 * Arguments
 *     row - number of row in the matrix
 *     col - number of column in the matrix
 * Returns the pointer to the matrix or NULL if row or col <= 0
 */
MATRIX_T *matrixCreate(int row, int col);

/* Get number of row in the matrix
 * Arguments
 *     m    - the input matrix
 * Returns number of row in the matrix or -1 if the matrix has not been
 * initialized
 */
int matrixRowCount(MATRIX_T *m);

/* Get number of column in the matrix
 * Arguments
 *     m    - the input matrix
 * Returns number of column in the matrix or -1 if the matrix has not been
 * initialized
 */
int matrixColumnCount(MATRIX_T *m);

/* Display matrix content
 * Arguments
 *     m    - the input matrix
 * Returns  1 if the matrix can be displayed successfully, otherwise -1.
 */
int matrixDisplay(MATRIX_T *m);

/* Assign a value into the matrix
 * Arguments
 *     m         - the input matrix
 *     row       - row in the matrix
 *     col       - column in the matrix
 *     content   - a double to assign at position row x col
 * Returns  1 if the content can be assigned successfully, otherwise -1.
 */
int matrixSet(MATRIX_T *m, int row, int col, double content);

/* Create a matrix from text file
 * Arguments
 *     filename    - the input filename
 * Returns a matrix
 */
MATRIX_T *matrixCreateFromFile(char *filename);

/* Write matrix information to text file
 * Arguments
 *     m         - the input matrix
 *     filename  - output file name
 * Returns  1 if write file successfully,
 *         -1 if matrix is not initialized.
 *         -2 if the file cannot be accessed.
 */
int matrixSaveToFile(MATRIX_T *m, char *filename);

/* Create a matrix from binary file
 * Arguments
 *     filename  - output file name
 * Returns a matrix.
 */
MATRIX_T *matrixCreateFromBinaryFile(char *filename);

/* Write matrix information to binary file
 * Arguments
 *     mat       - the input matrix
 *     filename  - output file name
 * Returns  1 if write successfully, otherwise -1.
 */
int matrixSaveToBinaryFile(MATRIX_T *mat, char *filename);

/* Compare that 2 matrixes are the same
 * Arguments
 *     m1    - first matrix
 *     m2    - second matrix
 * Returns  1 if the matrixes are the same, otherwise 0.
 */
int matrixCompare(MATRIX_T *m1, MATRIX_T *m2);

#endif