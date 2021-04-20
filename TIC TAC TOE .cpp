#include<iostream>

using namespace std;
char choice;
	char A[3][3] = {{'1','2','3'} , {'4','5','6'} , {'7','8','9'}} ;
	char turn='X';
	int r,c;
	bool draw=false;
	
	

/*

    //only for checking 
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"\t"<<A[i][j];
		}
		cout<<endl;
	}
*/
void display()
{
   //displaying game and player name
	
	system("cls");
	
	cout<<"\n\n    *********************************TIC TAC TOE GAME******************************";
	cout<<"\n            Player 1 [X]";
	cout<<"\n            Player 2 [O]"<<endl<<endl<<endl;
	
	
	//making pattern
	
	cout<<"\t\t"<<"     |     |     \n";
	cout<<"\t\t"<<"  "<<A[0][0]<<"  |  "<<A[0][1]<<"  |  "<<A[0][2]<<"   \n";
	cout<<"\t\t"<<"_____|_____|______\n";
	cout<<"\t\t"<<"     |     |     \n";
	cout<<"\t\t"<<"  "<<A[1][0]<<"  |  "<<A[1][1]<<"  |  "<<A[1][2]<<"   \n";
    cout<<"\t\t"<<"_____|_____|______\n";
	cout<<"\t\t"<<"     |     |     \n";
    cout<<"\t\t"<<"  "<<A[2][0]<<"  |  "<<A[2][1]<<"  |  "<<A[2][2]<<"   \n";
	cout<<"\t\t"<<"     |     |     \n";
		
}


void players_turn()
{
     if(turn=='X')
     cout<<"\n\tPlayer 1 [X] turn";
     
	 if(turn=='O')
     cout<<"\n\tPlayer 2 [O] turn";

	cin>>choice;
	
	
	switch(choice)
	{
		case '1' : 
		r=0;c=0;
		break;
		case '2' : 
		r=0;c=1;
		break;
		case '3' : 
		r=0;c=2;
		break;
		case '4' : 
		r=1;c=0;
		break;
		case '5' : 
		r=1;c=1;
		break;
		case '6' : 
		r=1;c=2;
		break;
		case '7' : 
		r=2;c=0;
		break;
		case '8' : 
		r=2;c=1;
		break;
		case '9' : 
		r=2;c=2;
		break;
		default : cout<<"\n invalid no";
		break;
	}
	if(turn=='X' && A[r][c]!='X'&&  A[r][c]!='O')
	{
		A[r][c]='X';
		turn='O';
		
		display();     //updating game after changes
	}
	else if(turn=='O' && A[r][c]!='X'&&  A[r][c]!='O')
	{
		A[r][c]='O';
		turn='X';
		
		display();     //updating game after changes
		}	
	
	else
{
		cout<<"\n Box alredy  filled \n please enter anything else!!!!";
	players_turn();
	display();     //updating game after changes
}
}
	
	
	
bool gameover()
{
	//check win vertically and horizontally
	for(int i=0;i<3;i++)
	
		if(A[i][0] == A[i][1] && A[i][0] == A[i][2] || A[0][i] == A[1][i] && A[0][i] == A[2][i])
		
		return false;                 //false
		
	
	//check win diagonally
	
	
		if(A[0][0]==A[1][1] && A[0][0]==A[2][2] || A[0][2]==A[1][1] && A[0][2]==A[2][0]) 
		
		return false;           //false
	
	
	
	//check game is over or not
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	if(A[i][j]!='X'&& A[i][j]!='O')
	
	return true;                //true
			
	draw=true;
	return false;             //false
	
	
}

 main()
{
	while(gameover())
	{
	display();
	players_turn();
	gameover();


	if(turn =='O' && draw == false)
cout<<"Player 1 [X] wins !!!!! congratulations\n ";
else if(turn =='X' && draw == false)
cout<<"Player 2 [X] wins !!!!! congratulations\n ";
else
cout<<"\n Draw!!!!!  \n Try another game";	
			
} 


	
}
