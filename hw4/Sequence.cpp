#include "Sequence.h"
#include <iostream>

Sequence::Sequence(void)
{}

// Constructor to initialize the Sequence object with description and sequence strings
Sequence::Sequence(const std::string& desc_str, const std::string& seq_str) : desc(desc_str), seq(seq_str) {
    check(); // Check if the sequence contains valid characters
}

// Function to check if the sequence contains valid characters
void Sequence::check() const {
    // Define a string containing all valid characters for the sequence
    std::string valid_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Check if any character in the sequence is not a valid amino acid
    size_t invalid_char_pos = seq.find_first_not_of(valid_chars);

    // If an invalid character is found, throw an exception
    if (invalid_char_pos != std::string::npos) {
        throw std::invalid_argument("Invalid character in sequence");
    }
}

// Function to find the next mutation in the sequence starting from a given position
std::string Sequence::findNextMutation(const Sequence& s, const int& pos) const {
    // Check if the position is valid
    if (pos < 0 || pos >= static_cast<int>(seq.length())) {
        throw std::invalid_argument("Invalid position");
    }
    
    // Check if sequences are of the same length
    if (seq.length() != s.seq.length()) {
        throw std::invalid_argument("Sequences must be of equal length");
    }

    // Check if amino acid at the given position is different
    if (seq[pos] != s.seq[pos]) {
        // Return the mutation string if different amino acids are found
        return std::string(1, seq[pos]) + std::to_string(pos + 1) + std::string(1, s.seq[pos]);
    } else {
        // Find the next mutation after the given position
        for (size_t i = pos + 1; i < seq.length(); ++i) {
            if (seq[i] != s.seq[i]) {
                // Return the mutation string if a mutation is found
                return std::string(1, seq[i]) + std::to_string(i + 1) + std::string(1, s.seq[i]);
            }
        }
    }

    // Return "no mutation found" if no mutation is found
    return "no mutation found";
}

// Overloaded input operator to read a Sequence object from the input stream
std::istream& operator>>(std::istream& is, Sequence& s) {
    std::string desc_str, seq_str;
    std::getline(is, desc_str); // Read description line
      // Read sequence line

    // Check if the input is valid
    //if (desc_str.empty() || seq_str.empty()) {
        //throw std::invalid_argument("Invalid sequence input");
    //}
   //while

    // Create a new Sequence object
    s.desc = desc_str.substr(1);
    s = Sequence(desc_str, seq_str);
    std::getline(is, seq_str);
    while (seq_str.size()>0)
    {
        s.seq += seq_str;
        getline(is, seq_str);
    }

    return is;
}

// Overloaded output operator to write a Sequence object to the output stream
std::ostream& operator<<(std::ostream& os, const Sequence& s) {
    os << s.desc << "\n"; // Output description line
    // Output sequence in lines of maximum 70 characters
    for (size_t i = 0; i < s.seq.length(); i += 70) {
        os << s.seq.substr(i, 70) << "\n";
    }
    os << "\n"; // Output an empty line at the end
    return os;
} 


Sequence findMUM(const Sequence& s1, const Sequence& s2)
{
   const int minsize = 20;
   int pos1 = 0;
    int pos2 = 0;
   std::string max_mum;
   for (size_t i1 = 0; i1 < s1.seq.size(); ++i1)
   {
        
       for (size_t length = minsize; length <= s1.seq.size() - i1; length++)
       {
            
           std::string sub = s1.seq.substr(i1, length);
           size_t i2 = s2.seq.find(sub);
           if (i2 != std::string::npos)
           {
                
               //Make two strings and compare strins to current substrings
               std::string::size_type o1, o2;
                o1 = (s1.seq.find(sub, i1 + 1) );
                o2 = (s2.seq.find(sub, i2 + 1) );

               if ((o1 == std::string::npos) && (o2 == std::string::npos))
               {
                    //std::cout << "inif" << std::endl;
                   // Update max_mum if the current substring is larger
                   if (max_mum.empty() || length > max_mum.size())
                   {
                       max_mum = sub;
                       pos1 = i1;
                       pos2 = i2;
                       //std::cout <<  " found MUM:" << max_mum << std::endl << "at i=" << i1+1 << " at i2=" << i2+1 << std::endl;
                   }
               }
                
           }
       }
   }

   if (!max_mum.empty())
   {
        // Return a Sequence object representing the MUM
       std::string mum_desc = "MUM pos1=" + std::to_string(pos1+1) + " pos2=" + std::to_string(pos2+1);
       return Sequence(mum_desc, max_mum);
       
   }
   else
   {
       // Return a Sequence object indicating no MUM found
       return Sequence("No MUM found", "");
   }
}
