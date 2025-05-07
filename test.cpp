#include <iostream>
#include <vector>
using namespace std;

class Bowling {
private:
    vector<int> throwsList;

public:
    void addThrow(int pins) {
        throwsList.push_back(pins);
    }

    int calculateScore() {
        int total = 0, index = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (isStrike(index)) { 
                total += 10 + strikeBonus(index);
                index++;
            } else if (isSpare(index)) { 
                total += 10 + spareBonus(index);
                index += 2;
            } else { 
                total += frameScore(index);
                index += 2;
            }
        }

        return total;
    }

private:
    bool isStrike(int idx) { return throwsList[idx] == 10; }

    bool isSpare(int idx) { return throwsList[idx] + throwsList[idx + 1] == 10; }

    int strikeBonus(int idx) { return throwsList[idx + 1] + throwsList[idx + 2]; }

    int spareBonus(int idx) { return throwsList[idx + 2]; }

    int frameScore(int idx) { return throwsList[idx] + throwsList[idx + 1]; }
};

int main() {
    Bowling game;

    vector<int> rolls = {1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6};

    for (int pins : rolls) game.addThrow(pins);

    cout << "Total Score: " << game.calculateScore() << endl;

    return 0;
}
