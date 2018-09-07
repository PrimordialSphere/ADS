#include "MyAlgorithms.h"
#include <omp.h>
using namespace std; 

namespace MyAlgorithms {

  //************
  // QuickSort *
  //************      
  void QuickSort(vector<int> &arr, int left, int right) {
	  int q;
	  if (left < right)
	  {
		  q = partition(arr, left, right);
		  QuickSort(arr, left, q - 1);
		  QuickSort(arr, q+1, right);

	  }
		
  }

  //************
  // MergeSort *
  //************
  void MergeSort(vector<int> &a, int low, int high) {
	  if (low < high) {
		  
		  int pivot = (low + high) /2;
		  MergeSort(a, low, pivot);
		  MergeSort(a, pivot+1, high);
		  merge(a, low, pivot, high);
		  
	  }
  }
  
  //************
  // Heapsort  *
  //************

  void HeapSort(vector<int> &a, int n) { 
	  int i = (n/2);
	  while (i >= 0)
	  {
		  percDown(a, i, n);
		  i--;
	  }

	  int j = n;
	  while (j >= 0) {
		  swap(a, 0, j);
		  percDown(a, 0, j);
		  j--;
	  }
  }

  //************
  // Shellsort *
  //************
  void ShellSort(vector<int> &a, int n) {
	  int size = n+1;
	  
	  for (int gap = (size / 2); gap > 0; gap = (gap/2)) {
		  for (int i = gap; i < size; i++)
		  {
			  int tmp = a[i];
			  int j = i;
			  for (;j >=gap && tmp < a[j-gap]; j-=gap )
			  {
				  a[j] = a[j - gap];
			  }
			  a[j] = tmp;
		  }
	  }
  }
 
  //************************************
  //Matrix Multiplication Column Major *
  //************************************

  void MatrixMul_ColMajor(vector<double> &A, 
			  vector<double> &B, 
			  vector<double> &C, 
			  int n, 
			  int numThreads)
  {
	  
	  omp_set_num_threads(numThreads);
    //lda, ldb, ldc are leading dimensions of matrices A,B and C
    int lda = n;
    int ldb = n;
    int ldc = n;
    double s = 0.0;

#pragma omp parallel for
    for (int i=0; i<n ; i++) {
      for (int j=0; j<n ; j++) {
	s = 0.0;
	for (int k=0; k<n; k++) {
	  s = s + A[j+k*lda] * B[k+i*ldb];
	}
	C[i+j*ldc]=s;
      }
    }
  }

  //*********************************
  //Matrix Multiplication Row Major *
  //*********************************

  void MatrixMul_RowMajor(vector<double> &A, 
			  vector<double> &B, 
			  vector<double> &C, 
			  int n,
			  int numThreads)
  {
	 
	  omp_set_num_threads(numThreads);
  //lda, ldb, ldc are leading dimensions of matrices A,B and C
  int lda = n;
  int ldb = n;
  int ldc = n;
  double s = 0.0;

#pragma omp parallel for
  for (int j = 0; j<n; j++) {
	  for (int i = 0; i<n; i++) {
		  s = 0.0;
		  for (int k = 0; k<n; k++) {
			  s = s + A[i + k * lda] * B[k + j * ldb];
		  }
		  C[j + i * ldc] = s;
	  }
  }

  }

  //********************
  // helper functions  *
  //********************
  double fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
  }

  void randomizeMatrix(vector<double> &matrix, int n) {
    matrix.resize(n*n);
    int i;
    for (i=0;i<matrix.size();i++)
      matrix[i]=fRand(-1000,1000);
  }

  void randomizeArray(vector<int> &array, int n) {
    array.resize(n);

    for(int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }
  int partition(vector<int> &arr, int left, int right) {
	  int x = arr[right];
	  int i = left - 1;

	  for (int j = left; j < right; j++) {
		  if (arr[j] <= x) {
			  i = i + 1;
			  swap(arr, i, j);
		  }
	  }
	  swap(arr, i + 1, right);
	  return i + 1;
  }
  void swap(vector<int>& arr, int i, int j)
  {
	  int zwischenspeicherI = arr[i];
	  arr[i] = arr[j];
	  arr[j] = zwischenspeicherI;
  }
  void merge(vector<int>& arr, int low, int pivot, int high)
  {
	  int n1 = pivot - low + 1;
	  int n2 = high - pivot;

	  vector<int> L(n1+1);
	  vector<int> R(n2+1);
	
	  for (int i = 0; i < n1; i++)
	  {
		  L[i] = arr[low +i];
	  }

	  for (int i = 0; i < n2; i++)
	  {
		  R[i] = arr[pivot +1+ i];
	  }

	  L[n1] = std::numeric_limits<int>::max();;
	  R[n2] = std::numeric_limits<int>::max();;

	  int i = 0;
	  int j = 0;
	  
	  for(int k = low; k <=high; k++ ){
		  if (L[i] <= R[j]) {
			  arr[k] = L[i];
			  i++;
		  }
		  else
		  {
			  arr[k] = R[j];
			  j++;
		  }
	  }
  }
  void percDown(vector<int>& a, int p, int n)
  {
	  int start = p;
	  int r =  rightChild(start);
	  int l = leftChild(start);
		  
		  if ((l < n) && (a[l] > a[start])) {
			  start = l;
		  }
		  if ((r < n) && (a[r] > a[start])) {
			  start = r;
		  }
		  if (start != p) {
			  swap(a, p, start);
			  percDown(a, start, n);
		  }
		  
	  
  }
  int leftChild(int i)
  {
	  int value = 2 * i + 1;
	  return value;
  }
  int rightChild(int i)
  {
	  int value = 2 * i + 2;
	  return value;
  }
}
