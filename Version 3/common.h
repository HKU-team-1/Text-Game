#ifndef COMMON_H
#define COMMON_H
#include<iostream>
#include<cstdlib>
#include<string>
#include <cstdlib>
#include <ctime>
#include<stdio.h>
#include <fstream>
using namespace std;

#define MAP_SIZE (13)
//The Size of the map
#define DESTION_SCOPE_SIZE_SIDE_BY (3)
#define DESTION_SCOPE_SIZE_NEAR (5) 
//Correction:Destination
#define SEPARATER "      "
#define PRINT_SEPARATER cout<<SEPARATER;
#include<iostream>
//the following is used for representing the events
enum PlaySense
{
    PlaySense_Error = 0,
    PlaySense_1,
    PlaySense_2,
    PlaySense_3,
    PlaySense_4,
    PlaySense_5,
    PlaySense_6,
    PlaySense_7,
    PlaySense_8,
    PlaySense_9,
    PlaySense_X,
};

//The following are the player's data
class Player
{
public:
    void goNextNode();
    void ShowBoard();
    void ShowPlayerBoard();

    //Functions of Basic Values
    string getName();
    int getNodeX();
    int getNodeY();
    int getMove();
    int getHealth();
    int getMaxHealth();
    int getAttackDamage();
    string getAttackName();
    string getShieldName();
    int getReboundDamage();
    int getEnergy();
    int getMaxEnergy();
    void IncreaseMaxHealth(int value);
    void ChangeName(string NewName);
    void ChangeNodeX(int value);
    void ChangeNodeY(int value);
    void ChangeHealth(int value);
    void ChangeMove(int value);
    void IncreaseHealth(int value);
    void ChangeMaxHealth(int value);
    void IncreaseAttack(int value);
    void IncreaseMagicAttack(int value);
    void IncreaseMaxEnergy(int value);
    void IncreaseNumofGem(int value);
    void ChangeAttackName(string NewName);
    void ChangeAttackDamage(int value);
    void ChangeShieldName(string NewName);
    void ChangeReboundDamage(int value);
    void ChangeEnergy(int value);
    void ChangeMaxEnergy(int value);
    void ChangeHealPower(int value);
	int getHealPower();
	void RecordFreezed(bool value);
    //Functions of Magic Values
    string getFreezeName();
    string getMagicAttackName();
    string getUpgradeName();
    string getCounterMagicName();
    bool getFreezed();
    int getMagicAttackDamage();
    int getUpgradeBy();
    int getUpgradedAttackValues();
    int getMagicAttackCost();
    int getFreezeCost();
    int getUpgradeCost();
    int getCounterMagicCost();
    int getNumOfHealPotion();
    int getNumOfEnergyPotion();
    int getNumofGem();
    void ChangeFreezeName(string NewName);
    void ChangeMagicAttackName(string NewName);
    void ChangeUpgradeName(string NewName);
    void ChangeCounterMagicName(string NewName);
    void ChangeFreezed();
    void ChangeMagicAttackDamage(int value);
    void ChangeUpgradeBy(int value);
    void ChangeUpgradedAttackValues(int value);
    void ChangeMagicAttackCost(int value);
    void ChangeFreezeCost(int value);
    void ChangeUpgradeCost(int value);
    void ChangeCounterMagicCost(int value);
    void ChangeNumOfHealPotion(int value);
    void ChangeNumOfEnergyPotion(int value);
    void ChangeNumofGem(int value);

    //Ability Availability
    int GemTrade();

    bool getKnowAttack();
    bool getKnowShield();
    bool getKnowMagicAttack();
    bool getKnowFreeze();
    bool getKnowUpgradeWeapon();
    bool getKnowCounterMagic();
    bool getKnowHealPotion();
    bool getKnowEnergyPotion();
    void ChangeKnowAttack();
    void ChangeKnowShield();
    void ChangeKnowMagicAttack();
    void ChangeKnowFreeze();
    void ChangeKnowUpgradeWeapon();
    void ChangeKnowCounterMagic();
    void ChangeKnowHealPotion();
    void ChangeKnowEnergyPotion();
    void ChangeCheckKnowAttack(bool value);
    void ChangeCheckKnowShield(bool value);
    void ChangeCheckKnowMagicAttack(bool value);
    void ChangeCheckKnowFreeze(bool value);
    void ChangeCheckKnowUpgradeWeapon(bool value);
    void ChangeCheckKnowCounterMagic(bool value);
    void ChangeCheckKnowHealPotion(bool value);
    void ChangeCheckKnowEnergyPotion(bool value);



    //MOVES
    void DrawEnergy();

    //Player's Move
    //Player's moves are processed before enemy's moves, so special cases are processed in player's moves.
    //(in enemy's moves, special cases are passed)
    void PlayerAttack(Player &enemy);// move 1
    void PlayerShield(Player &enemy);// move 2
    void PlayerMagicAttack(Player &enemy);// move 3
    void PlayerFreeze(Player &enemy);// move 4
    void PlayerUpgradeWeapon(Player &enemy);// move 5
    void PlayerCounterMagic(Player &enemy);// move 6
    void PlayerDrinkHealPotion(Player &enemy);// move 7
    void PlayerDrinkEnergyPotion(Player &enemy);// move 8

    //Enemy's Move

    void EnemyAttack(Player &player);// move 1
    void EnemyShield(Player &player);// move 2
    void EnemyMagicAttack(Player &player);// move 3
    void EnemyFreeze(Player &player);// move 4
    void EnemyUpgradeWeapon(Player &player);// move 5
    void EnemyCounterMagic(Player &player);// move 6
    void EnemyDrinkHealPotion(Player &player);// move 7
    void EnemyDrinkEnergyPotion(Player &player);// move 8
    void EnemyShowBoard();

    //Player Generate Move
    void PlayerMakeMove();

    //Enemy Generate Move
    void Enemy1MakeMove(Player &player);
    void Enemy2MakeMove(Player &player);
    void Enemy3MakeMove(Player &player);
    void Enemy4MakeMove(Player &player);
    void Enemy5MakeMove(Player &player);
    
    void Regular_EnemyMakeMove(Player &player);
    void ShieldMaster_EnemyMakeMove(Player &player);//Does a lot of shield
    void Mage_EnemyMakeMove(Player &player);//Does a lot of magic
    void Warrior_EnemyMakeMove(Player &player);//Does a lot of attack
    void Noob_EnemyMakeMove(Player &player); //noob
    void Tank_EnemyMakeMove(Player &player);

    //Player Carry Move
    void PlayerCarryMove(Player &enemy);

    //Enemy Carry Move
    void EnemyCarryMove(Player &player);


private:
    //Basic Values
    string Name="Player";
    int Move=0;
    int Health=100;
    int MaxHealth=100;
    int AttackDamage=10;
    string AttackName="Attack";
    string ShieldName="Shield";
    int ReboundDamage=20;//This value is not used anymore
    int Energy=10;
    int MaxEnergy=10;
    int OverdrawDamageWeight=10;
    int NumofGem=0;

    //Magic Values
    string FreezeName="Freeze";
    string MagicAttackName="Fire Ball";
    string UpgradeName="Enchant Weapon";
    string CounterMagicName="Counter Magic";
    bool Freezed=false;
    int MagicAttackDamage=25;
    int UpgradeBy=5;
    int UpgradedAttackValues=0;

    //Magic Cost
    int MagicAttackCost=5;
    int UpgradeCost=3;
    int FreezeCost=5;
    int CounterMagicCost=1;

    //Potion Values
    int NumOfHealPotion=3;
    int NumOfEnergyPotion=3;
    int HealPower=45;

    //Ability Availability
	//This shows whether the ability has been unlocked
    bool KnowAttack=true;
    bool KnowShield=true;
    bool KnowMagicAttack=true;
    bool KnowFreeze=true;
    bool KnowUpgradeWeapon=true;
    bool KnowCounterMagic=true;
    bool KnowHealPotion=true;
    bool KnowEnergyPotion=true;

    //Ability array
    string Abilities[8]={AttackName,ShieldName,MagicAttackName,FreezeName,
                         UpgradeName,CounterMagicName,"Heal Potion","Energy Potion"};
public:
    int x = 1;
    int y = MAP_SIZE - 1;

};

//Data of the map
class BattleFieldMap
{
public:
    BattleFieldMap(Player*);
    void showSelf();
    bool isPointOnDestion(int x, int y);
    bool isPointNearDest(int x, int y);
    bool isPointSideByDest(int x, int y);
    void randomDestion();
    bool checkPlayerPostion();
    //int m_player_x;
    //int m_player_y;
    int m_destion_x;
    int m_destion_y;
    Player* m_pplayer;
};

void ClickEnterToContinue(){
    cout<<"Click Any Key to Continue ";
    getchar();
    cout<<"\r";
    cout<<"                         ";
    cout<<"\r";
}


using namespace std;

//Generates events in certain probability
int EventGenerator(){
	int RandIndex;
    srand(unsigned(time(0)));
    RandIndex=rand() % 100 + 1;
    if(RandIndex<=7){
    	return 1;
	}
	else if(RandIndex<=14){
    	return 2;
	}
	else if(RandIndex<=21){
    	return 3;
	}
	else if(RandIndex<=28){
    	return 4;
	}
	else if(RandIndex<=35){
    	return 5;
	}
	else if(RandIndex<=40){
    	return 6;
	}
	else if(RandIndex<=42){
    	return 7;
	}
	else if(RandIndex<=50){
    	return 8;
	}
	else{
		return 9;
	}
}

//Enemy data of Noob type
void Noob_Enemy(Player &enemy,int EnemyLevel){//denotes increment on all the values(EnemyLevel:1-3
	srand(unsigned(time(0)));
	int NameIndex;
	string Names[24]={"Goblin","Skeloton","Ghost","Wolf","Murloc","cRaZY cR0Ww","Acidic Ooze","Ironbeak Own",
	"Life Drinker","Void Ripper","Abomination","Magma Rager","Nightmare Amalgam","Raging Worgen","Ironfur Grizzly",
	"Sad Ghoul","Igneous Elemental","Imp","Gluttonous Ooze","Faceless Hawk","Vicious Scalehide","Wraith","Creeper"}; 
	NameIndex=rand()%10;
	enemy.ChangeName(Names[NameIndex]);
	//Health
	enemy.ChangeMaxHealth(10+5*EnemyLevel-(NameIndex==5?10:0));
	enemy.IncreaseHealth(0);
	//Attack
	enemy.ChangeAttackName("Stick Attack");
	enemy.IncreaseAttack(1*EnemyLevel-10+(NameIndex==5?15:0));
	//Gem
	enemy.ChangeNumofGem(5*EnemyLevel);
	//Magic
	enemy.ChangeKnowCounterMagic();
	enemy.ChangeKnowFreeze();
	enemy.ChangeKnowMagicAttack();
	enemy.ChangeKnowUpgradeWeapon();
	//Potion
	enemy.ChangeNumOfHealPotion(0);
	enemy.ChangeNumOfEnergyPotion(0);
}
void Player::Noob_EnemyMakeMove(Player &player){
	int RandMove;
	srand(unsigned(time(0)));
	RandMove=rand() % 100 + 1;
	
	if(RandMove<=70){//Attack
		Move=1;
	}
	else{
		if(player.Freezed==1){
			Move=1;
		}
		else{
			Move=2;
		}
	}
	
	cout<<endl<<"CHOICE of "<<Name<<":"<<"Your enemy choose \""<<Abilities[Move-1]<<"\""<<endl<<endl<<endl;
	
}

//Enemy Data of Shield Master type
void ShieldMaster_Enemy(Player &enemy,int EnemyLevel){
	srand(unsigned(time(0)));
	string Names[18]={"Mask Goblin","Mask Skeloton","Tar Creeper","Dark Dwarf","Sludge Belcher","Rotten Shield Smith",
	"Fungalmancer","Carnivorous Cube","Chromatic Egg","Grave Keeper","Unbreakable Beetle","Voidwalker","Felgaurd",
	"Bloodhoof Defender","Deathlord","Dread Defender","Rotten Applebaum","Ironbark Protector"};
	enemy.ChangeName(Names[rand()%10]);
	//Health
	enemy.ChangeMaxHealth(10*EnemyLevel);
	enemy.IncreaseHealth(0);
	//Attack
	enemy.IncreaseAttack(3*EnemyLevel-10);
	//Magic
	enemy.ChangeMagicAttackCost(EnemyLevel*1);
	enemy.ChangeMagicAttackDamage(EnemyLevel*9);
	//Potion
	enemy.ChangeNumOfHealPotion(10);
	enemy.ChangeNumOfEnergyPotion(0);
	//Magic
	enemy.ChangeKnowCounterMagic();
	enemy.ChangeKnowFreeze();
	enemy.ChangeKnowUpgradeWeapon();
	//Gem
	enemy.ChangeNumofGem(5*EnemyLevel);
}
void Player::ShieldMaster_EnemyMakeMove(Player &player){
	int RandMove;
    srand(unsigned(time(0)));
    RandMove=rand() % 100 + 1;
    //30%Attack,15%Shield,10%MagicAttack,2%Freeze,30%UpgradeWeapon,3%CounterMagic,5%For Each potion
    if(RandMove<=10){//Attack
        Move=1;
    }
    else if(RandMove<=80){//Shield
        if(player.Freezed==1){
            Move=1;
        }
        else{
            Move=2;
        }
    }
    else if(RandMove<=95){//Magic Attack
        if(Energy<MagicAttackCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=3;
        }
    }
    else if(RandMove<=100){
        if(NumOfHealPotion>0){
            if(Health<MaxHealth*2/3){
                Move=7;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=1;
        }
    }

    cout<<endl<<"CHOICE of "<<Name<<":"<<"Your enemy choose \""<<Abilities[Move-1]<<"\""<<endl<<endl<<endl;

	
}

//Enemy data of regular enemy
void Regular_Enemy(Player &enemy,int EnemyLevel){
	srand(unsigned(time(0)));
	string Names[11]={"Twilight Drake","Faceless Manipulator","Azure Drake","Ice Revenant","Forest Wyrm","Boulderfist Ogre",
	"Blackwing Corrupter","Twilight Guardian","Steel Rager","Snapjaw","Eater of Secrets"}; 
	enemy.ChangeName(Names[rand()%10]);
	//Health
	enemy.ChangeMaxHealth(30+5*EnemyLevel);
	enemy.IncreaseHealth(0);
	//Attack
	enemy.IncreaseAttack(5*EnemyLevel-10);
	//Magic
	enemy.ChangeMagicAttackCost(EnemyLevel*1);
	enemy.ChangeMagicAttackDamage(7+EnemyLevel*3);
	//Potion
	enemy.ChangeNumOfEnergyPotion(10);
	enemy.ChangeNumOfHealPotion(10);
	
	//Gem
	enemy.ChangeNumofGem(5+5*EnemyLevel);
}
void Player::Regular_EnemyMakeMove(Player &player){
	int RandMove;
    srand(unsigned(time(0)));
    RandMove=rand() % 100 + 1;
    //30%Attack,15%Shield,10%MagicAttack,2%Freeze,30%UpgradeWeapon,3%CounterMagic,5%For Each potion
    if(RandMove<=30){//Attack
        Move=1;
    }
    else if(RandMove<=45){//Shield
        if(player.Freezed==1){
            Move=1;
        }
        else{
            Move=2;
        }
    }
    else if(RandMove<=55){//Magic Attack
        if(Energy<MagicAttackCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=3;
        }
    }
    else if(RandMove<=57){//Freeze
        if(Energy<FreezeCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else if(player.Freezed==1){
            Move=1;
        }
        else{
            Move=4;
        }
    }
    else if(RandMove<=87){//Upgrade Weapon
        if(Energy<UpgradeCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=5;
        }
    }
    else if(RandMove<=90){//Counter Magic
        if(Energy<CounterMagicCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else if(player.Freezed==1){
                Move=1;
            }
            else{
                Move=1;
            }
        }
        else if(player.getEnergy()<3){
            Move=1;
        }
        else{
            Move=6;
        }
    }
    else if(RandMove<=95){
        if(NumOfHealPotion>0){
            if(Health<(Health-HealPower)){
                Move=7;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=1;
        }
    }
    else if(RandMove<=100){
        if(NumOfEnergyPotion>0){
            if(Energy<3){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=1;
        }
    }

    cout<<endl<<"CHOICE of "<<Name<<":"<<"Your enemy choose \""<<Abilities[Move-1]<<"\""<<endl<<endl<<endl;
}

//Enemy Data of Mage Type
void Mage_Enemy(Player &enemy,int EnemyLevel){
	srand(unsigned(time(0)));
	string Names[11]={"Mage","Witch","Sorceress","Sorcerer","Bloodmage","Doomsayer","Crazed Alchemist","Pyromancer",
	"Coledlight Seer","Arcane Devourer","Archmage"}; 
	enemy.ChangeName(Names[rand()%10]);
	//Health
	enemy.ChangeMaxHealth(10+5*EnemyLevel);
	enemy.IncreaseHealth(0);
	//Enegy
	enemy.ChangeEnergy(5*EnemyLevel);
	enemy.ChangeMaxEnergy(10*EnemyLevel);
	//Attack
	enemy.IncreaseAttack(5*EnemyLevel-10);
	//Magic
	enemy.ChangeMagicAttackDamage(10+5*EnemyLevel);
	//Potion
	enemy.ChangeNumOfEnergyPotion(100);
	enemy.ChangeNumOfHealPotion(10);
	
	//Gem
	enemy.ChangeNumofGem(10*EnemyLevel);
}
void Player::Mage_EnemyMakeMove(Player &player){
	int RandMove;
    srand(unsigned(time(0)));
    RandMove=rand() % 100 + 1;
    //5%Attack,10%Shield,50%MagicAttack,10%Freeze,1%UpgradeWeapon,4%CounterMagic,10%For Each potion
    if(RandMove<=5){//Attack
        Move=1;
    }
    else if(RandMove<=15){//Shield
        if(player.Freezed==1){
            Move=1;
        }
        else{
            Move=2;
        }
    }
    else if(RandMove<=65){//Magic Attack
        if(Energy<MagicAttackCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=3;
        }
    }
    else if(RandMove<=75){//Freeze
        if(Energy<FreezeCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else if(player.Freezed==1){
            Move=1;
        }
        else{
            Move=4;
        }
    }
    else if(RandMove<=76){//Upgrade Weapon
        if(Energy<UpgradeCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=5;
        }
    }
    else if(RandMove<=80){//Counter Magic
        if(Energy<CounterMagicCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else if(player.Freezed==1){
                Move=1;
            }
            else{
                Move=1;
            }
        }
        else if(player.getEnergy()<3){
            Move=1;
        }
        else{
            Move=6;
        }
    }
    else if(RandMove<=90){
        if(NumOfHealPotion>0){
            if(Health<(Health-HealPower)){
                Move=7;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=1;
        }
    }
    else if(RandMove<=10){
        if(NumOfEnergyPotion>0){
            if(Energy<3){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=1;
        }
    }

    cout<<endl<<"CHOICE of "<<Name<<":"<<"Your enemy choose \""<<Abilities[Move-1]<<"\""<<endl<<endl<<endl;
}

//Enemy Data of Warrior Type
void Warrior_Enemy(Player &enemy,int EnemyLevel){
	srand(unsigned(time(0)));
	string Names[11]={"Chillwind Yeti","Bloodhoof","Mossy Horror","Storm Watcher","Twin Tyrant","Corridor Creeper",
	"Core Hound","Bonemare","Windfury Harpy","Necrotic Geist","Evasive Whelp"}; 
	enemy.ChangeName(Names[rand()%10]);
	//Health
	enemy.ChangeMaxHealth(20+5*EnemyLevel);
	enemy.IncreaseHealth(0);
	//Attack
	enemy.IncreaseAttack(5*EnemyLevel);
	//Magic
	enemy.ChangeMagicAttackDamage(10+5*EnemyLevel);
	//Potion
	enemy.ChangeNumOfEnergyPotion(3);
	enemy.ChangeNumOfHealPotion(5);
	
	//Gem
	enemy.ChangeNumofGem(3*EnemyLevel);
}
void Player::Warrior_EnemyMakeMove(Player &player){
	int RandMove;
    srand(unsigned(time(0)));
    RandMove=rand() % 100 + 1;
    //60%Attack,10%Shield,1%MagicAttack,1%Freeze,20%UpgradeWeapon,1%CounterMagic,6%Heal potion,1%Energy potion
    if(RandMove<=60){//Attack
        Move=1;
    }
    else if(RandMove<=70){//Shield
        if(player.Freezed==1){
            Move=1;
        }
        else{
            Move=2;
        }
    }
    else if(RandMove<=71){//Magic Attack
        if(Energy<MagicAttackCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=3;
        }
    }
    else if(RandMove<=72){//Freeze
        if(Energy<FreezeCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else if(player.Freezed==1){
            Move=1;
        }
        else{
            Move=4;
        }
    }
    else if(RandMove<=92){//Upgrade Weapon
        if(Energy<UpgradeCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=5;
        }
    }
    else if(RandMove<=93){//Counter Magic
        if(Energy<CounterMagicCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else if(player.Freezed==1){
                Move=1;
            }
            else{
                Move=1;
            }
        }
        else if(player.getEnergy()<3){
            Move=1;
        }
        else{
            Move=6;
        }
    }
    else if(RandMove<=99){
        if(NumOfHealPotion>0){
            if(Health<(Health-HealPower)){
                Move=7;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=1;
        }
    }
    else if(RandMove<=100){
        if(NumOfEnergyPotion>0){
            if(Energy<3){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=1;
        }
    }

    cout<<endl<<"CHOICE of "<<Name<<":"<<"Your enemy choose \""<<Abilities[Move-1]<<"\""<<endl<<endl<<endl;
}

//Enemy Data of Tank Type
void Tank_Enemy(Player &enemy,int EnemyLevel){
	srand(unsigned(time(0)));
	int NameIndex;
	string Names[10]={"Sea Giant","Dryad","Jade Golem","Quartz Golem","Iron Golem","Gem Golem","Arcane Giant",
	"Mountain Giant","Molten Giant","Firelord"};
	NameIndex=rand()%10;
	enemy.ChangeName(Names[NameIndex]);
	//Health
	enemy.ChangeMaxHealth(40+30*EnemyLevel);
	enemy.IncreaseHealth(0);
	//Attack
	//Magic
	enemy.ChangeMagicAttackDamage(5+EnemyLevel*5);
	//Potion
	enemy.ChangeNumOfHealPotion(10);
	
	//Gem
	enemy.ChangeNumofGem(10*EnemyLevel+(NameIndex==5?150:0));
}
void Player::Tank_EnemyMakeMove(Player &player){
	int RandMove;
    srand(unsigned(time(0)));
    RandMove=rand() % 100 + 1;
    //20%Attack,20%Shield,5%MagicAttack,20%Freeze,10%UpgradeWeapon,10%CounterMagic,10%Heal,5%Energy
    if(RandMove<=20){//Attack
        Move=1;
    }
    else if(RandMove<=40){//Shield
        if(player.Freezed==1){
            Move=1;
        }
        else{
            Move=2;
        }
    }
    else if(RandMove<=45){//Magic Attack
        if(Energy<MagicAttackCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=3;
        }
    }
    else if(RandMove<=65){//Freeze
        if(Energy<FreezeCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else if(player.Freezed==1){
            Move=1;
        }
        else{
            Move=4;
        }
    }
    else if(RandMove<=75){//Upgrade Weapon
        if(Energy<UpgradeCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=5;
        }
    }
    else if(RandMove<=85){//Counter Magic
        if(Energy<CounterMagicCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else if(player.Freezed==1){
                Move=1;
            }
            else{
                Move=1;
            }
        }
        else if(player.getEnergy()<3){
            Move=1;
        }
        else{
            Move=6;
        }
    }
    else if(RandMove<=95){
        if(NumOfHealPotion>0){
            if(Health<(Health-HealPower)){
                Move=7;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=1;
        }
    }
    else if(RandMove<=100){
        if(NumOfEnergyPotion>0){
            if(Energy<3){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=1;
        }
    }

    cout<<endl<<"CHOICE of "<<Name<<":"<<"Your enemy choose \""<<Abilities[Move-1]<<"\""<<endl<<endl<<endl;
}

//Random Enemy Type, with certain probability
int RandEnemyType(){
	//1 for Noob, 2 for Warrior, 3 for Shield Master, 4 for Regular, 5 for Tank, 6 for Mage
	//    30%   ,    20%       ,       15%          ,      15%     ,      10%  ,     10%
	srand(unsigned(time(0)));
	int RandIndex=rand()%100 + 1;
	if(RandIndex<=30){
		return 1;
	}
	else if(RandIndex<=50){
		return 2;
	}
	else if(RandIndex<=65){
		return 3;
	}
	else if(RandIndex<=80){
		return 4;
	}
	else if(RandIndex<=90){
		return 5;
	}
	else{
		return 6;
	}
}
int RandEnemyLevel(){
	//Level 1(Weakest) 60%, Level 2 30%, Level 3 10%    
	srand(unsigned(time(0)));
	int RandIndex=rand()%100 + 1;
	if(RandIndex<=60){
		return 1;
	}
	else if(RandIndex<=90){
		return 2;
	}
	else if(RandIndex<=100){
		return 3;
	}
}
int ENEMY_GENERATOR(Player &enemy,int Level){
	int Type=RandEnemyType();
	//1 for Noob, 2 for Warrior, 3 for Shield Master, 4 for Regular, 5 for Tank, 6 for Mage
	//    30%   ,    20%       ,       15%          ,      15%     ,      10%  ,     10%
	if(Type==1){
		Noob_Enemy(enemy,Level);
	}
	else if(Type==2){
		Warrior_Enemy(enemy,Level); 
	}
	else if(Type==3){
		ShieldMaster_Enemy(enemy,Level);
	}
	else if(Type==4){
		Regular_Enemy(enemy,Level);
	}
	else if(Type==5){
		Tank_Enemy(enemy,Level); 
	}
	else if(Type==6){
		Mage_Enemy(enemy,Level);
	}
	else{
		cout<<"ERROR!!!!!!!!"<<endl;
	}
	return Type;
}

//In the battle, when Enemy is Making Move, this function is used
void ENEMY_MAKE_MOVE(Player &enemy,Player &player,int Type){
	if(Type==1){
		enemy.Noob_EnemyMakeMove(player);
	}
	else if(Type==2){
		enemy.Warrior_EnemyMakeMove(player);
	}
	else if(Type==3){
		enemy.ShieldMaster_EnemyMakeMove(player);
	}
	else if(Type==4){
		enemy.Regular_EnemyMakeMove(player);
	}
	else if(Type==5){
		enemy.Tank_EnemyMakeMove(player); 
	}
	else if(Type==6){
		enemy.Mage_EnemyMakeMove(player);
	}
	else{
		cout<<"ERROR!!!!!!!!"<<endl;
	}
}

//The event is battle type- where player battles
void operatePlayer_Battle(Player &player){
	srand(unsigned(time(0)));
	Player enemy;
	int EnemyType;
	int EnemyLevel;
	EnemyLevel=RandEnemyLevel();
	EnemyType=ENEMY_GENERATOR(enemy,EnemyLevel);
	cout<<endl<<endl<<"{You encouter an Enemy}"<<endl<<endl<<endl;
	player.ShowBoard();
	ClickEnterToContinue();
	enemy.ShowBoard();
	ClickEnterToContinue();
	int RoundNum=1;
	while(player.getHealth()>0 && enemy.getHealth()>0){
		cout<<"---------------Round "<<RoundNum<<"---------------"<<endl<<endl<<endl;
		player.PlayerMakeMove();
		
		ENEMY_MAKE_MOVE(enemy,player,EnemyType);
		
		player.PlayerCarryMove(enemy);
		
		enemy.EnemyCarryMove(player);
		
		ClickEnterToContinue();
		
		player.ShowBoard();
		
		ClickEnterToContinue();
		
		enemy.ShowBoard();
		
		ClickEnterToContinue();
		
		cout<<endl<<endl<<endl;
		
		RoundNum+=1;
	}
	
	if(player.getHealth()<=0){
		cout<<endl<<endl;
		cout<<"YOU DIED ( T©nT )"<<endl<<endl;
	}
	else{
		cout<<endl<<endl;
		cout<<"YOU WIN !!! (¡«£þ¨£þ)¡«"<<endl<<endl;
		cout<<"You get "<<enemy.getNumofGem()<<" Gems!"<<endl<<endl;
		player.ChangeNumofGem(player.getNumofGem()+enemy.getNumofGem());
		if(player.getFreezed()==true){
			player.ChangeFreezed();
		}
		player.IncreaseAttack(-player.getUpgradedAttackValues());
		player.ChangeUpgradedAttackValues(0);
	}
	
}

string RandColour(){
	srand(unsigned(time(0)));
	string Colour[10]={"RED","BLUE","YELLOW","PURPLE","PINK","WHITE","GREEN","ORANGE","GREY","GROWN"};
	return Colour[rand()%10];
}

string RandAdj(){
	srand(unsigned(time(0)));
	string Adj[6]={"CREEPY","SPOOKY","PALE","HORRIFYING","GROSS","FEARFUL"};
	return Adj[rand()%6];
}

string RandObj(){
	srand(unsigned(time(0)));
	string Odj[20]={"EYE BALL","FINGER","BUTTERFLY","ERASER","SHOE","TOE","FROG","EARPHONE","FLY"
	"MUSHROOM","SOAP","BANANA","PINEAPPLE","ROCK","FISH","FRENCH FRIES","APPLE","NOSE","SQUAD",};
	return Odj[rand()%20];
}

//Choose fate means player is making a choice in the event
void operatePlayer_1_choosefate(Player& player){
	srand(unsigned(time(0)));
	char fatechoice='0';
	int event=rand()%60+1;
	cout<<"You see something is glowing with "<<RandAdj()<<" "<<RandColour()<<" light in the darkness."<<endl<<endl;
	cout<<"Is it a wise choice to get closer?"<<endl<<endl;
	cout<<"Please make your choice."<<endl<<endl;
	cout<<"A--It is risky, but let's see what is over there."<<endl<<endl;
	cout<<"Or B--I will never risk my own life for such a suspicious thing."<<endl<<endl;
	cout<<"Choice: ";
	cin>>fatechoice;
	cout<<endl;
	if (fatechoice == 'a' || fatechoice == 'A'){
		cout<<"You find there are bones reflecting the "<<RandAdj()<<" "<<RandColour()<<" light."<<endl<<endl;
    	ClickEnterToContinue();
    	cout<<"It is a giant "<<RandObj()<<"! It takes away all the fleshes from the bodies."<<endl<<endl;
    	cout<<"A crazy idea appears in your mind: EAT IT. "<<endl<<endl;
    	cout<<"Please make your choice. (A-- Follow your heart, EAT it. or B--Control yourself, then LEAVE"<<endl<<endl;
    	cout<<"Choice: ";
 		cin>>fatechoice;
 		cout<<endl;
 	
    	if (fatechoice == 'a' || fatechoice == 'A'){
    		cout<<"When you realised what you have done, you feel your body is getting hotter."<<endl<<endl;
        	cout<<"Endless energy is blooming in you."<<endl<<endl;
        	event=rand()%60+1;
        	if(event<=10){
        		cout<<"When it is over, you feel like you have reborned!"<<endl<<endl;
        		player.IncreaseMaxHealth(rand()%50+1);
        		cout<<"Your Max Health raised!"<<endl;
			}
			else if(event<=20){
				cout<<"You are Heavily Injured by the wild energy"<<endl<<endl;
        		player.IncreaseMaxHealth(-rand()%40-10);
			}
        	else if(event<=30){
        		cout<<"You Feel a Special Energy Growing in You"<<endl<<endl;
        		event=player.getEnergy()+rand()%20+1;
        		player.ChangeEnergy(event);
        		player.ChangeMaxEnergy(event);
        		cout<<"Your Energy Has Increased!"<<endl<<endl;
			}
			else if(event<=40){
				cout<<"You Feel This Energy Is Conflicting With Another Energy In You"<<endl<<endl;
        		event=player.getEnergy()+rand()%20+1;
        		player.ChangeEnergy(-event);
        		cout<<"Your Energy Has Decreased"<<endl<<endl;
			}
			else if(event<=50){
				cout<<"You Feel Like You Are the Most Powerful Warrior in The World"<<endl<<endl;
        		event=player.getAttackDamage()+rand()%20+1;
        		player.IncreaseAttack(event);
        		cout<<"Your Attack Has Increased!"<<endl<<endl;
			}
			else{
				cout<<"You Feel Like The Energy Is Stoling Your Strength"<<endl<<endl;
        		event=rand()%5+2;
        		event=player.getAttackDamage()/event;
        		player.IncreaseAttack(-event);
       	 	cout<<"Your Attack Has Decreased"<<endl<<endl;
			}
		}   
	}
    else
         {
         	event=rand()%100+1;
         	if(event%3==1){
         		cout<<"Wind Blows By"<<endl<<endl;
			 }
			 else if(event%3==2){
			 	cout<<"Some Thing is Murmuring By Your Ear"<<endl<<endl; 
			 } 
			 else{
			 	cout<<"You Feel Dizzy"<<endl<<endl;
			 }
			 ClickEnterToContinue();
         	if(event<=20){
         		cout<<"Luckily, Nothing Happened"<<endl<<endl;
			 }
			 else if(event<=50){
			 	cout<<"It was too late. Something Weird is Happening!"<<endl<<endl;
			 	ClickEnterToContinue();
			 	player.ChangeEnergy(0);
			 	cout<<"You Feel Emptiness"<<endl<<endl;
			 }
			 else if(event<=60){
			 	cout<<"An Evil Energy Sneaks Into Your Head"<<endl<<endl;
			 	cout<<"You feel more powerful, but you don't know why"<<endl<<endl;
			 	ClickEnterToContinue(); 
			 	player.ChangeMagicAttackDamage(player.getMagicAttackDamage()+rand()%20+1);
			 }
			 else if(event<=80){
			 	cout<<"You Feel Cold"<<endl<<endl;
			 	player.IncreaseHealth(-10);
			 	cout<<"You Get 10 Point of Damage"<<endl<<endl;
			 }
			 else{
			 	cout<<"It was too late. Something Weird has Happened!"<<endl<<endl;
			 	ClickEnterToContinue();
			 	event=rand()%5+2;
        		event=player.getAttackDamage()/event;
        		player.IncreaseAttack(-event);
			 	cout<<"You Feel Weaker"<<endl<<endl;
			 }
         
         player.ChangeEnergy(0);
        }
}

//good fate means there is no choice need to be made, and the player directly get good fate
void operatePlayer_2_goodfate1(Player& player)
{
    cout<<"There is "<<RandColour()<<" light in front of you."<<endl<<endl;
    cout<<"It looks like a piece of paper burning and floating in the air."<<endl<<endl;
    ClickEnterToContinue();
    cout<<"It is glowing and growing."<<endl<<endl;
    cout<<"You are surrounded by the purple light."<<endl<<endl;
    ClickEnterToContinue();
    cout<<"You feel your mind gets clearer."<<endl<<endl;
    cout<<"Your magic damage increases by 10 points"<<endl<<endl;
    player.IncreaseMagicAttack(10);
}

void operatePlayer_3_goodfate2(Player& player)
{
  srand(unsigned(time(0)));
  cout<<"There is a pool in front of you. Something glowing with "<<RandColour()<<" light is beneath the pool."<<endl<<endl;
  cout<<"The light is risng slowly. It rises upon the lake."<<endl<<endl;
  ClickEnterToContinue();
  cout<<"You have never seen such a creature, but it has exactly same features as a fairy in your childhood dream. "<<endl<<endl;
  cout<<"It is gone and you feel power running in your limbs."<<endl<<endl;
  ClickEnterToContinue();
  player.IncreaseAttack(rand()%20);
}

void operatePlayer_4_goodfate3(Player& player)
{
	srand(unsigned(time(0)));
    cout<<"There is "<<RandColour()<<" light in front of you."<<endl<<endl;
    cout<<"You Feel More and More Sleepy"<<endl<<endl;
    ClickEnterToContinue();
    cout<<"When You Wake Up, you feel your body get cured"<<endl<<endl;
    player.IncreaseHealth(rand()%30+20);

}

//bad fate is contrary to good fate
void operatePlayer_5_badfate1(Player& player)
{
  srand(unsigned(time(0)));
  cout<<"There is mist in this place"<<endl<<endl;
  cout<<"It smells sweet."<<endl<<endl;
  cout<<"It was a sudden, you feel dizy and disordered"<<endl<<endl;
  cout<<"Your health drops, leave this place!"<<endl<<endl;
  player.IncreaseHealth(-rand()%30+10);

}

void operatePlayer_6_badfate2(Player& player)
{
  cout<<"The whole place is shaking."<<endl<<endl;
  cout<<"Thousands of bugs fly out from the holes on the ground."<<endl<<endl;
  cout<<"You try to run away, but you are covered by those bugs."<<endl<<endl;
  cout<<"You spend all your magic energy, to burn all of the bugs."<<endl<<endl;
  player.ChangeEnergy(0);
}

void operatePlayer_7_choosefate2(Player& player)
{
    char fatechoice='0';
    cout<<"You find a skeleton sitting lonely in the darkness."<<endl<<endl;
    cout<<"There might be something helpful or dangerouse"<<endl<<endl;
    ClickEnterToContinue();
    cout<<"Will you A: Get closer and check it?"<<endl<<endl;
    cout<<"Or B: Keep away from it."<<endl<<endl;
    cout<<"Choice: ";
 	cin>>fatechoice;
 	cout<<endl;
    if (fatechoice == 'a' || fatechoice == 'A')
    {
        cout<<"You find a blade which is surrounded by arms without flesh and a necklace hanging on the spine."<<endl<<endl;
        cout<<"A piece of ruby is mounted on the necklace and there are mysterious patterns carved on the sword."<<endl<<endl;
        cout<<"What will you do next?"<<endl<<endl;
        cout<<"A--Take away the sword, it will be the best tool to help you to fight the monsters."<<endl<<endl;
        cout<<"B--Take away the necklace, somehow it attracts you."<<endl<<endl;
        cout<<"C--Pray for the body, for no reason."<<endl<<endl;
        cout<<"Choice: ";
 		cin>>fatechoice;
 		cout<<endl;
        if (fatechoice == 'a' || fatechoice == 'A')
        {
            cout<<"When your hands reach the sword, you suddenly feel headache."<<endl<<endl;
            cout<<"You lost your direction, your brain is too dizy to give order."<<endl<<endl;
            cout<<"You are drowning in the sea of red light."<<endl<<endl;
            cout<<"When you wake up, the skeleton is still sitting with the blade and the necklace."<<endl<<endl;
            cout<<"Nothing has happended, but fear fills up your heart."<<endl<<endl;
            cout<<"You leave the place with permanent headache."<<endl<<endl;
            cout<<"Your Max Energy decreases by 3."<<endl<<endl;
            player.IncreaseMaxEnergy(-3);



        }
        else if (fatechoice == 'b' || fatechoice == 'B')
        {
            cout<<"When your hands reach the ruby, the blade shakes."<<endl<<endl;
            cout<<"You paid a lot in order to survive from the fatal dance of the floating blade."<<endl<<endl;
            cout<<"You lose health by 50 points"<<endl<<endl;
            player.IncreaseHealth(-50);
        }
        else if (fatechoice == 'c' || fatechoice == 'C')
        {
            cout<<"When you are praying with eyes closed. Something dropped on the ground."<<endl<<endl;
            cout<<"You open your eyes and get ready to fight immediately "<<endl<<endl;
            cout<<"However, you only see a piece of ruby rolling to your feet. It seems to be cut off by something really sharp."<<endl<<endl;
            cout<<"A gift from the Dead."<<endl<<endl;
            cout<<"You gain 10 points of Max Health and 5 points of Max Energy."<<endl<<endl;
            player.IncreaseMaxEnergy(5);
            player.IncreaseMaxHealth(10);
        }
    }
    else{
        cout<<"It will be always one of the choices to leave safely."<<endl;
    }
}

//This is the event where the player gets to trade magic with gems
void operatePlayer_8_gemtrade(Player& player)
{
	srand(unsigned(time(0)));
	string move;
	int choice;
	int RandNum=rand()%20+3;
    cout<<"There is a statue of a person in hood. It is holding a opened book."<<endl<<endl;
    cout<<"Get Closer?(y/n):";
    cin>>move;
    cout<<endl;
    if(move=="y"){
    	cout<<"You Hear A Voice, Tiny in the Way That's Almost Slient:"<<endl<<endl;
    	cout<<"Put~"<<RandNum<<"~Gems~in~Front~of~Me~,~And~I~will~Reveal~You~the~Most~Magnificent~Powers~in~the~End~of~World"<<endl<<endl;
    	cout<<"Use Gem?(y/n):";
	    cin>>move;
	    cout<<endl;
	    if(move=="y"){
	    	if(player.getNumofGem()>=RandNum){
	    		cout<<"You Put The Gems On the Ground, Not Long Later, You Feel Special Energy Being Drew Away From The Gems"<<endl<<endl;
	    		cout<<"Suddenly, The Statue Begin Shaking, And  IT  CRACKS!!!!!"<<endl<<endl;
	    		ClickEnterToContinue();
	    		cout<<"A Shadow Flys Out"<<endl<<endl;
				cout<<"It says: Great, You Freed Me. In Returm, I Give You The Opportunity To TRADE ONE Magic Powers."<<endl<<endl;
				cout<<"[Four Kinds of Energy Aggregates in Front of You]"<<endl<<endl;
				cout<<"[They Are: Magic Attack, Freeze, Upgrade Weapon, Counter Magic]"<<endl<<endl;
				cout<<"[Their Price:Magic Attack=50 gems, Freeze=30 gems, Upgrade Weapon=60 gems, Counter Magic=20 gems]" <<endl<<endl;
				cout<<"Number Of Your Gems: "<<player.getNumofGem()<<endl<<endl;
				cout<<"Make Your Choice(1 for magic attack/2 for freeze/3 for upgrade weapon/4 for counter magic/5 for don't want any)"<<endl;
				cout<<"CHOICE(1/2/3/4/5): ";
				cin>>choice;
				cout<<endl;
				if(choice==1){
					if(player.getNumofGem()<50){
						cout<<"The Shadow: Hmmm, You Don't Got Enough Gems......I can't sell you the magic...even if you freed me..."<<endl<<endl;
					}
					else{
						player.ChangeCheckKnowMagicAttack(true);
						cout<<"You Unlocked Magic Attack"<<endl<<endl;
						cout<<"In the Battle, Click 3 to Use Magic Attack"<<endl<<endl;
						cout<<"This Attack Will Penetrate Shield(And Nothing Will Be Rebounded)"<<endl<<endl;
						player.ChangeNumofGem(player.getNumofGem()-50);
						ClickEnterToContinue();
					}
				}
				else if(choice==2){
					if(player.getNumofGem()<30){
						cout<<"The Shadow: Hmmm, You Don't Got Enough Gems......I can't sell you the magic...even if you freed me..."<<endl<<endl;
					}
					else{
						player.ChangeCheckKnowFreeze(true);
						cout<<"You Unlocked Freeze(Magic)"<<endl<<endl;
						cout<<"In the Battle, Click 4 to Use Freeze"<<endl<<endl;
						cout<<"This Magic Can Freeze Your Enemy For the Next Round"<<endl<<endl;
						ClickEnterToContinue();
						player.ChangeNumofGem(player.getNumofGem()-30);
					}
				}
				if(choice==3){
					if(player.getNumofGem()<60){
						cout<<"The Shadow: Hmmm, You Don't Got Enough Gems......I can't sell you the magic...even if you freed me..."<<endl<<endl;
					}
					else{
						player.ChangeCheckKnowUpgradeWeapon(true);
						cout<<"You Unlocked Upgrade Weapon(Magic)"<<endl<<endl;
						cout<<"In the Battle, Click 5 to Use Upgrade Weapon"<<endl<<endl;
						cout<<"This Magic Will Temporarily Increase Your Attack"<<endl<<endl;
						player.ChangeNumofGem(player.getNumofGem()-60);
						ClickEnterToContinue();
					}
				}
				if(choice==4){
					if(player.getNumofGem()<20){
						cout<<"The Shadow: Hmmm, You Don't Got Enough Gems......I can't sell you the magic...even if you freed me..."<<endl<<endl;
					}
					else{
						player.ChangeCheckKnowCounterMagic(true);
						cout<<"You Unlocked Counter Magic(Magic)"<<endl<<endl;
						cout<<"In the Battle, Click 6 to Use Counter Magic"<<endl<<endl;
						cout<<"If Your Enemy Is Casting A Magic, This Will Disable That Magic"<<endl<<endl;
						player.ChangeNumofGem(player.getNumofGem()-20);
						ClickEnterToContinue();
					}
				}
				else{
					cout<<"You Treasure Your Gems. You Leave The Place"<<endl<<endl;
				}
			}
			else{
				cout<<"You Don't Got Enough Gems. You Leave The Place"<<endl<<endl;
			}
		}
		else{
			cout<<"You Treasure Your Gems, No One Will Take It For No Reason. You Leave The Place"<<endl<<endl;
		}
	}
	else{
		cout<<"You Leave The Place, Nothing Happens"<<endl<<endl;
	}
}

//this is where the events are triggered
bool operatePlayer(Player& player, int sense)
{
    switch (sense)
    {
    case PlaySense_1:
        operatePlayer_1_choosefate(player);
        break;

    case PlaySense_2:
        operatePlayer_2_goodfate1(player);
        break;

    case PlaySense_3:
        operatePlayer_3_goodfate2(player);
        break;

    case PlaySense_4:
        operatePlayer_4_goodfate3(player);
        break;

    case PlaySense_5:
        operatePlayer_5_badfate1(player);
        break;

    case PlaySense_6:
        operatePlayer_6_badfate2(player);
        break;
        
    case PlaySense_7:
        operatePlayer_7_choosefate2(player);
        break;

    case PlaySense_8:
        operatePlayer_8_gemtrade(player);
        break;
    
    case PlaySense_9:
        operatePlayer_Battle(player);
        break;
    
    default:
        cout<<"invalid input"<<endl;
        return false;
    }
    
    return true;
}




//where player make move in the battle
void Player::PlayerMakeMove(){
    int MoveIndex;
    bool Done=false;
    if(Freezed==true){
        Move=0;
        cout<<"You are freezed for this round, unable to move"<<endl<<endl;
        Freezed=false;
    }
    else
    {
        while(Done==false){
        	cout<<"(Input A Number: 1 for Attack, ";
        	if(KnowShield==true){
        		cout<<"2 for Shield, ";
			}
			if(KnowMagicAttack==true){
        		cout<<"3 for Magic Attack, ";
			}
			if(KnowFreeze==true){
        		cout<<"4 for Freeze, ";
			}
			if(KnowUpgradeWeapon==true){
        		cout<<"5 for Upgrade Weapon, ";
			}
			if(KnowCounterMagic==true){
        		cout<<"6 for Counter Magic, ";
			}
			cout<<"7 for Heal Potion, 8 for Energy Potion)"<<endl<<endl;
            cout<<"Please input your move: ";
            cin>>MoveIndex;
            cout<<endl;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout<<"Your input is not in the choices, please input again"<<endl<<endl;
            }
            else if(MoveIndex<1 || MoveIndex>8){
                cout<<"Your input is not in the choices, please input again"<<endl<<endl;
            }
            else if((MoveIndex==1 && KnowAttack==false)||(MoveIndex==2 && KnowShield==false)||
            (MoveIndex==3 && KnowMagicAttack==false)||(MoveIndex==4 && KnowFreeze==false)||
            (MoveIndex==5 && KnowUpgradeWeapon==false)||(MoveIndex==6 && KnowCounterMagic==false)||
            (MoveIndex==7 && KnowHealPotion==false)||(MoveIndex==8 && KnowEnergyPotion==false)){
                cout<<"This ability has not been unlocked yet, please choose another one"<<endl<<endl;
            }
            else if((MoveIndex==7 && NumOfHealPotion==0)||(MoveIndex==8 && NumOfEnergyPotion==0)){
                cout<<"You are out of this potion, please make a new choice"<<endl<<endl;
            }
            else{
                Done=true;
            }
        }
        Move=MoveIndex;
        cout<<endl<<"CHOICE of YOU: "<<"You choose \""<<Abilities[Move-1]<<"\""<<endl<<endl;
    }
}

//where enemy 1 type make move in the battle
void Player::Enemy1MakeMove(Player &player){
    int RandMove;
    srand(unsigned(time(0)));
    RandMove=rand() % 100 + 1;
    //30%Attack,15%Shield,10%MagicAttack,2%Freeze,30%UpgradeWeapon,3%CounterMagic,5%For Each potion
    if(RandMove<=30){//Attack
        Move=1;
    }
    else if(RandMove<=45){//Shield
        if(player.Freezed==1){
            Move=1;
        }
        else{
            Move=2;
        }
    }
    else if(RandMove<=55){//Magic Attack
        if(Energy<MagicAttackCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=3;
        }
    }
    else if(RandMove<=57){//Freeze
        if(Energy<FreezeCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else if(player.Freezed==1){
            Move=1;
        }
        else{
            Move=4;
        }
    }
    else if(RandMove<=87){//Upgrade Weapon
        if(Energy<UpgradeCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=5;
        }
    }
    else if(RandMove<=90){//Counter Magic
        if(Energy<CounterMagicCost){
            if(NumOfEnergyPotion>0){
                Move=8;
            }
            else if(player.Freezed==1){
                Move=1;
            }
            else{
                Move=1;
            }
        }
        else if(player.getEnergy()<3){
            Move=1;
        }
        else{
            Move=6;
        }
    }
    else if(RandMove<=95){
        if(NumOfHealPotion>0){
            if(Health<(Health-HealPower)){
                Move=7;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=1;
        }
    }
    else if(RandMove<=100){
        if(NumOfEnergyPotion>0){
            if(Energy<3){
                Move=8;
            }
            else{
                Move=1;
            }
        }
        else{
            Move=1;
        }
    }

    cout<<endl<<"CHOICE of "<<Name<<":"<<"Your enemy choose \""<<Abilities[Move-1]<<"\""<<endl<<endl<<endl;


}


//Player Carry Move(In make move they choose a move, in carry move, the move is triggered)
void Player::PlayerCarryMove(Player &enemy){
    DrawEnergy();

    if(Move==1){
        PlayerAttack(enemy);// move 1
    }
    else if(Move==2){
        PlayerShield(enemy);// move 2
    }
    else if(Move==3){
        PlayerMagicAttack(enemy);// move 3
    }
    else if(Move==4){
        PlayerFreeze(enemy);// move 4
    }
    else if(Move==5){
        PlayerUpgradeWeapon(enemy);// move 5
    }
    else if(Move==6){
        PlayerCounterMagic(enemy);// move 6
    }
    else if(Move==7){
        PlayerDrinkHealPotion(enemy);// move 7
    }
    else if(Move==8){
        PlayerDrinkEnergyPotion(enemy);// move 8
    }
    else if(Move==0){
	}
    else{
        cout<<"An Error Occurs Please Check the Program"<<endl<<endl;
    }
}

//Enemy Carry Move
void Player::EnemyCarryMove(Player &player){

    DrawEnergy();
    if(Move==1){
        EnemyAttack(player);// move 1
    }
    else if(Move==2){
        EnemyShield(player);// move 2
    }
    else if(Move==3){
        EnemyMagicAttack(player);// move 3
    }
    else if(Move==4){
        EnemyFreeze(player);// move 4
    }
    else if(Move==5){
        EnemyUpgradeWeapon(player);// move 5
    }
    else if(Move==6){
        EnemyCounterMagic(player);// move 6
    }
    else if(Move==7){
        EnemyDrinkHealPotion(player);// move 7
    }
    else if(Move==8){
        EnemyDrinkEnergyPotion(player);// move 8
    }
    else if(Move==0){
	}
    else{
        cout<<"An Error Occurs Please Check the Program"<<endl<<endl;
    }
}


//New Program Begins Here
void Player::ShowBoard(){
    cout<<"--------- "<<Name<<"---"<<"Health: "<<Health<<" ---------"<<"  Gem:"<<NumofGem;
    cout<<endl<<endl;
    cout<<"  Attack:"<<AttackDamage<<"          ";
    cout<<"Energy:"<<Energy<<"          ";
    cout<<"Energy Potion:"<<NumOfEnergyPotion<<endl<<endl;
    cout<<"  Heal Potion:"<<NumOfHealPotion<<"      ";
    cout<<"HealPower:"<<HealPower<<"       ";
    cout<<"Freezed:"<<(Freezed?"Yes":"No")<<endl<<endl;
    if(KnowMagicAttack==true){
     cout<<"  Magic Attack Damage:"<<MagicAttackDamage<<"       ";
     cout<<"Magic Attack Cost:"<<MagicAttackCost<<endl<<endl;
 }
 if(KnowFreeze==true){
  cout<<"                               ";
     cout<<"Freeze Cost:"<<FreezeCost<<endl<<endl;
 }
 if(KnowUpgradeWeapon==true){
     cout<<"  Upgrade By (Attack Increment):"<<UpgradeBy<<"   ";
     cout<<"Upgrade Cost:"<<UpgradeCost<<endl<<endl;
 }
 if(KnowCounterMagic==true){
  cout<<"                                    ";
  cout<<"Counter Magic Cost:"<<this->CounterMagicCost<<endl<<endl;
 }
    
    

    //cout<<endl<<endl<<endl;

}

//-----MOVES-----

void Player::DrawEnergy(){
    if(Move==3){
        Energy-=MagicAttackCost;
        cout<<"Cost of "<<Name<<"'s Energy: "<<MagicAttackCost<<endl<<endl;
    }
    else if(Move==4){
        Energy-=FreezeCost;
        cout<<"Cost of "<<Name<<"'s Energy: "<<FreezeCost<<endl<<endl;
    }
    else if(Move==5){
        Energy-=UpgradeCost;
        cout<<"Cost of "<<Name<<"'s Energy: "<<UpgradeCost<<endl<<endl;
    }
    else if(Move==6){
        Energy-=CounterMagicCost;
        cout<<"Cost of "<<Name<<"'s Energy: "<<CounterMagicCost<<endl<<endl;
    }
    if(Energy<0){
        Health+=Energy*OverdrawDamageWeight;
        cout<<"Energy Overdraw: "<<-Energy<<endl<<endl;
        cout<<"Damage on "<<Name<<"'s Health: "<<-Energy*OverdrawDamageWeight<<endl<<endl;
        Energy=0;
    }
}




//-----PLAYER MOVES-----


void Player::PlayerAttack(Player &enemy){
    if(enemy.getMove()==1){
        if(AttackDamage>enemy.getAttackDamage()){
            cout<<"Both of you attack. Your attack exceeds your enemy's attack."<<endl<<endl;
            cout<<"Damage on your enemy: "<<AttackDamage-enemy.getAttackDamage()<<endl<<endl;
            enemy.IncreaseHealth(-AttackDamage+enemy.getAttackDamage());
        }
        else if(AttackDamage<enemy.getAttackDamage()){
            cout<<"Both of you attack. Your enemy's attack exceeds your's."<<endl<<endl;
            cout<<"Damage on you: "<<enemy.getAttackDamage()-AttackDamage<<endl<<endl;
            Health-=enemy.getAttackDamage()-AttackDamage;
        }
        else{
            cout<<"Both of you attack. Your attacks are equal."<<endl<<endl;
            cout<<"No one takes damage."<<endl<<endl;
        }
    }
    else if(enemy.getMove()==2){
        cout<<"Your enemy uses "<<enemy.getShieldName()<<endl<<endl;
        cout<<"Your "<<AttackName<<" is rebounded"<<endl<<endl;
        cout<<"Rebound damage on you: "<<AttackDamage<<endl<<endl;
        Health-=AttackDamage;
    }
    else{
        cout<<"Damage on enemy: "<<AttackDamage<<endl<<endl;
        enemy.IncreaseHealth(-AttackDamage);
    }
}

void Player::PlayerShield(Player &enemy){
    if(enemy.getMove()==1){
        cout<<"Your enemy attackes, you rebound the ATTACK"<<endl<<endl;
        cout<<"Rebound damage on enemy: "<<enemy.getAttackDamage()<<endl<<endl;
        enemy.IncreaseHealth(-enemy.getAttackDamage());
    }
}

void Player::PlayerMagicAttack(Player &enemy){
    if(enemy.getMove()==6){
        cout<<"Your enemy counters your magic"<<endl<<endl;
        cout<<"No damage on your enemy"<<endl<<endl;
    }
    else{
        cout<<"Damage on your enemy: "<<MagicAttackDamage<<endl<<endl;
        enemy.IncreaseHealth(-MagicAttackDamage);
    }
}

void Player::PlayerFreeze(Player &enemy){
    if(enemy.getMove()==6){
        cout<<"Your enemy counters your magic"<<endl<<endl;
        cout<<"No one get freezed"<<endl<<endl;
    }
    else{
        cout<<FreezeName<<" is successfully cast"<<endl<<endl;
        cout<<"Your enemy loses next round"<<endl<<endl;
        enemy.ChangeFreezed();
    }
}

void Player::PlayerUpgradeWeapon(Player &enemy){
    if(enemy.getMove()==6){
        cout<<"Your enemy counters your magic"<<endl<<endl;
        cout<<"You weapon is not upgraded"<<endl<<endl;
    }
    else{
        cout<<"You successfully upgrade your weapon"<<endl<<endl;
        cout<<"Increased Attack on your weapon: "<<UpgradeBy<<endl<<endl;
        AttackDamage+=UpgradeBy;
        UpgradedAttackValues+=UpgradeBy;
    }
}

void Player::PlayerCounterMagic(Player &enemy){
    //~
}

void Player::PlayerDrinkHealPotion(Player &enemy){
    if(enemy.getMove()==1 || enemy.getMove()==3){
        cout<<"Your enemy attacks you, Heal Potion Bottle CRASHES"<<endl<<endl;
        cout<<"Unfortunately, you are not healed"<<endl<<endl;
        NumOfHealPotion-=1;
    }
    else{
        cout<<"You successfully Healed yourself"<<endl<<endl;
        cout<<"Healing Power: "<<HealPower<<endl<<endl;
        NumOfHealPotion-=1;
        this->IncreaseHealth(HealPower);
    }
}

void Player::PlayerDrinkEnergyPotion(Player &enemy){
    if(enemy.getMove()==1 || enemy.getMove()==3){
        cout<<"Your enemy attacks you, Energy Potion Bottle CRASHES"<<endl<<endl;
        cout<<"Unfortunately, you Energy is not restored"<<endl<<endl;
        NumOfEnergyPotion-=1;
    }
    else{
        cout<<"You successfully restored your energy"<<endl<<endl;
        cout<<"Energy FULLY restored"<<endl<<endl;
        NumOfEnergyPotion-=1;
        Energy=MaxEnergy;
    }
}


//-----ENEMY MOVES-----

void Player::EnemyAttack(Player &player){
    if(player.getMove()==1){
        //This part is processed in player's Attack()
    }
    else if(player.getMove()==2){
        //This part is processed in player's Attack()
    }
    else{
        cout<<"Damage on you: "<<AttackDamage<<endl<<endl;
        player.IncreaseHealth(-AttackDamage);
    }
}

void Player::EnemyShield(Player &player){
    //This part is processed in player's Attack()
}

void Player::EnemyMagicAttack(Player &player){
    if(player.getMove()==6){
        cout<<"You counters your enemy's magic"<<endl<<endl;
        cout<<"No damage on you"<<endl<<endl;
    }
    else{
        cout<<"Damage on you: "<<MagicAttackDamage<<endl<<endl;
        player.IncreaseHealth(-MagicAttackDamage);
    }
}

void Player::EnemyFreeze(Player &player){
    if(player.getMove()==6){
        cout<<"You counters your enemy's magic"<<endl<<endl;
        cout<<"No one gets freezed"<<endl<<endl;
    }
    else{
        cout<<"You are freezed, you looses next round"<<endl<<endl;
        player.ChangeFreezed();
    }
}

void Player::EnemyUpgradeWeapon(Player &player){
    if(player.getMove()==6){
        cout<<"You counters your enemy's magic"<<endl<<endl;
        cout<<"Your opponent's weapon is not upgraded'"<<endl<<endl;
    }
    else{
        cout<<"Your enemy upgraded weapon"<<endl<<endl;
        AttackDamage+=UpgradeBy;
        UpgradedAttackValues+=UpgradeBy;

    }
}

void Player::EnemyCounterMagic(Player &player){
    //~
}

void Player::EnemyDrinkHealPotion(Player &player){
    if(player.getMove()==1 || player.getMove()==3){
        cout<<"Your Enemy's Heal Potion Bottle is CRASHED by your attack"<<endl<<endl;
        cout<<"You stopped your enemy from healing"<<endl<<endl;
        NumOfHealPotion-=1;
    }
    else{
        cout<<"Enemy gets healed, "<<HealPower<<" healths restored"<<endl<<endl;
        this->IncreaseHealth(HealPower);
    }
}

void Player::EnemyDrinkEnergyPotion(Player &player){
    if(player.getMove()==1 || player.getMove()==3){
        cout<<"Your Enemy's Energy Potion Bottle is CRASHED by your attack"<<endl<<endl;
        cout<<"You stopped your enemy from restoring Energy"<<endl<<endl;
        NumOfEnergyPotion-=1;
    }
    else{
        cout<<"Enemy's Energy is FULLY restored"<<endl<<endl;
        Energy=MaxEnergy;
    }
}






void BattleDescription(){
    cout<<"You and your enemy take moves at the same time, both of you don't know your opponent's move."<<endl;
    cout<<"Each round both of you can only take one move. The following are some of the moves you can take, input the number to take the move."<<endl;
    cout<<"1 Attack: Normal attack. Shield can cancel this attack and cause a rebound attack. If both characters are attacking, the equivalent part of the attack will be cancelled."<<endl;
    cout<<"2 Shield: Can cancel (1)Attack and cause a rebound damage."<<endl;
    cout<<"3 MAGIC- Magic Attack: Will cause certain damage."<<endl<<"  cost of energy:"<<5<<endl;
    cout<<"4 MAGIC- Freeze: Opponent cannot move for the next round."<<endl<<"  cost of energy:"<<5<<endl;
    cout<<"5 MAGIC- Upgrade Weapon: Increase your attack by "<<5<<" ."<<endl<<"  cost of energy:"<<3<<endl;
    cout<<"6 MAGIC- Counter Magic: Cancel your opponent's magic."<<endl<<"  cost of energy:"<<1<<endl;
    cout<<"7 POTION- Heal Potion: Restore "<<40<<" points of your health."<<endl;
    cout<<"8 POTION- Energy Potion: Restore all your energy."<<endl;
}






//-----Functions of Basic Values-----
string Player::getName(){
    return Name;
}
void Player::ChangeName(string NewName){
    Name=NewName;
}
int Player::getNodeX() {
    return x;
}
int Player::getNodeY() {
    return y;
}
int Player::getMove(){
    return Move;
}
void Player::ChangeMove(int value){
    Move=value;
}
int Player::getHealth(){
    return Health;
}
void Player::IncreaseHealth(int value){
    Health+=value;
    if(Health>MaxHealth){
        Health=MaxHealth;
    }
    else if(Health<0){
        Health=0;
    }
}
int Player::getMaxHealth(){
    return MaxHealth;
}
void Player::ChangeNodeX(int value) {
    x = value;
}
void Player::ChangeNodeY(int value) {
    y = value;
}
void Player::ChangeHealth(int value) {
    Health = value;
}
void Player::ChangeAttackDamage(int value) {
    AttackDamage = value;
}
void Player::ChangeHealPower(int value) {
    HealPower = value;
}
void Player::IncreaseMaxHealth(int value){
    Health+=value;
}
void Player::ChangeMaxHealth(int value){
    MaxHealth=value;
}
int Player::getHealPower() {
    return HealPower;
}
int Player::getAttackDamage(){
    return AttackDamage;
}
void Player::IncreaseAttack(int value){
    AttackDamage+=value;
}
string Player::getAttackName(){
    return AttackName;
}
void Player::ChangeAttackName(string NewName){
    AttackName=NewName;
}
string Player::getShieldName(){
    return ShieldName;
}
void Player::ChangeShieldName(string NewName){
    ShieldName=NewName;
}
int Player::getReboundDamage(){
    return ReboundDamage;
}
void Player::ChangeReboundDamage(int value){
    ReboundDamage=value;
}
int Player::getEnergy(){
    return Energy;
}
void Player::ChangeEnergy(int value){
    Energy=value;
}
int Player::getMaxEnergy(){
    return MaxEnergy;
}
void Player::ChangeMaxEnergy(int value){
    MaxEnergy=value;
}


//-----Functions of Magic Values-----

string Player::getFreezeName(){
    return FreezeName;
}
void Player::IncreaseMaxEnergy(int value){
    MaxEnergy+=value;
}
void Player::ChangeFreezeName(string NewName){
    FreezeName=NewName;
}
string Player::getMagicAttackName(){
    return MagicAttackName;
}
void Player::ChangeMagicAttackName(string NewName){
    MagicAttackName=NewName;
}
string Player::getUpgradeName(){
    return UpgradeName;
}
void Player::ChangeUpgradeName(string NewName){
    UpgradeName=NewName;
}
string Player::getCounterMagicName(){
    return CounterMagicName;
}
void Player::ChangeCounterMagicName(string NewName){
    CounterMagicName=NewName;
}
bool Player::getFreezed(){
    return Freezed;
}
void Player::ChangeFreezed(){
    Freezed=not Freezed;
}
int Player::getMagicAttackDamage(){
    return MagicAttackDamage;
}
void Player::ChangeMagicAttackDamage(int value){
    MagicAttackDamage=value;
}
int Player::getUpgradeBy(){
    return UpgradeBy;
}
void Player::ChangeUpgradeBy(int value){
    UpgradeBy=value;
}
int Player::getUpgradedAttackValues(){
    return UpgradedAttackValues;
}
void Player::ChangeUpgradedAttackValues(int value){
    UpgradedAttackValues=value;
}
int Player::getMagicAttackCost(){
    return MagicAttackCost;
}
void Player::ChangeMagicAttackCost(int value){
    MagicAttackCost=value;
}
int Player::getFreezeCost(){
    return FreezeCost;
}
void Player::ChangeFreezeCost(int value){
    FreezeCost=value;
}
int Player::getUpgradeCost(){
    return UpgradeCost;
}
void Player::ChangeUpgradeCost(int value){
    UpgradeCost=value;
}
int Player::getCounterMagicCost(){
    return CounterMagicCost;
}
void Player::ChangeCounterMagicCost(int value){
    CounterMagicCost=value;
}
void Player::IncreaseMagicAttack(int value){
    MagicAttackDamage+=value;
}
int Player::getNumOfHealPotion(){
    return NumOfHealPotion;
}
void Player::ChangeNumOfHealPotion(int value){
    NumOfHealPotion=value;
}
int Player::getNumOfEnergyPotion(){
    return NumOfEnergyPotion;
}
void Player::ChangeNumOfEnergyPotion(int value){
    NumOfEnergyPotion=value;
}



//-----Ability Availability-----

bool Player::getKnowAttack(){
    return KnowAttack;
}
bool Player::getKnowShield(){
    return KnowShield;
}
bool Player::getKnowMagicAttack(){
    return KnowMagicAttack;
}
bool Player::getKnowFreeze(){
    return KnowFreeze;
}
bool Player::getKnowUpgradeWeapon(){
    return KnowUpgradeWeapon;
}
bool Player::getKnowCounterMagic(){
    return KnowCounterMagic;
}
bool Player::getKnowHealPotion(){
    return KnowHealPotion;
}
bool Player::getKnowEnergyPotion(){
    return KnowEnergyPotion;
}
void Player::ChangeKnowAttack(){
    KnowAttack=not KnowAttack;
}
void Player::ChangeKnowShield(){
    KnowShield=not KnowShield;
}
void Player::ChangeKnowMagicAttack(){
    KnowMagicAttack=not KnowMagicAttack;
}
void Player::ChangeKnowFreeze(){
    KnowFreeze=not KnowFreeze;
}
void Player::ChangeKnowUpgradeWeapon(){
    KnowUpgradeWeapon=not KnowUpgradeWeapon;
}
void Player::ChangeKnowCounterMagic(){
    KnowCounterMagic=not KnowCounterMagic;
}
void Player::ChangeKnowHealPotion(){
    KnowHealPotion=not KnowHealPotion;
}
void Player::ChangeKnowEnergyPotion(){
    KnowEnergyPotion = not KnowEnergyPotion;
}
void Player::ChangeCheckKnowAttack(bool value) {
    KnowAttack = value;
}
void Player::ChangeCheckKnowShield(bool value) {
    KnowShield = value;
}
void Player::ChangeCheckKnowMagicAttack(bool value) {
    KnowMagicAttack = value;
}
void Player::ChangeCheckKnowFreeze(bool value) {
    KnowFreeze = value;
}
void Player::ChangeCheckKnowUpgradeWeapon(bool value) {
    KnowUpgradeWeapon = value;
}
void Player::ChangeCheckKnowCounterMagic(bool value) {
    KnowCounterMagic = value;
}
void Player::ChangeCheckKnowHealPotion(bool value) {
    KnowHealPotion = value;
}
void Player::ChangeCheckKnowEnergyPotion(bool value) {
    KnowEnergyPotion = value;
}
/*
int Player::GemTrade(){
   if (getKnowCounterMagic()==false){
    if (NumofGem>=10 && NumofGem<20){
        NumofGem-=10;
        ChangeKnowCounterMagic();
        return 1;

    }
       }
   else if (getKnowFreeze()==false){
       if(NumofGem>=20 && NumofGem<25){
           NumofGem-=20;
           ChangeKnowFreeze();
           return 1;
       }
   }
   else if (getKnowMagicAttack()==false){
       if(NumofGem>=25 && NumofGem<40){
           NumofGem-=25;
           ChangeKnowMagicAttack();
           return 1;
       }
   }
   else if (getKnowUpgradeWeapon()==false){
       if(NumofGem>=40){
           NumofGem-=40;
           ChangeKnowUpgradeWeapon();
           return 1;

       }
   }
   else{
       return 0;
   }
}*/

void Player::ChangeNumofGem(int value){
	NumofGem=value;
}

int Player::getNumofGem(){
	return NumofGem;
}
void Player::RecordFreezed(bool value){
	Freezed=value;
}

BattleFieldMap::BattleFieldMap(Player* pplyer)
{
    m_pplayer = pplyer;
    //m_player_x = 1;
    //m_player_y = MAP_SIZE - 1;
    m_destion_x = 3;
    m_destion_y = 3;
}

void BattleFieldMap::showSelf()
{
    cout<<"battle field map:\n"<<endl;
    for(int y = 0; y < MAP_SIZE; y++)
    {
        cout<<"\t";
        for(int x = 0; x < MAP_SIZE; x++)
        {
            if(m_pplayer->x == x && m_pplayer->y == y)
            {
                cout<<"P";
            }
            else if(isPointOnDestion(x, y)) //destination, can be shown by cout different figure
            {
                cout<<"*";
            }
            else if(isPointSideByDest(x, y))// area next to the destination 5*5
            {
                cout<<"*";
            }
            else if(isPointNearDest(x, y))// area around the destination 9*9
            {
                cout<<"*";
            }
            else
            {
                cout<<"*";
            }
            PRINT_SEPARATER
        }
        cout<<"\n\n\n";
    }
}

bool BattleFieldMap::isPointOnDestion(int x, int y)//destination
{
    if(m_destion_x == x &&  y == m_destion_x)
    {
        return true;
    }
    return false;
}

bool BattleFieldMap::isPointNearDest(int x, int y)//inside a square of 9*9, while the destination is the centre
{
    if(m_destion_x - DESTION_SCOPE_SIZE_NEAR + 1 <= x &&  x <= m_destion_x + DESTION_SCOPE_SIZE_NEAR - 1
                        && m_destion_y - DESTION_SCOPE_SIZE_NEAR + 1 <= y &&  y <= m_destion_y + DESTION_SCOPE_SIZE_NEAR - 1)
    {
        return true;
    }
    return false;
}

bool BattleFieldMap::isPointSideByDest(int x, int y)//3*3 square
{
    //cout<<"------"<<m_destion_x<<"\t"<<m_destion_y<<endl;
    //cout<<"------"<<x<<"\t"<<y<<endl;
    if(m_destion_x - DESTION_SCOPE_SIZE_SIDE_BY + 1 <= x &&  x <= m_destion_x + DESTION_SCOPE_SIZE_SIDE_BY - 1
                        && m_destion_y - DESTION_SCOPE_SIZE_SIDE_BY + 1 <= y &&  y <= m_destion_y + DESTION_SCOPE_SIZE_SIDE_BY - 1)
    {
        return true;
    }
    return false;
}

bool BattleFieldMap::checkPlayerPostion()
{
    if(isPointOnDestion(m_pplayer->x, m_pplayer->y))
    {
        cout<<"You find your teammates."<<endl;
        cout<<"Thank God! All of you guys have made it."<<endl;
        return true;
    }
    else if(isPointSideByDest(m_pplayer->x, m_pplayer->y))
    {
        cout<<"The voice is just next to you."<<endl;
    }
    else if(isPointNearDest(m_pplayer->x, m_pplayer->y))
    {
        cout<<"A familiar voice is calling from far away."<<endl;
    }
    return false;
}

void BattleFieldMap::randomDestion()
{
    srand(unsigned(time(0)));
    m_destion_x=rand() % (MAP_SIZE - 5) + 1 + 5 - 1;

    srand(unsigned(time(0)));
    m_destion_y=rand() % (MAP_SIZE - 5) + 1 + 5 -1;
}



void Player::goNextNode()
{
    char move_direction = '0';
    bool end=false;
    while(end==false){
        cout<<"Please input your moving direction(A--left, D--right, W--up, S--down)"<<endl;
		cout<<" or action(b--ShowBoard, e--Drink Energy Potion, h--Drink Heal Potion): ";
        cin>>move_direction;
        cout<<endl;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Your input is not in the choices, please input again"<<endl<<endl;
        }
        else if(move_direction == 'a' || move_direction == 'A')
        {
            x = x - 1;
            x = x < 0 ? 0:x;
            end=true;
        }
        else if(move_direction == 'd' || move_direction == 'D')
        {
            x = x + 1;
            x = x > MAP_SIZE - 1 ? MAP_SIZE - 1:x;
            end=true;
        }
        else if(move_direction == 'w' || move_direction == 'W')
        {
            y = y - 1;
            y = y < 0 ? 0:y;
            end=true;
        }
        else if(move_direction == 's' || move_direction == 'S')
        {
            y = y + 1;
            y = y > MAP_SIZE - 1 ? MAP_SIZE - 1:y;
            end=true;
        }
        else if(move_direction == 'b' || move_direction == 'B'){
        	this->ShowBoard();
		}
		else if(move_direction == 'e' || move_direction == 'E'){
        	if(this->NumOfEnergyPotion==0){
        		cout<<"There's not enough Energy Potion"<<endl<<endl;
			}
			else{
				cout<<"You Drink a Energy Potion"<<endl<<endl;
				NumOfEnergyPotion -= 1;
            	Energy = MaxEnergy;
			}
		}
		else if(move_direction == 'h' || move_direction == 'H'){
        	if(this->NumOfEnergyPotion==0){
        		cout<<"There's not enough Heal Potion"<<endl<<endl;
			}
			else{
				cout<<"You Drink a Heal Potion"<<endl<<endl;
				NumOfHealPotion -= 1;
            	this->IncreaseHealth(HealPower);
			}
		}
        else
        {
            cout<<"Your input is not in the choices, please input again"<<endl<<endl;
        }
    }
}



#endif // COMMON_H
