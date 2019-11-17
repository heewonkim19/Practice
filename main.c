/* practice */ 
#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30


//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag


//card processing functions ------------------------------------------------------------------------------------------------------------------------------------------------
// 계산할 때 사용 
//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
	 
	if (cardnum <= 9)
		cardnum += 1;
	else if (cardnum >= 13 && cardnum <= 22)
		cardnum %= 12;
	else if (cardnum >= 26 && cardnum <= 35)
		cardnum %= 25;
	else if (cardnum >= 39 && cardnum <= 48)
		cardnum %= 38;
	else 
		cardnum = 10;
		
	return cardnum;
}
	
// 만약 이 함수를 int 형으로 선언한다면 모양들을 숫자로 설정하고 뒤에서 나머지로 모양을 프린트 해주는 것인가? 
//print the card information (e.g. DiaA)
void printCard(int cardnum) {

	switch (cardnum)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		if (cardnum==0)
			printf(" Hart A ");
		else if (cardnum==10)
			printf (" Hart J ");
		else if (cardnum==11)
			printf(" Hart Q ");
		else if (cardnum==12)
			printf(" Hart K ");	
		else	
			printf(" Hart %d ",cardnum+1);
		break;
		
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		if (cardnum==13)
			printf(" Dia A ");
		else if (cardnum==23)
			printf(" Dia J ");
		else if (cardnum==24)
			printf(" Dia Q ");
		else if (cardnum==25)
			printf(" Dia K ");
		else
			printf(" Dia %d ",cardnum%12);
		break;	
		
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
		case 32:
		case 33:
		case 34:
		case 35:
		case 36:
		case 37:
		case 38:
		if (cardnum==26)
			printf(" Spade A ");
		else if (cardnum==36)
			printf(" Spade J ");
		else if (cardnum==37)
			printf(" Spade Q ");
		else if (cardnum==38)
			printf(" Spade K ");
		else
			printf(" Spade %d ", cardnum%25);
		break;
		
		case 39:
		case 40:
		case 41:
		case 42:
		case 43:
		case 44:
		case 45:
		case 46:
		case 47:
		case 48:
		case 49:
		case 50:
		case 51:
		if (cardnum==39)
			printf(" Club A ");
		else if (cardnum==49)
			printf(" Club J ");
		else if (cardnum==50)
			printf(" Club Q ");
		else if (cardnum==51)
			printf(" Club K ");
		else
			printf(" Club %d ",(cardnum%12)-2);
		break;	
		
		}	
}


// 이함수로 먼저 cardnum 가 들어와서 작용한 후 getcardnum의 함수로 들어가 실제 숫자를 출력 
	
//card array controllers -------------------------------------------------------------------------------------------------------------------------------------- 
//mix the card sets and put in the array
void mixCardTray(void) {

	int i, j;
	int temp;
	
	for (i=0; i<N_CARDSET*N_CARD; i++)
	{
		CardTray[i]=i;
	}
	
	for (j=0; j<N_CARDSET*N_CARD; j++)
	{
		int k = rand()%(N_CARDSET*N_CARD);
		temp = CardTray[j];
		CardTray[j] = CardTray[k];
		CardTray[k] = temp;
	}
 
}


//playing game functions -----------------------------

//player settiing
int configUser(void) {

	do{
	printf("input the number of player(Max:5): ");
	scanf("%d", &n_user);
	}while(N_MAX_USER < n_user);
	
	return n_user;
}


//betting
void betDollar(void) {

	int i;
	
	printf("\n\n----------------BETTING STEP-----------------\n");
	printf("-> Your betting(total: %d)", dollar[0]); //This is user's betting(Player 0) 
	scanf("%d", &bet[0]);
	dollar[0]-=bet[0];
	
	for (i=1; i<n_user; i++) // This is computer players 
	{
		bet[i] = 1+(rand()%N_MAX_BET);
		printf("-> player%d's betting: %d(out of %d)\n", i, bet[i], dollar[i]);
		
		if (dollar[i] == 0)
			gameEnd = 1;
	}
}

//get one card from the tray
int pullCard(void) {
 
	int pull_card;  
	
	pull_card = CardTray[cardIndex];
	cardIndex++;
	
	if (cardIndex >= 48)
		gameEnd = 1;
	
	return pull_card;	
}


//offering initial 2 cards
void offerCards(void) {
	int i;
	//1. give two card for each players
	for (i=0;i<n_user;i++)
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
	}
	//2. give two card for the operator
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] = pullCard();
	
	return;
}

//print initial card status
void printCardInitialStatus(void) {
   
   int i;

    printf("-> dealer: X ");
	printCard(cardhold[n_user][1]);

	printf("\n-> you: ");
	printCard(cardhold[0][0]);
	printCard(cardhold[0][1]);
   
	for(i=1; i<n_user-1; i++)
	{
	printf("\n-> player%d: ",i);
    printCard(cardhold[i][0]);
    printCard(cardhold[i][1]);
	}
	
   return;
}
int getAction(int user){
	
	int action;
	
	if (cardSum[user] <17)
	{
		action = 0;
		printf("\t ::: GO!");	
	}
	else
	{
		action = 1;
		printf("\t ::: STAY!");
	}
	
	return action;  
}


void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0; i<cardcnt; i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}

// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
void calcStepResult(int user, int cardcnt) {
	
	int i;
	int number;
	
	for (i=0; i<cardcnt; i++)
	{
		number = getCardNum(cardhold[user][i]);
		if(number == 1)
		{
			if (cardSum[user] <=10)
				number = 11;
			else 
				number = 1;
		}		
		cardSum[user] += number;	
			
	}
	if (i!= n_user)
	{
		if (cardSum[user] > 21)
		{
			printf("\t ::: DEAD (sum: %d)", cardSum[user]);
			dollar[user] -= bet[user];
			printf(" --> -$%d($%d)", bet[user], dollar[user]);
			cardSum[user]=0;
		}
		else if (cardSum[user] == 21)
			{
				if (cardcnt==2)
					{
					printf("\t ::: Black Jack Congratuation!");
					dollar[user] += (bet[user]*2);
					cardSum[user]=100;
					}
				else
					{
					printf("\t ::: ");
					}
			} 
	}
	else 
		{
		if(cardSum[user] > 21)
			{
			printf("\t ::: Dealer Dead (sum: %d)", cardSum[user]);
			cardSum[user] = 0;
			} 
		else if(cardSum[user] == 21)
			{
				if (cardcnt==2)
					{
					printf("\t ::: Black Jack"); // 이러한 경우에는 블랙잭이 아닌 모든 플레이어는 패배 
					cardSum[user] = 100;
					// 여기에 딜러가 블랙잭인 경우 해줘야할 듯 하지만 딜러가 블랙잭이고 다른 플레이어도 블랙잭인 경우도 생각해주어야 함.  
					}
				else 
					printf("\t ::: ");
			}
		}
}

void checkResult(void) { // 매개변수와 반환형 모두 내가 void로 바꾼것임.  
	
	int i, j;
	
	for (j=0; j<n_user; j++)
	{
		if (cardSum[j] < cardSum[n_user])
			cardSum[j]=0;	 		
	}

	for (i=0; i<=n_user; i++)
	{
		if (i==0)
		{
			if (cardSum[i]!=0)
				printf("\t -> Your result: win (sum : %d) --> $ %d", cardSum[i], dollar[i] + bet[i]);		
			else 
				printf("\t -> Your result: lose! --> $ %d", dollar[i]);
		}
		else if (i < n_user)
		{
			if (cardSum[i]!=0)
				printf("\t -> Player %d result: win (sum : %d) --> $ %d", i, cardSum[i], dollar[i] + bet[i]);
			else 
				printf("\t -> Player %d result: lose --> $ %d", dollar [i]);
		}
		else 
		{
			if (cardSum[i]!=0)
				printf("\t -> Dealer result: win ");
		}
	}
 
	// 딜러가 0이라면 0이 아닌 모두가 승리
}	

void checkWinner(void) {

		int max, i;
		int winner;
		max = dollar[0];
		for(i=1; i<n_user; i++)
		{
			if (dollar[i] > max)
				{
				max=dollar[i];
				winner=i;
				}
		
		}
		printf("Final Winner is %d", winner);
		
}

int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int i;
	int action = 0;
	int cardcnt = 2;
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	max_user = configUser(); // 맞는지 확인ㅎㅐ 
	
	//Game initialization --------
	//1. players' dollar	
	for(i=0; i<max_user; i++)
	{
		dollar[i] = N_DOLLAR;
	}
	
	//2. card tray
	mixCardTray();

	//Game start --------
	do{
		printf("\n---------------------------------------------------------------\n");
		printf("-----------------------ROUND%d(cardIndex: %d)-----------------------", roundIndex, cardIndex);
		printf("\n----------------------------------------------------------------\n");
		
		betDollar();
		offerCards(); //1. give cards to all the players
		
		printf("\n---------------------CARD OFFERING--------------------------------\n");
		printCardInitialStatus();
	
		printf("\n---------------------- GAME start -------------------------------\n");
		
		//each player turn
		for (i=0; i<=n_user; i++)
		{
			if (i==0)
			{
				printf(">>>>My turn!----------------------------------\n");
				do{
					printUserCardStatus(i, cardcnt);
					printf("\t ::: Action?(0-Go, other integer-Stop)");
					scanf("%d", &action);
					if (action == 0)		
					{
						cardhold[0][cardcnt] = pullCard();
						cardcnt++;
						calcStepResult(i, cardcnt);
					}
					else 
						break;			
				} while (action == 0);	
			}
			else if (i == n_user)
			{
				cardcnt = 2;
				action = 0;
				printf(">>>> Dealer turn!---------------------------------\n");
				while (action == 0) //do until the player dies or player says stop
				{
					printUserCardStatus(i, cardcnt);
					calcStepResult(i, cardcnt);
					action = getAction(i);
					if (action == 0)
					{
						cardhold[i][cardcnt] = pullCard();
						cardcnt++;					
					}	
				}
			}
			else
			{
				cardcnt = 2;
				action = 0;
				// playr turn
				printf(">>>>Player%d turn!-----------------------------\n", i);
				while (action == 0) //do until the player dies or player says stop
				{
					printUserCardStatus(i, cardcnt);
					calcStepResult(i, cardcnt);
					action = getAction(i);
					if (action == 0)
					{
						cardhold[i][cardcnt] = pullCard();
						cardcnt++;					
					}				
				}
			}
			//check if the turn ends or not xxxxxxx
		}		
		//result
		printf("-----------------------------ROUND %d result-----------------------------------", roundIndex);
		checkResult();
		
	} while (gameEnd == 0);
	checkWinner();
	// printf("Final winner")
	
	return 0;
}
