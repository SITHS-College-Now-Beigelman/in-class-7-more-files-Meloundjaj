#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    // Variables for file input and output
    ifstream inFile;
    ofstream outFile;
    
    // Variables to store player info and scores
    string player;
    string name;
    double score1, score2, score3;
    
    // Open the files
    inFile.open("ingame_scores.txt");
    outFile.open("outgame_scores.txt");

    // Check if files opened successfully
    if (!inFile || !outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Loop to process 3 players
    for (int i = 1; i <= 3; i++) {
        // Read player and name from input file
        inFile >> player >> name;
        
        // Write player and name to output file
        outFile << player << " " << name << endl;

        // Read three scores from input file
        inFile >> score1 >> score2 >> score3;

        // Calculate average score
        double average = (score1 + score2 + score3) / 3.0;
        
        // Write the average to the output file
        outFile << "Average: " << average << endl;

        // Classify the player's level based on average score
        if (average < 1000)
            outFile << "Beginner - Keep practicing!" << endl;
        else if (average < 1500)
            outFile << "Intermediate" << endl;
        else if (average < 1800)
            outFile << "Advanced - Good Job!" << endl;
        else if (average < 2000)
            outFile << "Master - Great work!" << endl;
        else
            outFile << "Congratulations! You are an Expert!" << endl;
    }
    
    // Close the files
    inFile.close();
    outFile.close();

    // output 
    /*Player1 Alex
Average: 71155
Congratulations! You are an Expert!
Player2 Maddie
Average: 659
Beginner - Keep practicing!
Player3 Yani
Average: 8.40821e+06
Congratulations! You are an Expert!*/

    return 0;
}
