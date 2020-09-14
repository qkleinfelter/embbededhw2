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
// Global creditStatus flag to keep track of the last rewardsOrAlarm
int creditStatus;
// Global month flag so we know where we were last
int month = 23;

// Function called when Alice makes a monthly payment or defaults on the monthly payment.
// Returns nothing, updates global variable creditRatingAlice.
// opcode is 0 if default, 1 if paid
void updateCreditRatingAlice(int opcode){
	// If our opcode is 0 she defaulted
	if (opcode == 0 && creditRatingAlice > 700){
		// If her creditRating is currently above 700 then we are good to reduce it
		// otherwise, keep her at 700 since thats the lowest she can go
		creditRatingAlice -= 10;
	} else if (opcode == 1 && creditRatingAlice < 800) {
		// If her creditRating is currently below 800 then we are good to increase it
		// otherwise, keep her at 800 since thats the highest she can go
		creditRatingAlice += 10;
	}
}

int rewardsOrAlarm(){
	while(1){
		// Update the current month so that we know where we need to look in the array
		// because month is initally 23, it will be updated to 0 on this statement
		// so we can start at the front, and then increment from there, before looping back to 0
		month = (month + 1) % 24;
		// Check if the current month is a 1, i.e. she paid
		if(monthlyPaymentHistoryAlice[month] == 1){
			// if her current month is a 1, then check if the last time her
			// credit rating changed was an 800, indicating she had 100 last time,
			// and will this time too, if so return 1 to reward her
			if(creditRatingAlice == 800){
				return 1;
			}
			// Otherwise, we'll get to here and update her (non-800) credit rating with a 1
			updateCreditRatingAlice(1);
		} else {
			// In here, her current monthlyPayment is a 0, so we want to do the same
			// thing as before except check if her last month was a 700, and if it was
			// then we need to return 0 so there is an alarm
			if (creditRatingAlice == 700){
				return 0;
			}
			// Otherwise, we'll get to here and update her (non-700) credit rating with a 0
			updateCreditRatingAlice(0);
		}
	}
}	

void question4(void){
	while(1) {
		// Loop endlessly and update creditStatus to the value returned by rewardsOrAlarm()
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


