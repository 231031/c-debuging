#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

MATRIX_T *createNewMatrix() {
  MATRIX_T *pMatrix = NULL; /* matrix to be created */
  char stringInput[128];    /* input buffer */
  int inputRow = 0;         /* matrix row */
  int inputCol = 0;         /* matrix column */
  double matrixValue = 0;   /* value in matrix */
  int i = 0;                /* counter */
  int j = 0;                /* counter */

  printf("Please enter number of rows:\n");
  fgets(stringInput, sizeof(stringInput), stdin);
  sscanf(stringInput, "%d", &inputRow);

  printf("Please enter number of columns:\n");
  fgets(stringInput, sizeof(stringInput), stdin);
  sscanf(stringInput, "%d", &inputCol);

  /* create and set matrix values */
  pMatrix = matrixCreate(inputRow, inputCol);
  if (pMatrix != NULL) {
    for (i = 0; i < inputRow; i++) {
      for (j = 0; j < inputCol; j++) {
        printf("Please enter a double value:\n");
        fgets(stringInput, sizeof(stringInput), stdin);
        sscanf(stringInput, "%lf", &matrixValue);
        matrixSet(pMatrix, i, j, matrixValue);
      }
    }
    matrixDisplay(pMatrix);
  }

  return pMatrix;
}

int main() {
  int N_ROW = 3; /* number of row for testing matrix */
  int N_COL = 4; /* number of column for testing matrix */

  int numRow = 0; /* row count of test matrix */
  int numCol = 0; /* column count of test matrix */

  MATRIX_T *pMatrix = matrixCreate(N_ROW, N_COL); /* test matrix */
  MATRIX_T *pMatrixA = NULL;                      /* matrix A */
  MATRIX_T *pMatrixB = NULL;                      /* matrix B */
  MATRIX_T *pAddOut = NULL;                       /* addition output */
  MATRIX_T *pMulOut = NULL;                       /* multiplication output */
  MATRIX_T *pTransOut = NULL;                     /* transpose output */

  int setValidation = 0;      /* validate matrixSet function */
  int displayValidation = 0;  /* validate matrixDisplay function */
  int addValidation = 0;      /* validate matrixAdd function */
  int multiplyValidation = 0; /* validate matrixMultiply function */
  int transValidation = 0;    /* validate matrixTranspose function */

  /* check that test matrix has been initialized */
  if (pMatrix != NULL) {
    printf("Successfully create a matrix!\n");
  } else {
    printf("Cannot create matrix :(\n");
    return 0;
  }

  /* check row/column of test matrix */
  numRow = matrixRowCount(pMatrix);
  numCol = matrixColumnCount(pMatrix);
  if (numRow == N_ROW && numCol == N_COL) {
    printf("The matrix has %d row and %d columns\n", N_ROW, N_COL);
  } else {
    printf("Check your row/column count function again!\n");
    return 0;
  }

  /* set a value for test matrix and check the result */
  setValidation = matrixSet(pMatrix, 0, 0, 12.3);
  if (setValidation != 1 || pMatrix->data[0][0] != 12.3) {
    printf("Check you matrixSet function again!\n");
    return 0;
  }

  /* print test matrix */
  displayValidation = matrixDisplay(pMatrix);
  if (displayValidation != 1) {
    printf("Check your matrix again\n");
    return 0;
  }

  /* create matrix A and B */
  printf("Creating matrix A\n");
  pMatrixA = createNewMatrix();
  printf("Creating matrix B\n");
  pMatrixB = createNewMatrix();

  /* setup output matrixes */
  if (pMatrixA != NULL && pMatrixA->numRow > 0 && pMatrixA->numColumn > 0) {
    pAddOut = matrixCreate(pMatrixA->numRow, pMatrixA->numColumn);
    pTransOut = matrixCreate(pMatrixA->numColumn, pMatrixA->numRow);
    if (pMatrixB != NULL && pMatrixB->numRow > 0 && pMatrixB->numColumn > 0) {
      pMulOut = matrixCreate(pMatrixA->numRow, pMatrixB->numColumn);
    }
  }

  /* add matrix A and matrix B */
  addValidation = matrixAdd(pAddOut, pMatrixA, pMatrixB);
  printf("Addition result:\n");
  printf("%d\n", addValidation);
  if (addValidation == 1) {
    matrixDisplay(pAddOut);
  }

  /* multiply matrix A and matrix B */
  multiplyValidation = matrixMultiply(pMulOut, pMatrixA, pMatrixB);
  printf("Multiplication result:\n");
  printf("%d\n", multiplyValidation);
  if (multiplyValidation == 1) {
    matrixDisplay(pMulOut);
  }

  /* transpose matrix A */
  transValidation = matrixTranspose(pTransOut, pMatrixA);
  printf("Transpose matrix A result:\n");
  printf("%d\n", transValidation);
  if (transValidation == 1) {
    matrixDisplay(pTransOut);
  }

  return 0;
}
