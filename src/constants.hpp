#include <string>
#include <vector>
#include <map>

namespace accordion_bot {

static const std::vector<std::string> NotesInOrder = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

static const std::map<std::string, std::string> NoteMappings = {
    {"Cb", "B"},
    {"Cbb", "A#"},
    {"C##", "D"},
    {"Db", "C#"},
    {"Dbb", "C"},
    {"D##", "E"},
    {"Eb", "D#"},
    {"Ebb", "D"},
    {"E#", "F"},
    {"E##", "F#"},
    {"Fb", "E"},
    {"Fbb", "D#"},
    {"F##", "G"},
    {"Gb", "F#"},
    {"Gbb", "F"},
    {"G##", "A"},
    {"Ab", "G#"},
    {"Abb", "G"},
    {"A##", "B"},
    {"Bb", "A#"},
    {"Bbb", "A"},
    {"B#", "C"},
    {"B##", "C#"}
};

static const double C1Freq = 32.70319566257483;

} // namespace accordion_bot