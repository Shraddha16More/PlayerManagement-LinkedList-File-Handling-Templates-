using namespace std;
#include<iostream>
#include<string.h>
#include"player.h"
#include"player_management.h"

	Player :: Player()
	{
		this->j_no=0;
		strcpy(this->name,"Not Given !!");
		this->no_of_matches=0;
		this->no_of_runs=0;
		this->no_of_wickets=0;
	}
	Player :: Player(int jno,const char* nm, int m,int r, int w)
	{
		this->j_no=jno;
		strcpy(this->name,nm);
		this->no_of_matches=m;
		this->no_of_runs=r;
		this->no_of_wickets=w;
	}
	void Player :: setJNo(int jno)
	{
		this->j_no=jno;
	}
	void Player :: setName(const char* nm)
	{
		strcpy(this->name,nm);
	}
	void Player :: setMatch(int m)
	{
		this->no_of_matches=m;
	}
	void Player :: setRun(int r)
	{
		this->no_of_runs=r;
	}
	void Player :: setWickets(int w)
	{
		this->no_of_wickets=w;
	}
	
	int Player :: getJNo()
	{
		return this->j_no;
	}
	char* Player :: getName()
	{
		return this->name;
	}
	int Player :: getMatch()
	{
		return this->no_of_matches;
	}
	int Player :: getRuns()
	{
		return this->no_of_runs;
	}
	int Player :: getWickets()
	{
		return this->no_of_wickets;
	}
	//display players
	void Player :: displayData()
	{
		cout<<this->j_no<<"\t|\t";
		cout<<this->name<<"\t|\t";
		cout<<this->no_of_matches<<"\t|\t";
		cout<<this->no_of_runs<<"\t|\t";
		cout<<this->no_of_wickets<<"\t|\n";
	}
	
