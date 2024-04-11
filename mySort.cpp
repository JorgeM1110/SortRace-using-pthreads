#include <iostream>
#include <fstream>
#include <pthread.h>

using namespace std;


struct mySort
{
 int* arr;
 int size; 

};

void myswap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void Bubblesort(int arr[], int size)
{
    for(int i = 0; i < size - 1 ; i++){
        for(int j = 0; j< size - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                myswap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void *bridge(void *argv)
{
    mySort *arg = (mySort *)argv;
    Bubblesort(arg->arr, arg->size);
    return NULL;
}

void merge(int arr[], int start, int end)
{
    int temp[end - start + 1 ];
    int i = start, j = (start + end) / 2 + 1, k = 0;

    while (i <= (start + end) / 2 || j <= end) {
        if (i > (start + end) / 2 || (j <= end && arr[j] < arr[i])) {
            temp[k++] = arr[j++];
        } else {
            temp[k++] = arr[i++];
        }
    }

    for (int p = 0; p < k; p++) {
        arr[start + p] = temp[p];
    }

}

int main(int argc, char *argv[]){

    if (argc != 3){
        cout << "Error\n need to be 3" << endl; 
        return 1; 
    }


    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

     int *numbers = new int[1000000];
    pthread_t sections[8];
    int sectionSize = 125000;

    int count = 0;
    int number;
    while (fin >> number && count < 1000000){
        numbers[count++] = number;
    }
    fin.close();


    mySort ss1;
    ss1.arr = &numbers[0];
    ss1.size = 125000;

    mySort ss2;
    ss2.arr = &numbers[125000];
    ss2.size = 125000;

    mySort ss3;
    ss3.arr = &numbers[250000];
    ss3.size = 125000;

    mySort ss4;
    ss4.arr = &numbers[375000];
    ss4.size = 125000;

    mySort ss5;
    ss5.arr = &numbers[500000];
    ss5.size = 125000;
    
    mySort ss6;
    ss6.arr = &numbers[625000];
    ss6.size = 125000;

    mySort ss7;
    ss7.arr = &numbers[750000];
    ss7.size = 125000;

    mySort ss8;
    ss8.arr = &numbers[875000];
    ss8.size = 125000;

    pthread_create(&sections[0], NULL, bridge, (void*) &ss1);
    pthread_create(&sections[1], NULL, bridge, (void*) &ss2);
    pthread_create(&sections[2], NULL, bridge, (void*) &ss3);
    pthread_create(&sections[3], NULL, bridge, (void*) &ss4);
    pthread_create(&sections[4], NULL, bridge, (void*) &ss5);
    pthread_create(&sections[5], NULL, bridge, (void*) &ss6);
    pthread_create(&sections[6], NULL, bridge, (void*) &ss7);
    pthread_create(&sections[7], NULL, bridge, (void*) &ss8);

    for (int i = 0; i < 8; ++i) {
        pthread_join(sections[i], NULL);
    }

    while (sectionSize < 1000000) {
        for (int i = 0; i < 1000000; i += 2 * sectionSize) {
            int end = min(i + 2 * sectionSize, 1000000);
            
            merge(numbers, i, end - 1);
        }
        sectionSize *= 2;
    }



    for (int i = 0; i < count; ++i) {
        fout << numbers[i] << endl;
    }
  

    fout.close();

    delete[] numbers;

    return 0;

}