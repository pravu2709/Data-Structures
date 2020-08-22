#include <iostream>
using namespace std;

void display_array (int array[], int len_array)
{
	for (int i = 0 ; i < len_array; i++)
		cout<< array[i] <<" ";
	cout << "\n";
}

void max_heap(int array[], int len_array, int index )
{
	int root = index; 
	int l_child = 2*index + 1;
	int r_child = 2*index + 2;
	
	if (l_child < len_array && array[l_child] > array[root]) 
		root = l_child;
	if (r_child < len_array && array[r_child] > array[root]) 
		root = r_child;
	if(root != index) 
		{
		    swap(array[index], array[root]);
	        max_heap(array, len_array, root); 
		} 
}


void Heap_Sort(int array[], int len_array)
{
	for(int i = len_array/2 - 1 ; i >=0; i--)  
		max_heap(array, len_array, i);
		cout << "Maximum Heap Array : \n";
		display_array(array, len_array);
		
	for(int i = len_array-1; i >= 0; i--) 
	{
		swap (array[0],array[i]); 
		max_heap(array, i, 0); 
	}
}


int main ()
{
	int array[] = #include <iostream>
using namespace std;

void display (int array[], int len_array)
{
	for (int i = 0 ; i < len_array; i++)
		cout<< array[i] <<" ";
	cout << "\n";
}

void max_heap(int array[], int len_array, int index )
{
	int root = index; 
	int l_child = 2*index + 1;
	int r_child = 2*index + 2;
	
	if (l_child < len_array && array[l_child] > array[root]) 
		root = l_child;
	if (r_child < len_array && array[r_child] > array[root])
		root = r_child;
	if(root != index) 
		{
		    swap(array[index], array[root]);
	        max_heap(array, len_array, root); 
		} 
}

void Heap_Sort(int array[], int len_array)
{
	for(int i = len_array/2 - 1 ; i >=0; i--)  
		max_heap(array, len_array, i);
		cout << "Maximum Heap Array : \n";
		display_array(array, len_array);
		
	for(int i = len_array-1; i >= 0; i--) 	{
		swap (array[0],array[i]); 
		max_heap(array, i, 0); 	}
}

int main ()
{
	int array[] = {56, 23, 30, 12, 67, 33, 4, 89,65,21,20,8,13,7,88,54,29, 18, 51,100};
	int len = sizeof(array)/sizeof(array[0]);
	cout << "Input array : \n";
	display(array, len);
	
	Heap_Sort(array, len);
	cout << "Sorted Array :  \n";
	display(array, len);
}