/*******************************************************************
 *  main.c
 *  
 *  
 *  Author: Quinn Kleinfelter
 *  Date: Date: Sept. 14, 2020
 *
 *  
 *******************************************************************/

void question1a(void){
	// Declare ch1 to be 0x34
	volatile char ch1 = 0x34;
	// Declare ch2 with no inital value
	volatile char ch2;
	// Declare mask to be 0x20
	volatile char mask = 0x20;
	
	// Shift ch1 to the right 4 bits and then run a bitwise 
	// and on this value with a single 1, which will only be
	// 1 if the value in bit 5 was a 1 before. Then, because
	// 1 is 'true' in C, we can assign ch2 based on it with a 
	// quick ternary operator
	ch2 = (ch1 >> 4) & 1 ? 1 : 0;
}

void question1b(void){
	// Declare ch1 to be 0x34
	volatile char ch1 = 0x34;
	// Declare mask to be 0x80, which puts a 1 in bit 7
	volatile char mask = 0x80;
	
	// Run a bitwise OR on ch1 and mask so that bit 7 in ch1
	// will be set to 1 no matter what the value of it is
	// currently in ch1
	ch1 = ch1 | mask;
}

void question1c(void){
	// Declare ch1 to be 0x34
	volatile char ch1 = 0x34;
	// Declare mask to be 0xF7, which is all 1 except for bit 3, which is 0
	volatile char mask = 0xF7;
	
	// Run a bitwise AND on ch1 and mask, so that bit 3 in ch1
	// is set to 0 no matter what the value of it is currently
	// Note: in this case because ch1 = 0x34, which has bit 3 as 0
	// already, this doesn't change the value.
	ch1 = ch1 & mask;
}

void question2(void){
	// Declare an int variable 'factorial' to be 1, we will use this to store our calculations
	int factorial = 1;
	// Declare an iterator variable 'i'
	int i;

	for (i = 1; i <= 5; i++) {
		// Loop through from i = 1 while i <= 5, multiplying our factorial variable by i each time
		factorial *= i;
	}
}

// Declare & init global maxValueArray as specified
int maxValueArray[] = {-1, 5, 3, 8, -10, 23, 6, 5, 2, 10};
// Declare & init global arraySize as specified
int arraySize = 10;

void question3(void){
	// Declare a local largest value to be the first value so we will always get it correctly
	int largest = maxValueArray[0];
	// Declare a local iterator
	int i;
	for (i = 0; i < arraySize; i++) {
		// Loop through the array
		if (maxValueArray[i] > largest) {
			// If the value at the current position of the array is larger
			// than our current largest then set largest to be it
			largest = maxValueArray[i];
		}
	}
}

// Called by startup assembly code, start of C code
int main(void){
	question1a();
	question1b();
	question1c();
	question2();
	question3();
	
  while(1){
		
  }
}


