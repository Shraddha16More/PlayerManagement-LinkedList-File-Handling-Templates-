using namespace std;
#include<iostream>
#include<fstream>
#include<string.h>
#include"player.h"
#include"player_management.h"
template<class T>
	
	PlayerManagement<T> :: PlayerManagement()
	{
		start = NULL;
		
		int i=1;
		ifstream in("playerInfo.bin",ios_base::binary);
		if(in)
		{
			while(!in.eof())
			{
				T p1;
				in.read((char*)&p1,sizeof(p1));
				if(in.eof())
				{
					break;
				}
				addPlayer(p1,i);
				i++;
			}
			in.close();
		}
	}
	template<class T>
	void PlayerManagement<T> :: addPlayer(const T& p1,int pos)
	{
		Node<T>* temp=new Node<T>(p1);
		if(pos==1 || start==NULL)
		{
			start=temp;
		}
		else
		{
			Node<T>* p=start;
			int i=1;
			while(i<pos-1 && p->getNext()!=NULL)
			{
				i++;
				p=p->getNext();
			}
			temp->setNext(p->getNext());
			p->setNext(temp);
		}
	}
	template<class T>
	void PlayerManagement<T>::hardCodedData() 
	{
    // Add players to the linked list
	    addPlayer(T(10,"Sachin",10,55,6),1);
	    addPlayer(T(7,"Dhoni",41,305,3),2);
	    addPlayer(T(45, "Rohit", 60,402,3),3);
	    addPlayer(T(18, "Virat", 78,487,6),4);
	    addPlayer(T(19, "Rahul", 55, 120, 8),5);
	    addPlayer(T(48, "Raina", 46, 15, 7),6);
	    addPlayer(T(33, "Hardik", 12, 247, 5),7);
	    addPlayer(T(93, "Bumrah", 45, 335, 7),8);
	    addPlayer(T(99, "Ashwin",33 , 332, 4),9);
	    addPlayer(T(8, "Jadeja", 23, 443, 5),10);
    }
    
	//serach player by jno
	template<class T>
	void PlayerManagement<T> :: searchPlayerId(int& jerNum)
	{
		if(start==NULL)
		{
			cout<<"\nTeam is empty!";
		}
		else
		{
			Node<T>* p=start;
			while(p!=NULL)
			{
				if(jerNum==p->getData().getJNo())
				{
					cout<<"-------------------------------------------------------------------------\n";
					cout<<"JNo     |\tName\t|No. of Matches\t|No. of Runs\t|No. of Wickets |\n";
					cout<<"-------------------------------------------------------------------------\n";
					p->getData().displayData();
					cout<<"-------------------------------------------------------------------------\n";
					return;
				}
				p=p->getNext();
			}
			cout<<"\nPlayer not found!";
		}	
	}
	//search by name
	template<class T>
	void PlayerManagement<T> :: searchPlayerName(const char* playerName)
	{
		fflush(stdin);
		if(start==NULL)
		{
			cout<<"\nTeam is empty!";
		}
		else
		{
			Node<T>* p=start;
			while(p!=NULL)
			{
				if(strcasecmp(playerName,p->getData().getName())==0)
				{
					cout<<"-------------------------------------------------------------------------\n";
					cout<<"JNo     |\tName\t|No. of Matches\t|No. of Runs\t|No. of Wickets |\n";
					cout<<"-------------------------------------------------------------------------\n";
					p->getData().displayData();
					cout<<"-------------------------------------------------------------------------\n";
					return;
				}
				p=p->getNext();
			}
			cout<<"\nPlayer not found!";
		}		
	}
	//update player
	template<class T>
	void PlayerManagement<T> :: updatePlayer(int jn)
	{
		if(start==NULL)
		{
			cout<<"\nTeam is empty!";
		}
		else
		{
			Node<T>* p=start;
			while(p!=NULL)
			{
				if(jn==p->getData().getJNo())
				{
					int choice;
					cout<<"\nUpdate:";
					cout<<"\n1.No of runs ";
					cout<<"\n2.No of matches ";
					cout<<"\n3.No of wickets ";
					cin>>choice;
					if(choice==1)
					{
						int runs;
						cout<<"\nEnter runs to update: ";
						cin>>runs;
						Player p1;
						p1=p->getData();
						p1.setRun(runs);
						p->setData(p1);
					}
					else if(choice==2)
					{
						int matches;
						cout<<"\nEnter matches to update: ";
						cin>>matches;
						Player p1;
						p1=p->getData();
						p1.setMatch(matches);
						p->setData(p1);
					}
					else if(choice==3)
					{
						int wickets;
						cout<<"\nEnter wickets to update: ";
						cin>>wickets;
						Player p1;
						p1=p->getData();
						p1.setWickets(wickets);
						p->setData(p1);
					}
					else
					{
					    cout<<"\nInvalid choice!!";
					}
					cout<<"\nUpdated player:\n";
					cout<<"-------------------------------------------------------------------------\n";
					cout<<"JNo     |\tName\t|No. of Matches\t|No. of Runs\t|No. of Wickets |\n";
					cout<<"-------------------------------------------------------------------------\n";
					p->getData().displayData();
					cout<<"-------------------------------------------------------------------------\n";
					return;	
				}
				p=p->getNext();
			}
			cout<<"\nPlayer not found!";
		}
	}	
	//delete player 
	template<class T>
	void PlayerManagement<T> :: deletePlayer(int jn)
	{
		if(start==NULL)
		{
			cout<<"\nTeam is empty!";
			return;
		}
		if(start->getData().getJNo()==jn)
		{
			Node<T>* p=start;
			start=start->getNext();
			cout<<"\nPlayer is deleted...";
			delete p;
			return;
		}
		if(start->getNext()==NULL)
		{
			cout<<"\nPlayer not found! line no 185";
			return;
		}
		Node<T>* p=start;
		T p1=start->getNext()->getData();
		while(p1.getJNo()!=jn && p->getNext()->getNext()!=NULL)
		{
			p=p->getNext();
			p1=p->getNext()->getData();
		}
		if(p1.getJNo()==jn)
		{
			Node<T>* q=p->getNext();
			p->setNext(q->getNext());
			cout<<"\nPlayer deleted..";
			delete q;
			return;
		}
		cout<<"\nPlayer not found!";
      
	}
	//sort player
	template<class T>
	void PlayerManagement<T> :: sortPlayer(int ch)
	{
		for(Node<T>* p=start;p!=NULL;p=p->getNext())
		{
			if(ch!=1 && ch!=2)
			{
				cout<<"\nInvalid choice!!";
				return;
			}
			for(Node<T>* q=p->getNext();q!=NULL;q=q->getNext())
			{
				if(ch==1)
				{
					if(p->getData().getRuns() < q->getData().getRuns())
					{
						T temp=p->getData();
						p->setData(q->getData());
						q->setData(temp);
					}
				}
				else if(ch==2)
				{
					if(p->getData().getWickets()<q->getData().getWickets())
					{
						T temp=p->getData();
						p->setData(q->getData());
						q->setData(temp);
					}
				}
			}
		}
	}
	//display	
	template<class T>
	void PlayerManagement<T> :: displayPlayer()
	{
		if(start==NULL)
		{
			cout<<"LinkedList is Empty\n";
		}
		else
		{
			Node<T>* p=start;
			cout<<"-------------------------------------------------------------------------\n";
			cout<<"JNo     |\tName\t|No. of Matches\t|No. of Runs\t|No. of Wickets |\n";
			cout<<"-------------------------------------------------------------------------\n";
			while(p->getNext()!=NULL)
			{
				p->getData().displayData();
				p=p->getNext();
			}
			p->getData().displayData();
			cout<<"-------------------------------------------------------------------------\n";
		}
	}
	template<class T>
	PlayerManagement<T> :: ~PlayerManagement()		//destructor
	{
		ofstream out("playerInfo.bin",ios_base::binary);
		Node<T>*p=start;
		while(p!=NULL)
		{
			T p1= p->getData();
			out.write((char*)&p1,sizeof(p1));
			p=p->getNext();
		}
		out.close();
		p=start;
		while(p->getNext()!=NULL)
		{
			Node<T>* q=p->getNext();
		    delete p;
		    p=q;
		}
	}

