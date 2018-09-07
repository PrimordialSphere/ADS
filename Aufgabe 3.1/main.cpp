#include <iostream>
#include <fstream> 
#include <iomanip> 
#include <vector>
#include <omp.h>
#include "MyAlgorithms.h"

using namespace std;

int main(int argc, char** argv) {

  //***************
  // file streams *
  //***************
  ofstream quicksort;

  //quicksort.open("quicksort.txt", ios::out | ios::app);
 //quicksort.open("heapsort.txt", ios::out | ios::app);
  //quicksort.open("mergesort.txt", ios::out | ios::app);
 // quicksort.open("shellsort.txt", ios::out | ios::app);

  quicksort.open("matrixmul_colmajor_singlethread.txt", ios::out | ios::app);
 // quicksort.open("matrixmul_rowmajor_singlethread.txt", ios::out | ios::app);
 // quicksort.open("matrixmul_colmajor_maxthreads.txt", ios::out | ios::app);
 // quicksort.open("matrixmul_rowmajor_maxthreads.txt", ios::out | ios::app);


  //******************** 
  //benchmark settings *
  //********************
  
  double dtime;
  int n_start = 1000;
  int n_step = 1000;
  int n_end = 1000000;
  int numThreads = 2; //only for matrix multiplication

  //********************************************************************
  //data structures for sorting algorithms (int) and matrices (double) *
  //********************************************************************
 
  vector<int> array,temp_array;
  vector<double> A,B,C; 


  //********************************************************
  //benchmark main loop (run only ONE algorithm at a time) *
  //********************************************************

  for (int n = n_start; n<n_end; n+=n_step) {    
    cout << "n: " << n << endl;

    //***************************************
    //init data structure with random values*
    //***************************************
    
    //sorting algorithms
    MyAlgorithms::randomizeArray(array,n);
	
    //matrix multiplication
    if (n>800) { n_step=11; }
    MyAlgorithms::randomizeMatrix(A,n);
    MyAlgorithms::randomizeMatrix(B,n);
    C.resize(n*n);
	
    //****************
    //  start clock  *
    //**************** 
    dtime = omp_get_wtime();
	
    //**********************
    //  execute algorithm  *
    //**********************
   //MyAlgorithms::QuickSort(array,0,array.size()-1);
	//MyAlgorithms::HeapSort(array, array.size() - 1);
	//MyAlgorithms::MergeSort(array, 0, array.size() - 1);
	//MyAlgorithms::ShellSort(array, array.size() - 1);
   	
    //***************
    //  stop clock  *
    //***************
    dtime = omp_get_wtime() - dtime;    
    
    //*************************
    //  write results to file *
    //*************************
    quicksort << n << "\t" << setprecision(10) << scientific << dtime << endl;
    
  } 

  //**********************
  //  close file handles *
  //**********************
  
  quicksort.close();
  
  

	/*vector<int> meinVektor;
	meinVektor.push_back(1);
	meinVektor.push_back(3);
	meinVektor.push_back(2);
	meinVektor.push_back(5);
	meinVektor.push_back(9);
	meinVektor.push_back(8);
	


	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = meinVektor.begin(); it != meinVektor.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	
	

	MyAlgorithms::ShellSort(meinVektor, meinVektor.size()-1);

	std::cout << "After MergeSort myvector contains:";
	for (std::vector<int>::iterator it = meinVektor.begin(); it != meinVektor.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';*/


/*
vector<int> meinVektor;
meinVektor.push_back(98);
meinVektor.push_back(44);
meinVektor.push_back(30);
meinVektor.push_back(22);
meinVektor.push_back(64);
meinVektor.push_back(63);
meinVektor.push_back(11);
meinVektor.push_back(23);
meinVektor.push_back(8);
meinVektor.push_back(18);

std::cout << "myvector contains:";
for (std::vector<int>::iterator it = meinVektor.begin(); it != meinVektor.end(); ++it)
std::cout << ' ' << *it;
std::cout << '\n';




MyAlgorithms::HeapSort(meinVektor, meinVektor.size()-1);

std::cout << "After MergeSort myvector contains:";
for (std::vector<int>::iterator it = meinVektor.begin(); it != meinVektor.end(); ++it)
std::cout << ' ' << *it;
std::cout << '\n'; 

*/


	system("PAUSE");
}
