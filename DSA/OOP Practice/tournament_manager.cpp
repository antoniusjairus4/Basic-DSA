#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

class Player {
    protected:
        int player_id;
        string name;
        int age;

    public:
        Player() {
            player_id = 0;
            name = "";
            age = 0;
        }

        Player(int id, string n, int a) {
            player_id = id;
            name = n;
            age = a;
        }

        void display_basics() {
            cout << endl << "Player ID : " << player_id << endl;
            cout << "Name      : " << name << endl;
            cout << "Age       : " << age << endl;
        }

        int get_id() {
            return player_id;
        }
};

class Table_Tennis : public Player {
    private:
        int matches_won;
        float reaction_speed;

    public:
        Table_Tennis() {
            matches_won = 0;
            reaction_speed = 0.0;
        }

        Table_Tennis(int id, string n, int a, int m, float r) : Player(id, n, a) {
            matches_won = m;
            reaction_speed = r;
        }

        float calculate_score() { 
            return (matches_won * 10) + (reaction_speed * 2);
        }

        void display_details() {
            
            display_basics();

            cout << "Sport : Table Tennis" << endl;
            cout << "Matches won : " << matches_won << endl;
            cout << "Reaction Speed " << reaction_speed << endl;
            cout << "Score : " << calculate_score() << endl;
        }
};

class Chess_Player : public Player {
    private:
        int ratings;
        int tournaments;

    public:
        Chess_Player() {
            ratings = 0;
            tournaments = 0;
        }

        Chess_Player(int id, string n, int a, int r, int t) : Player(id, n, a){
            ratings = r;
            tournaments = t;
        }

        double calculate_score() {
            return (ratings / 100.0) + (tournaments * 15);
        }

        void display_details() {
            
            display_basics();
            
            cout << "Sport : Chess" << endl;
            cout << "Ratings : " << ratings << endl;
            cout << "Tournaments Won : " << tournaments << endl;

            cout << "Score : " << calculate_score() << endl;
        }
};

class Athlete : public Player {
    private:
        float speed;
        float stamina;

    public:
        Athlete() {
        speed = 0;
        stamina = 0;
    }

    Athlete(int id, string n, int a, float s, float st) : Player(id, n, a) {
        speed = s;
        stamina = st;
    }

    float calculate_score() {
        return (speed * 5) + (stamina * 3);
    }

    void display_details() {

        display_basics();

        cout << "Sport : Athlete" << endl;
        cout << "Speed : " << speed << endl;
        cout << "Stamina : " << stamina << endl;
        cout << "Score : " << calculate_score() << endl;
    }
};

int main()
{
    Table_Tennis tt[MAX];
    Chess_Player chess[MAX];
    Athlete ath[MAX];

    int tt_count = 0;
    int chess_count = 0;
    int athlete_count = 0;

    int choice;

    do
    {
        cout << endl << "Choices are being displayed below" << endl;
        cout << "1. Add Table Tennis Player" << endl;
        cout << "2. Add Chess Player" << endl;
        cout << "3. Add Athlete" << endl; 
        cout << "4. Display All Players" << endl;
        cout << "5. Show Top Performer" << endl;
        cout << "6. Exit" << endl;

        cout << endl << "Enter Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            int id, age;
            string name;

            int matches_won;
            float reaction_speed;

            cout << endl << "Enter Player ID : ";
            cin >> id;

            cin.ignore();

            cout << "Enter Name : ";
            getline(cin, name);

            cout << "Enter Age : ";
            cin >> age;

            cout << "Matches Won : ";
            cin >> matches_won;

            cout << "Reaction Speed : ";
            cin >> reaction_speed;

            tt[tt_count] = Table_Tennis(id, name, age, matches_won, reaction_speed );

            tt_count++;

            cout << endl << "Player Added Successfully!" << endl;
        }

        else if (choice == 2)
        {
            int id, age;
            string name;

            int ratings;
            int tournaments;

            cout << endl << "Enter Player ID : ";
            cin >> id;

            cin.ignore();

            cout << "Enter Name : ";
            getline(cin, name);

            cout << "Enter Age : ";
            cin >> age;

            cout << "Enter Rating : ";
            cin >> ratings;

            cout << "Enter Tournaments Won : ";
            cin >> tournaments;

            chess[chess_count] = Chess_Player( id, name, age, ratings, tournaments);

            chess_count++;

            cout << "\nPlayer Added Successfully!" << endl;
        }


        else if (choice == 3)
        {
            int id, age;
            string name;

            float speed;
            float stamina;

            cout << endl << "Enter Player ID : ";
            cin >> id;

            cin.ignore();

            cout << "Enter Name : ";
            getline(cin, name);

            cout << "Enter Age : ";
            cin >> age;

            cout << "Enter Speed : ";
            cin >> speed;

            cout << "Enter Stamina : ";
            cin >> stamina;

            ath[athlete_count] = Athlete(id, name, age, speed, stamina);

            athlete_count++;

            cout << endl << "Player Added Successfully!" << endl;
        }

        else if (choice == 4)
        {
            cout << "\n======= TABLE TENNIS PLAYERS =======\n";

            for (int i = 0; i < tt_count; i++){
                tt[i].display_details();

                cout << "--------------------------------\n";
            }

            cout << "\n=========== CHESS PLAYERS ==========\n";

            for (int i = 0; i < chess_count; i++){
                chess[i].display_details();

                cout << "--------------------------------\n";
            }

            cout << "\n============= ATHLETES =============\n";

            for (int i = 0; i < athlete_count; i++){
                ath[i].display_details();

                cout << "--------------------------------\n";
            }
        }

        else if (choice == 5)
        {
            double max_score = -1;
            string top_sport;

            for (int i = 0; i < tt_count; i++){
                if (tt[i].calculate_score() > max_score)
                {
                    max_score =
                        tt[i].calculate_score();

                    top_sport = "Table Tennis";
                }
            }

            for (int i = 0; i < chess_count; i++){
                if (chess[i].calculate_score()
                    > max_score)
                {
                    max_score =
                        chess[i].calculate_score();

                    top_sport = "Chess";
                }
            }

            for (int i = 0; i < athlete_count; i++){
                if (ath[i].calculate_score()
                    > max_score)
                {
                    max_score =
                        ath[i].calculate_score();

                    top_sport = "Athlete";
                }
            }

            if (max_score == -1) {
                cout << "\nNo Players Available!\n";
            }
            else {
                cout << "\n========== TOP PERFORMER ==========\n";

                cout << "Sport Type : "
                     << top_sport << endl;

                cout << "Highest Score : "
                     << max_score << endl;
            }
        }

        else if (choice == 6){
            cout << "\nExiting Program...\n";
        }

        else{
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}