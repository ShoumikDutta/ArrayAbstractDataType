#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "adtArray.h"

struct adtArray {
    int size;
    int *data;

};
void main()
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
}
adtArray *createArray(int size)
{
    adtArray *array=malloc(sizeof(adtArray));
    array->size=size;
    array->data=malloc(size*sizeof(int));
    return array;

}
void setarray(int arr[],int size,adtArray array)
{

    if (size>array.size)
    {
        exit(1);
    }
    
    for (int i = 0; i < size; i++)
    {
        array.data[i]=arr[i];
    }
    
}
bool search(int key,adtArray array)
{
    //My array is going to be stored in a sorted way always so i can use binary search
    //base case
    for (int i = 0; i < array.size; i++)
    {
        if (array.data[i]==key)
        {
            return true;
        }
        
    }
    return false;
    

   
}
void insertvalue(int index,int value,adtArray **array)
{
    if (index > (*array)->size)
    {
        exit(1);
    }
    adtArray *temparray=createArray((*array)->size+1);
    for (int i = 0; i < (*array)->size-index; i++)
    {
        temparray->data[i]=(*array)->data[i];
    }
    temparray->data[index]=value;
    for(int i=index+1;i<temparray->size+1;i++)
    {
        temparray->data[i]=(*array)->data[i-1];
    }
    

    deleteArray(*array);
    *array=temparray;
    //free the temp array here
    deleteArray(temparray); 
    

}
void appendvalue(int value,adtArray **array)
{
    adtArray *temparray=createArray((*array)->size+1);
    for(int i=0;i<(*array)->size;i++)
    {
        temparray->data[i]=(*array)->data[i];
    }
    temparray->data[(*array)->size]=value;
    deleteArray(*array);
    *array=temparray;
    //free the temp array here
    deleteArray(temparray); 
}
void deleteArray(adtArray *array)
{
    free(array->data);
    free(array);
}
int min(adtArray array)
{
    int min=array.data[0];
    for(int i=0;i<array.size;i++)
    {
        if(min>array.data[i])
        {
            min=array.data[i];
        }
    }
    return min;

}
int max(adtArray array)
{
    int max=array.data[0];
    for(int i=0;i<array.size;i++)
    {
        if(max<array.data[i])
        {
            max=array.data[i];
        }
    }
    return max;
}