#include "Games.h"
#include <vector>
#include <string>
#include <iostream>

std::vector<Games> getTopN_Heap(const std::vector<Games> &allGames, int N);
void printGame(const Games &g);

int main() {
    Games g1("Elden Ring", "PC", {"RPG", "Open World"}, 9.7f);
    Games g2("Animal Crossing", "Switch", {"Simulation", "Casual"}, 9.1f);
    Games g3("Call of Duty", "Xbox", {"Shooter"}, 8.4f);
    Games g4("Stardew Valley", "PC", {"Farming", "Indie"}, 9.4f);
    Games g5("Overwatch", "PlayStation", {"Shooter", "Multiplayer"}, 8.9f);

    std::vector<Games> sample = {g1, g2, g3, g4, g5};

    std::vector<Games> top3 = getTopN_Heap(sample, 3);

    std::cout << "\nTop 3 games by rating:\n";
    for (const auto &g : top3) {
        printGame(g);
    }

    return 0;
}
