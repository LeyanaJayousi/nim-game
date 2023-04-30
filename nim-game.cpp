#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define COMPUTER 1 
#define HUMAN 2 


int pickRandInt(int max) {
        
        return (int)((rand() / (RAND_MAX + 1.0)) * (max + 1));
}


void makeInitialRows(int &row1, int &row2, int &row3)
{
        row1 = 1; 
        row2 = 3; 
        row3 = 5; 
}




void displayRows(int row1, int row2, int row3)
{
        //cout << "Row 1:" << row1 << "  \t Row 2:" << row2 << "  \t Row 3: " << row3 << endl;
        cout << "\tRow 1:" << "\tRow 2:"  << "\tRow 3: "<< endl;
        cout << "\t " << row1 << "\t " << row2 << "\t " << row3 << endl;
}


void selectComputerMove(int& row1, int &row2, int& row3, int rowChosen, int tokensRemoved)
{
        if (rowChosen == row1)
        {
                row1 = row1 - tokensRemoved;
        }
        else
                if (rowChosen == row2)
                {
                        row2 = row2 - tokensRemoved;
                }
                else
                        if (rowChosen == row3)
                        {
                                row3 = row3 - tokensRemoved;
                        }
}

void makeMove(int& row1, int &row2, int& row3, int rowChosen, int tokensRemoved)
{
        if (rowChosen == row1)
        {
                row1 = row1 - tokensRemoved;
        }
        else if (rowChosen == row2)
                {
                        row2 = row2 - tokensRemoved;
                }
                else if (rowChosen == row3)
                        {
                                row3 = row3 - tokensRemoved;
                        }
}

bool getPlayerMove(int row1, int row2, int row3, int rowChosen, int tokensRemoved)
{
        //shorten variable names to make it less tedious for the loooooong if statements
        int pc = rowChosen;                                                                                                                                             ///////////////////////////////////////////////////////////////////////////////
        int cr = tokensRemoved;                                                                                                                                 //THIS FUNCTION CURRENTLY DOESNT WORK WHEN PLAYER INPUTS INVALID/ILLEGAL MOVE//
        int p1 = row1;                                                                                                                                                  /////////////////////////////////////////////////////////////////////////////
        int p2 = row2;
        int p3 = row3;

        if (!(rowChosen > 0 && rowChosen <= 3))//checks rowChosen is valid or not from the user
        {
                cout << "You have entered an Invalid row number or number of tokens." << endl;
                return 0;
        }
        else if (pc == 1 && (cr <= 0 || cr > p1))//checks if the tokenRemoved from row 1 input from user is valid or not
                {
                        cout << "You have entered an Invalid row number or number of tokens." << endl;
                        return 1;
                }
                else if (pc == 2 && (cr <= 0 || cr > p2))//checks if the tokenRemoved from row 2  input from user is valid or not
                        {
                                cout << "You have entered an Invalid row number or number of tokens." << endl;
                                return 1;
                        }
                        else if (pc == 3 && (cr <= 0 || cr > p3))//checks if the tokenRemoved from row 3 input from user is valid or not
                                {
                                        cout << "You have entered an Invalid row number or number of tokens." << endl;
                                        return 1;
                                }
                                else
                                {
                                        return 0;
                                }
}

void startGame(bool computerToMove, int row1, int row2, int row3)
{
        int rowChosen;
        int tokensRemoved;
        int num;
        int newRow; //clones current row slected with updated results

        // display the initial state of the game
        cout << "\nInitial State:\n";
        displayRows(row1, row2, row3);//outputs first Rows information about the tokens
        cout << " --------------------------------------\n";
        for (;;) //"It's an infinite loop, equivalent to while(true). When no termination condition is provided, the condition defaults to true."
        {
                if (computerToMove)
                {
                        //the following statements are designed to inititae selectComputerMove
                        //function in order to remove all tokens from same row.         
                        if (row1 > 0 && row2 == 0 && row3 == 0)
                        {
                                rowChosen = row1;
                                tokensRemoved = row1;
                                newRow = 1;
                                selectComputerMove(row1, row2, row3, rowChosen, tokensRemoved); //remove all tokens from selected row. row1
                        }
                        else if (row1 == 0 && row2 > 0 && row3 == 0)
                                {
                                        rowChosen = row2;
                                        tokensRemoved = row2;
                                        newRow = 2;
                                        selectComputerMove(row1, row2, row3, rowChosen, tokensRemoved); //remove all tokens from selected row. row2
                                }
                                else if (row1 == 0 && row2 == 0 && row3 > 0)
                                        {
                                                rowChosen = row3;
                                                tokensRemoved = row3;
                                                newRow = 3;
                                                selectComputerMove(row1, row2, row3, rowChosen, tokensRemoved); //remove all tokens from selected row. row3
                                        }
                                        else
                                        {
                                                if (row1 > 0 && row2 > 0 && row3 > 0)//when tokens in all the rows are >0
                                                {
                                                        num = rand() % 3 + 1;//by this way there will only be 1 or 2 or 3 random iterations
                                                        if (num == 1)
                                                        {
                                                                rowChosen = row1;
                                                                newRow = 1;
                                                        }
                                                        else if (num == 2)
                                                                {
                                                                        rowChosen = row2;
                                                                        newRow = 2;
                                                                }
                                                                else if (num == 3)
                                                                        {
                                                                                rowChosen = row3;
                                                                                newRow = 3;
                                                                        }
                                                        for (;;) //"It's an infinite loop, equivalent to while(true). When no termination condition is provided, the condition defaults to true."
                                                        {
                                                                tokensRemoved = rand() % 20 + 1;//randomly select number of tokens to be removed
                                                                if (tokensRemoved <= row1 && tokensRemoved <= row2 && tokensRemoved <= row3)
                                                                        //however random tokens has to be less than initial chosen tokens by rand function
                                                                {
                                                                        break;
                                                                }
                                                        }
                                                }
                                                else if (row1 == 0 && row2 > 0 && row3 > 0)//when tokens in row1 is zero and others are not
                                                        {
                                                                num = rand() % 2 + 1;//only 2 or 3 will be chosen randomly
                                                                //the following if statements will carefully selct rows 2,3 and ignore row 1 because it has zero tokens
                                                                if (num == 1)
                                                                {
                                                                        rowChosen = row2;
                                                                        newRow = 2;
                                                                }
                                                                else if (num == 2)
                                                                        {
                                                                                rowChosen = row3;
                                                                                newRow = 3;
                                                                        }
                                                                for (;;) //"It's an infinite loop, equivalent to while(true). When no termination condition is provided, the condition defaults to true."
                                                                {
                                                                        tokensRemoved = rand() % 20 + 1;//a number is randomly choosen from 1 to 20
                                                                        if (tokensRemoved <= row2 && tokensRemoved <= row3)
                                                                                //however tokens chosen randomly has to be less than row2 and row3
                                                                        {
                                                                                break;
                                                                        }
                                                                }
                                                        }
                                                        else if (row1 > 0 && row2 == 0 && row3 > 0)//only row 1 and row 3 has tokens greater than 0 and row 2 is zero
                                                                {
                                                                        num = rand() % 2 + 1;//only 1 or 3 will be chosen randomly
                                                                        //the following if statements will carefully selct rows1,3  and ignore row 2 because it has zero tokens
                                                                        if (num == 1)
                                                                        {
                                                                                rowChosen = row1;
                                                                                newRow = 1;
                                                                        }
                                                                        else if (num == 2)
                                                                                {
                                                                                        rowChosen = row3;
                                                                                        newRow = 3;
                                                                                }
                                                                        for (;;) //"It's an infinite loop, equivalent to while(true). When no termination condition is provided, the condition defaults to true."
                                                                        {
                                                                                tokensRemoved = rand() % 20 + 1;//a number is randomly choosen from 1 to 20
                                                                                if (tokensRemoved <= row1 && tokensRemoved <= row3)
                                                                                        //however tokens chosen randomly has to be less than row1 and row3
                                                                                {
                                                                                        break;
                                                                                }
                                                                        }
                                                                }
                                                                else if (row1 > 0 && row2 > 0 && row3 == 0)//only row 1 and row 2 has tokens greater than 0 and row 3 is zero
                                                                        {
                                                                                num = rand() % 2 + 1;//only 1 or 2 will be chosen randomly
                                                                                if (num == 1)
                                                                                {
                                                                                        rowChosen = row1;
                                                                                        newRow = 1;
                                                                                }
                                                                                else if (num == 2)
                                                                                        {
                                                                                                rowChosen = row2;
                                                                                                newRow = 2;
                                                                                        }
                                                                                for (;;) //"It's an infinite loop, equivalent to while(true). When no termination condition is provided, the condition defaults to true."
                                                                                {
                                                                                        tokensRemoved = rand() % 20 + 1;//a number is randomly choosen from 1 to 20
                                                                                        if (tokensRemoved <= row1 && tokensRemoved <= row2)
                                                                                                //however tokens chosen randomly has to be less than row1 and row2
                                                                                        {
                                                                                                break;
                                                                                        }
                                                                                }
                                                                        }
                                                //calls function to do the opeartion that will remove tokens from a particular row
                                                makeMove(row1, row2, row3, rowChosen, tokensRemoved);

                                        }
                        cout << "\n";
                        cout << " --------------------------------------\n";
                        cout << "The computer has removed " << tokensRemoved //prints out what the computer has removed
                                << " tokens from row " << newRow << ":\n"; //and what row the tokens were removed from
                        cout << " --------------------------------------\n";

                        if ((row1 + row2 + row3) == 0) //If rows are = 0 durning Computer's turn, then it wins
                        {
                                cout << "The Computer has won!\n"; //display computer won message to console
                                system("PAUSE");
                                return;
                        }
                }
                else 
                { // player / non computer to make a move
                        //this is also where the invalid selections are are checked
                        do
                        {
                                cout << "\n";
                                cout << " --------------------------------------\n";
                                cout << "Please enter the row number and tokens to remove :";
                                cin >> rowChosen >> tokensRemoved;

                        } while (getPlayerMove(row1, row2, row3, rowChosen, tokensRemoved));
                        //skips when a valid input is given
                        //the next if statements will select the row that the player has selected
                        if (rowChosen == 1) //row 1
                        {
                                rowChosen = row1;
                        }
                        else if (rowChosen == 2) //row 2
                                {
                                        rowChosen = row2;
                                }
                                else if (rowChosen == 3) //row 3
                                        {
                                                rowChosen = row3;
                                        }
                        //calls in the makeMove function and it takes in the tokensRemoved and rowChosen from user then runs the removal of tokens 
                        makeMove(row1, row2, row3, rowChosen, tokensRemoved);
                        if ((row1 + row2 + row3) == 0) //if rows = 0 during players' turn, then player wins
                        {
                                cout << "you have won!\n"; //dispalys winning message to console for Player
                                system("PAUSE");
                                return;
                        }
                }
                // display the new number of tokens in the rows after user has imputed their selection
                displayRows(row1, row2, row3);
                computerToMove = !computerToMove; // it's now the other player's turn
        }
}



struct move
{
        int IndexRow;
        int RemovedToken;
};

int calculateNimSum(int nRows[], int num)
{
        int k, nimSum = nRows[0];
        for (k = 0; k < num; k++) nimSum = nimSum ^ nRows[k];
        return(nimSum);
}


class Player
{
public:
        // this function decide the next move for the game 
        void Move(int nRows[], const int num, struct move * moves)

        {
                int k, nimSum = calculateNimSum(nRows, num);

                // The player/computer on the current turn is on a winning position. 
                // So this will play optimally and try to make  nimSum = 0
                if (nimSum != 0)
                {
                        for (k = 0; k < num; k++)
                        {
                                // If this is NOT an invalid move then make the next move based on the if 
                                if ((nRows[k] ^ nimSum) < nRows[k])
                                {
                                        (*moves).IndexRow = k;
                                        (*moves).RemovedToken = nRows[k] - (nRows[k] ^ nimSum);
                                        nRows[k] = (nRows[k] ^ nimSum);
                                        break;
                                }
                        }
                }

                else
                {
                        // Create an array to hold the index of non-empty rows
                        int *nonZero = new int[num];
                        //int nonZero[num];
                        int count;

                        for (k = 0, count = 0; k < num; k++)
                                if (nRows[k] > 0) nonZero[count++] = k;

                        (*moves).IndexRow = (rand() % (count));
                        (*moves).RemovedToken = 1 + (rand() % (nRows[(*moves).IndexRow]));
                        nRows[(*moves).IndexRow] = nRows[(*moves).IndexRow] - (*moves).RemovedToken;

                        if (nRows[(*moves).IndexRow] < 0) 
                                nRows[(*moves).IndexRow] = 0;

                        delete[] nonZero;
                }
                return;
        }
};


void displayState(int nRows[], int num)
{
        int k;
        cout << "Current Game Status: " << endl;
        cout << " --------------------------------------\n";
        for (k = 0; k < num; k++)
                cout << "Row: " << nRows[k] << endl;
        cout << " --------------------------------------\n";
        cout << "\n" << endl;
        return;
}


bool gameEnd(int nRows[], int num)
{
        int k;
        for (k = 0; k < num; k++)
                if (nRows[k] != 0)
                        return (false);
        return (true);
}

void announceWin(int Turn)
{
        if (Turn == COMPUTER)
                cout << "\nThe Player is declared the winner!\n\n" << endl;
        else
                cout << "\nThe Computer is declared the winner!\n\n" << endl;
        return;
}



void startGame_SIM(int nRows[], int num, int Turn)
{
        system("PAUSE");
        cout << "\nGAME STARTS\n\n" << endl;
        struct move moves;

        //making object of player class
        Player player;
        while (gameEnd(nRows, num) == false)
        {
                displayState(nRows, num);

                player.Move(nRows, num, &moves);

                if (Turn == COMPUTER)
                {
                        cout << "The Computer has removed " << moves.RemovedToken << " tokens from row " << moves.IndexRow + 1 << endl;
                        Turn = HUMAN;
                }
                else
                {
                        cout << "The Player has removed " << moves.RemovedToken << " tokens from row " << moves.IndexRow + 1 << endl;
                        Turn = COMPUTER;
                }
        }

        displayState(nRows, num);
        announceWin(Turn);
        return;
}





int main()
{
        char option;
        int row1, row2, row3;

        
        //srand(time(NULL)); 

        for (;;) //"It's an infinite loop, equivalent to while(true). When no termination condition is provided, the condition defaults to true."
        {
                cout << endl;
                cout << " +------------------------------------------------------+\n"
                         << " | |              W  E  L  C  O  M  E                 | |\n"
                         << " +------------------------------------------------------+\n";
                // prompt user for the following options:
                cout << "\nWhat would you like to do?\n"
                        << "+-------------------------------------------------------+\n"
                       
                        << "| A | I want to Play Game where Computer goes first.  |\n"
                        << "| B | I want to Play Game where I go first.           |\n"
                        << "| C | Quit NIM                                                |\n"
                        << "| ------------------------------------------------------|\n";
                       
                      
                        
                cout << "+-------------------------------------------------------+\n"
                         << "My Choice is:  ";
                cin >> option;
                cin.ignore(1000, '\n'); // get rid of the rest of the input line
                option = toupper(option); // convert option to uppercase
                
                 if (option == 'A')
                        {
                                cout <<"\n--------------------------Let's Play----------------------------" << endl <<
                                        
                                        "-----------------------------------------------------------------" << endl;

                                makeInitialRows(row1, row2, row3); //forms the initial rows for the game
                                startGame(true, row1, row2, row3);
                        }
                        else if (option == 'B')
                                {
                                        cout << "Play----------------------------" << endl <<
                                                
                                               
                                                "-----------------------------------------------------------------" << endl;

                                        makeInitialRows(row1, row2, row3); //forms the initial rows for the game
                                        startGame(false, row1, row2, row3);
                                }

                                

                                else if (option == 'C')
                                        {
                                                // option to quit the program
                                                
                                                system("PAUSE"); 
                                                return 0;
                                        }
                                        else
                                        {
                                                //returns if none of the user imputs are valid.
                                                cout << "\n That option is not recognised. Please try again\n";
                                        }

        }
        return 0;
}
