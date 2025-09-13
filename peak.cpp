//Peak index
#include<iostream>
using namespace std;

int peak(int arr[], int n)
{
	int max = 0;
	for(int i = 0; i < n; i ++)
	{
		if(arr[i] > arr[max]){
			max = i;
		}
	}
	return max;
}
int main()
{
	int arr[] = {1,3,20,4,1,0};
	int n = (sizeof(arr)/sizeof(arr[0]));
	
	int max = peak(arr,n);
	
	cout << "Peak index is " << max;
	return 0;
}

