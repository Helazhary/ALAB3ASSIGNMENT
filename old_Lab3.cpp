#include <iostream>
#include <iomanip>
using namespace std;


void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}

int bubble_sort(int* arr, int n)  
{  
    int i, j;
    int count=0;  
    for (i = 0; i < n-1; i++)
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)
    {  
        count++;
        if (arr[j] > arr[j+1])  
            swap(arr[j], arr[j+1]);  
    }
    return count;
}

// int insertion_sort(int* arr, int n)  
// {  
//     int i, key, j;  
//     int count=0;
//     for (i = 1; i < n; i++) 
//     {  
//         key = arr[i];  
//         j = i - 1;  
  
      
//         while (j >= 0 && arr[j] > key) 
//         {  
            
//             arr[j + 1] = arr[j];  
//             j = j - 1;  
//             count++;
//         }  
//         arr[j + 1] = key;  

// if (count == 0 && n > 0)
//         count = n - 1;

//     }  
    
//     return count;
// } 
int insertion_sort(int* arr, int n)  
{  
	int comparisons = 0;

    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        while (j >= 0 && comparisons++, arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  

        arr[j + 1] = key;  
    }  

	return comparisons;
}

// int* generate_k_inversion(int k, int n) {
//     int* arr = new int[n];
//     for (int i = 0; i < n; i++) {
//         arr[i] = i+1;
//     }
//       for(int i = 0; k>0; i++, k--)
// 		swap(arr[i], arr[i + 1]);

//     return arr;
// }

int* generate_k_inversion(int k, int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }
    int inversions = 0;
    int i = 0;
    while (inversions < k && i < n) {
        int j = i - 1;
        while (j >= 0 && arr[j] < arr[j + 1] && inversions < k) {
            swap(arr[j], arr[j + 1]);
            inversions++;
            j--;
        }
        i++;
    // }
    // for (int j = n - 1; j >= 0 && inversions < k; j--) {
    //  swap(arr[j], arr[j - 1]);
    //  inversions++;
}

    return arr;
}


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void task2() {



   for(int n = 1; n <= 15; ++n)
	{
		int arr[n], rarr[n];
		int arr2[n], rarr2[n];

		for(int i = 0; i < n; ++i)
			arr[i] = arr2[i] = i, rarr[i] = rarr2[i] = n - i - 1;
		
		cout<<setw(4)<<left<<n<<"  "<<setw(4)<<bubble_sort(arr, n)<<"  "<<setw(4)<<bubble_sort(rarr, n) <<"  "<<setw(4)<<
        insertion_sort(arr2, n)<<"  "<<setw(4)<< insertion_sort(rarr2, n)<<endl;
	}

   
}

void task3()
{

for (int i=5; i<=15; i++)
{
   int*barr = new int[i];
   barr = generate_k_inversion(i/4,i);

   int*iarr = new int[i];
   iarr = generate_k_inversion(2*i,i);

 cout<<setw(4)<<left<<i<<"  "<<setw(4)<<bubble_sort(barr, i)<<"  "<<setw(4)<<insertion_sort(iarr, i)<<endl;

//    int*iarr2 = new int;
//    iarr2 = generate_k_inversion(2*i,i);

//    int*barr2 = new int;
//    barr2 = generate_k_inversion(2*i,i);


}

}
 
int main()
{

//printArray(generate_k_inversion(3, 5),5);
// cout<<endl;
//task2();
// cout<<endl;
task3();

}
