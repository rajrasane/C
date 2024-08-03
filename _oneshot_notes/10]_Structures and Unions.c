// Structures


// - Group related variables under a single name.
// - Define using struct.
// - Access members using the dot (.) operator.

struct Student {
    char name[50];
    int age;
    float gpa;
};

struct Student s1 = {"John", 20, 3.5};
// printf("Name: %s, Age: %d, GPA: %f\n", s1.name, s1.age, s1.gpa);

//---------------------------------------------------------------------------------------------------------------------------------------

// Unions

// - Store different data types in the same memory location.
// - Define using union.
// - Use when memory efficiency matters.

union Data {
    int i;
    float f;
    char str[20];
};

union Data data;
// data.i = 10;
// printf("Data: %d\n", data.i);

//---------------------------------------------------------------------------------------------------------------------------------------