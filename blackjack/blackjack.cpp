#include<iostream>
#include<ctime>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<vector>
using namespace std;

void play21(void);

int dealCards(int, string);

void hit(int &);

void determineWinner(int, int);

int Random(int, int);
int pot;
int bet;
int count = 0;
int deposit;
string name;
int main(){
  char choice;
  char keepPlaying = 'y'; 
 do {

   play21();

   cout << "Another round (Y/N)? Or enter 'D' to add funds..."<<endl;
   cin >> choice;
   if (choice == 'D' || choice == 'd') {
     cout << "How much to deposit?" <<endl;
     cin>>deposit;
     pot+=deposit;
     cout<< "Sucessfully deposited $"<<deposit<<endl;
     cout<< "Current pot: $"<<pot<<endl;
   }
   if(pot <= 0) {
     cout<<"Ut oh! It looks like you are out of funds!" <<endl;
     cout<<"Please add to bankroll immediately: ";
     cin>>deposit;
     pot+= deposit;
 cout<< "Sucessfully deposited $"<<deposit<<endl;
     cout<< "Current pot: $"<<pot<<endl;
   }

 }
 while(choice == 'Y' || choice  == 'y'|| choice == 'd' || choice == 'D');

}

void play21(void){ 

  if(count == 0) {
    cout<<"--------------------------------------------"<<endl;
    cout<<"Welcome to BlackJack! What is your name?" <<endl;
    cout<<"--------------------------------------------"<<endl;
    cin>>name;
    cout<< name<<", how much money to add to bankroll?"<<endl;
    cin>>pot;
  }
  srand((int) time(0));
  
  cout<< "How much would you like to bet on this hand, "<<name<<"?" <<endl;
  cin>>bet;
  if (bet > pot) {
    cout<<"You can't bet more than what's in the pot ("<<pot<<"), try again:";
  cin>>bet;
  }
  

  int house = dealCards(2, "Dealers Cards:");

  cout << " = " << house << endl;
  
int person = dealCards(2, "Your Cards:");

  cout <<" = " << person << endl; 
  cout<<endl;
  hit(person);

  cout << endl;
  

  while ((house < person) && (house <= 21) && (person <= 21)) {

    house += dealCards(1,"The Dealer takes a card ");

    cout << endl;

  }


  determineWinner(person, house);
  count++;

}

 

void determineWinner(int humanScore, int houseScore) { 

  cout <<"Your Score: " << humanScore << endl;

  cout <<"Dealer Score: " << houseScore << endl;

  if (humanScore == houseScore){

    cout << "Tie"<<endl; 
  bet = 0;
  }

  if ((humanScore == 21 || humanScore >= houseScore || houseScore > 21) && (humanScore <= 21)){
    
cout<<"--------------------------------------------"<<endl;
    cout <<"You Won $"<<bet*2<<"!"<<endl;
  pot += bet*2;
  bet = 0;
  cout<<"Current pot: $"<<pot<<endl;
cout<<"--------------------------------------------"<<endl;

  }
  else{

cout<<"--------------------------------------------"<<endl;
    cout <<"You Lost $"<<bet<<"!"<<endl;
    pot -= bet;
  cout<<"Current pot: $"<<pot<<endl;
cout<<"--------------------------------------------"<<endl;
  }

}

int dealCards(int numberOfCards, string message){ 

  int cardDealt = 0; 

  int totalValue = 0;

  cout << message <<" "; 

  for (int i = 1 ; i <= numberOfCards ; i++){ 

    cardDealt = Random(1, 10);

    totalValue += cardDealt;

    vector<string> faceCards = {"J","Q","K","10"};

    if (cardDealt == 10 ) {
      srand(time(NULL));
      int randomNum = rand()%4;
      string tempCard = faceCards.at(randomNum);
      cout<<tempCard<<" ";
    }
    else {
      cout << cardDealt <<" ";
    }

  }
 
  return totalValue;

}

void hit(int &playerScore){ 

  char takeHit = 'Y'; 

  while (takeHit != 'S') { 

    if (playerScore < 21) { 

      cout <<"Hit or Stay (H/S)? ";

      cin >> takeHit;
      if (takeHit == 'H' || takeHit == 'h'){ 

	playerScore += dealCards(1,"Hit: ");
	cout<<endl;
	cout <<"Your total is " << playerScore << endl;

      }
      else 

	takeHit ='S';

    }
    else { 
      cout<<endl;
      cout <<"You Busted!"<<endl;
      takeHit ='S';

    }

  }

}

int Random(int lowerLimit, int upperLimit) {

//returns a random number within the given boundary
  return 1 + rand() % (upperLimit - lowerLimit + 1);

}
