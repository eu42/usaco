""" A simple script file to create a folder with input and output files
	and c++ file with initial comment for usaco
"""
import subprocess
import sys

# Change following variables when needed
usrname = 'erkam.u1'
lang = 'C++'
problemName = input('enter the problem name:')

initialComment = """\"/*
	ID: {id}
	PROG: {prog}
	LANG: {lang}
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {{
    ofstream fout (\\\"{prog}.out\\\");
    ifstream fin (\\\"{prog}.in\\\");
    string result;
    int a, b;
    fin >> a >> b;
    fout << result << endl;
    return 0;
}}\"""".format(id=usrname, prog=problemName, lang=lang)

if problemName == '':
	sys.exit('no problem name is given')

createFolder = "mkdir " + problemName
subprocess.run(createFolder, shell=True, check=True)

createFiles = "touch {name}/{name}.in {name}/{name}.out {name}/{name}.cpp".format(name=problemName)
subprocess.run(createFiles, shell=True, check=True)

initializeCode = "echo {comment} >> {name}/{name}.cpp".format(comment=initialComment, name=problemName)
subprocess.run(initializeCode, shell=True, check=True)
