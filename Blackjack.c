#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>


int shuffle(int cards[])
{
	
	int i2, i;
	int deckCards[52];
		
		for (i=0;i<52;i++){
			deckCards[i] = ( i / 13 + 3)* 100 + i % 13 + 1;														  
		}
		
	srand(time(NULL));
	
		for (i = 0; i < 52; i++)
		{
			do{
				i2 = rand() % 52;
				
			}while (deckCards[i2] == 0);
			
			cards[i] = deckCards[i2];
			deckCards[i2] = 0;
		}

}

int converterJQK(int a)
{
		if ((a % 100 == 11) ||(a % 100 == 12) ||(a % 100 == 13)){
			return (a / 100)* 100 + 10;
			
		} 
		
		else{
			return a;
			
		} 
}

void picCards(int num)
{
	char suit;
	int numCard;
	
		suit = num / 100;
		numCard = num % 100;
		
		switch (numCard)
		{
			default:
			{
				printf("\t\t\t\t\t\t _____________\n");          
				printf("\t\t\t\t\t\t|             |\n");         
				printf("\t\t\t\t\t\t|  %c          |\n", suit);
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|     %2d      |\n", numCard);
				printf("\t\t\t\t\t\t|             |\n");			
				printf("\t\t\t\t\t\t|             |\n");    
				printf("\t\t\t\t\t\t|         %c   |\n", suit);	
				printf("\t\t\t\t\t\t|_____________|\n");
				break;
			}
			
			case 1: 
			{
				printf("\t\t\t\t\t\t _____________\n");          
				printf("\t\t\t\t\t\t|             |\n");         
				printf("\t\t\t\t\t\t|  %c          |\n", suit);
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|      A      |\n", numCard);
				printf("\t\t\t\t\t\t|             |\n");			
				printf("\t\t\t\t\t\t|             |\n");    
				printf("\t\t\t\t\t\t|         %c   |\n", suit);	
				printf("\t\t\t\t\t\t|_____________|\n");
				break;
			}
			
			case 11:
			{
				printf("\t\t\t\t\t\t _____________\n");          
				printf("\t\t\t\t\t\t|             |\n");         
				printf("\t\t\t\t\t\t|  %c          |\n", suit);
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|      J      |\n", numCard);
				printf("\t\t\t\t\t\t|             |\n");			
				printf("\t\t\t\t\t\t|             |\n");    
				printf("\t\t\t\t\t\t|         %c   |\n", suit);	
				printf("\t\t\t\t\t\t|_____________|\n");
				break;
			}
			case 12:
			{
				printf("\t\t\t\t\t\t _____________\n");          
				printf("\t\t\t\t\t\t|             |\n");         
				printf("\t\t\t\t\t\t|  %c          |\n", suit);
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|      Q      |\n", numCard);
				printf("\t\t\t\t\t\t|             |\n");			
				printf("\t\t\t\t\t\t|             |\n");    
				printf("\t\t\t\t\t\t|         %c   |\n", suit);	
				printf("\t\t\t\t\t\t|_____________|\n");
				break;
			}
			case 13:
			{
				printf("\t\t\t\t\t\t _____________\n");          
				printf("\t\t\t\t\t\t|             |\n");         
				printf("\t\t\t\t\t\t|  %c          |\n", suit);
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|             |\n");
				printf("\t\t\t\t\t\t|      K      |\n", numCard);
				printf("\t\t\t\t\t\t|             |\n");			
				printf("\t\t\t\t\t\t|             |\n");    
				printf("\t\t\t\t\t\t|         %c   |\n", suit);	
				printf("\t\t\t\t\t\t|_____________|\n");
				break;
			}
	
		}
}

int Rules(void)
{
	char y;
	
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\t - The player and the computer initially receive two cards each.\n");	
		printf("\t - The player start the game deciding whether to stay with two cards, or draw more cards,"); 
		printf("\n\t  in an attempt to reach the maximum points, as long as it is less than or equal to 21.");
		printf("\n\t - When the player passes, the computer plays the same way, trying to reach the best score.");
		printf("\n\t - Each player can accumulate a maximum of 5 cards in their hand and whenever someone maxes out at 21 points,");
		printf("\n\t  the opponent wins");
		printf("\n\n\t  Press y to go back: ");
		
		y = getchar();
		
	}while(y != 'y');
}

int Menu(void)
{
	int i, c=0;
	int sumPlayer=0;
	int sumComputer=0;
	int cardsPlayer[5]={0};
	int cardsComputer[5]={0};
	int cards[52];
	char start;
	static bool once = false;
	
	if(once == false){	
		once = true;
		do{				
				printf("\n\n\n\n");  						
				printf("\t\t\t\t\t _____________________________________\n");          
				printf("\t\t\t\t\t|                                     |\n");
				printf("\t\t\t\t\t|             Welcome to,             |\n");         
				printf("\t\t\t\t\t|              Blackjack              |\n");		
				printf("\t\t\t\t\t|_____________________________________|\n");			
				printf("\t\t\t\t\t|                                     |\n");     			
				printf("\t\t\t\t\t|                                     |\n");
				printf("\t\t\t\t\t|     1.   Player vs Computer         |\n"); 	
				printf("\t\t\t\t\t|     2.        Rules                 |\n"); 							 						                                  				                
				printf("\t\t\t\t\t|                                     |\n"); 						
				printf("\t\t\t\t\t|                                     |\n"); 							   
				printf("\t\t\t\t\t|                                     |\n"); 
				printf("\t\t\t\t\t|                                     |\n"); 
				printf("\t\t\t\t\t|          Choose a Gamemode          |\n"); 								
				printf("\t\t\t\t\t|  Press the number and Enter key...  |\n"); 	
				printf("\t\t\t\t\t|                                     |\n");
				printf("\t\t\t\t\t|                                     |\n");   	
				printf("\t\t\t\t\t|_____________________________________|\n"); 
			
			printf("\n\t\t\t\t\t    Created by: Paulo Eduardo Grazia\n"); 	
			
			start = getchar();		
			
			if(start != '1'){
				system("cls");
			}
			
			if(start == '2'){
				Rules();
			}
			
							
		}while (start != '1');
		
	}

	system("cls");
	printf("\n");
	
	shuffle(cards);
	
	system("color 09");

	cardsPlayer[0]=cards[0];
	cardsPlayer[1]=cards[1];
	cardsComputer[0]=cards[2];
	cardsComputer[1]=cards[3];
	

	printf("\n\t\tCards of your Opponent\n");
	picCards(cardsComputer[0]);
	picCards(cardsComputer[1]);
	
	printf("\n");
	
	printf("\n\t\tThis is your Cards\n");
	picCards(cardsPlayer[0]);
	picCards(cardsPlayer[1]);

	
		i=0;
		for (i=0; i<2; i++){
			
			if(converterJQK(cardsPlayer[i]) % 100 == 10){
				sumPlayer = sumPlayer + 10;
				
			} 
			
			else{
				sumPlayer = sumPlayer + cardsPlayer[i]%100;
				
			} 
					
		}
	
		printf("\n\t\tThe Sum of your Cards are:%d\n\n",sumPlayer);
	
		i=0;
		for (i=0; i<3; i++)
		{
			char j = 'y';
			
			printf("\n\t\t\tDo you want one more Card? Press y for Yes or n for No: ");
			
			do{				
				j = getchar();
				
			}while (j!='y' && j!='n');
			
			if (j=='y')
			{
				
				printf("\n\n\n\n\t\tYou picked up one more Card, Now you have: %d cards\n", i+3);
				cardsPlayer[i+2]=cards[i+4];
				
				printf("\n\t\tThis is the Card you picked up: \n");
				picCards(cardsPlayer[i+2]);		
				
				if (sumPlayer > 21){
				
					system("color 04");
					
					printf("\n\t\tThe Sum of your Cards are:%d\n\n",sumPlayer);
					printf("\n\t\tYour opponent Won, Good Luck Next Time!\n");
					return 1;
				}
							
				else if(converterJQK(cardsPlayer[i+2]) %100 ==10){
					sumPlayer = sumPlayer + 10;
					
					printf("\n\t\tThe Sum of your Cards are:%d\n\n",sumPlayer);
					
					if (sumPlayer > 21){
					
						system("color 04");
						
						printf("\n\t\tYour opponent Won, Good Luck Next Time!\n");
						return 0;
					}
				} 
				
				if(sumPlayer < 21 && converterJQK(cardsPlayer[i+2]) %100 !=10)
					
					sumPlayer = sumPlayer + cardsPlayer[i+2]%100;	
					
					printf("\n\t\tThe Sum of your Cards are:%d\n\n",sumPlayer);
				} 														
			
			
			else
			{
				if (sumPlayer > 21){// Verifica se as cards pegadas passam de 21
					printf("\n\n\n\t\tThe Sum of your Cards are:%d\n\n",sumPlayer);
					system("color 04");
					printf("\n\n\t\tYour opponent Won, Good Luck Next Time!\n");
					
					return 0;
				}
				
				break;
				
			}
			
		}
	
	printf("\n\n|--------- Opponent's turn");
	
		i=0;
		for (i=0; i<2; i++)
		{	
		
			if (sumPlayer > 21){
				
					printf("\n\n\n\t\tThe Sum of your Cards are:%d\n\n",sumPlayer);
					system("color 04");
					printf("\n\n\t\tYour opponent Won, Good Luck Next Time!\n");
					
					return 0;
			}
				
			if(sumPlayer == sumComputer && sumComputer > 17){
				system("color 07");
				printf("\n\t\tDraw!\n");
				return 0;
			}
			
			if(converterJQK(cardsComputer[i]) % 100 == 10){
					sumComputer = sumComputer + 10;
			} 
				
				else{
					sumComputer = sumComputer + cardsComputer[i]%100;
				} 
				
			if (sumPlayer < sumComputer)
			{
				system("color 04");
				printf("\n\n\t\tYour opponent Won, Good Luck Next Time!\n");
				return 0;
			}	
				
		}
		
			
		i=0;
		for (i=0; i<3 && sumComputer<19; i++)
		{
			printf("\n\n\n\n\t\tHe picked up a Card, Now He has: %d cards\n", i+3);
			cardsComputer[i+2]=cards[i+7];
			
			printf("\n\t\tThis is the Card He picked up: \n");
			picCards(cardsComputer[i+2]);
			
			sumComputer = sumComputer + converterJQK(cardsComputer[i+2])%100;
			printf("\n\t\tThe Sum of his Cards are:%d\n\n", sumComputer);
	
			
			if (sumComputer>21){
			
				system("color 02");
				printf("\n\t\tYour opponent passed the value of 21, You Won!\n");
				return 0;
			}
			
			else if (sumPlayer == sumComputer){
				system("color 07");
				printf("\n\t\tDraw!\n");
				return 0;
			}
			
			else if (sumPlayer < sumComputer){
			
				system("color 04");
				printf("\n\t\tYour opponent Won, Good Luck Next Time!\n");
				return 0;
			}		
		}
				
}


int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	char repeat;
	
	
	Menu();
  	
		printf("\n\n\n\n\t\tDo You want to play again? Press y for Yes or n for No: ");
		
		do{
			repeat = getchar();
			
		} while (repeat!='y' && repeat!='n');
	   
	   	if(repeat == 'y'){
	   		
		   	system("cls");
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading...\n\n");		
			sleep(2);
			system("cls");
			main();		
		}
	   
		else if (repeat == 'n'){
			system("cls");
			printf("\n\n\n\n\t\tDo you really want to close the Game? Press y for Yes or n for No: ");
			
			do{
			repeat = getchar();
			
			} while (repeat!='y' && repeat!='n');
		
			if(repeat == 'y'){
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tThanks for playing :)\n\n");
			
				sleep(2);
				system("cls");
			}
			
			else if (repeat == 'n'){
				
				system("cls");
				printf("\n\n\n\n\t\tDo You want to play again? Press y for Yes or n for No: ");
		
				do{
					repeat = getchar();
					
				} while (repeat!='y' && repeat!='n');
				
					if(repeat == 'y'){
	   		
					   	system("cls");
						printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading...\n\n");		
						sleep(2);
						system("cls");
						main();		
					}
					
					if(repeat == 'n'){
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tThanks for playing :)\n\n");
			
						sleep(2);
						system("cls");
					}
			}
		}

	return 0;
}
