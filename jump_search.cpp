#include "stdio.h"

int min(int first,int second){
    if(second > first){
        return first;
    }else{
        return second;
    }

}

int jumpSearch(int arr[],int size,int key){
    int previous = 0;
    int step = 0;

    if(size%2 == 0){
        step = size%2 + 4;
    }else{
        step = size%2 + 3;
    }


    while(arr[min(step,size)-1] < key){
        previous = step;

        if(size%2 == 0){
            step += size%2 + 4;
        }else{
            step += size%2 + 3;
        }


        if(previous >= size){
            return -1;
        }
    }

    int count=0;

    for (int i = previous; i < step; ++i) {
        count++;
    }



    count = count/2;



    if(arr[previous + (count + 1)] == key ){
        return previous + (count + 1);
    } else if (arr[previous + (count - 1)] == key ){
        return previous + (count - 1);
    } else if(arr[step-count] == key ){
        return step - count;
    }else if(arr[previous] == key){
        return previous;
    }else if(arr[step] == key){
        return step;
    }


    return -1;

}

int main(){

    int arr[] = {15,20,25,30,35,40,45,50,55};

    int size = sizeof(arr)/sizeof(arr[0]);



    int toFind =30;

    int indexNumber = jumpSearch(arr,size,toFind);

    if(indexNumber != -1){
        printf("We found\n");
        printf("found at %d : %d",indexNumber,arr[indexNumber]);
    }else{
        printf("Not found");
    }



    return 0;
}
