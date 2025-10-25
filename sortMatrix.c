int compare1(const void *x_void, const void *y_void) { // ascending
    return (*(int*)x_void - *(int*)y_void);
}

int compare2(const void *x_void, const void *y_void) { // descending
    return (*(int*)y_void - *(int*)x_void);
}

int** sortMatrix(int** grid, int gS, int* gCS, int* rS, int** rCS) {
    int rows = gS;
    int cols = gCS[0];

    *rS = rows;
    *rCS = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        (*rCS)[i] = gCS[i];
    }

    // Sort upper-right diagonals (ascending)
    for (int c = 1; c < cols; c++) { // start from (0,c)
        int r = 0, cc = c, len = 0;
        while (r < rows && cc < cols) {
            len++;
            r++; cc++;
        }
        int *arr = (int*)malloc(len * sizeof(int));
        r = 0; cc = c;
        for (int i = 0; i < len; i++) {
            arr[i] = grid[r][cc];
            r++; cc++;
        }
        qsort(arr, len, sizeof(int), compare1);
        r = 0; cc = c;
        for (int i = 0; i < len; i++) {
            grid[r][cc] = arr[i];
            r++; cc++;
        }
        free(arr);
    }

    // Sort lower-left diagonals (descending)
    for (int r = 0; r < rows; r++) { // start from (r,0)
        int rr = r, c = 0, len = 0;
        while (rr < rows && c < cols) {
            len++;
            rr++; c++;
        }
        int *arr = (int*)malloc(len * sizeof(int));
        rr = r; c = 0;
        for (int i = 0; i < len; i++) {
            arr[i] = grid[rr][c];
            rr++; c++;
        }
        qsort(arr, len, sizeof(int), compare2);
        rr = r; c = 0;
        for (int i = 0; i < len; i++) {
            grid[rr][c] = arr[i];
            rr++; c++;
        }
        free(arr);
    }

    return grid;
}
