//
//  battle.h
//  1340grpproj
//
//  Created by Karson Yip on 30/4/2022.
//

#ifndef battle_h
#define battle_h

int battle(int *hp, int *atk, int *level, int monster[4], string name, int *skills){  //Player_stats and monster_stats also skill_usage included
    
    char flag;
    int fresult;
    cout << "You have met a " << name << " ! " << endl;
    //print monster data
    int monster_hp = monster[0];
    int monster_attack = monster[1];
    int monster_gold = monster[2];
    int dead_code = 20030414;
    int initialhp = *hp;
    //int monster_xp = monster[3];
    cout << name << "'s " << "HP: " << monster_hp << endl;
    cout << name << "'s " << "Attack: " << monster_attack << endl;
    //battle screen
    int action;
    cout << endl;
    cout << "Your turn! Please choose your action" << endl;
    cout << endl;
    // action
    cout << "1. Attack" << endl;
    cout << "2. Dodge" << endl;
    
    if (*level >= 10){
    cout << "3. Special Skills " << endl;
    }

    cin >> action;
    cout << endl;
    int monster_die = 0;
   
    while (monster_die == 0){
        
        while (action < 1 or action >3){
            cout << "Invalid input, Please input again! " << endl;
            cin >> action;
        }
        
        if (action == 1){
            int chance = rand() % 100; // critical hit chance;
            int damage = *atk;
            
            if (chance >= 50){
                cout << "Well done! Critical hit! ";
                damage *= 2;
            }
            
            monster_hp -= damage;
            cout << "You have dealed " << damage << "damage to the mosnter! " << endl;
            cout << "Monster HP remaining: " << monster_hp << endl;
            cout << endl;
            if (monster_hp <= 0){
                monster_die = 1;
                cout << "The monster have died! You get " << monster_gold << "gold! " << endl;
                return monster_gold;
            }
            else{
                *hp -= monster_attack;
                cout << "The monster have hit you, you have minus " << monster_attack << " HP!" << endl;
                cout << "Your HP remaining is : " << *hp << endl;
                if (*hp <= 0){
                    cout << "You died! Return to main menu." << endl;
                    return dead_code;
                }
            }
        }
        
        if (action == 2){
            int chance = rand () % 100;
            if (chance >= 30){
                cout << "You have dodge the attack from the monster! " << endl;
                if (*hp < initialhp){
                *hp += monster_attack;
                    cout << "You have healed: " << monster_attack << "HP" << endl;
                }
            }
            else{
                cout << "Fail to dodge! " << endl;
                *hp -= monster_attack;
                cout << "The monster have hit you, you have minus " << monster_attack << " HP!" << endl;
                cout << endl;
                cout << "Your HP remaining is : " << *hp << endl;
                if (*hp <= 0){
                    //cout << "You died! Return to main menu." << endl;
                    return dead_code;
                }
            }
        }
        
        if (action == 3){
            if (*skills == 1){
                cout << "Do you want to use the skill, Excalubur? -y/n (Only can use once)" << endl;
                cin >> flag;
                fresult = inputcheck(flag);
                    if (fresult == 1){
                        cout << "Excaliburrr !" << endl;
                        int damage = monster_hp * 0.99;
                        monster_hp -= damage;
                        *skills -= 1;
                        cout << "You have dealed " << damage << "damage to the mosnter! " << endl;
                        cout << "Monster HP remaining: " << monster_hp << endl;
                        
                        *hp -= monster_attack;
                        cout << "The monster have hit you, you have minus " << monster_attack << " HP!" << endl;
                        cout << "Your HP remaining is : " << *hp << endl;
                        if (*hp <= 0){
                            if (name != "The Eternity Vampire - Dracula"){ //if the boss is not Dracula, the player will die directly
                                cout << "You died! Return to main menu." << endl;
                            }
                            return dead_code;
                        }
                        
                    }
            }
            else{
                cout << "Your skills is out of usage!" << endl;
            }
            
        }
            
        cout << "Your turn! Please choose your action" << endl;
        cout << endl;
        // action
        cout << "1. Attack" << endl;
        cout << "2. Dodge" << endl;
        if (*level >= 10){
            cout << "3. Special skills" << endl;
        }

        cin >> action;
    }
        
    //cout << "You win! " << endl;
    return monster_gold;

}
#endif
