//PROBLEM: Implement efficecy improvements for duplicates for quicksort
//
//EARLY NOTES: We need to make changes to the partitioning scheme to grab identical values of our pivot and sort them immediately.
//
//FINAL NOTES: When I reduced the range of numbers the new hybrid sort kicked std::sort's butt. It ran substantially faster. However, sort seems to always run the about the same amount of time regardless the different constraints. The size of the data seems to be the only thing that effects the run time. 

using namespace std;

#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

#define THRESHOLD 64
#define RANGE 1000
#define SIZE 100000
#define NUM 50

void print(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
void insertion_sort(int arr[], int start, int end)
{
	int value;
	int j;

	for(int i = start + 1; i <= end; i++)
	{
		value = arr[i];
		j = i;
		while(j > start && arr[j - 1] > value)
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = value;
	}
}
pair<int,int> partition(int arr[], int left, int right)
{
	//select our pivot
	int pivot = arr[right];
	int loc_0;
	int loc_1;

	//create our subarrays
	int less[right - left];
	int greater[right - left];
	int k = 0;
	int j = 0;

	//pivot counter
	int p = 0;
	
		
	//sort the elements into their proper arrays
	for(int i = left; i < right; i++)
	{
		if(arr[i] < pivot)
		{
			less[k++] = arr[i];
		}
		else if(arr[i] == pivot)
		{
			p++;
		}
		else
		{
			greater[j++] = arr[i];
		}
	}

	//fill the master array with the less than array
	for(int i = 0; i < k; i++)
	{
		arr[i+left] = less[i];
	}
	
	//place the pivot
	loc_0 = k + left;
	loc_1 = loc_0 + p;

	for(int i = loc_0; i <= loc_1; i++)
	{
		arr[i] = pivot;
	}	

	//fill master with greater 
	for(int i = 0; i < j; i++)
	{
		arr[i + loc_1 + 1] = greater[i];
	}
	
	//return the pivot location
	return make_pair(loc_0,loc_1);
}
void hybrid_quick_sort(int arr[], int n)
{
	//insertion sort/quick sort hybrid
	stack<pair<int,int>> stk;
	int start = 0;
	int end = n - 1;
	pair<int,int> pivot;

	stk.push(make_pair(start,end));

	while(!stk.empty())
	{
		//grab our current partition values and pop
		start = stk.top().first;
		end = stk.top().second;
		stk.pop();

		//start our parition
		pivot = partition(arr,start,end);

		if(pivot.first - start <= THRESHOLD && pivot.first - start > 0)
		{
			insertion_sort(arr,start,pivot.first - 1);
		}
		else if(pivot.first  - 1 > start)
		{
			stk.push(make_pair(start,pivot.first - 1));
		}

		if(end - pivot.second <= THRESHOLD && end - pivot.second > 0)
		{
			insertion_sort(arr,pivot.second + 1, end);
		}
		else if(pivot.second + 1 < end)
		{
			stk.push(make_pair(pivot.second + 1, end));
		}
	}
}
bool is_sorted(int arr[], int n)
{

	for(int i = 1; i < n; i++)
	{
		if(arr[i-1] > arr[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int arr[SIZE], dup[SIZE];

	srand(time(NULL));

	clock_t begin, end;
	double t1 = 0.0, t2 = 0.0;

	for(int i = 0; i < NUM; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			dup[j] = arr[j] = rand() % RANGE;
		}
		begin = clock();
		sort(dup, dup + SIZE);
		end = clock();
		t1 += (double)(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		hybrid_quick_sort(arr, SIZE);
		end = clock();
		t2 += (double)(end - begin) / CLOCKS_PER_SEC;
	}
	cout << "Average time for sort: " << t1/NUM << endl;
	cout << "Average time for hybrid quick sort: " << t2/NUM << endl;

	return 0;
}
