#include <bits/stdc++.h>
#include <conio.h>

#define PI 3.14
using namespace std;
#define Up_Move 72
#define Left_Move 75
#define Right_Move 77
#define Down_Move 80

int arr1[4][4];
int arr[4][4];
int moves=2000;
char name[20];

void createArray()
{
    int index, num[15],lastIndex=14;
    srand(time(NULL));
    for(int i=0; i < 15; i++)
        num[i]=i+1;



    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(lastIndex >=0)
            {
                index=rand() % (lastIndex + 1);
                arr[i][j]=num[index];
                num[index]=num[lastIndex];
                lastIndex--;
            }
        }
    }
    arr[3][3]=0;
}
void swap72()
{
    int tempI,tempJ,upperValue;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(arr[i][j]==0)
            {
                tempI=i;
                tempJ=j;
                break;
            }
        }   
    }
    if(tempI>=1)
    {
        upperValue=arr[tempI-1][tempJ];
        arr[tempI][tempJ]=upperValue;
        arr[tempI-1][tempJ]=0;
    }
    // cout<<"\ni = "<<tempI<<"   j = "<<tempJ<<endl;
    
}
void swap75()
{
    int tempI,tempJ,LeftValue;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(arr[i][j]==0)
            {
                tempI=i;
                tempJ=j;
                break;
            }
        }   
    }
    if(tempJ>=1)
    {
        LeftValue=arr[tempI][tempJ-1];
        arr[tempI][tempJ]=LeftValue;
        arr[tempI][tempJ-1]=0;
    }
}
void swap77()
{
    int tempI,tempJ,rightValue;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(arr[i][j]==0)
            {
                tempI=i;
                tempJ=j;
                break;
            }
        }   
    }
    if(tempJ<=2)
    {
        rightValue=arr[tempI][tempJ+1];
        arr[tempI][tempJ]=rightValue;
        arr[tempI][tempJ+1]=0;
    }
}
void swap80()
{
    int tempI,tempJ,downValue;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(arr[i][j]==0)
            {
                tempI=i;
                tempJ=j;
                break;
            }
        }   
    }
    if(tempI<=2)
    {
        downValue=arr[tempI+1][tempJ];
        arr[tempI][tempJ]=downValue;
        arr[tempI+1][tempJ]=0;
    }
}
int check_winner()
{
    arr1[0][0]=1;
    arr1[0][1]=2;
    arr1[0][2]=3;
    arr1[0][3]=4;
    arr1[1][0]=5;
    arr1[1][1]=6;
    arr1[1][2]=7;
    arr1[1][3]=8;
    arr1[2][0]=9;
    arr1[2][1]=10;
    arr1[2][2]=11;
    arr1[2][3]=12;
    arr1[3][0]=13;
    arr1[3][1]=14;
    arr1[3][2]=15;
    arr1[3][3]=0;
    int count=0;
    if(arr[3][3]!=0)
        return 1;
    for (int  i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(arr[i][j]==arr1[i][j])
                count++;
        }
    }
    if(count==16)
    {
        count=0;
        return count;
    }
    return 1;
    
}

void display()
{
    system("cls");
    cout<<"Player's Name : "<<name<<"\t\t"<<"Move remaining : "<<moves<<endl;
    cout<<"  -----------------------"<<endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(arr[i][j]==0)
                cout<<"  |   ";
            else
            {
                int t=arr[i][j];
                t=t/10;
                if(t==0)
                {
                    cout<<"  |  "<<arr[i][j];
                }
                else
                {
                    cout<<"  | "<<arr[i][j];
                }
            }
        }cout<<"|"<<endl;
        // cout<<endl;        
    }
    cout<<"  -----------------------"<<endl;
}

int input()
{
    int key;
    char ch;
    ch=getch();
    key=ch;
    return key;
}
void instruction()
{
    cout<<"                    "<<"MATRIX PUZZLE"<<"                        "<<endl<<endl;
    cout<<"                  "<<"Rules of this Game"<<"                        "<<endl<<endl;  
    cout<<"1.You can move only 1 step at a time by arrow key "<<endl;
    cout<<"          "<<"Move Up       :  by Up arrow key"<<endl;
    cout<<"          "<<"Move Down     :  by down arrow key"<<endl;
    cout<<"          "<<"Move Left     :  by left arrow key"<<endl;
    cout<<"          "<<"Move Right    :  by Right arrow key"<<endl;
    cout<<"2.You can move number at empty position only "<<endl;
    cout<<"3.For each valid move : your total number of move will decreased by 1"<<endl;
    cout<<"4.Winning situation : Number in a 4*4 matrix should be in order from 1 to 15"<<endl<<endl;
    cout<<"           Winning situation : "<<endl;
    cout<<"------------------------"<<endl;
    cout<<"|  1  |  2  |  3  |  4  |"<<endl;
    cout<<"|  5  |  6  |  7  |  8  |"<<endl;
    cout<<"|  9  |  10 | 11  | 12  |"<<endl;
    cout<<"|  13 |  14 | 15  |     |"<<endl;
    cout<<"-------------------------"<<endl<<endl;
    cout<<"5.You can exit the game at any time by pressing 'e' or 'E'"<<endl;
    cout<<"Try to win the game in minimun of moves "<<endl;
    cout<<"Enter any key to start........."<<endl;
    getch();
    system("cls");

}




int main()
{
    cout<<"Testing"<<endl;
    cout<<"\nEnter Your Name : ";
    cin.getline(name,20);
    cout<<"\nWelcome : "<<name<<endl<<endl;
    instruction();
    createArray();
    display();
    cout<<endl;

    int flag = 1;int key;
    while(moves && flag)
    {

        key=input();
        switch (key)
        {
            case 101:
                goto Exit;
                break;
            case Up_Move:
                swap72();
                moves--;
                display();
                flag=check_winner();
                break;
            case Left_Move :
                swap75();
                moves--;
                display();
                flag=check_winner();
                break;
            case Right_Move :
                swap77();
                moves--;
                display();
                flag=check_winner();
                break;
            case Down_Move :
                swap80();
                moves--;
                display();
                flag=check_winner(); 
                break;
            default :
                cout<<"default"<<endl;
                break;
        }

        if(flag==0 )
        {
            cout<<"\nCongrats "<<name<<"You won the Game "<<endl;
            getch();
            exit(0);
        }
    }
    if(moves==0)
        {cout<<"All Moves Have Exhausted "<<endl;}
    Exit:
        cout<<"Thank You For Playing "<<endl;
    cout <<"If You Want To Play Again Press Y ";
    char var;
    var=getch();
    if(var=='y' && var=='Y')
        main();
    return 0;
}


