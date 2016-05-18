#include<stdio.h>
#include<time.h>

int readNumber(const char* prompt);
int firstDayOfMonth(int month,int year);
int noOfMonthDays(int month,int year);
void printCalender(int firstDay,int monthDays);

int main (void){
	
	int month;
	int year;
	int firstDay;
	int monthDays;
	
	printf("\n\t***To Display Calender Of Any Month And Year Since 1900***\n");
	
	month=readNumber("\nEnter Month Of The Calender : ");
	year=readNumber("\nEnter Year Of The Calender : ");
	
	firstDay=firstDayOfMonth(month,year);
	monthDays=noOfMonthDays(month,year);

	printCalender(firstDay,monthDays);
	
	printf("\n\n");
	return 0;
}

int readNumber(const char* prompt){
	
	int number;
	
	printf(" %s",prompt);
	scanf(" %d",&number);

	return number;
			
}

int noOfMonthDays(int month,int year){
	
	if(year%4==0){
		
		if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
			return 31;
		
		else if(month==2)
			return 29;
			
		else
			return 30;		
	}
	else{
		
		if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
			return 31;
		
		else if(month==2)
			return 28;
			
		else
			return 30;	
	}
}

int firstDayOfMonth(int month,int year){
	
	
  time_t rawtime;
  struct tm * timeinfo;
  
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  timeinfo->tm_year = year - 1900;
  timeinfo->tm_mon = month - 1;
  timeinfo->tm_mday = 1;

  mktime ( timeinfo );

  return timeinfo->tm_wday;
} 
void printCalender(int firstDay,int monthDays){
	
	int index;
	
	printf("\n Su Mo Tu We Th Fr Sa");
	printf("\n======================\n");
	
	for(index = 0 ; index<firstDay; index++)
        printf("   ");
    
	 for(index = 1; index <=monthDays;index++) {
        
		printf("%3d", index);
    		firstDay = (firstDay + 1) % 7;

    		if(firstDay == 0)
        		printf("\n");
    }
    printf("\n======================\n");
}


