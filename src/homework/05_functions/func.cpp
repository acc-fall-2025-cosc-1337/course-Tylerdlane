#include "func.h"

// Calculate GC content
double get_gc_content(const string& dna)
{
    int count_gc = 0;
    for (char base : dna)
    {
        if (base == 'G' || base == 'C')
        {
            count_gc++;
        }
    }

    // Convert to percentage
    return static_cast<double>(count_gc) / dna.size();
}

// Reverse a string manually (no std::reverse)
string get_reverse_string(string dna)
{
    string reversed = "";
    for (int i = dna.size() - 1; i >= 0; --i)
    {
        reversed += dna[i];
    }
    return reversed;
}

// Get DNA complement (reverse first, then swap bases)
string get_dna_complement(string dna)
{
    string reversed = get_reverse_string(dna);
    for (char& base : reversed)
    {
        switch (base)
        {
        case 'A': base = 'T'; break;
        case 'T': base = 'A'; break;
        case 'C': base = 'G'; break;
        case 'G': base = 'C'; break;
        }
    }
    return reversed;
}
