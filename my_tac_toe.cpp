#include<bits/stdc++.h>
using namespace std;
int k=9,num=0;
int X_score=0,O_score=0;
char board[][3]={
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}};
int freq[][3]={
    {0,0,0},
    {0,0,0},
    {0,0,0}};
string line="\n---+---+---";
void score_card(){
    string line1="\n+---+---+";
    string line2="\n| X | O |";
    cout<<line1;
    cout<<line2;
    cout<<line1;
    cout<<'\n'<<"| "<<X_score<<" | "<<O_score<<" |";
    cout<<line1;
}
bool decision(){
    for(int j=0;j<3;j++){
        if((board[j][0]==board[j][1])&&(board[j][0]==board[j][2])){
            return 1;
        }}
    for(int j=0;j<3;j++){
        if((board[0][j]==board[1][j])&&(board[0][j]==board[2][j])){
            return 1;
        }}
    if((board[0][0]==board[1][1])&&(board[0][0]==board[2][2]))return 1;
    else if((board[0][2]==board[1][1])&&(board[0][2]==board[2][0]))return 1;
    else return 0;
}
void print_board(){
    for(int i=0;i<3;i++){
        cout<<'\n';
    for(int j=0;j<3;j++){
        cout<<' '<<board[i][j]<<' ';
        if(j<2)cout<<'|';
    }
    if(i<2)cout<<line;
    }
}
void fun(char *player){
    cout<<"\nplayer "<<*player<<" enter a value (1,9) :";
    int x;
    cin>>x;
    x--;
    if((x<9 &&x>=0)&&!freq[x/3][x%3]){
        if(*player=='X'){
        board[x/3][x%3]='X';
        *player='O';
    }
    else{
        board[x/3][x%3]='O';
        *player='X';
    }
    k--;
    print_board();
    char xa=(*player=='X')?'O':'X';
    if(decision()){
        cout<<"\nPlayer "<<xa<<" WINS";
        (xa=='X')?X_score++:O_score++;
        score_card();
        }
    else if(!k){cout<<"It's a Draw!!";
           score_card();
        }
    freq[x/3][x%3]++;
    }
    else cout<<"Invalid Input";
}
void main_fun(){
    char person='X';
    if(!num){cout<<"Enter Person name:";
    cin>>person;
    num++;}
    print_board();
    while(k&& (!decision()))fun(&person);
    char ch;
    cout<<"Restart Y/n";
    cin>>ch ;
    if(ch=='Y'){
        char c='1';
       for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=c++;
            freq[i][j]=0;
        }
       }
        k=9;
    main_fun();
    }
}
int main(){
    main_fun();
}
