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
  MATRIX_T *pMatrix = NULL;     /* input matrix */
  MATRIX_T *pFromText = NULL;   /* matrix created from text file */
  MATRIX_T *pFromBinary = NULL; /* matrix created from binary file */

  /* create a baseline matrix to be saved in different files */
  pMatrix = createNewMatrix();
  if (pMatrix == NULL) {
    printf("Error, cannot create a matrix\n");
    return 0;
  }

  /* save matrix to text file */
  matrixSaveToFile(pMatrix, "text.txt");
  /* read matrix from text file */
  pFromText = matrixCreateFromFile("text.txt");
  /* validate that matrix read from text file is the same as baseline */
  if (matrixCompare(pMatrix, pFromText) == 1) {
    printf("Successfully save matrix to text file!\n");
  }

  /* save matrix to binary file */
  matrixSaveToBinaryFile(pMatrix, "binary.bin");
  /* read matrix from binary file */
  pFromBinary = matrixCreateFromBinaryFile("binary.bin");
  /* validate that matrix read from binary file is the same as baseline */
  if (matrixCompare(pMatrix, pFromBinary) == 1) {
    printf("Successfully create matrix and save to binary file!\n");
  }

  return 0;
}
