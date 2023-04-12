#include <iostream>
using namespace std;

void bubblesort(uint64_t a[], uint32_t n){ //O(n^2)
    for(uint32_t j = n-1; j>0; j--){ //O(n)
        for(uint32_t i = 0; i < j; i++){ //O(n-1) = O(n)
            if(a[i] > a[i+1]){
                uint64_t temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
}

/* xor doesnt need temp
#if 0
    a[i] ^= a[i+1];
    a[i+1] ^= a[i];
    a[i] ^= a[i+1];
#endif
*/

void improved_bubblesort(uint64_t a[], uint32_t n){ //O(n^2) omega(n)
    int swaps;
    for(uint32_t j = n-1; j>0; j--){ //O(n)
    swaps = 0;
        for(uint32_t i = 0; i < j; i++){ //O(n-1) = O(n)
            if(a[i] > a[i+1]){
                uint64_t temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                swaps++;
            }
        }
        if (swaps == 0)
            return; //omega(n)
    }
}