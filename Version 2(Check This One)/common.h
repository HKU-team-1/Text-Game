#ifndef COMMON_H
#define COMMON_H
#include<iostream>
#include<cstdlib>
#include<string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include<conio.h>
#include <fstream>
using namespace std;

int MAP_SIZE=9;
#define DESTION_SCOPE_SIZE_SIDE_BY (3)
#define DESTION_SCOPE_SIZE_NEAR (5) 
#define SEPARATER "      "
#define PRINT_SEPARATER cout<<SEPARATER;
#include<iostream>
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
    Sleep(200);
}

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
    Sleep(150);

}


//Player Carry Move
void Player::PlayerCarryMove(Player &enemy){
    DrawEnergy();
    Sleep(100);
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
        Sleep(10000);
    }
}

//Enemy Carry Move
void Player::EnemyCarryMove(Player &player){

    DrawEnergy();
    Sleep(100);
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
        Sleep(10000);
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
