//
//  forest.h
//  1340grpproj
//
//  Created by Karson Yip on 30/4/2022.
//
#include "battle.h"
#include <string>

string town(int *hp, int *atk, int *level, int *gold){ //input player_stat
    int slimedata[4] = {10, 1, 20, 10}; //hp, atk, gold, xp
    string monster_name;
    int goldslimedata[4] = {10, 1, 200, 10}; //hp, atk, gold, xp
    int boss_medusa[4] = {300, 30, 2000, 50};
    int skills = 0;
    //cout << "HP address: " << hp << endl;
    string line = "============================================================";
    cout << "Welcome to the Road outside the town!" << endl;
    cout << endl;
    cout << "You take out the map from the king" << endl;
    cout << "It shows that you have to pass the road outside the town to reach the forest, then the castle." << endl;
    cout << line << endl;
    cout << endl;
    cout << "After you walked a while, suddenly you see a monster in front of you." << endl;
    cout << "Battle? -y/n" << endl;
    
    char flag;
    int fresult;
    int tmpgold;
    
    cin >> flag;
    fresult = inputcheck(flag); //check whether the input is valid
   
    if (fresult == 1){
        int chance = rand() % 100 ; //chance for met the rare monster
        
        
        if (chance >= 30){
            monster_name = "Golden_Slime(rare)";
            tmpgold = battle(hp , atk, level, goldslimedata, monster_name, &skills);
        }else{
            monster_name = "Slime";
            tmpgold = battle(hp , atk, level, slimedata, monster_name, &skills);
        }
            
            *gold += tmpgold;
            //cout << "HP: " << *hp << " ATK: " << *atk << " LVEL:  " << *level << endl;
            cout << "battle end;" << endl;
            cout << line << endl;
            cout << "Level Up! You level up to level 2! " << endl;
            cout << "HP + 5, ATK + 5" << endl;
            cout << "Your HP will become full when you level up" << endl;
            cout << line << endl;
            *level += 1;
            *hp += 6;
            *atk += 5;
        
    }
    
    if (fresult == 0){
        cout << "You continue to walk" << endl;
        
    }
    
    cout << line << endl;
    cout << "After a while, you met a merchant. He would like to sell you." << endl;
    cout << " 1. Giant Sword - 120G (ATK +5)" << endl;
    cout << " 2. The Enchanted Giant Sword - 200G (ATK +10)" << endl;
    cout << " 3. The Great Armor - 120G (HP +10) " << endl;
    cout << " 4. Normal Sword - 100G (ATK +3)" << endl;
    cout << " 5. No thank you!" << endl;
    cout << "Your balance: " << *gold << "G" << endl;
    
    int shop;
    cin >> shop; //item that player want to buy
    while (shop <1 or shop >5){
        cout << "Invalid input! Please input again! " << endl;
        cin >> shop;
    }
    
    int check = 0;
    
    while (check == 0){
        
        if (shop == 1){
            if (*gold >= 120){
                cout << "Thank you! here's your giant sword" << endl;
                cout << "ATK +5!" << endl;
                *atk += 5;
                *gold -= 120;
                check = 1;
            }else
            {
                cout << "You dont have sufficient money :(" << endl;
                cout << "Your balance: " << *gold << "G" << endl;
            }
        }
        
        if (shop == 2){
            if (*gold >= 200){
                cout << "Thank you! here's your enchanted giant sword" << endl;
                cout << "ATK +10!" << endl;
                *atk += 10;
                *gold -= 200;
                cout << "Your balance: " << *gold << "G" << endl;
                check = 1;
            }else
            {
                cout << "You dont have sufficient money :(" << endl;
                cout << "Your balance: " << *gold << "G" << endl;
            }
        }
        
        if (shop == 3){
            if (*gold >= 120){
                cout << "Thank you! here's your The great armor" << endl;
                cout << "HP +10!" << endl;
                *hp += 10;
                *gold -= 120;
                cout << "Your balance: " << *gold << "G" << endl;
                check = 1;
            }else
            {
                cout << "You dont have sufficient money :(" << endl;
                cout << "Your balance: " << *gold << "G" << endl;
            }
        }
        
        
        if (shop == 4){
            if (*gold >= 100){
                cout << "Thank you! here's your normal sword" << endl;
                cout << "ATK +5!" << endl;
                *atk += 5;
                *gold -= 100;
                cout << "Your balance: " << *gold << "G" << endl;
                check = 1;
            }else
            {
                cout << "You dont have sufficient money :(" << endl;
                cout << "Your balance: " << *gold << "G" << endl;
            }
        }
        
        if (shop == 5){
            check = 1;
        }
        
        if (check == 1){
            
            cout << "Thank you and bye! " << endl;
            
        }else{
           
            cout << line << endl;
            cout << "Oh no, you seems like cant afford this, would you like to purchase other stuff?" << endl;
            cout << " 1. Giant Sword - 120G (ATK +5)" << endl;
            cout << " 2. The Enchanted Giant Sword - 200G (ATK +10)" << endl;
            cout << " 3. The Great Armor - 120G (HP +10) " << endl;
            cout << " 4. Normal Sword - 100G (ATK +3)" << endl;
            cout << " 5. No thank you!" << endl;
            cout << "Your balance: " << *gold << "G" << endl;
            cin >> shop;
            while (shop <1 or shop >5){
                cout << "Invalid input! Please input again! " << endl;
                cin >> shop;
            }
            
        }
        
    }
    
    cout << line << endl;
    cout << "After you say bye to the merchant , you see there is a huge gate in front of you, and there is a guardian there." << endl;
    cout << "You walk to the front, you see a banshee who look like a snake." << endl;
    cout << line << endl;
    cout << "Suddenly, there is an magician passed by you" << endl;
    cout << "Would you like to chat with him? -y/n" << endl;
    
    cin >> flag;
    fresult = inputcheck(flag); //check whether input is yes or not, return 0 and 1
    string chat;
    if (fresult == 1){
        cout << "Oh, Where are you going, knight." << endl;
        //cout << "Type to chat: " << endl;
        //getline(cin, chat);
        //cout << "Andy: " << chat << endl;
        cout << endl;
        cout << "I don't actually know what you are talking about due to magic, but i guess you need my help." << endl;
        cout << "Here you go. Malimali hon!" << endl;
        cout << endl;
        cout << "You feel like you get empowered! " << endl;
        cout << "HP +100" << endl;
        cout << "Atk +50" << endl;
        *hp += 100;
        *atk += 50;
    }
    if (fresult == 0){
        cout << "OK, nevermind, you will come back again, for sure." << endl;
    }
    cout << line << endl;
    cout << "When you want to apporach the gate, the banshee said: " << endl;
    cout << "I, am the guardian of the forest, MEDUSA" << endl;
    cout << "Serving my great lord Dracula, if you want to go in to the forest" << endl;
    cout << "I WILL TEAR OFF YOUR SKIN AND KILL YOU!" << endl;
    cout << line << endl;
    cout << "Boss battle: The Forest Guardian —— Medusa Start!" << endl;
    monster_name = "Medusa";
    int tmphp = *hp;
    int tmplv = *level;
    tmpgold = battle(hp ,atk, level, boss_medusa, monster_name, &skills); //call battle function, return monster gold
    if (tmpgold != 20030414){
        cout << endl;
        cout << "Congratulations! You have defeated the boss! ";
        *level += 10;
        *gold += tmpgold;
        cout << "Level up! " << tmplv << "-->" << *level << endl;
        cout << "HP +50, ATK +50" << endl;
        *hp = tmphp;
        *hp += 50;
        *atk += 50;
        return "Pass";
    }
    else
    {
        
        return "Dead";
    }
    
    return "Dead";
    
}


