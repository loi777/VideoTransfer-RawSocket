#include "../VideoTransfer.h"

//==============================

char FolderDirPath[64];

//==============================



// For internal use
// Tries to find str2 in the end of str1
int strcmpEnd(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int start1 = len1 - len2;

    for (int x = 0; x < len2; x++) {
        if (str1[start1 + x] != str2[x]) {
            return 0;   // they are not equal
        }
    }

    return 1;           // they are equal
}



//---------------------------------------------------------------------



// Get the current directory from the therminal window
void FM_getDirAtTerminal() {
    getcwd(FolderDirPath, 63);
    strcat(FolderDirPath, "/");
}



// Print the Directory path that the code is in at the moment
void FM_printDir() {
    printf("%s\n", FolderDirPath);
}

// Print the Video files in the current folder path
// video files valid: .mp4 | .webm
void FM_printVideoFiles() {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(FolderDirPath)) != NULL) {    // Open and verify at the same time
        while((ent = readdir(dir)) != NULL) {    // while there are folders to be read
            if ((ent->d_type == 8)) {
                if ((strcmpEnd(ent->d_name, ".mp4")) | (strcmpEnd(ent->d_name, ".webm"))) {
                    printf("%s\n", ent->d_name);
                }
            }
        }

        closedir(dir);                          // remember to close the DIR.
    } else {
        printf("Error when opening current folder!\n");
    }
}



//---------------------------------------------------------------------



// Prints out the Folders directly acessible
// and allows the user to change dir with one of the listed folders.
void FM_goDownDir() {
    DIR *dir;
    struct dirent *ent;
    int fileIndex = 0;

    if ((dir = opendir(FolderDirPath)) != NULL) {    // Open and verify at the same time
        while((ent = readdir(dir)) != NULL) {    // while there are folders to be read

            if ((ent->d_type == 4) & (ent->d_name[0] != '.')) {
                printf("[%d] %s\n", fileIndex, ent->d_name);
                fileIndex++;
            }

        }

        closedir(dir);                          // remember to close the DIR.
    } else {
        printf("Error when opening current folder!\n");
    }

    //

    printf("[%d] None\n", fileIndex);             // if user does not want to go down

    //

    fileIndex = 0;
    printf("Choose a folder to enter:\n");
    int folderChosen;
    scanf("%d", &folderChosen);                 // get from user folder to go down

    //

    if ((dir = opendir(FolderDirPath)) != NULL) {    // Open and verify at the same time
        while((ent = readdir(dir)) != NULL) {    // while there are folders to be read

            if ((ent->d_type == 4) & (ent->d_name[0] != '.')) {
                if (fileIndex == folderChosen) {
                    strcat(FolderDirPath, ent->d_name);
                    closedir(dir);               // remember to close the DIR.
                    return;
                }
                fileIndex++;
            }

        }

        closedir(dir);                          // remember to close the DIR.
    } else {
        printf("Error when opening current folder!\n");
    }

}



// Go Up a Dir by removing the current folder from the saved Directory Path.
// This function always remains a single '/' if you go up on all folders
void FM_goUpDir() {
    int len = strlen(FolderDirPath);

    for (int i = len-2; i >= 0; i--) {
        if (FolderDirPath[i] == '/') {
            FolderDirPath[i+1] = '\0';  // Make it go up by ending the string before the next folder
            return;
        }
    }

    return;
}
