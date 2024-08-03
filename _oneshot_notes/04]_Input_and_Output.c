#include <stdio.h>

int main() {
    int a;
    float b;
    char c;

    printf("Enter an integer, a float, and a character: ");
    scanf("%d %f %c", &a, &b, &c);

    printf("You entered: %d, %f, %c\n", a, b, c);
    return 0;
}


// 1) Header File  :- 
// #include <stdio.h>: This line includes the standard input/output library, which provides functions for reading input and printing output.


// 2) main() Function  :-
// The main() function is the entry point of the program.
// It declares three variables: a (integer), b (float), and c (character).


// 3) Input using scanf()  :-
// printf("Enter an integer, a float, and a character: ");: Displays a prompt to the user.
// scanf("%d %f %c", &a, &b, &c);: Reads input from the user.
// %d reads an integer and stores it in a.
// %f reads a float and stores it in b.
// %c reads a character and stores it in c.
// The & operator is used to get the memory address of each variable.


// 4) Output using printf()  :-
// printf("You entered: %d, %f, %c\n", a, b, c);: Displays the values entered by the user.
// %d prints the integer value stored in a.
// %f prints the float value stored in b.
// %c prints the character stored in c.
// \n adds a newline character for better formatting.


// 5) Return Statement  :-
// return 0;: Indicates successful program execution and terminates the program.