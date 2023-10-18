#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//prototype:
void Print_Status();
void print_Sensor_Set_Menu();
void Update_Engine_Speed();
void Update_AC_Status();
void Update_Engine_Ctrl_Status();


//global variables;
char choise;
char exit_flag1=0;
char exit_flag2=0;

char Engine_State[3] ;
char Traffic_Light_Color = '\0';
float  Room_Temperature  = 0;
char Engine_Temperature_Controller_State[3] = " ";
float  Engine_Temperature  = 0;
int  Vehicle_Speed  = 0;
char AC[3] ;   //AC -> Air Conditioner

int main ()
{
	while(!exit_flag1)
	{
		printf("\nHello in Vehicle Control System\n");
		printf("What do you want to do?\n\n");
		printf("1. Turn ON the vehicle engine\n");
		printf("2. Turn OFF the vehicle engine\n");
		printf("3. Quit the program\n\n");
		printf("Enter the number of your choise: ");
		scanf("%d",&choise);
		
		switch(choise)
		{
			case 1:	strcpy(Engine_State,"ON");
							printf("\nThe vehicle engine is ON Now\n");
							printf("--- Assumption --- \n");
							printf("--- Please enter the initial values to start tracking --\n");
							printf("enter the traffic light color (G/O/R): ");
							scanf(" %c",&Traffic_Light_Color);
							printf("enter the room temperature: ");
							scanf(" %f",&Room_Temperature);
							printf("enter the engine temperature: ");
							scanf(" %f",&Engine_Temperature);
							while(!exit_flag2)
							{								
								//FIXME:
								Update_Engine_Speed();
								Update_Engine_Ctrl_Status();
								Update_AC_Status();

								Print_Status();
								print_Sensor_Set_Menu();

								scanf("%d",&choise);
								switch(choise)
								{
									case 1:	exit_flag2 =1; 	
													break;
									case 2:	printf("enter the traffic light color (G/O/R): ");
													scanf(" %c",&Traffic_Light_Color);
													
													//FIXME:
													Update_Engine_Speed();
													Update_Engine_Ctrl_Status();
													Update_AC_Status();
											
													break;
									case 3: printf("enter the room temperature: ");
													scanf(" %f",&Room_Temperature);	
													
													//FIXME:
													Update_Engine_Speed();
													Update_Engine_Ctrl_Status();
													Update_AC_Status();
													
													break;
									case 4:	printf("enter the engine temperature: ");
													scanf(" %f",&Engine_Temperature);

													//FIXME:
													Update_Engine_Speed();
													Update_Engine_Ctrl_Status();
													Update_AC_Status();
													
													break;
									default:break;
								}
							}
					break;
			case 2:	strcpy(Engine_State,"OFF");
					printf("\nThe vehicle engine is OFF Now\n\n");	
					break;
			case 3:	printf("\nThanks for using our system\n\n");
					exit_flag1 =1; 	
					break;
			default:break;
		}		
	}		
	return 0;
}


void Print_Status()
{
	printf("\n---- Vehivle State ----\n");
	printf("Engine State: %s\n",Engine_State);
	printf("Air Conditioner: %s\n",AC);
	printf("Vehicle Speed: %d\n",Vehicle_Speed);
	printf("Room Temperature: %.2f\n",Room_Temperature);
	printf("Engine Temperature Controller State: %s\n",Engine_Temperature_Controller_State);
	printf("Engine Temperature: %.2f\n",Engine_Temperature);
}

//FIXME:
void Update_Engine_Ctrl_Status()
{

	if(choise == 2 && Vehicle_Speed==30)
	{
		strcpy(Engine_Temperature_Controller_State,"ON");
		Engine_Temperature = Engine_Temperature*(5/4)+1;
	}

	if(Engine_Temperature>=100 && Engine_Temperature<=150)
	{
		strcpy(Engine_Temperature_Controller_State,"OFF");
	}
	else
	{
		strcpy(Engine_Temperature_Controller_State,"ON"); 
		Engine_Temperature = 125;
	}

}

//FIXME:
void Update_AC_Status()
{
	if(choise == 2 && Vehicle_Speed==30)
	{
		strcpy(AC,"ON");
		Room_Temperature = Room_Temperature*(5/4)+1;
	}

	if(Room_Temperature>=10 && Room_Temperature<=30)
	{
		strcpy(AC,"OFF");
	}
	else
	{
		strcpy(AC,"ON"); 
		Room_Temperature = 20;
	}

}

void Update_Engine_Speed()
{
	switch(Traffic_Light_Color)
	{
		case 'G': Vehicle_Speed = 100;  break;
		case 'O': Vehicle_Speed = 30;	break;
		case 'R': Vehicle_Speed = 0;	break;
		default : break;
	}
}


void print_Sensor_Set_Menu()
{
	printf("\n--- Sensor set menu ---\n");
	printf("1. Turn OFF the engine\n");
	printf("2. Set the traffic light color\n");
	printf("3. Set the room temperature (temprature sensor)\n");
	printf("4. Set the engine temperature (enginr temprature sensor)\n");
	printf("\nEnter the number of your choise: ");
}					
