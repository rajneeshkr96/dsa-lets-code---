// print array
#include <iostream>
using namespace std;
void printArr(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}

// question 1 
// Write a program to reverse an array or string

// using  itrative method 

void reverse(int arr[], int n){
    int mid = n/2;
    for (int i = 0; i < mid; i++)
    {
       int temp;
       temp = arr[i];
       arr[i] = arr[n-i-1];
       arr[n-i-1] = temp;
    }
    
}

// using recursivale 
void reverseArr(int arr[], int n){
    

}


int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    cout<<"before reversing the arrays"<<endl;
    printArr(arr,8);
    reverse(arr,8);
    cout<<"after reversing the arrays"<<endl;
    printArr(arr,8);


    return 0;
}