void normalend1(){
    string Line = "============================================================";
    int flag, fresult;
    
    cout << Line << endl;
    cout << Line << endl;
    
    cout << "You missed the chance to save the princess and get the gold" << endl;
    cout << "You become a normal knight for 80years with nothing special" << endl;
    cout << "You died eventually due to old age" << endl;
    cout << Line << endl;
    cout << "Do you wanna try again? -y/n?";
    
    cin >> flag;
    fresult = inputcheck(flag);
    
    if (fresult == 1){
        cout << "Proceed to the main menu" << endl;
        cout << Line << endl;
        cout << main();
    }
    
    if (fresult == 0){
        cout << "Proceed to the main menu" << endl;
        cout << Line << endl;
        cout << main();
    }
    
    
}
