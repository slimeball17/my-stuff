#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

string encryption();
string decryption();

int main()
{
    // prompt user to choose whether to encrypt or decrypt
     int choice;
        cout << "What do you want to do? \n";
        cout << "1. Encryption \n";
        cout << "2. Decryption \n";

        // get choice from user
        cin >> choice;
        cin.ignore(); // 

        bool test = true;
        while(test == true) // while statment to make sure right option is chosen
        {
            if(choice == 1 || choice == 2)
            {
                if(choice == 1) // performs the encryption if 1 is chosen
                {
                    encryption();
                    break;
                }
                else if( choice == 2)
                {
                    decryption();
                    break;
                }   
            }
            else // prompts the user to enter the correct option
            {
                cout << "Please enter 1 or 2 \n";
                cin >> choice;
                cin.ignore(); // allows the user to input the string to encrypt or decrypt
            }
            
        }  
    return 0;
}

// defining encryption of plain text
string encryption()
{
    string message;
    string output;
    int x;
    int pos;

    map <int, char> link = {
        {0,'A'},{1,'B'},{2,'C'},{3,'D'},
        {4,'E'},{5,'F'},{6,'G'},{7,'H'},
        {8,'I'},{9,'J'},{10,'K'},{11,'L'},
        {12,'M'},{13,'N'},{14,'O'},{15,'P'},
        {16,'Q'},{17,'R'},{18,'S'},{19,'T'},
        {20,'U'},{21,'V'},{22,'W'},{23,'X'},
        {24,'Y'},{25,'Z'}
    };


    // get user input
    cout << "Enter your message: \n";
    getline(cin, message);

     /*
    change the message to all caps
    so characters in the message can match the keys in the map
    */
    transform(message.begin(), message.end(), message.begin(), ::toupper);

    for(int i = 0; i < message.length(); i ++)
    {
        for(auto y : link)
        {
            if(isalpha(message[i]))
            {
                if(message[i] == y.second)
                {
                    x = y.first;
                    pos = ((5 * x) + 8) % 26;
                    output = link[pos];  
                }
            }
            else if(isspace(message[i]))
            {
                output = " ";
            }
            else if(isdigit(message[i]))
            {
                output = message[i];
            }   
            else 
           {
               output = message[i];
            }
        }
        cout << output;
    }    
}

// defining decryption of affine text
string decryption() 
{
    string message1;
    string output2;
    int x2;
    int pos2;
    int pos3;

    map <int, char> link2 = {
        {0,'A'},{1,'B'},{2,'C'},{3,'D'},
        {4,'E'},{5,'F'},{6,'G'},{7,'H'},
        {8,'I'},{9,'J'},{10,'K'},{11,'L'},
        {12,'M'},{13,'N'},{14,'O'},{15,'P'},
        {16,'Q'},{17,'R'},{18,'S'},{19,'T'},
        {20,'U'},{21,'V'},{22,'W'},{23,'X'},
        {24,'Y'},{25,'Z'}
    };


        // get user input
    cout << "Enter your message: \n";
    getline(cin, message1);

     /*
    change the message to all caps
    so characters in the message can match the keys in the map
    */
    transform(message1.begin(), message1.end(), message1.begin(), ::toupper);

    for(int k = 0; k < message1.length(); k ++)
    {
        for(auto j : link2)
        {
            if(isalpha(message1[k]))
            {
                if(message1[k] == j.second)
                {
                    x2 = j.first;
                    pos2 = 21*(x2 - 8);
                    
                    if(pos2 < 0)
                    {
                        pos3 = ((21 * (x2 - 8) % 26) + 26) % 26;
                        output2 = link2[pos3];
                    }
                    else if(pos2 >= 0) 
                    {   
                         pos2 = 21*(x2 - 8) % 26;
                        output2 = link2[pos2]; 
                    }
                
                   
                }
            }
            else if(isspace(message1[k]))
            {
                output2 = " ";
            }
            else if(isdigit(message1[k]))
            {
                output2 = message1[k];
            }   
            else 
           {
               output2 = message1[k];
            }
        }
         cout << output2;   
    }  


}