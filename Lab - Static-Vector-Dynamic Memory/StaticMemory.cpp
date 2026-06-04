/*
	Author:  Dr. Mark E. Lehr
	Date:    May 28th, 2026
	Purpose: Static Memory Tests
*/

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>
#include <ctime>
using namespace std; 

//User Libraries

//Global Constants - Scientific/Physics/Chemistry/Conversions Higher Dimensions

//Function Prototypes
void filAry(int *,int);

//Execution Begins Here
int main(int argv,char **argc){
	//Set the Random Number Seed
	srand(static_cast<unsigned int>(time(0)));
	
	//Declare Variables
	const int SIZE=2'091'000;

	int array[SIZE];

	//Fill Array
	filAry(array,SIZE);
	
	//Initialize Variables
	cout<<"Array Size Allocated "<<SIZE<<endl;
	cout<<"Input a Dummy integer value to end Program"<<endl;
	int dummy;
	cin>>dummy;
	
	//Mapping Input to Output
	
	//Display the Results
	
	//Exit Stage Right
	return 0;
}

void filAry(int *a,int n){
	for(int i=0;i<n;i++){
		a[i]=rand();
	}
}
