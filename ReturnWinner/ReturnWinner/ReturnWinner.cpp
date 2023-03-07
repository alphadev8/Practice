// ReturnWinner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

std::string DetermineWinner(std::string Participants[], int scores[], int n) {

    std::map<std::string, int> ScoresMap;
    for (int i = 0; i < n; i++)
    {
        ScoresMap[Participants[i]] += scores[i];
    }

    std::string winner = "";
    int max_score = 0;

    for (auto x : ScoresMap)
    {
        if (x.second > max_score)
        {
            max_score = x.second;
            winner = x.first;
        }
    }
    return winner;
}

int main()
{
    std::string participants[] = { "leela","abhisek","phani" };
    int scores[] = { 10,30,12};
    int n = 3;
    std::string w = DetermineWinner(participants, scores, n);
    std::cout <<"Winner:" << w;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
