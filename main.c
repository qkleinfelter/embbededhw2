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
	volatile char ch1 = 0x34;
	volatile char ch2;
	volatile char mask = 0x20;
	
	ch2 = (ch1 >> 4) && 1 ? 1 : 0;
}

void question2(void){
	int factorial = 1;
	int i;

	for (i = 1; i <= 5; i++) {
		factorial *= i;
	}
}
int maxValueArray[] = {-1, 5, 3, 8, -10, 23, 6, 5, 2, 10};
int arraySize = 10;

void question3(void){
	int largest = maxValueArray[0];
	int i;
	for (i = 0; i < arraySize; i++) {
		if (maxValueArray[i] > largest) {
			largest = maxValueArray[i];
		}
	}
}

// Called by startup assembly code, start of C code
int main(void){
	question1a();
	question2();
	question3();
	
  while(1){
		
  }
}


