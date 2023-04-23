#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

enum class NoteGeneratorType {
    Random,
    OftenEqual,
    Unidirectional,
    Bidirectional,
};

bool bernoulli(double p) {
    return rand()/(RAND_MAX + 1.0) < p;
}

class NoteGenerator {
    private:

    int randomNote() {
        return 1+(rand()%maximumNote);
    }

    vector<int> generateRandom() {
        vector<int> notes;
        for (int i = 0; i < n; i++) {
            notes.push_back(randomNote());
        }
        return notes;
    }

    vector<int> generateOftenEqual() {
        vector<int> notes;
        for (int i = 0; i < n; i++) {
            if (i == 0 || !bernoulli(probabilityEqual)) {
                notes.push_back(randomNote());
            }
            else {
                notes.push_back(notes.back());
            }
        }
        return notes;
    }

    vector<int> generateUnidirectional() {
        vector<int> notes;
        for (int i = 0; i < n; i++) {
            if (i == 0 || bernoulli(probabilityChangeDirection)) {
                notes.push_back(randomNote());
            }
            else {
                int remainingNotes = (int)(1e9 - notes.back());
                int maxJump = (int)(remainingNotes * probabilityChangeDirection);
                if (maxJump <= 0)
                    maxJump = 1;
                notes.push_back(notes.back() + (rand() % maxJump));
            }
        }
        if (rand() % 2) {
            for (int& note : notes) {
                note = 1000000001 - note;
            }
        }
        return notes;
    }

    vector<int> generateBidirectional() {
        vector<int> notes;
        bool direction = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || bernoulli(probabilityChangeDirection)) {
                notes.push_back(randomNote());
                direction ^= 1;
            }
            else if (direction) {
                int remainingNotes = (int)(1e9 - notes.back());
                int maxJump = (int)(remainingNotes * probabilityChangeDirection);
                if (maxJump <= 0)
                    maxJump = 1;
                notes.push_back(notes.back() + (rand() % maxJump));
            }
            else {
                int remainingNotes = (int)(notes.back());
                int maxJump = (int)(remainingNotes * probabilityChangeDirection);
                if (maxJump <= 0)
                    maxJump = 1;
                notes.push_back(notes.back() - (rand() % maxJump));
            }
        }
        return notes;
    }

    public:
    
    NoteGeneratorType type;
    int n, m, maximumNote;
    double probabilityEqual;
    double probabilityChangeDirection;

    vector<int> generate() {
        switch (type) {
            case NoteGeneratorType::Random: return generateRandom();
            case NoteGeneratorType::OftenEqual: return generateOftenEqual();
            case NoteGeneratorType::Unidirectional: return generateUnidirectional();
            case NoteGeneratorType::Bidirectional: return generateBidirectional();
        }
        throw "Unknown note generator type";
    }
};

enum class QueryGeneratorType {
    Random,
    Wide,
    Narrow,
};

struct Query {
    int begin, end;

    Query(int _begin, int _end) : begin(_begin), end(_end) {
    }
};

class QueryGenerator {
    private:

    Query randomQuery() {
        int a = rand()%n;
        int b = rand()%n;
        if (b >= a)
            b++;
        else
            swap(a, b);
        return Query(a, b);
    }

    vector<Query> generateRandom() {
        vector<Query> queries;
        for (int i = 0; i < q; i++) {
            queries.push_back(randomQuery());
        }
        return queries;
    }

    vector<Query> generateWide() {
        vector<Query> queries;
        int chooseFrom = min((int)(2 * sqrt(q)), n / 2);
        if (chooseFrom <= 0)
            chooseFrom = 1;
        for (int i = 0; i < q; i++) {
            int a, b;
            do {
                a = rand()%chooseFrom;
                b = n-(rand()%chooseFrom);
                if (rand() % 1000 == 0) {
                    a = 0;
                    b = n-1;
                }
            } while (a >= b);
            queries.emplace_back(a, b);
        }
        return queries;
    }

    vector<Query> generateNarrow() {
        vector<Query> queries;
        for (int i = 0; i < q; i++) {
            int a = rand() % n;
            int b = a + 1 + (rand() % min(maxDistance, n - a));
            queries.emplace_back(a, b);
        }
        return queries;
    }

    public:

    QueryGeneratorType type;
    int n, q;
    int maxDistance;

    vector<Query> generate() {
        switch (type) {
            case QueryGeneratorType::Random: return generateRandom();
            case QueryGeneratorType::Wide: return generateWide();
            case QueryGeneratorType::Narrow: return generateNarrow();
        }
        throw "unknown query generator type";
    }
};

int main(int argc, char* argv[]) {
    try {
    int seed = atoi(argv[1]);
    srand(seed);
	ostream& out = cout;
    int n, m, q;
    n = atoi(argv[2]);
    m = atoi(argv[3]);
    q = atoi(argv[4]);
    out << n << " " << m << " " << q << endl;
    string noteTypeString = string(argv[5]);
    int argIndex = 6;
    NoteGenerator noteGenerator;
    noteGenerator.n = n;
    noteGenerator.m = m;
    noteGenerator.maximumNote = 1000000000;
    if (noteTypeString == "random")
        noteGenerator.type = NoteGeneratorType::Random;
    else if (noteTypeString == "often_equal") {
        noteGenerator.type = NoteGeneratorType::OftenEqual;
        noteGenerator.probabilityEqual = atof(argv[argIndex++]);
    }
    else if (noteTypeString == "unidirectional") {
        noteGenerator.type = NoteGeneratorType::Unidirectional;
        noteGenerator.probabilityChangeDirection = atof(argv[argIndex++]);
    }
    else if (noteTypeString == "bidirectional") {
        noteGenerator.type = NoteGeneratorType::Bidirectional;
        noteGenerator.probabilityChangeDirection = atof(argv[argIndex++]);
    }
    else
        throw "unknown note generator type " + noteTypeString;
    vector<int> notes = noteGenerator.generate();
    for (size_t i = 0; i < notes.size(); i++) {
        if (i > 0)
            out << " ";
        out << notes[i];
    }
    out << endl;
    string queryTypeString = string(argv[argIndex++]);
    QueryGenerator queryGenerator;
    queryGenerator.n = n;
    queryGenerator.q = q;
    if (queryTypeString == "random")
        queryGenerator.type = QueryGeneratorType::Random;
    else if (queryTypeString == "wide")
        queryGenerator.type = QueryGeneratorType::Wide;
    else if (queryTypeString == "narrow") {
        queryGenerator.type = QueryGeneratorType::Narrow;
        queryGenerator.maxDistance = atoi(argv[argIndex++]);
    }
    else
        throw "unknown note generator type " + queryTypeString;
    vector<Query> queries = queryGenerator.generate();
    for (const Query& query : queries) {
        out << query.begin+1 << " " << query.end << endl;
    }
    }
    catch (const char* exception) {
        cerr << exception << endl;
    }
}
