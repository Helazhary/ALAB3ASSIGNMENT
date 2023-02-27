

#include <iostream>
#include <fstream>
#include <numeric>
#include <iomanip>
using namespace std;



void display_arr(int* arr, int n)
{
	cout<<endl;
	for (int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int bubble_sort_comparisons(int* arr, int n)
{
    int counter = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
			counter++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
              
			}
        }
    }
    
    return counter;
}



int insertion_sort_comparisons(int* arr, int n) 
{
	
    int key,j;
    
    //count number of comparisons  
    int counter = 0;
    for (int i = 1; i < n; i++) 
    {
		key = arr[i];  
        j = i - 1;  
        
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;
            counter++; 

        }  
        if (j<0)
		    arr[j + 1] = key;
        else
            counter++;  
    }
   
    return counter;
}

int* generate_k_inversion(int k, int n) 
{
	int* arr = new int[n];
    iota(arr, arr + n, 1); // initialize the array as 1, 2, 3, ..
    
  int inversions = 0;
    int i = 0;
    while (inversions < k && i < n) {
        int j = i - 1;
        while (j >= 0 && arr[j] < arr[j+1] && inversions < k) {
            swap(arr[j], arr[j+1]);
            inversions++;
            j--;
        }
        i++;
    }

	return arr;	
	
	
}

void task1 ()
{
	
	int n = 5;
	//ascending array
	int* best_case = new int[n];
    iota(best_case, best_case + n, 1);
    
    //descending array
    int* worst_case = new int[n];
    for(int i=0;i<n;i++)
		worst_case[i] = n-i ;
    
    //test bubble_sort_comparisons and insertion_sort_comparisons with n=5 
    
   
   
    //test generate_k_inversions with n=5 and k =3
    int* arr = new int[n];
    int k =5;
    arr = generate_k_inversion(k,n);
    display_arr(arr,n);
		 
}

void task2 ()
{
	
	cout<<"n\t Bubble Sort-Best    Bubble Sort-worst    Insertion Sort-Best    Insertion Sort-Worst\n";
	cout<<"_______________________________________________________________________________________________\n";  
	
    for(int n=1; n<=15;n++)
    {
		int* best_case = new int[n];
        iota(best_case, best_case + n, 1);
		
		int* worst_case = new int[n];
		for(int i=0;i<n;i++)
			worst_case[i] = n-i ;

		int* worst_case2 = new int[n];
		for(int i=0;i<n;i++)
			worst_case2[i] = n-i ;
		
    
	cout<<left<<setw(3)<<n<<"  "<<setw(3)<<bubble_sort_comparisons(best_case, n)<<"  "<<setw(3)<<bubble_sort_comparisons(worst_case, n)
     <<"  "<<setw(3) <<insertion_sort_comparisons(best_case, n)<<"  "<<setw(3) <<insertion_sort_comparisons(worst_case2, n)<<endl;
	}
		 
}

void task3()
{
	cout<<"n Bubble Sort comparisons  Insertion Sort comparisons\n";
	cout<<"_______________________________________________________________________________________________\n";  
    //int k=n/4;
    for( int i=5; i<=15;i++)
    {
		
cout<<setw(4)<<left<<i<<"  "<<setw(4)<<bubble_sort_comparisons(generate_k_inversion(i/4,i), i)<<"  "<<setw(4)<<insertion_sort_comparisons(generate_k_inversion(i/4,i), i)<<endl;

	}

    cout<<endl<<"n Bubble Sort comparisons  Insertion Sort comparisons\n";
	cout<<"_______________________________________________________________________________________________\n";  
   
	//int k=2n;
	 for( int i=5; i<=15; i++)
    {
		
cout<<setw(4)<<left<<i<<"  "<<setw(4)<<bubble_sort_comparisons(generate_k_inversion(i*2,i), i)<<"  "<<setw(4)<<insertion_sort_comparisons(generate_k_inversion(i*2,i), i)<<endl;

	}
	
}	


int main()
{
task1();
task2();
task3();





   
    
    
return 0;
}

