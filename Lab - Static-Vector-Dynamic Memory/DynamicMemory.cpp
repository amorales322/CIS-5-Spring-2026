/*
	Author:  Dr. Mark E. Lehr
	Date:    May 28th, 2026
	Purpose: Dynamic Memory Tests
*/

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>
#include <ctime>
using namespace std; 

//User Libraries

//Global Constants - Scientific/Physics/Chemistry/Conversions Higher Dimensions

//Function Prototypes
long int *filAry(long int);

//Execution Begins Here
int main(int argv,char **argc){
	//Set the Random Number Seed
	srand(static_cast<long int>(time(0)));
	
	//Declare Variables
	long int size = 6'500'000'000;
	long int *array;
	array=filAry(size);

	//Initialize Variables
	cout<<"Array Size Allocated "<<size<<endl;
	cout<<"Input a integer value"<<endl;
	int dummy;
	cin>>dummy;
	
	//Mapping Input to Output
	cout << sizeof(*array) * size << '\n';	
	//Display the Results

	//De-allocate Memory
	delete []array;
	
	//Exit Stage Right
	return 0;
}

long int *filAry(long int size){
	long int *array=new long int[size];
	for(long int i=0;i<size;i++){
		array[i]=rand();
	}
	return array;
}
