#include <bits/stdc++.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class TicTacToe{
public:
    vector<vector<char>> board{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    vector<vector<char>> s_board{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    string player = "Player";
    int s;
    int start = 0;

    char X = 'X';
    char O = 'O';

    int countWins(char p1, char p2){
        int count = 0;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] != p1 && board[i][j] != p2){
                    char c = board[i][j];
                    board[i][j] = p1;

                    if(win(p1) == 1)
                        count++;

                    board[i][j] = c;
                }
            }
        }

        return count;
    }

    void getInsaneAIMove(char ai, char pl, int x = 0, string name = ""){
        srand(time(NULL));

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] != ai && board[i][j] != pl){
                    char c = board[i][j];
                    board[i][j] = ai;

                    if(win(ai) == 1 || tie() == 1){
                        if(x) cout << name << " Moved To Grid " << i * 3 + j + 1 << endl;
                        return ;
                    }

                    board[i][j] = c;
                }
            }
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] != ai && board[i][j] != pl){
                    char c = board[i][j];
                    board[i][j] = pl;

                    if(win(pl) == 1 || tie() == 1){
                        board[i][j] = ai;
                        if(x) cout << name << " Moved To Grid " << i * 3 + j + 1 << endl;
                        return ;
                    }

                    board[i][j] = c;
                }
            }
        }

        vector<vector<int>> wins2;
        int l = 0;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] != ai && board[i][j] != pl){
                    char c = board[i][j];
                    board[i][j] = ai;

                    if(countWins(ai, pl) > 1){
                        l++;
                        vector<int> r{i, j};
                        wins2.push_back(r);
                    }

                    board[i][j] = c;
                }
            }
        }

        if(l){
            vector<int> m = wins2[rand() % l];
            board[m[0]][m[1]] = ai;
            if(x) cout << name << " Moved To Grid " << m[0] * 3 + m[1] + 1 << endl;
            return ;
        }

        if(board[1][1] == '5'){
            board[1][1] = ai;
            if(x) cout << name << " Moved To Grid 5\n";

            return ;
        }

        int l1 = 0, l2 = 0;

        vector<vector<int>> pos_edges{{0, 0}, {0, 2}, {2, 0}, {2, 2}};
        vector<vector<int>> edges;

        for(int i = 0; i < 4; i++){
            int x = pos_edges[i][0], y = pos_edges[i][1];

            if(board[x][y] != ai && board[x][y] != pl){
                edges.push_back(pos_edges[i]);
                l1++;
            }
        }

        if(l1){
            vector<int> r = edges[rand() % l1];
            board[r[0]][r[1]] = ai;
            if(x) cout << name << " Moved To Grid " << r[0] * 3 + r[1] + 1 << endl;

            return ;
        }

        vector<vector<int>> pos_middles{{0, 1}, {1, 0}, {1, 2}, {2, 1}};
        vector<vector<int>> middles;

        for(int i = 0; i < 4; i++){
            int x = pos_middles[i][0], y = pos_middles[i][1];

            if(board[x][y] != ai && board[x][y] != pl){
                middles.push_back(pos_middles[i]);
                l2++;
            }
        }

        vector<int> r = middles[rand() % l2];
        board[r[0]][r[1]] = ai;
        if(x) cout << name << " Moved To Grid " << r[0] * 3 + r[1] + 1 << endl;

        return ;
    }

    void getHardAIMove(char ai, char pl, int x = 0, string name = ""){
        srand(time(NULL));

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] != ai && board[i][j] != pl){
                    char c = board[i][j];
                    board[i][j] = ai;

                    if(win(ai) == 1 || tie() == 1){
                        if(x) cout << name << " Moved To Grid " << i * 3 + j + 1 << endl;
                        return ;
                    }

                    board[i][j] = c;
                }
            }
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] != ai && board[i][j] != pl){
                    char c = board[i][j];
                    board[i][j] = pl;

                    if(win(pl) == 1 || tie() == 1){
                        board[i][j] = ai;
                        if(x) cout << name << " Moved To Grid " << i * 3 + j + 1 << endl;
                        return ;
                    }

                    board[i][j] = c;
                }
            }
        }

        int l = 0;

        vector<vector<int>> possible{{0, 0}, {0, 2}, {2, 0}, {2, 2},
                                      {0, 1}, {1, 0}, {1, 2}, {2, 1}};

        vector<vector<int>> available;

        for(int i = 0; i < 8; i++){
            int x = possible[i][0], y = possible[i][1];

            if(board[x][y] != ai && board[x][y] != pl){
                available.push_back(possible[i]);
                l++;
            }
        }

        vector<int> r = available[rand() % l];
        board[r[0]][r[1]] = ai;
        if(x) cout << name << " Moved To Grid " << r[0] * 3 + r[1] + 1 << endl;
        return ;
    }

    void getEasyAIMove(char ai, char pl, int x = 0, string name = ""){
        srand(time(NULL));

        int l = 0;

        vector<vector<int>> possible{{0, 0}, {0, 2}, {2, 0}, {2, 2},
                                      {0, 1}, {1, 0}, {1, 2}, {2, 1}};

        vector<vector<int>> available;

        for(int i = 0; i < 8; i++){
            int x = possible[i][0], y = possible[i][1];

            if(board[x][y] != ai && board[x][y] != pl){
                available.push_back(possible[i]);
                l++;
            }
        }

        vector<int> r = available[rand() % l];
        board[r[0]][r[1]] = ai;
        if(x) cout << name << " Moved To Grid " << r[0] * 3 + r[1] + 1 << endl;
        return ;
    }

    void getUserMove(char p1, char p2){
            int g;

            cout << "Please Enter Grid Number (1 - 9) : ";
            cin >> g;

            g -= 1;

            int x = g / 3;
            int y = g % 3;

            if(board[x][y] == p1 || board[x][y] == p2){
                cout << "Please Enter A Valid Move\n" << endl;
                getUserMove(p1, p2);
                return ;
            }

            cout << endl << player << " Moved To Grid " << g + 1;

            board[x][y] = p1;
            cout << "\n";
        }

    void getWin(char p){
        bool r1 = board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == p;
        bool r2 = board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == p;
        bool r3 = board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == p;
        bool c1 = board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == p;
        bool c2 = board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == p;
        bool c3 = board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == p;
        bool d1 = board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == p;
        bool d2 = board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == p;

        if(r1 == 1) {s_board[0][0] = p; s_board[0][1] = p; s_board[0][2] = p;}
        if(r2 == 1) {s_board[1][0] = p; s_board[1][1] = p; s_board[1][2] = p;}
        if(r3 == 1) {s_board[2][0] = p; s_board[2][1] = p; s_board[2][2] = p;}
        if(c1 == 1) {s_board[0][0] = p; s_board[1][0] = p; s_board[2][0] = p;}
        if(c2 == 1) {s_board[0][1] = p; s_board[1][1] = p; s_board[2][1] = p;}
        if(c3 == 1) {s_board[0][2] = p; s_board[1][2] = p; s_board[2][2] = p;}
        if(d1 == 1) {s_board[0][0] = p; s_board[1][1] = p; s_board[2][2] = p;}
        if(d2 == 1) {s_board[0][2] = p; s_board[1][1] = p; s_board[2][0] = p;}
    }

    void print1(){
        cout << "      |       |\n";
        cout << "  " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << "\n";
        cout << "      |       |\n";
        cout << "---------------------\n";
        cout << "      |       |\n";
        cout << "  " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << "\n";
        cout << "      |       |\n";
        cout << "---------------------\n";
        cout << "      |       |\n";
        cout << "  " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << "\n";
        cout << "      |       |\n";
        cout << "\n";
    }

    void print2(){
        cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
        cout << "---------\n";
        cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
        cout << "---------\n";
        cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
        cout << "\n";
    }

    void printWin(char p){
        getWin(p);
        cout << s_board[0][0] << " | " << s_board[0][1] << " | " << s_board[0][2] << endl;
        cout << "---------\n";
        cout << s_board[1][0] << " | " << s_board[1][1] << " | " << s_board[1][2] << endl;
        cout << "---------\n";
        cout << s_board[2][0] << " | " << s_board[2][1] << " | " << s_board[2][2] << endl;
        cout << endl;
    }

    string getRandomName(){
        srand(time(NULL));

        string names[250] = {
                "Jacob", "Michael",
                "Joshua", "Ethan", "Matthew", "Daniel",
                "Christopher", "Andrew", "Anthony", "William",
                "Joseph", "Alexander", "David", "Ryan",
                "Noah", "James", "Nicholas", "Tyler",
                "Logan", "John", "Christian", "Jonathan",
                "Nathan", "Benjamin", "Samuel", "Dylan",
                "Brandon", "Gabriel", "Elijah", "Aiden",
                "Angel", "Jose", "Zachary", "Caleb",
                "Jack", "Jackson", "Kevin", "Gavin",
                "Mason", "Isaiah", "Austin", "Evan",
                "Luke", "Aidan", "Justin", "Jordan",
                "Robert", "Isaac", "Landon", "Jayden",
                "Thomas", "Cameron", "Connor", "Hunter",
                "Jason", "Diego", "Aaron", "Bryan",
                "Owen", "Lucas", "Charles", "Juan",
                "Luis", "Adrian", "Adam", "Julian",
                "Alex", "Sean", "Nathaniel", "Carlos",
                "Jeremiah", "Brian", "Hayden", "Jesus",
                "Carter", "Sebastian", "Eric", "Xavier",
                "Brayden", "Kyle", "Ian", "Wyatt",
                "Chase", "Cole", "Dominic", "Tristan",
                "Carson", "Jaden", "Miguel", "Steven",
                "Caden", "Kaden", "Antonio", "Timothy",
                "Henry", "Alejandro", "Blake", "Liam",
                "Richard", "Devin", "Riley", "Jesse",
                "Seth", "Victor", "Brady", "Cody",
                "Jake", "Vincent", "Bryce", "Patrick",
                "Colin", "Marcus", "Cooper", "Preston",
                "Kaleb", "Parker", "Josiah", "Oscar",
                "Ayden", "Jorge", "Ashton", "Alan",
                "Jeremy", "Joel", "Trevor", "Eduardo",
                "Ivan", "Kenneth", "Mark", "Alexis",
                "Omar", "Cristian", "Colton", "Paul",
                "Levi", "Damian", "Jared", "Garrett",
                "Eli", "Nicolas", "Braden", "Tanner",
                "Edward", "Conner", "Nolan", "Giovanni",
                "Brody", "Micah", "Maxwell", "Malachi",
                "Fernando", "Ricardo", "George", "Peyton",
                "Grant", "Gage", "Francisco", "Edwin",
                "Derek", "Max", "Andres", "Javier",
                "Travis", "Manuel", "Stephen", "Emmanuel",
                "Peter", "Cesar", "Shawn", "Jonah",
                "Edgar", "Dakota", "Oliver", "Erick",
                "Hector", "Bryson", "Johnathan", "Mario",
                "Shane", "Jeffrey", "Collin", "Spencer",
                "Abraham", "Leonardo", "Brendan", "Elias",
                "Jace", "Bradley", "Erik", "Wesley",
                "Jaylen", "Trenton", "Josue", "Raymond",
                "Sergio", "Damien", "Devon", "Donovan",
                "Dalton", "Martin", "Landen", "Miles",
                "Israel", "Andy", "Drew", "Marco",
                "Andre", "Gregory", "Roman", "Ty",
                "Jaxon", "Avery", "Cayden", "Jaiden",
                "Roberto", "Dominick", "Rafael", "Grayson",
                "Pedro", "Calvin", "Camden", "Taylor",
                "Dillon", "Braxton", "Keegan", "Clayton",
                "Ruben", "Jalen", "Troy", "Kayden",
                "Santiago", "Harrison", "Dawson", "Corey",
                "Maddox", "Leo", "Johnny", "Kai",
                "Drake", "Julio", "Lukas", "Kaiden",
                "Zane", "Aden", "Frank", "Simon",
                "Sawyer", "Marcos", "Hudson", "Trey"
        };

        string name = names[rand() % 250];
        return name;
    }

    void help(){
        system("CLS");
        string option;

        cout << "B for Back\n\n";
        cout << "1.) Rules\n";
        cout << "2.) Tips\n";
        cout << "3.) About\n";

        cout << "\nPlease Enter Your Option : "; cin >> option;
        cout << endl;

        system("CLS");

        if(option == "b" || option == "B")
            return ;

        if(option == "1")
            rules();

        if(option == "2")
            tips();

        if(option == "3")
            about();

        system("pause");
        system("CLS");
        help();
    }

    void about(){
        cout << "This Game Of Tic-Tac-Toe Is Created By Srivaths\n";
        cout << "If You Are Unfamiliar With This Game, Please Read The Rules And Tips\n";
        cout << "Enjoy!!\n\n";
    }

    void changeName(){
        cout << "Please Enter Your Name : "; cin >> player;
    }

    void changeBoard(){
        system("CLS");
        cout << "B for Back\n\n";
        cout << "1.)\n\n";
        print1();
        cout << "2.)\n\n";
        print2();

        cout << endl;
        string option;

        cout << "\nPlease Enter Your Option : "; cin >> option;

        if(option == "b" || option == "B")
            return ;

        if(option == "1") s = 1;
        if(option == "2") s = 2;
    }

    void changeColor(){
        system("CLS");
        string c = "color ";
        string option;

        cout << "B for Back\n\n";
        cout << "1 = Blue\n";
        cout << "2 = Green\n";
        cout << "3 = Aqua\n";
        cout << "4 = Red\n";
        cout << "5 = Purple\n";
        cout << "6 = Yellow\n";
        cout << "7 = White\n";
        cout << "8 = Gray\n";
        cout << "9 = Light Blue\n";
        cout << "A = Light Green\n";
        cout << "B = Light Aqua\n";
        cout << "C = Light Red\n";
        cout << "D = Light Purple\n";
        cout << "E = Light Yellow\n";
        cout << "F = Bright White\n";
        cout << "\nPlease Enter Your Option : "; cin >> option;

        if(option == "b" || option == "B")
            return ;

        const char* x = (c + option).c_str();

        system(x);
    }

    void changeCharacters(){
        system("CLS");
        cout << "Please Enter Character For Player 1 (currently " << X << ") : "; cin >> X;
        cout << "Please Enter Character For Player 2 (currently " << O << ") : "; cin >> O;
    }

    void settings(){
        system("CLS");
        string option;

        cout << "B for Back\n\n";
        cout << "1.) Change Name\n";
        cout << "2.) Change Board\n";
        cout << "3.) Change Color\n";
        cout << "4.) Change Characters\n";
        cout << "\nPlease Enter Your Option : "; cin >> option;

        if(option == "b" || option == "B")
            return ;

        if(option == "1") changeName();
        if(option == "2") changeBoard();
        if(option == "3") changeColor();
        if(option == "4") changeCharacters();

        system("CLS");
        settings();
    }

    void main_menu(){
        system("CLS");
        string option;

        if(start == 0){
            intro();
            start = 1;
            main_menu();
            return ;
        }

        cout << "Hello " << player << endl;

        cout << "\nQ for Quit\n\n";
        cout << "1.) Help\n";
        cout << "2.) Settings\n";
        cout << "3.) Play\n";
        cout << "\nPlease Enter Your Option : "; cin >> option;

        if(option == "1")
            help();

        if(option == "2")
            settings();

        if(option == "3"){
            initialize();
            play('X', 'O');
        }

        if(option == "q" || option == "Q"){
            cout << "Thanks For Playing!\n";
            return ;
        }

        system("CLS");
        main_menu();
    }

    void rules(){
        cout << "1.) In Tic-Tac-Toe, There Are 2 Players \n\tAnd Their Characters Are X and O respectively\n";
        cout << "2.) Any Row Or Column or Diagonal Filled With The Same Characters Is A Win\n";
        cout << "3.) A Board Where There Are No Moves Left Is A Tie Or Draw\n";
        cout << "4.) You Are Not Allowed To Place Characters Over Another\n";
        cout << endl;
    }

    void tips(){
        cout << "1.) Always Try To Capture The Center\n";
        cout << "2.) Next Try To Capture The Edges\n";
        cout << "3.) Be Aware Of Instant Moves\n";
        cout << "4.) Always Try To Think A Move Ahead\n";
        cout << "5.) Try The Easy Bot To Get The Hang Of The Game\n";
        cout << endl;
    }

    void intro(){
        initialize();

        cout << "Hello Player, ";

        changeName();

        cout << "\nHello " << player << ", ";
        cout << "Welcome To The Game Of Tic-Tac-Toe!!\n";

        string know;

        cout << "Are You Familiar With The Game? (y / n) : "; cin >> know;

        if(know == "n" || know == "N"){
            cout << "\nFirst A Little Introduction To The Rules : \n\n";
            rules();
            cout << "\nNext A Few Tips : \n\n";
            tips();
            cout << "\nAnd That's ALL!!!\n\n";
            system("pause");
            cout << "\n\n";
        }

        cout << "\nPlease Pick Your Board Preference : \n\n";

        cout << "1.)\n";
        print1();
        cout << "2.)\n\n";
        print2();

        cout << endl;

        string option;
        cout << "Please Enter Your Option : "; cin >> option;

        if(option == "1") s = 1;
        if(option == "2") s = 2;

        cout << endl;

        cout << "Change Characters Via [Main Menu -> Settings -> Change Characters]\n";
        cout << endl;

        cout << "Here You Must Try Your Luck Against Three Levels!!\n\n";
        cout << "1.) Easy\n";
        cout << "2.) Hard\n";
        cout << "3.) Insane\n";
        cout << endl;

        cout << "Can YOU Beat Them ALL????\n";
        cout << "Let's See....\n\n";

        system("pause");
        system("CLS");
    }

    void play(char p1, char p2){
        system("CLS");
        initialize();
        srand(time(NULL));

        string computer = getRandomName();

        int level;

        cout << "1.) Easy\n";
        cout << "2.) Hard\n";
        cout << "3.) Insane\n";
        cout << endl;
        cout << "Please Enter Level : "; cin >> level;

        system("CLS");

        while(computer == player){
            computer = getRandomName();
        }

        cout << "\t\t" << player << " VS " << computer << "\n\n\n";

        int c = rand() % 2;

        char pl = p1, ai = p2;

        if(c == 0){
            ai = p1;
            pl = p2;

            cout << "\n" << computer << " Goes First!\n\n\n";
        }

        else {
            cout << "\n" << player << " Goes First!\n\n\n";
            if(s == 1) print1();
            else print2();
        }

        int d = 0;

        while(true){
            int t = d % 2;

            if(t == c){
                if(level == 1) getEasyAIMove(ai, pl, 1, computer);
                if(level == 2) getHardAIMove(ai, pl, 1, computer);
                if(level == 3) getInsaneAIMove(ai, pl, 1, computer);

                if(s == 1) print1();
                else print2();

                if(win(ai)){
                    cout << computer << " Wins!\n" << endl;
                    cout << "Below Is How " << computer << " Won\n\n";
                    printWin(ai);
                    break;
                }
            }

            else {
                getUserMove(pl, ai);

                if(s == 1) print1();
                else print2();

                if(win(pl)){
                    cout << player << " Wins!\n";
                    cout << "Below Is How " << player << " Won\n\n";
                    printWin(pl);
                    break;
                }
            }

            if(tie()){
                cout << "Tie!\n";
                break;
            }

            d += 1;
        }

        playAgain(p1, p2);
    }

    void initialize(){
        board[0][0] = '1'; s_board[0][0] = ' ';
        board[0][1] = '2'; s_board[0][1] = ' ';
        board[0][2] = '3'; s_board[0][2] = ' ';
        board[1][0] = '4'; s_board[1][0] = ' ';
        board[1][1] = '5'; s_board[1][1] = ' ';
        board[1][2] = '6'; s_board[1][2] = ' ';
        board[2][0] = '7'; s_board[2][0] = ' ';
        board[2][1] = '8'; s_board[2][1] = ' ';
        board[2][2] = '9'; s_board[2][2] = ' ';
    }

    void playAgain(char p1, char p2){
        cout << "\n";

        string option;
        cout << "Would You Like To Play Again? (y(yes) / n(no) / m(Main Menu) : "; cin >> option;

        if(option == "y" || option == "Y")
            play(p1, p2);

        else if(option == "n" || option == "N")
            return ;

        else if(option == "m" || option == "M")
            return ;

        else {
            cout << "\nPlease Enter a Valid Option";
            playAgain(p1, p2);
        }
    }

    bool win(char p){
        bool r1 = board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == p;
        bool r2 = board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == p;
        bool r3 = board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == p;

        bool c1 = board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == p;
        bool c2 = board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == p;
        bool c3 = board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == p;

        bool d1 = board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == p;
        bool d2 = board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == p;

        return r1 || r2 || r3 || c1 || c2 || c3 || d1 || d2;
    }

    bool tie(){
        bool c1 = board[0][0] != '1';
        bool c2 = board[0][1] != '2';
        bool c3 = board[0][2] != '3';
        bool c4 = board[1][0] != '4';
        bool c5 = board[1][1] != '5';
        bool c6 = board[1][2] != '6';
        bool c7 = board[2][0] != '7';
        bool c8 = board[2][1] != '8';
        bool c9 = board[2][2] != '9';

        return c1 && c2 && c3 && c4 && c5 && c6 && c7 && c8 && c9;
    }
};

int main()
{
    TicTacToe game;

    game.main_menu();
}
