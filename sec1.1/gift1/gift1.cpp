/*
	ID: erkam.u1
	PROG: gift1
	LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

/*
A group of NP (2 ≤ NP ≤ 10) uniquely named friends has decided to exchange gifts of money. Each of these friends might or might not give some money to any or all of the other friends. Likewise, each friend might or might not receive money from any or all of the other friends. Your goal in this problem is to deduce how much more money each person gives than they receive.

The rules for gift-giving are potentially different than you might expect. Each person sets aside a certain amount of money to give and divides this money evenly among all those to whom he or she is giving a gift. No fractional money is available, so dividing 3 among 2 friends would be 1 each for the friends with 1 left over -- that 1 left over stays in the giver's "account".

In any group of friends, some people are more giving than others (or at least may have more acquaintances) and some people have more money than others.

Given a group of friends, no one of whom has a name longer than 14 characters, the money each person in the group spends on gifts, and a (sub)list of friends to whom each person gives gifts, determine how much more (or less) each person in the group gives than they receive.
*/

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    string result, name;
    int n, money, count;
    map <string, int> profit;
    fin >> n;
    string orderedNames[n]; // to keep name order
    for (int i = 0; i < n; ++i)
    {
        fin >> name;
        profit[name] = 0;
        orderedNames[i] = name;
    }
    for (int i = 0; i < n; ++i)
    {
        fin >> name;
        fin >> money >> count;
        if(money == 0 || count == 0 || money < count){
            continue;
        }
        profit[name] += money % count - money;
        for (int i = 0; i < count; ++i)
        {
            fin >> name;
            profit[name] += money / count;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        name = orderedNames[i];
        fout << name << " " << profit[name] << endl;
    }
    return 0;
}
