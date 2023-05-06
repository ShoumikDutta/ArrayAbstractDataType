

# ADT Array

This code provides a basic implementation of an Array Abstract Data Type (ADT) in C language. It provides functionality to create, set, insert, append, delete, search, and find the minimum and maximum values in an array.

## Usage

To use this code, simply include the `adtArray.h` header file in your C program and compile it with the `adtArray.c` source file.

```c
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "adtArray.h"

int main()
{
    
    int arr[]={1,2,4,5,6,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    adtArray *array=createArray(size);
    setarray(arr,size,*array);
    for (int i = 0; i < array->size; i++)
    {
        printf("%d,",array->data[i]);
    }
    printf("\nAfter inserting 2\n");
    insertvalue(2,3, &array);
    for (int i = 0; i < array->size; i++)
    {
        printf("%d,",array->data[i]);
    }
    printf("\nAfter Appending 9\n");
    appendvalue(9,&array);
    for (int i = 0; i < array->size; i++)
    {
        printf("%d,",array->data[i]);
    }
    printf("min=%d \nmax=%d\n",min(*array),max(*array));
    printf("search result:%d",search(15,*array));
    deleteArray(array);
    return 0;
}
```

## Functions

This implementation provides the following functions:

### createArray

```c
adtArray *createArray(int size);
```

Creates a new array with the given size.

### setarray

```c
void setarray(int arr[],int size,adtArray array);
```

Sets the values of the given array.

### search

```c
bool search(int key,adtArray array);
```

Searches the given key in the array.

### insertvalue

```c
void insertvalue(int index,int value,adtArray **array);
```

Inserts the given value at the given index in the array.

### appendvalue

```c
void appendvalue(int value,adtArray **array);
```

Appends the given value to the end of the array.

### deleteArray

```c
void deleteArray(adtArray *array);
```

Deletes the given array.

### min

```c
int min(adtArray array);
```

Finds the minimum value in the array.

### max

```c
int max(adtArray array);
```

Finds the maximum value in the array.
