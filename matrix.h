#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    double** data;
    int numRow;
    int numColumn;
} MATRIX_T;

/* Create a new matrix
 * Arguments
 *     row - number of row in the matrix
 *     col - number of column in the matrix
 * Returns the pointer to the matrix or NULL if row or col <= 0
 */
MATRIX_T* matrixCreate(int row, int col);

/* Get number of row in the matrix
 * Arguments
 *     m    - the input matrix
 * Returns number of row in the matrix or -1 if the matrix has not been initialized
 */
int matrixRowCount(MATRIX_T* m);

/* Get number of column in the matrix
 * Arguments
 *     m    - the input matrix
 * Returns number of column in the matrix or -1 if the matrix has not been initialized
 */
int matrixColumnCount(MATRIX_T* m);

/* Assign a value into the matrix
 * Arguments
 *     m         - the input matrix 
 *     row       - row in the matrix
 *     col       - column in the matrix
 *     content   - a double to assign at position row x col
 * Returns  1 if the content can be assigned successfully, otherwise -1.
 */
int matrixSet(MATRIX_T *m, int row, int col, double content);

/* Display matrix content
 * Arguments
 *     m    - the input matrix
 * Returns  1 if the matrix can be displayed successfully, otherwise -1.
 */
int matrixDisplay(MATRIX_T *m);

/* Adding two matrices and store result in the another matrix 
 * Arguments
 *     out  - matrix to store the result (can be the same as m1 or m2)
 *     m1   - the first input matrix
 *     m2   - the second input matrix
 * Returns  1 if the matrix can be added successfully
 *         -1 if the matrix hasn't been initialize
 *         -2 if the matrix can't be added e.g. incompatible dimension etc.
 */
int matrixAdd(MATRIX_T* out, MATRIX_T* m1, MATRIX_T* m2);

/* Multiply two matrices and store result in the another matrix 
 * Arguments
 *     out  - matrix to store the result (can be the same as m1 or m2)
 *     m1   - the first input matrix
 *     m2   - the second input matrix
 * Returns  1 if the matrix can be added successfully
 *         -1 if the matrix hasn't been initialize
 *         -2 if the matrix can't be added e.g. incompatible dimension etc.
 */
int matrixMultiply(MATRIX_T* out, MATRIX_T* m1, MATRIX_T* m2);

/* Flips a matrix over its diagonal
 * Arguments
 *     out - matrix to store the result (can be the same as m)
 *     m   - the input matrix
 * Returns  1 if the matrix can be tranposed successfully
 *         -1 if the matrix hasn't been initialize
 */
int matrixTranspose(MATRIX_T* out, MATRIX_T* m);

#endif