//PROBLEM: Implement a insertion sort quick sort hybrid
//
//EARLY NOTES: Will use an iterative implementation on a large randomly generate array. When two start end pointers occupy a range less than 64 units the program will run insertion sort. I'm going to test some different values, such as the insertion threshold, and the range of numbers
//
//FINAL NOTES: Quicksort vs hybrid: Worked as intended, hybrid is much faster. STD::sort vs hybrid: Strangely enough hybrid was marginally faster when threshold was 64, range and size were 100000. However, when I chagned the range to 1000 sort stayed relatively the same but hybrid doubled in run time! I believe that is because the standard sort is a hybrid quick sort with a lot of improvements built in. The next problem will address duplicates.

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
int partition(int arr[], int left, int right)
{
	//select our pivot
	int pivot = arr[right];
	int loc;

	//create our subarrays
	int less[right - left];
	int greater[right - left];
	int k = 0;
	int j = 0;
	
		
	//sort the elements into their proper arrays
	for(int i = left; i < right; i++)
	{
		if(arr[i] <= pivot)
		{
			less[k++] = arr[i];
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
	loc = k + left;
	arr[loc] = pivot;

	//fill master with greater 
	for(int i = 0; i < j; i++)
	{
		arr[i + loc + 1] = greater[i];
	}
	
	//return the pivot location
	return loc;
}
void quick_sort(int arr[], int n)
{
	//stack based implementation for quicksort
	stack<pair<int,int>> stk;
	int start = 0;
	int end = n - 1;
	int pivot;

	stk.push(make_pair(start,end));

	while(!stk.empty())
	{
		//grab our current partition values and pop
		start = stk.top().first;
		end = stk.top().second;
		stk.pop();

		//start our parition
		pivot = partition(arr,start,end);

		//create our new partition values
		if(pivot  - 1 > start)
		{
			stk.push(make_pair(start,pivot - 1));
		}
		if(pivot + 1 < end)
		{
			stk.push(make_pair(pivot + 1, end));
		}
	}
}
void hybrid_quick_sort(int arr[], int n)
{
	//insertion sort/quick sort hybrid
	stack<pair<int,int>> stk;
	int start = 0;
	int end = n - 1;
	int pivot;

	stk.push(make_pair(start,end));

	while(!stk.empty())
	{
		//grab our current partition values and pop
		start = stk.top().first;
		end = stk.top().second;
		stk.pop();

		//start our parition
		pivot = partition(arr,start,end);

		if(pivot - start <= THRESHOLD && pivot - start > 0)
		{
			insertion_sort(arr,start,pivot - 1);
		}
		else if(pivot  - 1 > start)
		{
			stk.push(make_pair(start,pivot - 1));
		}

		if(end - pivot <= THRESHOLD && end - pivot > 0)
		{
			insertion_sort(arr,pivot + 1, end);
		}
		else if(pivot + 1 < end)
		{
			stk.push(make_pair(pivot + 1, end));
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
