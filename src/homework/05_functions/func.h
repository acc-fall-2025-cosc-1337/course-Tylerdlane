#include <string>
using std::string;

// Calculates GC content of a DNA string
double get_gc_content(const string& dna);

// Reverses a DNA string (without using std::reverse)
string get_reverse_string(string dna);

// Returns the DNA complement (reverse + complement)
string get_dna_complement(string dna);

