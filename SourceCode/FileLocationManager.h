// Get the current directory from the therminal window
void FM_getDirAtTerminal();

// Print the Directory path that the code is in at the moment
void FM_printDirPath();

// Print the Video files in the current folder path
// video files valid: .mp4 | .webm
void FM_printVideoFiles();

// Prints out the Folders directly acessible
// and allows the user to change dir with one of the listed folders.
void FM_goDownDir();

// Go Up a Dir by removing the current folder from the saved Directory Path.
// if you go up all folders it will return a single '/'
void FM_goUpDir();
