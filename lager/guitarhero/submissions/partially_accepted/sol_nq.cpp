#include <vector>
#include <iostream>

using namespace std;

class Query {
public:
    size_t begin, end;

    Query(size_t _begin, size_t _end) : begin(_begin), end(_end) {
    }
};

template <class T>
class Song {
private:
    vector<T> notes;
public:
    Song(const vector<T>&& _notes) : notes(_notes) {
    }

    bool canPlay(const Query& query, int m) {
        int lowestNote = 1;
        int highestNote = m;
        for (size_t i = query.begin + 1; i < query.end; i++) {
            int previousNote = notes[i - 1];
            int currentNote = notes[i];
            if (currentNote < previousNote) {
                highestNote--;
                lowestNote = 1;
            }
            else if (currentNote > previousNote) {
                lowestNote++;
                highestNote = m;
            }
            if (lowestNote > highestNote) {
                return false;
            }
        }
        return true;
    }
};

Song<int> readSong(int numNotes) {
    vector<int> notes(numNotes);
    for (int i = 0; i < numNotes; i++) {
        cin >> notes[i];
        if (notes[i] <= 0 || notes[i] > 1000000000) {
            throw "notes must be integers in the range [1,1e9]";
        }
    }
    return Song<int>(move(notes));
}

int main() {
    ios_base::sync_with_stdio(false);
    try {
    int n, m, q;
    cin >> n >> m >> q;
    if (n <= 0 || n > 1000000) {
        throw "n must be an integer in the range [1,1000000]";
    }
    if (m <= 0 || m > 1000000) {
        throw "m must be an integer in the range [1,1000000]";
    }
    if (q <= 0 || q > 1000000) {
        throw "q must be an integer in the range [1,1000000]";
    }
    auto song = readSong(n);
    vector<Query> queries;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (a < 1 || b > n) {
            throw "a and b must be integers in the range [1,n]";
        }
        if (a > b) {
            throw "a cannot be greater than b";
        }
        queries.emplace_back(a-1, b);
    }
    for (const Query& query : queries) {
        if (song.canPlay(query, m)) {
            cout << "Ja" << endl;
        }
        else {
            cout << "Nej" << endl;
        }
    }
    }
    catch(char const* exception) {
        cout << exception << endl;
    }
}
