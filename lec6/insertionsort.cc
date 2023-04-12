/*
    1 2 3 5 4 9 8 6 7
    O(1) + O(1) + O(1) = O(1) + O(1) + O(2) + O(n-1) average n/2 = O(n)


*/

void insert(int a[], int n){ // n/2 + 
    for (int i = j = 1; i > 0; i--){
        if(a[i] > temp){
            a[i+1] = a[i];
        }
    }

}