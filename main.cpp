#include <iostream>
#include <iterator>

int min(int x, int y){
    if(x<y)
        return x;
    return y;
    }
void mergeSort(int arr[], int n)
{
    int curr_size;
    int left_start;
    for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
    {
        for (left_start=0; left_start<n-1; left_start += 2*curr_size)
        {
            int mid = min(left_start + curr_size - 1, n-1);
            int right_end = min(left_start + 2*curr_size - 1, n-1);
            int i, j, k;
            int n1 = mid - left_start + 1;
            int n2 =  right_end - mid;
            int* L = new int[n1];
            int* R = new int[n2];
            for (i = 0; i < n1; i++)
                L[i] = arr[left_start + i];
            for (j = 0; j < n2; j++)
                R[j] = arr[mid + 1+ j];
            i = 0;
            j = 0;
            k = left_start;
            while (i < n1 && j < n2){
                if (R[j] > L[i] ){
                    arr[k] = L[i];
                    i++;
                }
                else{
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }
            while (i < n1){
                arr[k] = L[i];
                i++;
                k++;
            }
            while (j < n2){
                arr[k] = R[j];
                j++;
                k++;
            }
            delete[] L;
            delete[] R;
        }
    }
}

int main() {
    int* array = new int[100];
    for(int i = 0; i < 100; ++i) {
        array[i] = rand();
        std::cout << array[i] << std::endl;
    }
    std::cout << std::endl;

    mergeSort(array, 100);

    for(int i = 0; i < 100; ++i) {
        std::cout << array[i] << std::endl;
;
    }
    std::cout << std::endl;


    delete[] array;
    return 0;
}
