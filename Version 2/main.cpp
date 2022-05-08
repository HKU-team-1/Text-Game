#include<iostream>
#include<cstdlib>
#include<string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include<conio.h>
#include <fstream>
#include "common.h"

using namespace std;

void BattleDescription();

void ClickEnterToContinue(){
    cout<<"Click Any Key to Continue ";
    getch();
    cout<<"\r";
    cout<<"                         ";
    cout<<"\r";
}


using namespace std;


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


void Noob_Enemy(Player &enemy,int EnemyLevel){//denotes increment on all the values(EnemyLevel:1-3
	enemy.ChangeName("Noob");
	//Health
	enemy.ChangeMaxHealth(10+5*EnemyLevel);
	enemy.IncreaseHealth(0);
	//Attack
	enemy.ChangeAttackName("Stick Attack");
	enemy.IncreaseAttack(1*EnemyLevel-10);
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

void ShieldMaster_Enemy(Player &enemy,int EnemyLevel){
	enemy.ChangeName("Shield Master");
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

void Regular_Enemy(Player &enemy,int EnemyLevel){
	enemy.ChangeName("Monster");
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

void Mage_Enemy(Player &enemy,int EnemyLevel){
	enemy.ChangeName("Wizard");
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

void Warrior_Enemy(Player &enemy,int EnemyLevel){
	enemy.ChangeName("Warrior");
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

void Tank_Enemy(Player &enemy,int EnemyLevel){
	enemy.ChangeName("Giant");
	//Health
	enemy.ChangeMaxHealth(40+30*EnemyLevel);
	enemy.IncreaseHealth(0);
	//Attack
	//Magic
	enemy.ChangeMagicAttackDamage(5+EnemyLevel*5);
	//Potion
	enemy.ChangeNumOfHealPotion(10);
	
	//Gem
	enemy.ChangeNumofGem(10*EnemyLevel);
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
		Sleep(10000);
	}
	return Type;
}
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
		Sleep(10000);
	}
}

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
    
    SkipTutorial=ReadFile(player);
    
    if(SkipTutorial==false){
    	Tutorial(player);
	}
    
    BattleFieldMap map(&player);
    
    map.randomDestion();
    
    //BattleDescription();
    
    player.ShowBoard();
    
    ClickEnterToContinue();

    //Round Begin
    bool iswin;
    int sense;
    map.showSelf();
    while(player.getHealth()>0)
    {
        srand(unsigned(time(0)));
        sense = EventGenerator();//random event
        if(!operatePlayer(player, sense))//events
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

