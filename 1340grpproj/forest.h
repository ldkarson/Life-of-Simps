//
//  forest.h
//  1340grpproj
//
//  Created by Karson Yip on 2/5/2022.
//

#ifndef forest_h
#define forest_h
#include "battle.h"

string forest(int *hp, int *atk, int *level, int *gold, int *excalibur, int *necklace){ //input player_stats
    string line = "========================================";
    char flag;
    int fresult;
    int bone = 0;
    *necklace = 0;
    *excalibur = 0;
    int boss_cerberus[4] = {980, 75, 3000, 12000};
    int monster_wolves[4] = {500, 30, 200, 500};
    
    cout << line << endl;
    cout << line << endl;
    
    cout << "Here is the mysterical forest, butterflies everywhere and you can hear the bird chirping." << endl;
    cout << "Your Current status: HP: " << *hp << " ATK: " << *atk << " Level: " << *level << " Gold: " << *gold << " Level: " << *level << endl;
    cout << line << endl;
    cout << "You walked a while in the forest, following the direction from the map" << endl;
    cout << line << endl;
    cout << "Merchant: Hello knight, it is me again. Do you want to get some new stuff from me?" << endl;
    cout << line << endl;
    cout << " 1. The Excalibur - 1500G (ATK +50)" << endl;
    cout << " 2. Cross necklace - 450G" << endl;
    cout << " 3. 10 Bones - 30G" << endl;
    cout << " 4. The Great Armor - 1200G (HP + 250)" << endl;
    cout << " 5. No, Thank you." << endl;
    cout << "Your balance: " << *gold << "G" << endl;
    
    int shop;
    cin >> shop; //item that the player want to buy
    int check = 0;
    
    while (shop <1 or shop >5){
        cout << "Invalid input! Please input again! " << endl;
        cin >> shop;
    }
    while (check == 0){
        if (shop == 1){
            if (*gold >= 1500){
                *gold -= 1500;
                cout << "Here you go, the legendary sword, Excalibur." << endl;
                cout << "When you hold the sword, you feel a special feeling." << endl;
                cout << line << endl;
                cout << "You have learn 1 special skills! -The Excalibur beam-" << endl;
                cout << "Remember, it only can use once." << endl;
                cout << "Atk + 50" << endl;
                *atk += 50;
                check = 1;
                *excalibur += 1;
            }else
            {
                cout << "You don't have sufficient money." << endl;
                cout << "Your balance : " << *gold << "G" << endl;
            }
        }
        
        if (shop == 2){
            if (*gold >= 400){
                *gold -= 400;
                cout << "Here you go, the cross necklace." << endl;
                cout << "It will definitely be useful in future. " << endl;
                cout << line << endl;
                *necklace += 1;
                check = 1;
            }else
            {
                cout << "You don't have sufficient money." << endl;
                cout << "Your balance : " << *gold << "G" << endl;
            }
        }
        
        if (shop == 3){
            if (*gold >= 30){
                *gold -= 30;
                cout << "Here you go, the 10 bones." << endl;
                cout << "Why are u buying these bones? " << endl;
                cout << line << endl;
                bone += 1;
                check = 1;
            }else
            {
                cout << "You don't have sufficient money." << endl;
                cout << "Your balance : " << *gold << "G" << endl;
            }
        }
        
        if (shop == 4){
            if (*gold >= 1200){
                *gold -= 1200;
                cout << "Here you go, The Heavenly Demon Fire Armor." << endl;
                cout << "Wow! You look a lot more stronger!" << endl;
                cout << line << endl;
                cout << "HP +100" << endl;
                *hp += 100;
                
                check = 1;
            }else
            {
                cout << "You don't have sufficient money." << endl;
                cout << "Your balance : " << *gold << "G" << endl;
            }
        }
        
        if (shop == 5){
            check = 1;
        }
        
        if (check == 1){
            cout << "Do you need other stuff? -y/n" << endl;
            cin >> flag;
            fresult = inputcheck(flag);
            if (fresult == 1){
                check = 0;
            }
            if (fresult == 0){
                cout << "Bye!" << endl;
                break;
            }
        }
        cout << line << endl;
        cout << " 1. Excalibur - 1500G (ATK +50)" << endl;
        cout << " 2. Cross necklace - 400G" << endl;
        cout << " 3. 10 Bones - 30G" << endl;
        cout << " 4. Heavenly Demon Fire Armor - 1200G (HP +250)" << endl;
        cout << " 5. No, Thank you." << endl;
        cout << "Your balance: " << *gold << "G" << endl;
        cin >> shop;
        
        
    }
    cout << line << endl;
    cout << endl;
    
    cout << "After a while , you saw a big castle and you reach the big gate in front of the castle." << endl;
    cout << "Suddenly, you are surrounded by a group of wolves" << endl;
    cout << line << endl;
    cout << "Battle start!" << endl;
    string name = "A group of wolves";
    int original_level = *level;
    int original_hp = *hp;
    //int original_atk = *atk;
    if (bone >= 1){
        cout << line << endl;
        cout << "Emmm.. they sounds like interested in your bone, would you like to give 10 to them? -y/n" << endl;
        cin >> flag;
        fresult = inputcheck(flag);
            if (fresult == 1){
                cout << endl;
                cout << "You throw the bone to the wolves." << endl;
                cout << "All the wolves run to the bone and eat it, they sounds more friendly to you." << endl;
                monster_wolves[1] = 5;
                cout << "ATK of the wolve -25!" << endl;
            }
        
    }
    int tmpgold = battle(hp, atk, level, monster_wolves, name, excalibur); //call the battle function, return the gold of monster
    
    if (tmpgold == 20030414){
        return "Dead";
    }
    else{
        cout << "Congratulations! You win the battle" << endl;
        *level += 1;
        cout << "Level up! " << original_level << " -->" << *level << endl;
        cout << "HP +20" << endl;
        cout << "ATK +20" << endl;
        *hp = original_hp + 20;
        *atk += 20;
        cout << endl;
        cout << "Your Current status: HP: " << *hp << " ATK: " << *atk << " Level: " << *level << " Gold: " << *gold << " Level: " << *level << endl;
    }
    cout << line << endl;
    cout << "Urghhhhhhhhhh who kill my lovely wolves! I - The HELL HOUND CERBERUS will NOT forgive you!" << endl;
    
    if (bone >= 1){
        cout << line << endl;
        cout << "Emmm.. Cerberus is also a wolf, maybe he likes bones too, do u want to throw 10 bones to Cerberus? -y/n" << endl;
        cin >> flag;
        fresult = inputcheck(flag);
            if (fresult == 1){
                cout << endl;
                cout << "You throw the bone to Cerberus." << endl;
                cout << "Cerberus run to the bone and eat it, he is very enjoy it." << endl;
                boss_cerberus[1] = boss_cerberus[1] - 45;
                cout << "ATK of cerberus - 60%!" << endl;
            }
        
    }
    cout << line << endl;
    cout << "Boss Battle: The Hell Hound - Cerberus" << endl;
    cout << "Battle start!" << endl;
    name = "The Hell Hound - Cerberus";
    original_level = *level;
    original_hp = *hp;
    tmpgold = battle(hp, atk, level, boss_cerberus, name, excalibur);//call the battle function, return the gold of monster
    if (tmpgold == 20030414){
        return "Dead";
    }
    else{
        cout << "Congratulations! You win the battle" << endl;
        *level += 20;
        cout << "Level up! " << original_level << " -->" << *level << endl;
        cout << "HP +600" << endl;
        cout << "ATK +600" << endl;
        *hp = original_hp + 600;
        *atk += 600;
        cout << endl;
        cout << "Your Current status: HP: " << *hp << " ATK: " << *atk << " Level: " << *level << " Gold: " << *gold << " Level: " << *level << endl;
        cout << line << endl;
        
        
        if (*necklace == 1){
            return "Pass_with_necklace";
        }
        
        return "Pass";
    }
    
    
    
    
    
    
    return "Pass";
}


#endif /* forest_h */
