#include <stdio.h>

int main() {
    FILE *fileF, *fileG, *fileH;
    int num, posCount = 0, negCount = 0;

    // Open file F for reading
    fileF = fopen("C:\\Users\\evila\\Desktop\\C++\\HW_11\\F.txt", "r");
    if (fileF == NULL) {
        printf("Failed to open file F.\n");
        return 1;
    }

    // Count the number of positive and negative numbers
    while (fscanf(fileF, "%d", &num) != EOF) {
        if (num > 0)
            posCount++;
        else if (num < 0)
            negCount++;
    }
    fclose(fileF);

    // Check the condition of equal count
    if (posCount != negCount) {
        printf("File F does not contain an equal number of positive and negative numbers.\n");
        return 0;
    }

    // Reopen files for further processing
    fileF = fopen("C:\\Users\\evila\\Desktop\\C++\\HW_11\\F.txt", "r");
    fileG = fopen("C:\\Users\\evila\\Desktop\\C++\\HW_11\\G.txt", "w");
    fileH = fopen("C:\\Users\\evila\\Desktop\\C++\\HW_11\\H.txt", "w");
    if (fileF == NULL || fileG == NULL || fileH == NULL) {
        printf("Failed to open one of the files.\n");
        return 1;
    }

    int prevNum = 0, isFirst = 1;

    // Write numbers to file G such that no two adjacent numbers have the same sign
    while (fscanf(fileF, "%d", &num) != EOF) {
        fprintf(fileH, "%d\n", num); // Save number to file H
        if (isFirst || (num > 0 && prevNum < 0) || (num < 0 && prevNum > 0)) {
            fprintf(fileG, "%d\n", num);
            prevNum = num;
            isFirst = 0;
        }
    }

    // Close files
    fclose(fileF);
    fclose(fileG);
    fclose(fileH);

    printf("File processing completed. Results saved to file G.\n");
    return 0;
}
