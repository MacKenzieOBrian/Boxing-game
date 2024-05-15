#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include <set>
#include <time.h>
#include <vector>

using namespace std;

// Define weight classes for boxing
int weightClasses[13] = {
    115, 118, 122, 126, 130, 135, 140, 147, 154, 160, 168, 175, 200
};

// Define attributes for boxers
struct Attributes
{
    int speed;
    int power;
    int agility;
    int endurance;
};

// Define a boxer
struct Boxer
{
    int id;
    Attributes attributes;
    int weightClass;
    int weight;
    int wins = 0;
    int losses = 0;
};

// Define a boxing match
class BoxingMatch
{
public:
    BoxingMatch(Boxer& boxer1, Boxer& boxer2) : boxer1(boxer1), boxer2(boxer2) {}

    // Simulate the boxing match
    void simulate()
    {
        // Simulate each round
        for (int round = 1; round <= numRounds; ++round)
        {
            // Simulate actions in the round
            // For simplicity, let's assume the boxer with higher overall attributes wins the round
            int score1 = calculateScore(boxer1);
            int score2 = calculateScore(boxer2);

            // Update match statistics based on round outcome
            if (score1 > score2)
            {
                boxer1.wins++;
                boxer2.losses++;
            }
            else
            {
                boxer1.losses++;
                boxer2.wins++;
            }
        }
    }

    // Calculate score for a boxer in a round
    int calculateScore(Boxer& boxer)
    {
        // For simplicity, calculate score based on overall attributes
        return boxer.attributes.speed + boxer.attributes.power + boxer.attributes.agility + boxer.attributes.endurance;
    }

    // Print the winner of the match
    void printWinner()
    {
        if (boxer1.wins > boxer2.wins)
            cout << "The winner is boxer " << boxer1.id << "!" << endl;
        else if (boxer2.wins > boxer1.wins)
            cout << "The winner is boxer " << boxer2.id << "!" << endl;
        else
            cout << "The match ended in a draw!" << endl;
    }

private:
    Boxer& boxer1;
    Boxer& boxer2;
    int numRounds = 12; // Number of rounds in a boxing match
};

// Define a boxing tournament
class BoxingTournament
{
public:
    BoxingTournament(vector<Boxer>& boxers) : boxers(boxers) {}

    // Simulate the tournament
    void simulate()
    {
        // Create matches for the tournament
        for (int i = 0; i < boxers.size(); i += 2)
        {
            BoxingMatch match(boxers[i], boxers[i + 1]);
            match.simulate();
            match.printWinner();
        }
    }

private:
    vector<Boxer>& boxers;
};

int main()
{
    vector<Boxer> boxers;
    srand(time(0));

    // Create boxers for the tournament
    for (int i = 0; i < 16; ++i)
    {
        int weightClass = weightClasses[rand() % 13];
        Attributes attributes = {rand() % 100 + 50, rand() % 100 + 50, rand() % 100 + 50, rand() % 100 + 50};
        boxers.push_back({i + 1, attributes, weightClass, rand() % 20 + 100});
    }

    // Simulate the tournament for each weight class
    for (int i = 0; i < 13; ++i)
    {
        BoxingTournament tournament(boxers);
        cout << "Weight Class: " << weightClasses[i] << endl;
        tournament.simulate();
        cout << endl;
    }

    return 0;
}
