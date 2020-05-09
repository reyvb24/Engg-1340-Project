#include <iostream>
#include <string>
#include "character.h"
#include "potions.h"
#include "word_art.h"
#include "itemsNspells.h"
#ifndef BATTLE_H
#define BATTLE_H 
using namespace std;

void victory() {
    cout<<"::::      ::::     ::::        .::::::::       :::::::::::       .:::::::.        ::::::::.        :::::       :::::"<<endl;
    cout<<" ::::    ::::      ::::        :::                 :::           :::   :::        ::     ::         :::::      ::::"<<endl;
    cout<<"  ::::  ::::       ::::        :::                 :::           :::   :::        ::::::::             ::::::::::"<<endl;
    cout<<"    ::::::         ::::        :::                 :::           :::   :::        :::   :::                :::"<<endl;
    cout<<"     ::::          ::::        `::::::::           :::           `;;;;;;;'        ;;;   ;;;                :::"<<endl;
}

bool checkMana (int mana, string choice) {
    if((choice == "Heavy blow") || (mana < 40)) {
        return true;
    }
    else if((choice == "Bloodlust") || (mana < 35)) {
        return true;
    }
    else if((choice == "Fire blast") || (mana < 25)){
        return true;
    }
    else if((choice == "Thunder wrath") || (mana < 70)) {
        return true;
    }
    else if((choice == "Essence beam") || (mana < 100)) {
        return true;
    }
    else {
        return false;
    }
}

bool checkCooldown(string choice, int heavyBlowCD, int bloodlustCD, int fireBlastCD, int thunderWrathCD, int essenceBeamCD) {
    if((choice == "Heavy blow") && (heavyBlowCD != 0)) {
        return true;
    }
    else if((choice == "Bloodlust") && (bloodlustCD != 0)) {
        return true;
    }
    else if((choice == "Fire blast") && (fireBlastCD != 0)){
        return true;
    }
    else if((choice == "Thunder wrath") && (thunderWrathCD != 0)) {
        return true;
    }
    else if((choice == "Essence beam") && (essenceBeamCD != 0)) {
        return true;
    }
    return false;
}

void useItems(string choice, int & playerHealth, int & enemyHealth, int & counter, player& player1, int poisonCounter, int & additonalDamage, int &playerdamage) {
    int check = 0;	     
    if (choice!="none") {
	    for (int i = 0; i<5; i++) {
            if (player1.inventory[i] == choice) {
                check++;
            }
        }
    }
    if (check!=0) {
        for(int i = 0; i < amount_of_health_potions; ++i) { // health potion
            if(choice == potions[i].name) {
                healthPotion(potions[i].health, playerHealth);
                for(int j = 0; j < 5; ++j) {
                    if(player1.inventory[j] == potions[i].name) {
                        player1.inventory[j] = "none";
                        break;
                    }
                }
            }
        }
        if(choice == "stun attack") {
            stunAttack(counter, enemyHealth, attack_elixir[0].attack);
            for(int j = 0; j < 5; ++j) {
                if(player1.inventory[j] == "stun attack") {
                    player1.inventory[j] = "none";
                    break;
                }
            }
        }   
        else if(choice == "poison arrow") {
            poisonArrow(poisonCounter);
            for(int j = 0; j < 5; ++j) {
                if(player1.inventory[j] == "poison arrow") {
                    player1.inventory[j] = "none";
                    break;
                }
            }
        }
        else if(choice == "olympus blade") {
            olympusBlade(enemyHealth, 100);
            for(int j = 0; j < 5; ++j) {
                if(player1.inventory[j] == "olympus blade") {
                    player1.inventory[j] = "none";
                    break;
                }
            }
        }
        else if(choice == "spirit of the gods") {
            spiritOfTheGods(50, playerHealth, 100, playerdamage);
            for(int j = 0; j < 5; ++j) {
                if(player1.inventory[j] == "spirit of the gods") {
                    player1.inventory[j] = "none";
                    break;
                }
            }
        }
    }
    else {
        if (check==0 && choice!="back") {
            cout<<"Please enter a valid input!"<<endl;
            getline(cin, choice);
            useItems(choice, playerHealth, enemyHealth, counter, player1, poisonCounter, additonalDamage, playerdamage);
        }
    }
}
void useSpells(string choice, int & mana, int & enemyHealth, int & heavyBlowCD, int & bloodlustCD, int & fireBlastCD, int & thunderWrathCD, int & essenceBeamCD, int & counter, int & thunderCounter) {
    if(choice == "heavy blow") {
        heavyBlow(heavyBlowCD, mana);
    }
    else if(choice == "bloodlust") {
        bloodlust(bloodlustCD, mana);
    }
    else if(choice == "fire blast"){
        fireBlast(enemyHealth, fireBlastCD, mana);
    }
    else if(choice == "thunder wrath") {
        thunderWrath(thunderWrathCD, mana, thunderCounter);
    }
    else if(choice == "essence beam") {
        essenceBeam(enemyHealth, counter, essenceBeamCD, mana);
    }
}

void battle(enemy &creep, player &player1){
    //battle mechanic variables
    int counter = 0;
    bool fleeing = false, backtrack = false;
    // player stat variables
    int playerHealth = player1.health, playerMana = player1.mana, playerdamage = player1.damage;
    int additionalDamage = 0;
    // spell and item variables
    int poisonCounter = 0, thunderCounter = 0;
    int heavyBlowCD = 0, bloodlustCD = 0, fireBlastCD = 0, thunderWrathCD = 0, essenceBeamCD = 0; 
    cout << "You have encountered a " << creep.name << "!" << endl;
    print_warrior();
    print_monster();
    creep.enemyAttributes();
    int enemyHealth = creep.health;
    int enemydamage = creep.damage;
    creep.healthDamageBar(enemyHealth, enemydamage);
    while((enemyHealth > 0) && (fleeing == false) && playerHealth > 0) {
        if(backtrack == false) {    // cooldown of spells
            if(poisonCounter > 0) {
                poison_damage(enemyHealth);
                poisonCounter -= 1;
            }
            if(thunderCounter > 0) {
                electrocuted(enemyHealth);
                thunderCounter -= 1;
            }
            if(heavyBlowCD > 0) {
                heavyBlowCD -= 1;
            }
            if(bloodlustCD > 0) {
                bloodlustCD -= 1;
            }
            if(fireBlastCD > 0) {
                fireBlastCD -= 1;
            }
            if(thunderWrathCD > 0) {
                thunderWrathCD -= 1;
            }
            if(essenceBeamCD > 0) {
                essenceBeamCD -= 1;
            }
        }
        if(counter % 2 == 0) {  // player's move
            cout << "-----------------------------------------------------------------------------------------" << endl;
            counter+=1;
            backtrack = false;
            player1.healthManaDamageBar(playerHealth, playerMana, player1.damage);
            string input;
            cout << "Your turn, choose any of the following actions!" << endl;
            cout << "1. attack" << endl;
            cout << "2. use item" << endl;
            cout << "3. use spells" << endl;
            cout << "4. recharge mana" << endl;
            cout<<"Answer: ";
            getline(cin, input);
            while ((input != "attack") && (input != "use item") && (input != "use spells") && (input != "recharge mana")) {
                cout << "Invalid input! Please try again" << endl;
                getline(cin, input);
            }
            if(input == "attack") {
                if(heavyBlowCD == 3) {
                    int Damage = (playerdamage + additionalDamage) * 2.5;
                    enemyHealth -= Damage;
                    cout << "You dealt " << Damage << " critical damage to " << creep.name << "!" << endl;
                }
                if(bloodlustCD == 3) {
                    int Damage = playerdamage + additionalDamage;
                    playerHealth += Damage * 0.25;
                    enemyHealth -= Damage;
                    cout << "You dealt " << Damage << " damage to " << creep.name << " and lifestealed " << Damage*0.25 << " health!" << endl;
                }
                else if((heavyBlowCD != 3) && (bloodlustCD != 3)) {
                    int Damage = playerdamage + additionalDamage;
                    enemyHealth -= Damage;
                    cout << "You dealt " << Damage << " damage to " << creep.name << "!" << endl;
                }
            }
            else if(input == "use item") {
                player1.showItems(player1);
                cout << "Type the potion name to use them or type \"back\" to go back and choose another action" << endl;
                string itemOption;
                getline(cin, itemOption);
                if(itemOption == "back") {
                    counter -= 1;
                    backtrack = true;
                }
                else{
                    useItems(itemOption, playerHealth, enemyHealth, counter, player1, poisonCounter, additionalDamage, playerdamage);
                }
            }
            else if(input == "use spells") {
                player1.showSpells();
                cout << "Type the spell name to use them or type \"back\" to go back and choose another action!" << endl;
                string spellOption;
                getline(cin, spellOption);
                while(spellOption!="bloodlust" && spellOption!="fire blast" && spellOption!="thunder wrath" && spellOption!="essence beam" && spellOption!="heavy blow" &&spellOption!="back") {
                    cout<<"Please input an appropriate answer!\nAnswer: ";
                    getline(cin, spellOption);
                }
                if(spellOption == "back") {
                    counter -= 1;
                    backtrack = true;
                }
                else{
                    bool noMana = checkMana(playerMana, spellOption);
                    bool onCooldown = checkCooldown(spellOption, heavyBlowCD, bloodlustCD, fireBlastCD, thunderWrathCD, essenceBeamCD);
                    if(noMana == true) {
                        counter -= 1;
                        backtrack = true;
                        cout << "Not enough mana! Choose another action" << endl;
                    }
                    if(onCooldown == true) {
                        counter -= 1;
                        backtrack = true;
                        cout << "Spell on cooldown! Choose another action" << endl;

                    }
                    else if((noMana == false) && (onCooldown == false)) {
                        useSpells(spellOption, playerMana, enemyHealth, heavyBlowCD, bloodlustCD, fireBlastCD, thunderWrathCD, essenceBeamCD, counter, thunderCounter);
                    }
                }
            }
            else if(input == "recharge mana") {
                playerMana +=100;
                if(playerMana > player1.mana) {
                    cout << "Mana full!" << endl;
                    int temp = playerMana - player1.mana;
                    playerMana -= temp;
                }
                else {
                cout << "You charged your mana for this turn! Gained 100 mana!" << endl;
                }
            }
            if (enemyHealth>0) {
                creep.healthDamageBar(enemyHealth, creep.damage);
            }
        }
        else if (counter % 2 == 1) { // enemy's move
            cout << "-----------------------------------------------------------------------------------------" << endl;
            creep.healthDamageBar(enemyHealth, creep.damage);
            playerHealth -= creep.attack();
            counter += 1;
        }
    }
    if(enemyHealth <= 0) {
        victory();
        cout<<endl;
        cout << "Great work! You Defeated the " << creep.name << "!"<< endl;
        if(player1.xp < 10 * 1000) {
            player1.xp += creep.xp;
            player1.coin += creep.coin;
            cout << "You received " << creep.xp << " XP and " << creep.coin << " gold!\n" << endl;
        }
        else{
            player1.coin += creep.coin;
            cout << "You received " << creep.coin << "gold!\n" << endl;
        }
    }
    else if(playerHealth <= 0) {
        cout << "You died! Rest up and try again another time!" << endl;
    }
    else if(fleeing ==  true) {
        cout << "Whew, Got out of there safely!" << endl;
    }
}
int final_battle(boss &final, player &player1){
    cout << "You have decided to fight " << final.name << " to save the village from terror!" << endl <<"We wish all the best for you, "<<player1.name<<"!"<<endl;
    print_warrior();
    print_boss();
    final.introduction();
    int enemyHealth = final.health;
    int enemyAttack = final.damage;
    int playerHealth = player1.health;
    int playerMana = player1.mana;
    int playerAttack = player1.damage;
    int checkHalfHP = 0;
    //battle mechanic variables
    int counter = 0;
    bool fleeing = false, backtrack = false;
    // player stat variables
    int additionalDamage = 0;
    // spell and item variables
    int poisonCounter = 0, thunderCounter = 0;
    int heavyBlowCD = 0, bloodlustCD = 0, fireBlastCD = 0, thunderWrathCD = 0, essenceBeamCD = 0; 
    cout << "Health: " << enemyHealth << endl;
    cout<<"Damage: "<<enemyAttack<<endl;
    while((enemyHealth > 0) && (fleeing == false) && playerHealth > 0) {
        if(backtrack == false) {    // cooldown of spells
            if(poisonCounter > 0) {
                poison_damage(enemyHealth);
                poisonCounter -= 1;
            }
            if(thunderCounter > 0) {
                electrocuted(enemyHealth);
                thunderCounter -= 1;
            }
            if(heavyBlowCD > 0) {
                heavyBlowCD -= 1;
            }
            if(bloodlustCD > 0) {
                bloodlustCD -= 1;
            }
            if(fireBlastCD > 0) {
                fireBlastCD -= 1;
            }
            if(thunderWrathCD > 0) {
                thunderWrathCD -= 1;
            }
            if(essenceBeamCD > 0) {
                essenceBeamCD -= 1;
            }
        }
        if(counter % 2 == 0) {  // player's move
            cout << "-----------------------------------------------------------------------------------------" << endl;
            counter+=1;
            backtrack = false;
            player1.healthManaDamageBar(playerHealth, playerMana, player1.damage);
            string input;
            cout << "Your turn, choose any of the following actions!" << endl;
            cout << "1. attack" << endl;
            cout << "2. use item" << endl;
            cout << "3. use spells" << endl;
            cout << "4. recharge mana" << endl;
            getline(cin, input);
            while ((input != "attack") && (input != "use item") && (input != "use spells") && (input != "recharge mana")) {
                cout << "Invalid input! Please try again" << endl;
                getline(cin, input);
            }
            if(input == "attack") {
                if(heavyBlowCD == 3) {
                    int Damage = (player1.damage + additionalDamage) * 2.5;
                    enemyHealth -= Damage;
                    cout << "You dealt " << Damage << " critical damage to " << final.name << "!" << endl;
                }
                if(bloodlustCD == 3) {
                    int Damage = player1.damage + additionalDamage;
                    playerHealth += Damage * 0.25;
                    enemyHealth -= Damage;
                    cout << "You dealt " << Damage << " damage to " << final.name << " and lifestealed " << Damage*0.25 << " health!" << endl;
                }
                else if((heavyBlowCD != 3) && (bloodlustCD != 3)) {
                    int Damage = player1.damage + additionalDamage;
                    enemyHealth -= Damage;
                    cout << "You dealt " << Damage << " damage to " << final.name << "!" << endl;
                }
            }
            else if(input == "use item") {
                player1.showItems(player1);
                cout << "Type the potion name to use them or type \"back\" to go back and choose another action" << endl;
                string itemOption;
                getline(cin, itemOption);
                if(itemOption == "back") {
                    counter -= 1;
                    backtrack = true;
                }
                else{
                    useItems(itemOption, playerHealth, enemyHealth, counter, player1, poisonCounter, additionalDamage, playerAttack);
                }
            }
            else if(input == "use spells") {
                player1.showSpells();
                cout << "Type the spell name to use them or type \"back\" to go back and choose another action!" << endl;
                string spellOption;
                getline(cin, spellOption);
                while(spellOption!="bloodlust" && spellOption!="fire blast" && spellOption!="thunder wrath" && spellOption!="essence beam" && spellOption!="heavy blow" &&spellOption!="back") {
                    cout<<"Please input an appropriate answer!\nAnswer: ";
                    getline(cin,spellOption);
                }
                if(spellOption == "back") {
                    counter -= 1;
                    backtrack = true;
                }
                else{
                    bool noMana = checkMana(playerMana, spellOption);
                    bool onCooldown = checkCooldown(spellOption, heavyBlowCD, bloodlustCD, fireBlastCD, thunderWrathCD, essenceBeamCD);
                    if(noMana == true) {
                        counter -= 1;
                        backtrack = true;
                        cout << "Not enough mana! Choose another action" << endl;
                    }
                    if(onCooldown == true) {
                        counter -= 1;
                        backtrack = true;
                        cout << "Spell on cooldown! Choose another action" << endl;

                    }
                    else if((noMana == false) && (onCooldown == false)) {
                        useSpells(spellOption, playerMana, enemyHealth, heavyBlowCD, bloodlustCD, fireBlastCD, thunderWrathCD, essenceBeamCD, counter, thunderCounter);
                    }
                }
            }
            else if(input == "recharge mana") {
                playerMana += 100;
                if(playerMana > player1.mana) {
                    cout << "Mana full!" << endl;
                    int temp = playerMana - player1.mana;
                    playerMana -= temp;
                }
                else {
                cout << "You charged your mana for this turn! Gained 100 mana!" << endl;
                }
            }
            if (enemyHealth<=final.health/2 && checkHalfHP==0) {
                final.halfHp(final, enemyAttack);
                checkHalfHP++;
            }
            if (enemyHealth>0) {
                final.healthDamageBar(enemyHealth, final.damage);
            }
        }
        else if (counter % 2 == 1) { // enemy's move
            cout << "-----------------------------------------------------------------------------------------" << endl;
            playerHealth -= final.attack(final.crit_damage);
            counter += 1;
        }
    }
    if(enemyHealth <= 0) {
        victory();
        cout<<endl;
        cout << "Great work! You have saved the village from " << final.name << endl;
        return true;
    }
    else if(playerHealth <= 0) {
        cout << "Game Over! Try again later!" << endl << endl;
        return false;
    }
    else if(fleeing ==  true) {
        cout<<final.name<<": Cowards run, heroes fight! You are no different than the other cowards!\n"<<endl;
        cout << "Whew, Got out of there safely!" << endl;
        return false;
    }
    return false;     
}
#endif