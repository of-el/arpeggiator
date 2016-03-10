#include "Arpeggiator.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string chord, note;
	int bpm;

	cout << "Please enter a chord in this format: note chord" << endl;
	cout << "Chord types are: diminished, minor, major, augmented," << endl;
	cout << "\t halfdiminished7, fulldiminished7, minor7, dominant7, major7" << endl;
	cout << "(e.g. G minor or GSharp dominant7): " << endl;
	cin >> note >> chord;

	cout << "Enter BPM (between 40 and 240): " << endl;
	cin >> bpm;

	arpeggiator arpChord(note, chord, bpm);

	arpChord.play();

	system("pause");
	return 0;
}