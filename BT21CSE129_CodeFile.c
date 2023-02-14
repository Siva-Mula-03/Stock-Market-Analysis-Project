#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX_SIZE 1024
#define true 1
#define false 0
struct date
{
    int day;
    int month;
    int year;
}; 

typedef struct 
{
    float open_price;
    float high_price;
    float low_price;
    float close_price;
    float volume;
    char Present_date[20];
} Stock;
//Stock A;
//a.open_prize=1;


typedef struct {
    char name[50];
  	struct   date start_date ;
    struct date end_date;
    int no_of_days;
    Stock stock[MAX_SIZE];
}company;
company data[10];


int no_of_days( struct date date1, struct  date date2 )

{
	//struct date date1;
	//struct date date2;
//printf("This is a programme to find the number of days between two dates!\n");

    //printf("\nEnter first date (dd mm yyyy): ");
   // scanf(" %i%i%i", &date1.day, &date1.month, &date1.year);
      int   month = date1.month;
       int  year = date1.year;

   int  duration1 = date_Elapsed (date1);

    //printf("\nEnter second date (dd mm yyyy): ");
    //scanf(" %i%i%i", &date2.day, &date2.month, &date2.year);
     month = date2.month;
       year = date2.year;

    int duration2 = date_Elapsed (date2);

   int  diff = duration2 - duration1;
  return diff;
    
}
int number_of_Days (struct date d)
{
    int days;
    int  is_Leap_Year (struct date d);
    const int days_Per_Month[13] = {0, 31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31};

    if (is_Leap_Year (d) == true && d.month == 2)
    {
        days = 29;
    }
    else
    {
        days = days_Per_Month[d.month];
    }
    return days;
}
int is_Leap_Year (struct date d)
{
    int leap_Year_Flag;

    if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0))
    {
        leap_Year_Flag = true;
    }
    else
    {
        leap_Year_Flag = false;
    }
    return leap_Year_Flag;
}
int year_Func (int month, int year)
{
    int yrRet;
    yrRet = (month <= 2) ? (year - 1) : (year);
    return yrRet;
}

// Function to find g in formula
int month_Func (int month)
{
    int mntRet;
    mntRet = (month <= 2) ? (month + 13) : (month + 1);
    return mntRet;
}

int date_Elapsed (struct date d)
{
    int number_of_Days (struct date d);
    int is_Leap_Year (struct date d);
    int year_Func (int month, int year);
    int month_Func (int month);

    int yCalc, mCalc, nCalc;

    yCalc = year_Func (d.month, d.year);
    mCalc = month_Func (d.month);

    // Calculates number of elapsed days
    nCalc = ( ((1461 * (yCalc) / 4) + ((153 * (mCalc))) / 5) + d.day );

    if ((d.day < 1) && (d.month < 3) && (d.year < 1700))
    {
        printf("Invalid date input!\n");
        printf("Date must be from 1 March 1700.\n");
        exit (999);
    }
    else if (((d.day >= 1) && (d.month >= 3) && (d.year >= 1700)) && ((d.day <= 28) && (d.month <= 2) && (d.year <= 1800)))
 {
        nCalc = nCalc + 2;
    }
    else if (((d.day >= 1) && (d.month >= 3) && (d.year >= 1800)) && ((d.day <= 28) && (d.month <= 2) && (d.year <= 1900)))
    {
        nCalc = nCalc + 1;
    }
    else
    {
        return nCalc;
    }
}


void intialize_DB(company data [],int Size_of_array_of_structure, int maximumm_size)
{
	int i,j;
	for(i=0;i<10;i++)
	{
		data[i].name[0]='\0';
		data[i].start_date.day=0;
		data[i].start_date.month=0;
		data[i].start_date.year=0;
		data[i].end_date.day=0;
		data[i].end_date.month=0;
		data[i].end_date.year=0;
		data[i].no_of_days=0;
		for(j=0;j<maximumm_size;j++)
		{
			data[i].stock[j].open_price=0;
			data[i].stock[j].high_price=0;
			data[i].stock[j].low_price=0;
			data[i].stock[j].close_price=0;
			data[i].stock[j].volume=0;
			data[i].stock[j].Present_date[0]='\0';
		}
		
	}
}



void input(company data[],int maximum_size,char Naame[],struct date start_d,struct date end_d,int NO_OF_DAYS)
	{

//	printf("enter the data");
    int i=0,j=0,is_free_loc;
    int flag_variable=1;
    int ans=0;

   while(i<10&&flag_variable==1)
    {
    	is_free_loc=0;
    	
    	if(strcmp(data[i].name,Naame)==0)
    	{
    		is_free_loc=1;
		}
		
		else{
			i++;
			flag_variable=1;
		}
    if(is_free_loc==1)
	{
	
        strcpy(data[i].name,Naame);
        
		data[i].start_date=start_d;
        data[i].end_date=end_d;
        data[i].no_of_days=NO_OF_DAYS;
        
        for(j=0;j<data[i].no_of_days;j++)
        {
        	printf("value of J is %d\n",j);
            printf("Enter the data of %s of day %d\n", data[i].name,j+1);
            printf("Enter the open price of day %d \n",j+1);
            scanf("%f",&data[i].stock[j].open_price);
            printf("Enter the high price of day %d \n",j+1);
            scanf("%f",&data[i].stock[j].high_price);
            printf("Enter the low price of day %d \n",j+1);
            scanf("%f",&data[i].stock[j].low_price);
            printf("Enter the close price of day %d\n",j+1);
            scanf("%f",&data[i].stock[j].close_price);
            printf("Enter the volume of day %d \n  ",j+1);
            scanf("%f",&data[i].stock[j].volume);
            printf("enter the present date ");
            scanf("%s",data[i].stock[j].Present_date);
        
        } 
		flag_variable=0; 
     }
	
		     
    }
  

}



// first question .
void percentage_change_stock(company data [],char temp[])
{
	int i,j=0;
	float previous_closing;
	float closing;
	float ans=0;
	float count;
	float percentage_change;


	  
    while(i<10 )
    {
     if(strcmp(data[i].name,temp)==0)
		{
	
    	int count=data[i].no_of_days;
    	previous_closing=data[i].stock[0].close_price;
    	closing=data[i].stock[count-1].close_price;
       percentage_change =((closing-previous_closing)/previous_closing)*100;
        }
    	i=i+1;
	}
	printf("percentage change in stock of %s company is %f ",temp,percentage_change);

}


// second question
     void sorting_DB( company data1 [], char required_Date[])
     {
     	company temp [10];
     	company temp1;
     	int i,j,k=0;
     	int arr[10];
     	int flag=1;
    // searching records to be sorted  	
     	for(i=0;i<10;i++)
     	{
     		flag=1;
     		for(j=0;j<data1[i].no_of_days&&(flag==1);j++)
     		{
     			if(strcmp(data1[i].stock[j].Present_date,required_Date)==0)
     			  {
     			  strcpy(temp[i].name,data1[i].name);
     			  temp[i].stock[k]=data1[i].stock[j];
     			  flag=0;
     			 // k++;
				   }
			 }
		 }
     	
     	// sorting the obtained records
    for(k=1;k<10;k++)
    {
    	for(j=0;j<10-k;j++)
    	{
    		if(temp[j].stock[0].volume>temp[j+1].stock[0].volume)
    		{
    			/*temp1=temp[j].stock[0].volume;
    			temp[j].stock[0].volume=temp[j+1].stock[0].volume;
    			temp[j+1].stock[0].volume=temp1;*/
				temp1=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=temp1;

			}
    			
			
			else if(temp[j].stock[0].volume==temp[j+1].stock[0].volume)
			{
					if(temp[j].stock[0].close_price>temp[j+1].stock[0].close_price)
    		{
    			/*temp1=temp[j].stock[0].close_price;
    			temp[j].stock[0].close_price=temp[j+1].stock[0].close_price;
    			temp[j+1].stock[0].close_price=temp1;*/
				temp1=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=temp1;
			}
			}
			
    		
		}
	}
}
     
// third question	
   void profit_loss(company data[],char bought_date[],char sold_date[])  
   {
   	// for company 1
   	int j;
   	float profit=0;
   	float loss=0;
   	float first_price;
   	float last_price;
   	for(j=0;j<data[1].no_of_days;j++)
   	{
   		if(strcmp(data[1].stock[j].Present_date,bought_date)==0)
   		{
   			first_price=data[1].stock[j].low_price;
		   }
		  else if(strcmp(data[1].stock[j].Present_date,sold_date)==0) 
		  {
		  	last_price=data[1].stock[j].high_price;
		  }
		   
	   }
	   // if there is profit
   	if(last_price>first_price)
   	{
   		profit=(last_price)-(first_price);
	   }
   	else if(last_price<first_price)
   	{
   		loss=(first_price)-(last_price);
   		
	   }
	else
	   {
	   	profit=0;
	   	loss=0;
	   }
   	
   	printf(" profit is %f",profit);
   	printf("loss is %f",loss);
   
   	// for second company
   	float profit1=0;
   	float loss1=0;
   	float first_price1;
   	float last_price1;
   	for(j=0;j<data[2].no_of_days;j++)
   	{
   		if(strcmp(data[2].stock[j].Present_date,bought_date)==0)
   		{
   			first_price=data[2].stock[j].low_price;
		   }
		  else if(strcmp(data[2].stock[j].Present_date,sold_date)==0) 
		  {
		  	last_price=data[2].stock[j].high_price;
		  }
		   
	   }
	   // if there is profit
   	if(last_price1>first_price1)
   	{
   		profit1=(last_price1)-(first_price1);
	   }
   	else if(last_price1<first_price1)
   	{
   		loss1=(first_price1)-(last_price1);
   		
	   }
	   else
	   {
	   	profit1=0;
	   	loss1=0;
	   }
   	
   	printf(" profit is %f",profit1);
   	printf("Loss is %f ",loss1);
  
	   }
	   
//fourth question
void percentage_gain(company data[],char s_date[],char e_date[])	
{
	char stock_name[50];
	char temp[50];
	int i,j;
	int max=INT_MIN;
	int min=INT_MAX;
	int flag1=1;
	int flag=1;
	float starting_day_price;
	float ending_day_price;
	float Per_gain;
	for(i=0;i<10;i++)
	{
		strcpy(stock_name,data[i].name);
		for(j=0;j<data[i].no_of_days &&((flag==1)||(flag1==1));j++)
	{
		if(strcmp(data[i].stock[j].Present_date,s_date)==0)
	 {
		 	starting_day_price=data[i].stock[j].open_price;
		 	flag=0;
     }
     else if(strcmp(data[i].stock[j].Present_date,e_date)==0)
     {
     	ending_day_price=data[i].stock[j].close_price;
     	flag1=0;
     
	 }		
 }
    Per_gain=(((ending_day_price)-(starting_day_price))/(starting_day_price))*100;
    if(Per_gain>max)
    {
    	strcpy(temp,stock_name);
    	max=Per_gain;
	}

	}
         printf("the stock with maximum gain is %s and the maximum gain is   %f ",temp,max);
                                         
	   } 
	   
	   
	   
//fifth question 


void Percentage_gain(company data[],char s_date[],char e_date[])	
{
	char stock_name[50];
	char temp[50];
	int i,j;
	int max=INT_MIN;
	int min=INT_MAX;
	int flag1=1;
	int flag=1;
	float starting_day_price;
	float ending_day_price;
	float Per_gain;
	for(i=0;i<10;i++)
	{
		strcpy(stock_name,data[i].name);
		for(j=0;j<data[i].no_of_days &&((flag==1)||(flag1==1));j++)
	{
		if(strcmp(data[i].stock[j].Present_date,s_date)==0)
	 {
		 	starting_day_price=data[i].stock[j].open_price;
		 	flag=0;
     }
     else if(strcmp(data[i].stock[j].Present_date,e_date)==0)
     {
     	ending_day_price=data[i].stock[j].close_price;
     	flag1=0;
     
	 }		
 }
    Per_gain=(((ending_day_price)-(starting_day_price))/(starting_day_price))*100;
    if(Per_gain<min)
    {
    	strcpy(temp,stock_name);
    	min=Per_gain;
	}

	}
         printf("the stock with minimum gain is %s and the minimum gain is   %f ",temp,min);

	   }  
	   
	   
// sixth question 	   
void finding_overall_performance(company data[],int maxi_size)
{
      int i,j,k;
      company Temp;
	  float percentage_arr[10];
	  float percentage_change1=0;
	  float sum=0;
	  float maxi;
	  float previous_closing=0;
	  float percentage_change=0;
	  float closing=0;
	  for(i=0;i<10;i++)
	  {
		for(j=1;j<data[i].no_of_days;j++)
		{
              
    	previous_closing=data[i].stock[j-1].close_price;
    	closing=data[i].stock[j].close_price;
       percentage_change =((closing-previous_closing)/previous_closing)*100;
	   percentage_change1=(percentage_change)*(data[i].stock[j].volume) ;
	   sum=sum+percentage_change1;

		}
		percentage_arr[i]=sum;
	
	  }
	  //sorting the data base based on the overall performance
	   for(k=1;k<10;k++)
    {
    	for(j=0;j<10-k;j++)
    	{
    		if(percentage_arr[j]>percentage_arr[j+1])
    		{
				 Temp=data[j+1];
				data[j]=data[j+1];
				data[j+1]=Temp;
			}
		}
	}	
	// PRINTING THE RECORDS
	printf("THE STOCKS IN ASCENDING ORDER AS PER THE PERFORMANCE INDEX ");
	for(i=0;i<10;i++)
	{
		printf("%s",data[i].name);

	}  

}

// seventh question 

void average_value_of_all_stocks (company data[],int maxii_size)
{
   int i,j;
   float sum1=0;
   float sum2=0;
   float sum3=0;
   float avg;
   float final_average;
   float average_arr[10];
   for(i=0;i<10;i++)
   {
   	sum1=0;
   	sum2=0;
   	 for(j=0;j<data[i].no_of_days;j++)
   	 {
   	 	 sum1=sum1+ (data[i].stock[j].close_price)*(data[i].stock[j].volume);
   	 	 sum2=sum2+ (data[i].stock[j].volume);
   	 	 
		}
		avg=sum1/sum2 ;
		average_arr[i]=avg;
		
   }
   // finding the average value of all stocks 
   for(i=0;i<10;i++)
   {
   	sum3=sum3+average_arr[i];
   }
   final_average =sum3/10;
   printf("the required final average is %f \t",final_average);
}





  void main()
{
	int the_maximum_size=MAX_SIZE;
	int Size1=10;
     intialize_DB(  data, Size1,the_maximum_size);
  int NO_OF_DAYS;
  char Name[50];
  company data[10];
  char company1[50]="SBIN";
   strcpy(data[0].name,company1);
   char company2[50]="TATAMOTORS";
   strcpy(data[1].name,company2);
   char company3[50]="PNB";
   strcpy(data[2].name,company3);
   char company4[50]="YESBANK";
    strcpy(data[3].name,company4);
    char company5[50]="TECHM";
   strcpy(data[4].name,company5);
   char company6[50]="INFY";
   strcpy(data[5].name,company6);
    char company7[50]="TCS";
    strcpy(data[6].name,company7);
    char company8[50]="TITAN";
    strcpy(data[7].name,company8);
    char company9[50]="ONGC";
  strcpy(data[8].name,company9);
     char company10[50]="IOC";
    strcpy(data[9].name,company10);
    int i,j;
    struct date start_d;
    struct date end_d;
     float openPrice;
    float highPrice;
    float lowPrice;
    float closePrice;
    float Volume;
    char PresentDate;
    for(i=0;i<10;i++)
    {
    	strcpy(Name,data[i].name);
    	printf("\nEnter first date (dd mm yyyy): ");
       scanf(" %i%i%i", &start_d.day, &start_d.month, &start_d.year);
       printf("\nEnter last date(dd mm yyyy): ");
       scanf(" %i%i%i", &end_d.day, &end_d.month, &end_d.year);
       NO_OF_DAYS=no_of_days(start_d, end_d );
    	
    	input(data,MAX_SIZE,Name,start_d,end_d,NO_OF_DAYS);
    }
	
	
 //first question
 char Tempp[20];
 printf("please enter the name of company in upper case letters ");
 printf("enter the name of the company ");
 scanf(" %s ",Tempp);
 percentage_change_stock( data , Tempp);
 
	// second question  
  char required_Date[15];
  printf("enter the date required ");
  scanf("%s", required_Date);
  sorting_DB( data ,  required_Date);
    //third question
char bought_date[15];
char sold_date[15];
printf("enter the date on which stock is bought ");
scanf("%s",bought_date);
printf("enter the date on which stock is sold ");
scanf("%s",sold_date);
profit_loss( data,bought_date,sold_date);

	//fourth question   
char s_date[15];
char e_date[15];
printf("enter the starting date ");
scanf("%s",s_date);
printf("enter the ending date ");
scanf("%s",e_date);
percentage_gain( data, s_date, e_date);

  //fifth question
char s1_date[15];
char e1_date[15];
printf("enter the starting date ");
scanf("%s",s1_date);
printf("enter the ending date ");
scanf("%s",e1_date);
Percentage_gain(data, s1_date, e1_date);

// sixth question 
int The_maximum_size=MAX_SIZE;
finding_overall_performance( data, The_maximum_size);

	// seventh question 
	int maxiimum_size=MAX_SIZE;
    average_value_of_all_stocks(data,maxiimum_size);
    

}


