#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
using namespace std;

int main()
{
    COORD coord;
	coord.X = 0;
	coord.Y = 5;
	char game[]={'1','2','3','4','5','6','7','8','9'};
    int index;
    int win=1;   //controlling the loop
    int turn=2;
    int chance=0;

    cout<<"\t\t\tEnjoy The Tic Tac Toe\n\n";
    cout<<"\t\t Player 1 <X>  \t\t  Player 2 <O>\n\n\n";

    while( win ){
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for(int i=0;i<3;i++){
            for(int j=(3*i);j<3*(i+1);j++){
                cout<<"  "<<game[j]<<"  ";
                j==(3*i+2)?cout<<" ":cout<<"|";
            }
            cout<<"\n\n";
        }

        turn==2?turn=1:turn=2;
        chance++;
        cout<<"Player "<<turn<<", Enter The Number :   ";
        cin>>index;
        turn==1?game[index-1]='X':game[index-1]='O';

        for(int i=0;i<3;i++){
            if(game[i]==game[i+3]&&game[i+3]==game[i+6]&&game[i]==game[i+6])
                win=0;
        }
        for(int i=0;i<7;i+=3){
            if(game[i]==game[i+1]&&game[i+1]==game[i+2]&&game[i]==game[i+2])
                win=0;
        }
        if((game[0]==game[4]&&game[4]==game[8]&&game[0]==game[8])||(game[2]==game[4]&&game[4]==game[6]&&game[2]==game[6]))
            win=0;
        if(chance==9&&win!=0){
            cout<<"TIE";
            return 0;
        }
    }

    turn==1?cout<<"Player 1 Won":cout<<"Player 2 Won";
    return 0;
}
