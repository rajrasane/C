// File Handling

// - File handling involves creating, opening, reading, writing, and closing files.
// - Allows programs to store and retrieve data persistently.


//---------------------------------------------------------------------------------------------------------------------------------------

// File Operations :-

// FILE *file;
// file = fopen("example.txt", "w"); // Open file for writing
// fprintf(file, "Hello, file!\n"); // Write to file
fclose(file); // Close file


//---------------------------------------------------------------------------------------------------------------------------------------

// Reading from a File :-

// file = fopen("example.txt", "r"); // Open file for reading
char buffer[100];
// fscanf(file, "%s", buffer); // Read from file
// printf("Read from file: %s\n", buffer);
fclose(file); // Close file

//---------------------------------------------------------------------------------------------------------------------------------------