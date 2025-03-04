//
Binary Search: Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. 
If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. 
Time Complexity: T(n) = T(n/2) + c 
Auxiliary Space: O(1) in case of iterative implementation. 
In the case of recursive implementation, O(Logn) recursion call stack space

//

## PROGRAM (RECURSION)

#include<iostream>
using namespace std;

int binarySearch(int arr[],int l,int r,int x){
	if(r>=l){
		int mid=l+(r-1)/2;
		if(arr[mid] == x){
			return mid;
		}
		if(arr[mid]>x){
			return binarySearch(arr,l,mid-1,x);
		}
		return binarySearch(arr,mid+1,r,x);
	}
	return -1;
}
int main(){
	int arr[]={2,3,4,10,40};
	int x=10;
	int n=sizeof(arr)/sizeof(arr[0]);
	int result=binarySearch(arr,0,n-1,x);
	
	if(result==-1){
		cout<<"Elemnt not found";
	}
	else{
		cout<<"Found at index  "<<result;
	}
	return 0;
}
