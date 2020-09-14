/*******************************************************************
 *  main.c
 *  This is an embedded program template.
 *  
 *  Author: G. Serpen
 *  Date: Date: May 22, 2017
 *
 *  
 *******************************************************************/

void question1a(void){
	
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


