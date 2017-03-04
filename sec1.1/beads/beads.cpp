/*
	ID: erkam.u1
	PROG: beads
	LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
You have a necklace of N red, white, or blue beads (3<=N<=350) some of which are red, others blue, and others white, arranged at random. Here are two examples for n=29:

                1 2                               1 2
            r b b r                           b r r b
          r         b                       b         b
         r           r                     b           r
        r             r                   w             r
       b               r                 w               w
      b                 b               r                 r
      b                 b               b                 b
      b                 b               r                 b
       r               r                 b               r
        b             r                   r             r
         b           r                     r           r
           r       r                         r       b
             r b r                             r r w
            Figure A                         Figure B
                        r red bead
                        b blue bead
                        w white bead
The beads considered first and second in the text that follows have been marked in the picture.

The configuration in Figure A may be represented as a string of b's and r's, where b represents a blue bead and r represents a red one, as follows: brbrrrbbbrrrrrbrrbbrbbbbrrrrb .

Suppose you are to break the necklace at some point, lay it out straight, and then collect beads of the same color from one end until you reach a bead of a different color, and do the same for the other end (which might not be of the same color as the beads collected before this).

Determine the point where the necklace should be broken so that the most number of beads can be collected.

In some necklaces, white beads had been included as shown in Figure B above. When collecting beads, a white bead that is encountered may be treated as either red or blue and then painted with the desired color. The string that represents this configuration can include any of the three symbols r, b and w.
*/
int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    string result, necklace;
    int n, changed = 0, longest = 0;
    fin >> n >> necklace;

    // to give circular effect, append string to itself
    // be careful not to exceed original string length
    necklace.append(necklace);
    int len = necklace.length();

    int length = 0;
    for (int i = 0; i < len; ++i)
    {
        length = 0;
        changed = 0;
        char type = necklace[i];
        for (int j = i; j < i + len/2 && j < len; ++j)
        {
            // consider w as joker
            if(necklace[j] == 'w'){
                length++;
            }
            else if(changed == 0){
                type = necklace[j];
                changed++;
                length++;
            }
            else if(type == necklace[j]){
                length++;
            }
            // bead type can change at most 2 times in a substring
            else if(type != necklace[j] && changed == 1){
                type = necklace[j];
                changed++;
                length++;
            }
            else{
                break;
            }
        }
        if(longest < length){
            longest = length;
        }
    }
    fout << longest << endl;
    return 0;
}
