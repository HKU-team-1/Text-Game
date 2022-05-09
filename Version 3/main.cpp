#include<iostream>
#include<cstdlib>
#include<string>
#include <cstdlib>
#include <ctime>
#include<stdio.h>
#include <fstream>
#include "common.h"

using namespace std;

void BattleDescription();



bool ReadFile(Player &player);
void InitPlayer(Player &player); 
void Tutorial(Player &player);
///////////////////////Main Func is HERE/////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

int main()
{
    int RoundNum=1;
    bool SkipTutorial; 
    Player player;
    
    SkipTutorial=ReadFile(player);//Use ReadFile to aske player whether they need to use previous record, and see if they need tutorial
    
    if(SkipTutorial==false){
    	Tutorial(player);//Carry tutorial
	}
    
    BattleFieldMap map(&player);//initialize battle map
    
    map.randomDestion();//Obviously, he spells destination wrongly
    
    //BattleDescription();
    
    player.ShowBoard();//show player status
    
    ClickEnterToContinue();

    //Round Begin
    bool iswin;//see whether wins
    int sense;//used for labeling the events
    map.showSelf();//show map
    while(player.getHealth()>0)//while the player has not dead
    {
        srand(unsigned(time(0)));
        sense = EventGenerator();//random event
        map.showSelf();
        if(!operatePlayer(player, sense))//trigger the events
        {
            continue;
        }
        RoundNum+=1;
        cout<<endl<<endl;
        iswin = map.checkPlayerPostion();//check if win
        cout<<endl<<endl;
        ClickEnterToContinue();
        
        if(iswin)
        {
            break;
        }
	//Save the data in each move
        ofstream fout;//
        fout.open("playerstatus.txt");
        if (fout.fail()){
            cout<<"Error in file opening!"
               <<endl;
            exit(1);
        }
        int x = player.getNodeX();
        int y = player.getNodeY();
        fout << x << endl;
        fout << y << endl;

        string Name = player.getName();
        fout << Name << endl;
        int Move = player.getMove();
        fout << Move << endl;
        int Health = player.getHealth();
        fout << Health << endl;
        int MaxHealth = player.getMaxHealth();
        fout << MaxHealth << endl;
        int AttackDamage = player.getAttackDamage();
        fout << AttackDamage << endl;
        string AttackName = player.getAttackName();
        fout << AttackName << endl;
        string ShieldName = player.getShieldName();
        fout << ShieldName << endl;

        int Energy = player.getEnergy();
        fout << Energy << endl;
        int MaxEnergy = player.getMaxEnergy();
        fout << MaxEnergy << endl;
        int HealPower = player.getHealPower();
        fout << HealPower << endl;



        //Magic Values
        string FreezeName = player.getFreezeName();
        fout << FreezeName << endl;
        string MagicAttackName = player.getMagicAttackName();
        fout << MagicAttackName << endl;
        string UpgradeName = player.getUpgradeName();
        fout << UpgradeName << endl;
        string CounterMagicName = player.getCounterMagicName();
        fout << CounterMagicName << endl;

        bool Freezed = player.getFreezed();
        fout << Freezed << endl;
        int MagicAttackDamage = player.getMagicAttackDamage();
        fout << MagicAttackDamage << endl;
        int UpgradeBy = player.getUpgradeBy();
        fout << UpgradeBy << endl;
        int UpgradedAttackValues = player.getUpgradedAttackValues();
        fout << UpgradedAttackValues << endl;

        //Magic Cost
        int MagicAttackCost = player.getMagicAttackCost();
        fout << MagicAttackCost << endl;
        int UpgradeCost = player.getUpgradeCost();
        fout << UpgradeCost << endl;
        int FreezeCost = player.getFreezeCost();
        fout << FreezeCost << endl; 
        int CounterMagicCost = player.getCounterMagicCost();
        fout << CounterMagicCost << endl;

        //Potion Values
        int NumOfHealPotion = player.getNumOfHealPotion();
        fout << NumOfHealPotion << endl;
        int NumOfEnergyPotion = player.getKnowEnergyPotion();
        fout << NumOfEnergyPotion << endl;

        //Ability Availability
        bool KnowAttack = player.getKnowAttack();
        fout << KnowAttack << endl;
        bool KnowShield = player.getKnowShield();
        fout << KnowShield << endl;
        bool KnowMagicAttack = player.getKnowMagicAttack();
        fout << KnowMagicAttack << endl;
        bool KnowFreeze = player.getKnowFreeze();
        fout << KnowFreeze << endl;
        bool KnowUpgradeWeapon = player.getKnowUpgradeWeapon();
        fout << KnowUpgradeWeapon << endl;
        bool KnowCounterMagic = player.getKnowCounterMagic();
        fout << KnowCounterMagic << endl;
        bool KnowHealPotion = player.getNumOfHealPotion();
        fout << KnowHealPotion << endl;
        bool KnowEnergyPotion = player.getKnowEnergyPotion();
        fout << KnowEnergyPotion << endl;
        int NumofGem = player.getNumofGem();
        fout << NumofGem << endl;

        fout.close();
        map.showSelf();
	//Player Make Choice to Go to Next Position(can also check status or drink potions)
        player.goNextNode();
    }

    if(iswin)
    {
        map.showSelf();
        cout<<endl<<endl;
        cout<<"YOU WIN !!!"<<endl<<endl;
    }
    else if(player.getHealth()<=0)
    {
        cout<<endl<<endl;
        cout<<"YOU LOOSE"<<endl<<endl;
    }
    else
    {
        cout<<endl<<endl;
        cout<<"YOU WIN !!!"<<endl<<endl;
    }
    int end;
    cin>>end;
    return 0;
}


/////////////////////////////////////////////////////////////////////////
//Initialize the player
void InitPlayer(Player &player){
	string indicator;
	bool done=false;
	cout<<"Please Input Your Name: ";
	cin>>indicator;
	player.ChangeName(indicator);
	cout<<endl;
	cout<<"What's the Game Difficulty You Want (normal is suggested)"<<endl;
	cout<<"(difficulty from low to high: easy,simple,normal,medium,hard,hell,impossible)"<<endl;
	cout<<"Please Input: ";
	cin>>indicator;
	while(done==false){
		if(cin.fail()){
			cout<<"Please Input Again"<<endl<<endl;
			cout<<"What's the Game Difficulty You Want (normal is suggested)"<<endl;
			cout<<"(difficulty from low to high: easy,simple,normal,medium,hard,hell,impossible)"<<endl;
			cout<<"Please Input: ";
			cin>>indicator;
		}
		else if(indicator=="easy"){
			player.ChangeMaxHealth(1000);
			player.IncreaseHealth(1000);
			player.IncreaseAttack(50);
			player.ChangeMaxEnergy(60);
			player.ChangeEnergy(60);
			player.ChangeNumofGem(100);
			player.ChangeMagicAttackDamage(70);
			player.ChangeNumOfEnergyPotion(20);
			player.ChangeNumOfHealPotion(20);
			player.ChangeHealPower(100);
			done=true;
		}
		else if(indicator=="simple"){
			player.ChangeMaxHealth(500);
			player.IncreaseHealth(500);
			player.IncreaseAttack(40);
			player.ChangeMaxEnergy(30);
			player.ChangeEnergy(30);
			player.ChangeNumofGem(40);
			player.ChangeMagicAttackDamage(40);
			player.ChangeNumOfEnergyPotion(10);
			player.ChangeNumOfHealPotion(10);
			player.ChangeHealPower(60);
			done=true;
		}
		else if(indicator=="normal"){
			player.ChangeMaxHealth(150);
			player.IncreaseHealth(150);
			player.IncreaseAttack(10);
			player.ChangeMaxEnergy(20);
			player.ChangeEnergy(20);
			player.ChangeNumofGem(10);
			player.ChangeMagicAttackDamage(30);
			player.ChangeNumOfEnergyPotion(5);
			player.ChangeNumOfHealPotion(5);
			player.ChangeHealPower(45);
			done=true;
		}
		else if(indicator=="medium"){
			player.ChangeMaxHealth(100);
			player.IncreaseHealth(100);
			player.IncreaseAttack(5);
			player.ChangeMaxEnergy(15);
			player.ChangeEnergy(15);
			player.ChangeNumofGem(5);
			player.ChangeMagicAttackDamage(25);
			player.ChangeNumOfEnergyPotion(3);
			player.ChangeNumOfHealPotion(3);
			player.ChangeHealPower(40);
			done=true;
		}
		else if(indicator=="hard"){
			player.ChangeMaxHealth(70);
			player.IncreaseHealth(70);
			player.IncreaseAttack(0);
			player.ChangeMaxEnergy(10);
			player.ChangeEnergy(10);
			player.ChangeNumofGem(0);
			player.ChangeMagicAttackDamage(20);
			player.ChangeNumOfEnergyPotion(1);
			player.ChangeNumOfHealPotion(2);
			player.ChangeHealPower(35);
			done=true;
		}
		else if(indicator=="hell"){
			player.ChangeMaxHealth(60);
			player.IncreaseHealth(60);
			player.IncreaseAttack(-5);
			player.ChangeMaxEnergy(8);
			player.ChangeEnergy(8);
			player.ChangeNumofGem(0);
			player.ChangeMagicAttackDamage(18);
			player.ChangeNumOfEnergyPotion(0);
			player.ChangeNumOfHealPotion(0);
			player.ChangeHealPower(30);
			done=true;
		}
		else if(indicator=="impossible"){
			player.ChangeMaxHealth(40);
			player.IncreaseHealth(40);
			player.IncreaseAttack(-7);
			player.ChangeMaxEnergy(5);
			player.ChangeEnergy(5);
			player.ChangeNumofGem(0);
			player.ChangeMagicAttackDamage(15);
			player.ChangeNumOfEnergyPotion(0);
			player.ChangeNumOfHealPotion(0);
			player.ChangeHealPower(25);
			done=true;
		}
		else{
			cout<<"Please Input Again"<<endl<<endl;
			cout<<"What's the Game Difficulty You Want (normal is suggested)"<<endl;
			cout<<"(difficulty from low to high: easy,simple,normal,medium,hard,hell,impossible)"<<endl;
			cout<<"Please Input: ";
			cin>>indicator;
		}
	}
	player.ChangeKnowCounterMagic();
	player.ChangeKnowFreeze();
	player.ChangeKnowMagicAttack();
	player.ChangeKnowUpgradeWeapon();
}

//Read Previous Record Or Start New Game
bool ReadFile(Player &player){
	string indicator;
    cout<<endl<<endl<<"Do You Want To Continue From Previous Game Record?"<<endl<<endl;
    cout<<"y/n: ";
    cin>>indicator;
    cout<<endl;
    while(indicator!="y" && indicator!="n"){
    	cout<<"Please Input Again (y/n): ";
    	cin>>indicator;
	}
	if(indicator=="y"){
		 
		cout<<"Please Input The File Name of The Record: ";
		cin>>indicator;
		ifstream fin;
		fin.open(indicator);
		while(fin.fail()){
			cout<<"Wrong Input"<<endl;
			cout<<"Please Input The File Name of The Record: ";
			cin>>indicator;
			ifstream fin;
			fin.open(indicator);
		}
		int x,y,Move,Health,MaxHealth,AttackDamage,Energy,MaxEnergy,HealPower,MagicAttackDamage,UpgradeBy,UpgradedAttackValues,MagicAttackCost,UpgradeCost,FreezeCost,CounterMagicCost,NumOfHealPotion,NumOfEnergyPotion,NumofGem;
		string Name,AttackName,ShieldName,FreezeName,MagicAttackName,UpgradeName,CounterMagicName;
		bool Freezed,KnowAttack,KnowShield,KnowMagicAttack,KnowFreeze,KnowUpgradeWeapon,KnowCounterMagic,KnowHealPotion,KnowEnergyPotion;
		fin>>x>>y>>Name>>Move>>Health>>MaxHealth>>AttackDamage>>AttackName>>ShieldName>>Energy>>MaxEnergy>>HealPower>>FreezeName>>MagicAttackName>>UpgradeName>>CounterMagicName>>Freezed>>MagicAttackDamage>>UpgradeBy>>UpgradedAttackValues>>MagicAttackCost>>UpgradeCost>>FreezeCost>>CounterMagicCost>>NumOfHealPotion>>NumOfEnergyPotion>>KnowAttack>>KnowShield>>KnowMagicAttack>>KnowFreeze>>KnowUpgradeWeapon>>KnowCounterMagic>>KnowHealPotion>>KnowEnergyPotion>>NumofGem;
		player.ChangeName(Name);
		player.ChangeNodeX(x);
		player.ChangeNodeY(y);
		player.ChangeMove(Move);
		player.ChangeHealth(Health);
		player.ChangeMaxHealth(MaxHealth);
		player.ChangeAttackDamage(AttackDamage);
		player.ChangeAttackName(AttackName);
		player.ChangeShieldName(ShieldName);
		player.ChangeEnergy(Energy);
		player.ChangeMaxEnergy(MaxEnergy);
		player.ChangeHealPower(HealPower);
		player.ChangeFreezeName(FreezeName);
		player.ChangeMagicAttackName(MagicAttackName);
		player.ChangeUpgradeName(UpgradeName);
		player.ChangeCounterMagicName(CounterMagicName);
		player.RecordFreezed(Freezed);
		player.ChangeMagicAttackDamage(MagicAttackDamage);
		player.ChangeUpgradeBy(UpgradeBy);
		player.ChangeUpgradedAttackValues(UpgradedAttackValues);
		player.ChangeMagicAttackCost(MagicAttackCost);
		player.ChangeFreezeCost(FreezeCost);
		player.ChangeUpgradeCost(UpgradeCost);
		player.ChangeCounterMagicCost(CounterMagicCost);
		player.ChangeNumOfHealPotion(NumOfHealPotion);
		player.ChangeNumOfEnergyPotion(NumOfEnergyPotion);
		player.ChangeCheckKnowAttack(KnowAttack);
		player.ChangeCheckKnowShield(KnowShield);
		player.ChangeCheckKnowMagicAttack(KnowMagicAttack);
		player.ChangeCheckKnowFreeze(KnowFreeze);
		player.ChangeCheckKnowUpgradeWeapon(KnowUpgradeWeapon);
		player.ChangeCheckKnowCounterMagic(KnowCounterMagic);
		player.ChangeCheckKnowHealPotion(KnowHealPotion);
		player.ChangeCheckKnowEnergyPotion(KnowEnergyPotion);
		player.ChangeNumofGem(NumofGem);
		return true;
	}
	else{
		InitPlayer(player);
		return false;
	}
	//To be Continued
}



//Guide the Player
void Tutorial(Player &player){
	int command;
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"You open your eyes and find yourself in the deep woods."<<endl<<endl;
	cout<<"\"Who am I? What am I doing here?\""<<endl<<endl;
	cout<<"Slowly, You Recall. You are an adventurer whose exploring a forest at the end of the world"<<endl<<endl;
	cout<<"Unfortunately, a flood washes you and your friends away."<<endl<<endl;
	cout<<"You recalled that one of the teammate has loud voice."<<endl<<endl;
	ClickEnterToContinue();
	cout<<"You hear raven caws. And then you hear some creepy groan beside you."<<endl<<endl;
	ClickEnterToContinue();
	cout<<"You don¡¯t feel right"<<endl<<endl;
	ClickEnterToContinue();
	cout<<"\"I have to leave here now!\""<<endl<<endl;
	cout<<"LEAVE THIS PLACE AND FIND YOUR TEAMMATES !!!"<<endl<<endl;
	ClickEnterToContinue();
	cout<<"Suddenly, A ZOMBIE CREEPS OUT from the earth in front of you!"<<endl<<endl;
	ClickEnterToContinue();
	cout<<"{You encouter an enemy}"<<endl<<endl;
	player.ShowBoard();
	Player enemy;
	enemy.ChangeName("zombie");
	//Health
	enemy.ChangeMaxHealth(1);
	enemy.IncreaseHealth(1);
	//Attack
	enemy.ChangeAttackName("Zombie Attack");
	enemy.IncreaseAttack(-8);
	//Gem
	enemy.ChangeNumofGem(1);
	//Magic
	enemy.ChangeKnowCounterMagic();
	enemy.ChangeKnowFreeze();
	enemy.ChangeKnowMagicAttack();
	enemy.ChangeKnowUpgradeWeapon();
	//Potion
	enemy.ChangeNumOfHealPotion(0);
	enemy.ChangeNumOfEnergyPotion(0);
	enemy.ShowBoard();
	cout<<"-----Round-----"<<endl;
	cout<<"(1--Attack)"<<endl;
	cout<<"try input 1"<<endl;
	cout<<"Input: ";
	cin>>command;
	while(command!=1|| cin.fail()){
		cout<<"please input again, try input 1"<<endl;
		cout<<"Input: ";
		cin>>command;
	}
	cout<<"You choose attack"<<endl<<endl;
	cout<<"Your enemy choose attack"<<endl<<endl;
	cout<<"Your attack exceeds your enemy's"<<endl<<endl;
	cout<<player.getAttackDamage()-enemy.getAttackDamage()<<" points of attack on your enemy"<<endl<<endl;
	ClickEnterToContinue();
	enemy.ChangeMaxHealth(0);
	enemy.IncreaseHealth(0);
	player.ShowBoard();
	enemy.ShowBoard();
	
	cout<<endl<<endl<<"You Win"<<endl<<endl<<endl<<endl;
	
	
	// Second Enemy
	
	ClickEnterToContinue();
	
	cout<<"Suddenly, The Earth is Shaking!!!"<<endl<<endl;
	cout<<"\"Something bigger is comming, NO!\""<<endl<<endl;
	ClickEnterToContinue();
	cout<<"Suddenly, a Zombie KING creeps out in front of you!"<<endl<<endl;
	ClickEnterToContinue();
	cout<<"{You encouter an enemy}"<<endl<<endl;
	player.ShowBoard();
	enemy.ChangeName("ZOMBIE KING");
	//Health
	enemy.ChangeMaxHealth(100);
	enemy.IncreaseHealth(100);
	//Attack
	enemy.ChangeAttackName("Zombie Attack");
	enemy.IncreaseAttack(118);
	//Gem
	enemy.ChangeNumofGem(0);
	//Potion
	enemy.ChangeNumOfHealPotion(0);
	enemy.ChangeNumOfEnergyPotion(0);
	enemy.ShowBoard();
	cout<<"-----Round-----"<<endl;
	cout<<"(1--Attack, 2--Shield)"<<endl;
	cout<<"try input 2"<<endl;
	cout<<"Input: ";
	cin>>command;
	while(command!=2 || cin.fail()){
		cout<<"The Zombie Has HIGHER Attack, your attack cannot surpass it"<<endl;
		cout<<"try input 2"<<endl;
		cout<<"Input: ";
		cin>>command;
	}
	cout<<"You choose Shield"<<endl<<endl;
	cout<<"Your enemy choose Attack"<<endl<<endl;
	cout<<"You Rebounds Your Enemy's Attack"<<endl<<endl;
	cout<<"Rebound Damage On Your Enemy: 120"<<endl<<endl;
	ClickEnterToContinue();
	cout<<player.getAttackDamage()-enemy.getAttackDamage()<<" points of attack on your enemy"<<endl<<endl;
	enemy.ChangeMaxHealth(0);
	enemy.IncreaseHealth(0);
	player.ShowBoard();
	enemy.ShowBoard();
	cout<<endl<<endl<<"You Win"<<endl<<endl;
	cout<<"You Finally Escape From this Spot"<<endl;
	
}










/*Original
void Player::goNextNode()
{
    char move_direction = '0';
    this->ShowBoard();
    while (NumOfEnergyPotion != 0 && Energy != MaxEnergy) {
        cout << "Do you want to drink an energy potion to get ready for next unpredictable situation?" << endl;
        cout << "A--Yes, B--No" << endl;
        cin >> move_direction;
        if (move_direction == 'a' || move_direction == 'A') {
            NumOfEnergyPotion -= 1;
            Energy = MaxEnergy;
            this->ShowBoard();
        }
        else {
            cout << "It is wasting." << endl;
            break;
        }

    }
    while (NumOfHealPotion != 0 && Health != MaxHealth) {
        cout << "Do you want to drink a heal potion to get ready for next unpredictable situation?" << endl;
        cout << "A--Yes, B--No" << endl;
        cin >> move_direction;
        if (move_direction == 'a' || move_direction == 'A') {
            NumOfHealPotion -= 1;

            IncreaseHealth(HealPower);
            this->ShowBoard();
        }
        else {
            cout << "It is wasting." << endl;
            break;
        }

    }
    while(true){
        cout<<"Please input your move direction(A--left, D--right, W--up, S--down): ";
        cin>>move_direction;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Your input is not in the choices, please input again"<<endl<<endl;
        }
        else if(move_direction == 'a' || move_direction == 'A')
        {
            x = x - 1;
            x = x < 0 ? 0:x;
            break;
        }
        else if(move_direction == 'd' || move_direction == 'D')
        {
            x = x + 1;
            x = x > MAP_SIZE - 1 ? MAP_SIZE - 1:x;
            break;
        }
        else if(move_direction == 'w' || move_direction == 'W')
        {
            y = y - 1;
            y = y < 0 ? 0:y;
            break;
        }
        else if(move_direction == 's' || move_direction == 'S')
        {
            y = y + 1;
            y = y > MAP_SIZE - 1 ? MAP_SIZE - 1:y;
            break;
        }
        else
        {
            cout<<"Your input is not in the choices, please input again"<<endl<<endl;
        }
    }
}*/

