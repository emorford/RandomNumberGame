//Emily Morford
//5-9-17
//Random number game
//Cis230

//#include <iomanip>  //not needed? precision , width
#include <cstdlib>  //for rand and srand
#include <ctime>  //for time function
#include <string>  //for strings
#include <iostream>
using namespace std; //needed for?

void guessNumber (int , int *, string *, int *);
int generateRandom(int *);
void getName(string *);
void displayWinner(string *, string *, int *, int *);
void displayMenu(int &);  //reference function
void pickMax (int *);

int main ()

{
//variables
int random1, random2; //to hold the random numbers generated
int guess1, guess2;  // guess counters
string name1, name2;   //to hold players names
int choice;  //for menu choice
int max;   //to hold maximum value

//get the system time
unsigned seed = time (0);

//seed the random number generator
srand(seed);

do
{
	//function call to choose menu option
	displayMenu(choice);
	
	switch(choice)
{	
	case 1:   //one player game
	
		//function call to choose maximum number
		pickMax (&max);
	
		// function call to generate random number
		random1=generateRandom(&max);
		cin.ignore(100,'\n');
		
		//function call to get first persons name 
		getName(&name1);
		
		//function call for person1 to guess the number
		guess1=1;
		guessNumber (random1, &guess1, &name1, &max);
		cout <<"You guessed the number "<<random1<<" in "<<guess1<< " tries, "<< name1<<"!\n"<<endl;
		break;
	
	case 2:   //two player game	
	
		//function call to choose maximum number
		pickMax (&max);
	
	 	// function call to generate random numbers
		random1=generateRandom(&max);
		random2=generateRandom(&max);
		cin.ignore(100,'\n');
		
		//function call to get first persons name 
		getName(&name1);
		
		//function call for person1 to guess the number
		guess1=1;
		guessNumber (random1, &guess1, &name1, &max);
		cout <<"You guessed the number "<<random1<<" in "<<guess1<< " tries, "<< name1<<"!\n"<<endl;
		cin.ignore(100,'\n');
		
		//function call to get second persons name 
		getName(&name2);
		
		//function call for person2 to guess the number
		guess2=1;
		guessNumber (random2, &guess2, &name2, &max);
		cout <<"You guessed the number "<<random2<<" in "<<guess2<< " tries, "<< name2<<"!\n"<<endl;
		
		//function call to display winner
		displayWinner(&name1, &name2, &guess1, &guess2);
		break;

	case 0:
		cout<<"\t\t\tPlay The Random Number Game again soon!\n"<<endl;
		cout<<"\t\t\tGood Bye!!"<<endl;
		break;
}
		
}
while ((choice == 1)||(choice ==2));

	return 0;
}

void guessNumber (int random, int *guess, string *name, int *max)
{
	int number;   //number that is guessed
	
//initial guess
cout <<"\n"<<*name<<", guess your number from 1 to "<< *max <<". \n";
cin >> number;

//confirm that initial guess is within range
		if ((!(number>=1))||(!(number<=*max))){
				do 
					{
					cout <<"The number you enter must be at least 1 and at most most "<<*max <<". \n";	
					cin >> number;
					}
				while (!((number>=1)&&(number<=*max)));}

		//does the guess match the random number?
		if(number==random )
		//if so: congrats
		cout <<"Yay! You guessed the number on your first guess!" <<endl;
		
		//if not:
		else{
				while (number != random){
				//if guess is too high:
					if (number > random ){
							cout <<"Your guess " <<number<< " is too high. Please guess again!\n";
							cin >> number;
							
							//data validation:
							if ((!(number>=1))||(!(number<=*max))){
									do {
										cout <<"Your guess must be at least 1 and at most "<<*max<< ". \n";	
										cin >> number;}
									while (!((number>=1)&&(number<=*max)));
									}
									//increment counter	
									(*guess)++;
									//cout <<*guess<<endl;	
    				}
    			//if guess is too low:			
					else { // (number < random1 )
							cout <<"Your guess " <<number<< " too low. Please guess again!"<<endl;
							cin >> number;
							
							//data validation:
							if ((!(number>=1))||(!(number<=*max))){
									do {
										cout <<"Your guess must be at least 1 and at most "<<*max <<". \n";	
										cin >> number;}
									while (!((number>=1)&&(number<=*max)));
									}
									//increment counter	
									(*guess)++;									
					}
				}

		}
}

int generateRandom(int *max)
{
	int random;  //to hold random number
	//constant to generate minimum
	const int MIN =1;  //min=1
	
	//calculate random number based on 1 as min and given number as max
	random =(rand()%(*max -MIN +1)+MIN);
	return random;	
}

void getName(string *name)	
{
	cout <<"\nPlease enter your name:\t";	
	getline(cin,*name);		
}
	
void displayWinner(string *name1, string *name2, int *guess1, int *guess2)
{
	
	if (*guess1>*guess2)
			cout <<"\n\n"<<*name2<< ", you are the winner!!!"<<endl;
	else if (*guess1<*guess2)	
		cout <<"\n\n"<<*name1<< ", you are the winner!!!"<<endl;
	else
		cout <<"\n\nTie game!!"<< *name1<<" and " <<*name2<<" you are both winners!!"<<endl;
}	

void displayMenu(int& choice)
{
cout <<"\n\t\t\tTime to play.....The Random Number Game\n" <<endl;
cout<< "\t\t\t1: One player game\n"<<endl;
cout<< "\t\t\t2: Two player game\n"<<endl;
cout<< "\t\t\t0: Exit \"The Random Number Game\"\n"<<endl;
cout<< "\t\t\tPlease enter your choice:\n"<<endl;
cin>>choice;


if ( (choice < 0)||(choice >2)){
				do 
					{
					cout<< "Please enter 0, 1 or 2"<<endl;
					cin>>choice;	
					}
			while ((choice < 0)||(choice >2));}
			//	while ( (!(*choice==0))||(!(*choice==1))||(!(*choice==2)));}	     why not???	  should have been &&
}

void pickMax (int *max)
{
	cout <<"\n\t\t\tThe number 1 is the minimum number for all games\n" <<endl;
	cout <<"\n\t\t\tEnter your maximum number, from 10 to 100\n" <<endl;
	cin >>*max;
}


	
	
	
