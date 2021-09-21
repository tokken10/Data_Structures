// Arup Guha
// 5/27/09 - Shown in COP 3502
// Short example to show a function dynamically allocating an array of structs.

#include <stdio.h>
#include <time.h>

#define ABSOLUTE_MAX 100000
#define MAX_INT 32767
#define DEFAULT 10

struct point {
    int x;
    int y;
};

struct point* createRandPoints(int size, int maxVal);
void print(struct point array[], int size);

int main() {
    
    int max, arraySize;
    
    srand(time(0));

    // Read in user input.
    printf("How big do you want your array?\n");
    scanf("%d", &arraySize);
    printf("What is the maximum x or y coordinate you want?\n");
    scanf("%d", &max);
    
    // Changes user values if they are not in the designated range.
    if (arraySize < 0) arraySize = DEFAULT;
    if (arraySize > ABSOLUTE_MAX) arraySize = ABSOLUTE_MAX;
    if (max < 0) max = DEFAULT;
    if (max > MAX_INT) max = MAX_INT;
    
    // Create a new array and print it!
    struct point* values = createRandPoints(arraySize, max);
    print(values, arraySize);
        
    // Free the array memory.
    free(values);
    system("PAUSE");
    return 0;
}

// Creates an array with size elements, fills it with random points, with
// both the x and y components in between 1 and maxVal, inclusive, and returns
// a pointer to this newly created array.
struct point* createRandPoints(int size, int maxVal)  {

     // Allocate the correct amount of memory for the array.
     struct point* temp;
     temp = (struct point*)malloc(size*sizeof(struct point));
     int i;
     
     // Fill in each array slot with a random (x,y) in the desired range.
     for (i=0; i<size; i++) {
         temp[i].x = 1 + rand()%maxVal;
         temp[i].y = 1 + rand()%maxVal;
     }
     
     return temp;
}

// Prints out the first size elements of array separated by a space, followed
// by a newline.
void print(struct point array[], int size) {
    int i;
    
    // Print all but the last, followed by a comma.
    for (i=0; i<size-1; i++)
        printf("(%d,%d), ", array[i].x, array[i].y);
        
    // Print the last without a comma!
    printf("(%d,%d).\n", array[size-1].x, array[size-1].y);
}
