#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996).

int main() {
    // Variables
    char originalExeName[256];
    unsigned int fileSizeMB;

    printf("\t\t\t ###########################################################\n");
    printf("\t\t\t #         Dragons Breath - Designed By Cuong Nguyen       #\n");
    printf("\t\t\t ###########################################################\n\n");
    printf("\t\t\t\t--> File bloating evasion technique <--\n\n");

    // Get user input for original executable name
    printf("[i] Enter the name of the original executable file: ");
    scanf("%255s", originalExeName);

    // Get user input for file size in MBs
    printf("[i] Enter the file size in MBs: ");
    scanf("%u", &fileSizeMB);

    // Generate the new binary file with null bytes
    FILE* newMbFile = fopen("new_mb_file.bin", "wb");
    if (newMbFile == NULL) {
        perror("[!] Error creating new_mb_file.bin");
        return 1;
    }

    unsigned long long fileSizeBytes = (unsigned long long)fileSizeMB * 1024 * 1024;
    unsigned char nullByte = 0x00;

    for (unsigned long long i = 0; i < fileSizeBytes; i++) {
        fwrite(&nullByte, sizeof(unsigned char), 1, newMbFile);
    }

    fclose(newMbFile);

    // Construct the copy command
    char copyCommand[512];
    snprintf(copyCommand, sizeof(copyCommand), "copy /b \"%s\" + new_mb_file.bin newfile.exe", originalExeName);

    // Execute the copy command
    int result = system(copyCommand);
    if (result != 0) {
        printf("[!] Error executing copy command.\n");
        return 1;
    }

    // Delete the temporary .bin file
    remove("new_mb_file.bin");

    // Rename the final executable
    char newExeName[256];
    snprintf(newExeName, sizeof(newExeName), "%s_%d.exe", strtok(originalExeName, "."), fileSizeMB);

    if (rename("newfile.exe", newExeName) != 0) {
        perror("[!] Error renaming the final executable");
        return 1;
    }

    printf("[!] New file '%s' has been generated.\n", newExeName);
    getchar();
    printf("[i] Press <Enter> to exit program");
    getchar();
    printf("Bye...");

}
