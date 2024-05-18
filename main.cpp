using namespace std;
#include<iostream>
#include"player.h"
#include"player_management.h"
#include"player_management.cpp"

int main() 
{
	PlayerManagement<Player> pm;
	pm.hardCodedData();
	
	int choice;
	do
	{
		cout<<"\n\t1.AddPlayer";
		cout<<"\n\t2.DisplayData";
		cout<<"\n\t3.Search Player";
		cout<<"\n\t4.Update";
		cout<<"\n\t5.Delete";
		cout<<"\n\t6.Sort";
		cout<<"\n\t7.Exit";
		cout<<"\nEnter choice: ";
		cin>>choice;
	
		switch(choice)
		{
			case 1:
			{
				int j_no,pos;
				char name[30];
				int no_of_matches;
				int no_of_runs;
				int no_of_wickets;
				cout<<"\nEnter jersey no,name,no of matches,no of runs,no of wickets:";
				cin>>j_no>>name>>no_of_matches>>no_of_runs>>no_of_wickets;
				cout<<"\nEnter where to add:";
				cin>>pos;
				Player p1(j_no,name,no_of_matches,no_of_runs,no_of_wickets);
				pm.addPlayer(p1,pos);
				break;	
			}
			case 2:
			{
				pm.displayPlayer();
				break;	
			}
			case 3:
			{
				cout<<"\nSearch Player by :- \n1.Jersey Number  \n2.Player Name  \n";
				int choice1;
				cin>>choice1;
				if(choice1==1)
				{
					int jerNum;
					cout<<"\nEnter the Jersey Number you want to Search: ";			
					cin>>jerNum;
					pm.searchPlayerId(jerNum);
				}
				else if(choice1==2)
				{
					fflush(stdin);
					char playerName[20];
					cout<<"\nEnter the Player Name you want Search : ";					
					cin.getline(playerName,20);
					pm.searchPlayerName(playerName);
				}
				else
					cout<<"\nInvalid Choice !!";
				break;	
			}
			case 4:
			{
				int jno;
				cout<<"\nEnter jersey no to update: ";
				cin>>jno;
				pm.updatePlayer(jno);
				break;	
			}
			case 5:
			{
				int jno;
				cout<<"\nEnter jersey no to delete: ";
				cin>>jno;
				pm.deletePlayer(jno);
				break;	
			}
			case 6:
			{
				int choice;
				cout<<"\nSort by: ";
				cout<<"\n1.Runs";
				cout<<"\n2.Wickets";
				cout<<"\nEnter choice: ";
				cin>>choice;
				pm.sortPlayer(choice);
				break;	
			}
			
			case 7:	
			{
				printf("\nExiting Program. Thank You !\n");
				break;	
			}
			default:
			{
				printf("\nPlease Enter Valid Choice !");
			}
		}
	}while(choice!=7);
	return 0;
}