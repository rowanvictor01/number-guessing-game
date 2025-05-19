// ready to upload inital version to github


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int check(int i, int rn)
{
    if(i > rn)
    {
        return 1;
    }
    else if(i < rn)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

void validNumber(int &i)
{
    bool loop = true;
    while(loop)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer." << endl;
            cin >> i;
            loop;  // don't need. can use break instead and set while condition to true
        }
        else if(i > 100 || i < 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Number is not more than 100 nor less than 0. Please only enter numbers from 0 to 100." << endl;
            cin >> i;
            loop;  // don't need
        }
        else
        {
            loop = false;  // break instead
        }
    }
}

bool confirmReply(string &r)
{
    while(r != "Yes" && r != "yes" && r != "No" && r != "no")
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid response. Please reply with a yes or a no." << endl;
        cin >> r;
    }
    if(r == "Yes" || r == "yes")
    {
        cout << "Let's go!!" << endl;
        return true;
    }
    else if(r == "No" || r == "no")
    {
        cout << "Thanks for playing!" << endl;
        return false;
    }
}


int main()
{
    srand(time(NULL));
    int input;
    bool again = true;
    string reply;
    int checkResult;

    do
    {
        int randomNum = rand() % 101;
        int tries = 10;
        cout << "\nI have randomly selected a positive integer from 1 to 100. What number do I have?" << endl;
        do // using a for-loop might be better
        {
            cin >> input;
            validNumber(input);
            checkResult = check(input, randomNum);
            if(checkResult == 1)
            {
                cout << "Too High! " << --tries << " tries remaining..." << endl;
            }
            else if(checkResult ==2)
            {
                cout << "Too Low! " << --tries << " tries remaining..." << endl;
            }
        }while(tries > 0 && checkResult != 3);
        if(checkResult == 3)
        {
            cout << "\nYour guess is correct!! " << randomNum << " is my number!" << endl;
        }
        else if(tries == 0)
        {
            cout << "Oh no! Unfortunately you've ran out of tries.. :( The correct number is " << randomNum << "!\n" << endl;
        }
        cout << "Would you like to play again?" << endl;
        cin >> reply;
        again = confirmReply(reply);
    }while (again);

    return 0;
}