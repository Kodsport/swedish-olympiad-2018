#include <vector>
#include <iostream>
#include <queue>

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
    vector<size_t> earliestBegin;
public:
    Song(const vector<T>&& _notes) : notes(_notes) {
    }

    void preprocess(size_t m) {
        size_t n = notes.size();
        earliestBegin.resize(n);
        earliestBegin[0] = 0;
        queue<size_t> increasing, decreasing;
        increasing.push(0);
        decreasing.push(0);
        for (size_t i = 1; i < n; i++) {
            earliestBegin[i] = earliestBegin[i-1];
            if (notes[i] < notes[i-1]) {
                increasing = queue<size_t>();
                increasing.push(i);
                decreasing.push(i);
                if (decreasing.size() > m) {
                    decreasing.pop();
                    earliestBegin[i] = decreasing.front();
                }
            }
            else if (notes[i] > notes[i-1]) {
                decreasing = queue<size_t>();
                decreasing.push(i);
                increasing.push(i);
                if (increasing.size() > m) {
                    increasing.pop();
                    earliestBegin[i] = increasing.front();
                }
            }
        }
    }

    bool canPlay(const Query& query, size_t m) {
        return query.begin >= earliestBegin[query.end - 1];
    }
};

Song<int> readSong(size_t numNotes) {
    vector<int> notes(numNotes);
    for (size_t i = 0; i < numNotes; i++) {
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
    size_t n, m, q;
    cin >> n >> m >> q;
    if (n <= 0 || n > 1000000) {
        throw range_error("n must be an integer in the range [1,1000000]");
    }
    if (m <= 0 || m > 1000000) {
        throw "m must be an integer in the range [1,1000000]";
    }
    if (q <= 0 || q > 1000000) {
        throw "q must be an integer in the range [1,1000000]";
    }
    auto song = readSong(n);
    song.preprocess(m);
    vector<Query> queries;
    for (size_t i = 0; i < q; i++) {
        size_t a, b;
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
            cout << "ja" << endl;
        }
        else {
            cout << "nej" << endl;
        }
    }
    }
    catch(char const* exception) {
        cout << exception << endl;
    }
}
