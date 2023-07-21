/**
 * Element Shifter
 * 
 * Write a function named "ashifter" that accepts an int array and the array’s size as arguments.
 * The function should create a new array that is one element larger than the argument array.
 * The first element of the new array should be set to 0. Element 0 of the argument array should be
 * copied to element 1 of the new array, element 1 of the argument array should be copied to element 2
 * of the new array, and so forth. The function should return a pointer to the new array.
*/

int *ashifter(int numbers[], int numbersSize) {
    int *ptrNewArray = nullptr;
    int arraySize = numbersSize + 1;

    ptrNewArray = new int[arraySize];
    ptrNewArray[0] = 0;

    for(int i=1;i<arraySize;i++) {
        ptrNewArray[i] = numbers[i-1];
    }

    delete [] ptrNewArray;

    return ptrNewArray;
}