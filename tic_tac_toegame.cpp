#include<iostream>
#include<cmath>

//using namespace std;

//global variables
int board_matrix[3][3];
char player1 = 'X';
char player2 = 'O';

int move_count=0;


struct position{
int x;
int y;
};

using namespace std;
//function declarations
int display();
int propeller(bool);
position counsellor();
int judge(int matrix[3][3], bool is_maximizer);
int score(int matrix[3][3]);
bool move_left(int matrix[3][3]);



// the function that is responsible for graphics, Aww Snap! sorry to insult graphics, yeah call it whatever!!

int exhibitor(){
int x = 3;
cout<<"._____________.\n";
	for(int i=0;i<x;i++)
		{for (int j=0;j<x;j++)
			{if (board_matrix[i][j] == 1)
				cout<<"| X |";
			else if (board_matrix[i][j] == -1)
				cout<<"| O |";
			else
				cout<<"|   |";
			}
		cout<<"\n";
		
	
		
		cout<<"|___||___||___|\n";}
	return 0;
}	
// the function that budges the game of tic - tac - toe :-)
int propeller(bool turn)
{
if(move_count == 9 || (abs(score(board_matrix)) == 10 ))
return 0;


if(turn == true)
{position coordinates;
cout<<"\nInput your move Buddy\n";
cin>>coordinates.x>>coordinates.y;
board_matrix[coordinates.x][coordinates.y] = 1; 
exhibitor();
}
else
{
position coordinates = counsellor();
board_matrix[coordinates.x][coordinates.y] = -1;
cout<<"\nArtificial Intelligence at work\n";
exhibitor();
}
turn = !turn;
move_count+=1;
propeller(turn);
return 0;
}


// the function that checks out possible moves and returns the best one, well it's not artificial inteligence stuff, it's not minimax

position counsellor(){
int temp;
position best_move;best_move.x = -1,best_move.y= -1;int points=11;
for(int i=0;i<3;i++){
	for (int j=0;j<3;j++){
		if(board_matrix[i][j] == 0)
			{
				
				board_matrix[i][j] = -1;
				temp = judge(board_matrix,true);
				board_matrix[i][j] = 0;
				if(points > temp)
				{best_move.x = i;best_move.y= j;points = temp;  }

}			}
}
return best_move;
}

// this is mini-max algorithm implementation, the artificial intelligence stuff, Cool ah!, isn't it

int judge(int matrix[3][3], bool is_maximizer){


if(score(matrix) == 10)
return 10;
else if (score(matrix)==-10)
return -10;
if(!(move_left(matrix)))
return 0;

//maximizer
if(is_maximizer){

int max_value = -11;
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
if(matrix[i][j]==0){
matrix[i][j] = 1;

int temp = judge(matrix,false);

matrix[i][j] = 0;
if(max_value<temp)
max_value = temp;
}}}
return max_value;
}
//minimizer
else{
int minvalue = 11;

for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
if(matrix[i][j] == 0){
matrix[i][j] = -1;
int temp = judge (matrix,true);
matrix[i][j] = 0;
//minvalue = minvalue<temp?minvalue:temp;
if(minvalue > temp)
minvalue = temp;
}


}}
return minvalue;
}


}

// calculates score associated with the input matrix state

int score(int b[3][3]){

    // Checking for Rows for X or O victory.
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] && b[row][1]==b[row][2])
        {
            if (b[row][0]==1)
                return +10;
            else if (b[row][0]==-1)
                return -10;
        }
    }
 
    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] && b[1][col]==b[2][col])
        {
            if (b[0][col]==1)
                return +10;
 
            else if (b[0][col]==-1)
                return -10;
        }
    }
 
    // Checking for Diagonals for X or O victory.
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==1)
            return +10;
        else if (b[0][0]==-1)
            return -10;
    }
 
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==1)
            return +10;
        else if (b[0][2]==-1)
            return -10;
    }
 
    // Else if none of them have won then return 0
    return 0;
}

//calculates if any move further is possible

bool move_left(int matrix[3][3]){
for(int i=0;i<3;i++)
{for(int j=0;j<3;j++)
{if( matrix[i][j]==0)
return true;}}
return false;}

// ignites the whole game

int main(){
cout<<"Welcome beings"<<endl;
propeller(true);
if(score(board_matrix)==-10)
cout<<"\nYou Lost!\n";
else
cout<<"Game Drawn";
return 0;
}

