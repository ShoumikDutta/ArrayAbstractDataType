#ifndef ADTARRAY_H
#define ADTARRAY_H
#include<stdbool.h>

typedef struct adtArray adtArray;
void setarray(int arr[],int size,adtArray array);
bool search(int key,adtArray array);
void insertvalue(int index,int value,adtArray **array);
void appendvalue(int value,adtArray **array);
void deleteArray( adtArray *array);
int min(adtArray array);
int max(adtArray array);
adtArray *createArray(int size);
#endif