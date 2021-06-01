#include <iostream>
#include <conio.h>
//Snake Game
using namespace std;

bool gameOver;

const int width = 20;
const int heigth = 20;
int x,y;
int fruitX,fruitY;
int tailX[100];
int taily[100];
int ntail;
int score;
enum eDirection{ STOP = 0, LEFT ,RIGHT,UP,DOWN};
eDirection dir;

void Setup()
{
    gameOver= false;
    dir = STOP;
    x=width/2-1;
    y=heigth/2-1;
    fruitX=rand()%width;
    fruitY=rand()%heigth;
    score=0;
}
void Draw()
{
    system("cls");
    for(int i = 0;i<width+1;i++){
        cout << "#";
    }
    cout<<endl;
    for(int i = 0;i<heigth;i++){
        for (int j=0;j<width;j++){
            if (j==0 || j == width -1 ){
                cout << "#";
            }
            if (i==y && j==x){
                cout << "0";
            } else if (i==fruitY && j== fruitX){
                cout << "F";
            }else {
                bool print = false;
                for (int k = 0; k < ntail;k++){
                    if (tailX[k]==j && taily[k] == i){
                        print= true;
                        cout << "o";
                    }
                }
                if(!print)
                cout << " ";}
        }
        cout << endl;
    }
    for(int i = 0;i<width+1;i++){
        cout << "#";
    }
    cout<<endl;
cout << "Score:" << score << endl;
}
void Input()
{
    if(_kbhit()){
        switch (_getch())
        {
            case 'a':
                dir= LEFT;
                break;
            case 'd':
                dir=RIGHT;
                break;
            case 'w':
                dir=UP;
                break;
            case 's':
                dir=DOWN;
                break;
            case 'x':
                gameOver= true;
                break;
        }
    }
}
void Logic()
{
    int prevX=tailX[0];
    int prevY=taily[0];
    int prev2x, prev2y;
    tailX[0]=x;
    taily[0]=y;
    for(int i = 1;i < ntail;i++){
        prev2x = tailX[i];
        prev2y = taily[i];
        tailX[i] = prevX;
        taily[i] = prevY;
        prevX=prev2x;
        prevY=prev2y;
    }
    switch (dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }
   // if(x>width || x<0 || y > heigth || y < 0)
    //{
        //gameOver= true;
    //}
    if (x>=width-1){
        x=0;
    } else if (x<0){
        x=width-2;
    }
    if (y>=heigth){
        y=0;
    } else if (y<0){
        y=heigth-1;
    }
    for (int i = 0;i<ntail;i++){
        if (tailX[i] == x && taily[i] == y){
            gameOver= true;
        }
    }
    if(x==fruitX && y==fruitY){
        score+=10;
        fruitX=rand()%width;
        fruitY=rand()%heigth;
        ntail++;
    }

}
int main(){
    Setup();
    while (!gameOver){
        Draw();
        Input();
        Logic();
    }
}
