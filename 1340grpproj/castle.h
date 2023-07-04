#ifndef castle_h
#define castle_h

string castle(int *hp, int *atk, int *level, int *gold, int *excalibur, int *necklace){ //Player_stats inputted
    
    cout << "HP: " << *hp << " ATK: " << *atk << " LEVEL " << *level << " GOLD: " << *gold << " Excalibur: " << *excalibur << " NECKLACE: " << *necklace << endl;
    
    string line = "============================================================";
    int finalboss_Dracula[4] = {300000, 1200, 9000, 90000};
    int boss1_Belz[4] = {2000, 200, 5000, 5000};
    cout << line << endl;
    cout << "Dracula: Welcome to my castle, Brave knight" << endl;
    cout << "Dracula: If you want to save your princess carmen, come and beat me." << endl;
    cout << "Dracula: I will wait you on the top of the castle" << endl;
    cout << line << endl;
    
    cout << "You currently at 1/F of the castle, you have to defeat the guardian of every level in order to go to Dracula's room on the top." << endl;
    cout << line << endl;
    cout << "Suddenly, a large butterfly fly towards you and attack you." << endl;
    cout << "Boss Battle: The Queen of butterfly - Belz" << endl;
    cout << "Battle start!" << endl;
    string name = "Belz" ;
    int originalhp = *hp;
    int originallevel;
    int tmpgold = battle(hp, atk, level, boss1_Belz, name, excalibur); //call the battle function
    if (tmpgold == 20030414){
        return "Dead";
    }else{
        originallevel = *level;
        cout << "Belz: How can you beat me... Sorry my master..." << endl;
        cout << line << endl;
        cout << "Congratulations, You have defeated The queen of butterfly - Belz" << endl;
        *level += 5;
        *hp = originalhp + 250;
        *atk += 250;
        cout << "Level up! " << originallevel << " --> " << *level << endl;
        cout << "HP +250, ATK +250" << endl;
        cout << "Your Current status: HP: " << *hp << " ATK: " << *atk << " Level: " << *level << " Gold: " << *gold << "G" << endl;
    }
    cout << line << endl;
    cout << endl;
    cout << "You have proceed to 2/F" << endl;
    cout << line << endl;
    cout << "Inside 2/F, it is very dark and you cannot see anything." << endl;
    cout << "Suddenly, a dice appear in front of you. roll? -y/n" << endl;
    
    char flag;
    int fresult;
    cin >> flag;
    fresult = inputcheck(flag);
    originalhp = *hp;
    originallevel = *level;
    int number_of_bats;
    if (fresult == 1){
        number_of_bats = rand() % 6;
        if (number_of_bats == 0){
            number_of_bats = 3;
        }
        int boss_bats[4] = {number_of_bats * 600, number_of_bats * 60 , number_of_bats * 5000, number_of_bats * 5000};
        cout << "Suddenly, " << number_of_bats << " Bats come attack you!" << endl;
        name = "The Deepest Horror - Infintus bats";
        tmpgold = battle(hp, atk, level, boss_bats, name, excalibur); //call the battle function
    }else
    {
        number_of_bats = 6;
        int boss_bats[4] = {number_of_bats * 600, number_of_bats * 60 , number_of_bats * 5000, number_of_bats * 5000};
        cout << "Suddenly, " << number_of_bats << " Bats come attack you!" << endl;
        name = "The Deepest Horror - Infintus bats";
        tmpgold = battle(hp, atk, level, boss_bats, name, excalibur); //call the battle function
    }
    
    if (tmpgold == 20030414){
        return "Dead";
    }else
    {
        cout << "Bats: Urghhhhdhadajkdhwkjdnknkjafn..." << endl;
        cout << "The voices of bats has disappear, and the road become bright again" << endl;
        cout << line << endl;
        cout << "Congratulations, You have defeated The Deepest Horror - Infintus bats" << endl;
        *level += number_of_bats;
        *hp = originalhp + number_of_bats * 50;
        *atk += number_of_bats * 50;
        cout << "Level up! " << originallevel << " --> " << *level << endl;
        cout << "HP +" << number_of_bats * 50 << ", ATK +" << number_of_bats * 50 << endl;
        cout << "Your Current status: HP: " << *hp << " ATK: " << *atk << " Level: " << *level << " Gold: " << *gold << "G" << endl;
    }
    cout << line << endl;
    cout << endl;
    cout << "Finally, you reach the entrance of Dracula's room" << endl;
    cout << "After pushing the door and go in to the room, you see a giant vampire." << endl;
    cout << "Dracula: I know you will be here, brave knight" << endl;
    cout << "Dracula: I appreciate your brave, but here, is the end of your journey." << endl;
    cout << "Dracula: I am the invincible presense of this world." << endl;
    cout << "Dracula: And I, will destroy you in a second, NOW." << endl;
    cout << line << endl;
    cout << "Boss battle: The Eternity Vampire - Dracula" << endl;
    cout << "Battle start!" << endl;
    
    if (*necklace == 1){
        cout << "A mysterious sound suddenly tell you: " << endl;
        cout << "I will protect you, use the power of the necklace" << endl;
        cout << "You will defeat the evil presence. " << endl;
        cout << "Buff: Blessing from the girl god" << endl;
        cout << "HP+ 10000" << endl;
        cout << "ATK+ 5000" << endl;
        *hp += 10000;
        *atk += 5000;
    }
    name = "The Eternity Vampire - Dracula";
    tmpgold = battle(hp, atk, level, finalboss_Dracula, name, excalibur); //call the battle function
    
    if (tmpgold == 20030414){
        cout << "Dracula: Weak." << endl;
        cout << "You fell down and fainted on the floor with blood" << endl;
        return "Dead";
    }
    else{
        return "Pass";
    }
    
    
    
    return "Pass";
}


#endif /* castle_h */
