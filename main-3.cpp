#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Horse {
private:
    int position;

public:
    Horse() : position(0) {}

    int getPosition() const {
        return position;
    }

    void move() {
        if (rand() % 2 == 1) {
            position++;
        }
    }
};

class Race {
private:
    int numHorses;
    int trackLength;
    vector<Horse> horses;

public:
    Race(int numHorses, int trackLength) : numHorses(numHorses), trackLength(trackLength) {
        horses.resize(numHorses);
        srand(time(0));
    }

    void runRace() {
        cout << "Race begins ---" << endl;

        while (true) {
            for (int i = 0; i < numHorses; i++) {
                horses[i].move();
                for (int j = 0; j < trackLength; j++) {
                    if (j == horses[i].getPosition()) {
                        cout << i + 1;
                    } else {
                        cout << ".";
                    }
                }
                cout << endl;
                if (horses[i].getPosition() >= trackLength) {
                    cout << "Horse " << i + 1 << " wins!" << endl;
                    return;
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int numHorses, trackLength;

    do {
        cout << "Enter number of horses: ";
        cin >> numHorses;
        if (numHorses < 2) {
            cout << "Number of horses cannot be less than 2, try again!" << endl;
        }
    } while (numHorses < 2);

    do {
        cout << "Enter the track's length: ";
        cin >> trackLength;
        if (trackLength < 2) {
            cout << "The track's length cannot be less than 2, try again!" << endl;
        }
    } while (trackLength < 2);

    Race race(numHorses, trackLength);
    race.runRace();

    return 0;
}

