#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "configuration.hpp"
#include "helpers.hpp"
#include "constants.hpp"

namespace accordion_bot {

enum class ButtonType {
    Push,
    Pull
};

std::string toString(ButtonType type) {
    return (type == ButtonType::Push) ? "Push" : "Pull";
}

struct Button {
    int frequency;
    int column;
    int row;
    ButtonType type;
    std::string toString() const {
        return ::accordion_bot::toString(type) + " Button(" + std::to_string(frequency) + "Hz [" + std::to_string(row) + "," + std::to_string(column) + "])";
    }
};

struct NoteButton {
    Button button;
    double frequency_difference;
};
std::string toString(NoteButton button, bool show_delta = false) {
    return button.button.toString() + (show_delta ? " (Δ" + std::to_string(button.frequency_difference) + "Hz)" : "");
}

struct Note {
    std::string name;
    int octave;
    double frequency;
    std::vector<NoteButton> corresponding_buttons;
    std::string toString(bool list_buttons = false) const {
        return name + std::to_string(octave) + " (" + std::to_string(frequency) + " Hz)" + (list_buttons ? " Buttons: " + ::accordion_bot::toString(corresponding_buttons) : "");
    }
};

/// Assumes buttonFreqs is in row order
void addButtons(std::vector<Button>& buttons, const std::vector<int>& buttonFreqs, int column, ButtonType type) {
    for (int i = 0; i < buttonFreqs.size(); ++i) {
        buttons.push_back({
            .frequency = buttonFreqs[i], 
            .column = column, 
            .row = i + 1, 
            .type = type
        });
    }
}

} // namespace accordion_bot

using namespace accordion_bot;

int main() {
    std::vector<Button> buttons;
    addButtons(buttons, Col1PullFreqs, 1, ButtonType::Pull);
    addButtons(buttons, Col1PushFreqs, 1, ButtonType::Push);
    addButtons(buttons, Col2PullFreqs, 2, ButtonType::Pull);
    addButtons(buttons, Col2PushFreqs, 2, ButtonType::Push);

    const double semitoneRatio = std::pow(2.0, 1.0 / 12.0);
    const double quarterToneRatio = std::pow(2.0, 1.0 / 24.0);
    std::vector<Note> notes;
    for (int octave = 1; octave <= MaxOctaves; ++octave) {
        for (const auto& note_name : NotesInOrder) {
            Note note;
            note.name = note_name;
            note.octave = octave;
            note.frequency = notes.empty() ? C1Freq : notes.back().frequency * semitoneRatio;
            double maxFreq = note.frequency * quarterToneRatio;
            double minFreq = note.frequency / quarterToneRatio;
            for (const Button& button : buttons) {
                if (button.frequency >= minFreq && button.frequency <= maxFreq) {
                    note.corresponding_buttons.push_back(NoteButton{
                        .button = button, 
                        .frequency_difference = std::abs(button.frequency - note.frequency) });
                }
            }
            std::sort(note.corresponding_buttons.begin(), note.corresponding_buttons.end(), [&](const NoteButton& a, const NoteButton& b) {
                return a.frequency_difference < b.frequency_difference;
            });
            notes.push_back(note);
        }
    }
    for (const auto& note : notes) {
        std::cout << note.toString(true) << std::endl;
    }
    return 0;
}


