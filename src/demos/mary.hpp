#include <vector>
#include <string>
#include <variant>

struct Note {
    std::variant<std::string, std::vector<std::string>> notes;
    double duration;
};

std::vector<Note> melody{
    {"E4", 0.25}, {"D4", 0.25}, {"C4", 0.25}, {"D4", 0.25}, {"E4", 0.25}, {"E4", 0.25}, {"E4", 0.5}, 
    {"D4", 0.25}, {"D4", 0.25}, {"D4", 0.5}, 
    {"E4", 0.25}, {"G4", 0.25}, {"G4", 0.5}, 
    {"E4", 0.25}, {"D4", 0.25}, {"C4", 0.25}, {"D4", 0.25}, {"E4", 0.25}, {"E4", 0.25}, {"E4", 0.25}, {"E4", 0.25}, {"D4", 0.25}, {"D4", 0.25}, {"E4", 0.25}, {"D4", 0.25}, {"C4", 0.75}, {"X", 0.25}};