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

void question1d(void){
	// Declare ch1 to be 0x34
	volatile char ch1 = 0x34;
	// Declare mask to be 0x10 which only has a 1 in bit 4
	volatile char mask = 0x10;
	
	// Do a bitwise XOR to only change the value in bit 4
	// and toggle it based on its current value
	ch1 = ch1 ^ mask;
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

// Global variables here–avoid declaring too many globals unnecessarily as it is not considered a good programming practice.
int creditRatingAlice = 750;
// 0 represents “defaulted” and 1 represents “paid” for the payment history
int monthlyPaymentHistoryAlice[24] = {1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1};
int creditStatus;
int month = 23;

void updateCreditRatingAlice(int opcode){
	if (opcode == 0){
		if (creditRatingAlice > 700){
			creditRatingAlice -= 10;
		}
	} else {
		if (creditRatingAlice < 800){
			creditRatingAlice += 10;
		}
	}
}

int rewardsOrAlarm(){
	while(1){
		month = (month + 1) % 24;
		if(monthlyPaymentHistoryAlice[month] == 1){
			if(creditRatingAlice == 800){
				return 1;
			}
			updateCreditRatingAlice(1);
		} else {
			if (creditRatingAlice == 700){
				return 0;
			}
			updateCreditRatingAlice(0);
		}
	}
}	

void question4(void){
	while(1) {
		creditStatus = rewardsOrAlarm();
	}
}



// Called by startup assembly code, start of C code
int main(void){
	question1a();
	question1b();
	question1c();
	question1d();
	question2();
	question3();
	question4();
	
  while(1){
		
  }
}


