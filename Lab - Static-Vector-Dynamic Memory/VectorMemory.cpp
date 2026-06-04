/*
	Author:  Dr. Mark E. Lehr
	Date:    May 28th, 2026
	Purpose: Memory Tests
*/

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>
#include <ctime>
#include <vector>


using namespace std; 

//User Libraries

//Global Constants - Scientific/Physics/Chemistry/Conversions Higher Dimensions

//Function Prototypes
void filAry(vector<long int> &,long int);

//Execution Begins Here
int main(int argv,char **argc){
	//Set the Random Number Seed
	srand(static_cast<unsigned int>(time(0)));
	
	//Declare Variables
	long int size=6'500'000'000;
	vector<long int> array(size);
	filAry(array,size);
	
	//Initialize Variables
	cout<<"Array Size Allocated "<<size<<endl;
	cout<<"Input a integer value"<<endl;
	int dummy;
	cin>>dummy;
	
	//Mapping Input to Output
	cout << sizeof(vector<int>) * array.size() << '\n';	
	//Display the Results

	//De-allocate Memory

	//Exit Stage Right
	return 0;
}

void filAry(vector<long int> &array, long int size){
	for(long int i=0;i<size;i++){
		array[i]=rand();
	}
}
