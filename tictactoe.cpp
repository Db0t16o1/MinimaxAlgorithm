#include<iostream>
#include<cstdlib>
using namespace std;

/* display function is the function that prints the current tic tac toe configuration 
Here 
1 means user's move, X gets printed
0 means untouched space, Nothing gets printed
-1 means bot's move, 0 gets printed
*/
int opponent = -1;
int player =1;
char username[7];
int level,turn=2;
int position[3][3];
int sum[8];
int move_count=0;
int process_move(int x,int y);
int aiinput(int x[3][3]);

//ismove() tells whether there is any move left or not
bool ismove(int board[3][3])
{
for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			{if(board[i][j]==0)
				return true;
			}
	}
return false;
}

//evaluate a state value for the board state
int evaluate(int b[3][3])
{
    // Checking for Rows for X or O victory.
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] && b[row][1]==b[row][2])
        {
            if (b[row][0]==player)
                return +10;
            else if (b[row][0]==opponent)
                return -10;
        }
    }
 
    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] && b[1][col]==b[2][col])
        {
            if (b[0][col]==player)
                return +10;
 
            else if (b[0][col]==opponent)
                return -10;
        }
    }
 
    // Checking for Diagonals for X or O victory.
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==player)
            return +10;
        else if (b[0][0]==opponent)
            return -10;
    }
 
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==player)
            return +10;
        else if (b[0][2]==opponent)
            return -10;
    }
 
    // Else if none of them have won then return 0
    return 0;
}
 
// calculate the heuristic score for applcation of minimax algorithm for states.
int score()
{

for (int i=0;i<8;i++)
	{	if(sum [i] == 3 || sum[i] == -3)
			return  ((sum[i])/3*10);
		}
return 0;
}

// sum of row 0,1,2 coulumn 0,1,2 diagonal 1,2;
// 1 implies user's claimed box (X), -1 implies bot's claimed box (O), 0 implies unclaimed box
int display ()
{
	int x=3;

		cout<<"._____________.\n";
	for(int i=0;i<x;i++)
		{for (int j=0;j<x;j++)
			{if (position[i][j] == 1)
				cout<<"| X |";
			else if (position[i][j] == -1)
				cout<<"| O |";
			else
				cout<<"|   |";
			}
		cout<<"\n";
		
	
		
		cout<<"|___||___||___|\n";}
	return 0;
}

//read the input

int read_move()
{cout<<"Hello\t"<<username<<"\n Enter column number and row number, Note row & column indexing starts with 1\n :-)\t";
int x,y;
cin>>x>>y;
return(process_move(x,y));

}


// processing move to alter characteristics
int process_move(int x,int y){
int scoreid;
if(turn%2 != 0)
scoreid =1;
else
scoreid = -1;	
	position [x-1][y-1] = scoreid;
	display();
	sum[x-1] +=scoreid;
	sum[2+y] +=scoreid;
	if(x==y)
sum[6]+=scoreid;
	if (x+y == 4)
		sum[7]+=scoreid;
	
		for(int q=0;q<8;q++)
{if(sum[q]==3 || sum[q]==-3)
return 0;
}
			move_count+=1;turn+=1;
	if (move_count != 9)
			{if(turn%2 == 0)
	
			return(aiinput(position));
else
return (read_move());
				
}	
return (0);
	}




// Artificial intelligence function

int minimax(int move_counter,bool ismaximizer, int board[3][3]){
int scoreid = evaluate(board);
if (scoreid == 10 || scoreid== -10)
return scoreid;
if(ismove(board)==false)
return 0;
if(ismaximizer==true){ int favoured = -11;
	for(int row=0;row<3;row++)
	{
		for(int column=0;column<3;column++)
			{
				if (board[row][column] == 0){
					board[row][column] = 1;
int temp=minimax(move_counter+1,!ismaximizer,board);
if(temp>favoured)
favoured = temp;				
					board[row][column] = 0;	
			}	}
	}
return favoured;}
else
{
int favoured = 11;
for(int row = 0;row<3;row++)
	{ for (int column=0;column<3;column++)
		{
			if(board[row][column]==0){
				board[row][column] = -1;

				int temp=minimax(move_counter+1,!ismaximizer,board);
if(temp<favoured)
favoured = temp;
				board[row][column] = 0;
				}	
		}
	}
return favoured;
}
}

int aiinput(int board[3][3]){
int best_score = +100,move_score;
int move_column=-1,move_row=-1;
for(int row=0;row<3;row++)
	{
		for(int column=0;column<3;column++)
			{
				if (board[row][column]==0){
					board[row][column] = -1;
 move_score = minimax(0,true,board);
				
					board[row][column] = 0;
if(move_score<best_score)
{
best_score= move_score;
move_row = row;
move_column= column;}	
			}	}} 
return(process_move(move_row+1,move_column+1));}
//initialize the game

int initialize_game()
{
int player;


cout<<"---------------------------------------------Tic Tac Toe by Vishnu Goyal-----&copy BlissVish-----------------------------------------------------------";
cout<<"\n\n\n\n";
cout << "Enter your 6 character username:\t";
cin>>username;
cout<<"Select level 0 or 1:\t";
cin>>level;
cout<<"Wanna have first move ?? enter 1:\t";
cin>>player;
if(player==1)
turn=1;
else
turn = 2;
cout<<"\n\n\n\n\n\n\n\n------------------------------------------------------- LOADING----------------------------------------------------------------------------------------";
if (player==1)
return (read_move());
else
return (aiinput(position));

}



// process input move from terminal


// main function of the tic tac toe game

int main()
{
	display();
	initialize_game();
	for(int i=0;i<8;i++)
	  {if(sum[i]== 3)
		{
	
	      cout<<"You Won!";
return 0;}
	    else if(sum[i]==-3)
	      {cout<<"You lost!";
return 0;}
	    }
	      cout<<"Game Drawn";
	return 0;

}
