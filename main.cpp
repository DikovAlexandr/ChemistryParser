#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

vector<pair<string, int>> splitter(string s) {
    string formula = s;
    vector<pair<string, int>> elements;
    int index = -1;
    while (formula.length() > 0) {
        if (isupper(formula[0])) {
            index++;
            elements.emplace_back("", 1);
            elements[index].first = formula[0];
        }
        if (islower(formula[0]))
            elements[index].first += formula[0];
        if (isdigit(formula[0]))
            elements[index].second = int(formula[0]) - 48;
        formula.erase(0, 1);
    }
    return elements;
}

void printElements(vector<pair<string, int>> elements) {
    for (auto &element: elements)
        cout << element.first << "  " << element.second << endl;
}

int main() {
    string substance;
    getline(cin, substance);
    vector<pair<string, int>> elements;
    elements = splitter(substance);
    //printElements(elements);

    map<string, double> element;
    element["Ac"] = 227.028;
    element["Ag"] = 107.868;
    element["Al"] = 26.982;
    element["Am"] = 243.061;
    element["Ar"] = 39.948;
    element["As"] = 74.922;
    element["At"] = 209.987;
    element["Au"] = 196.967;
    element["B"] = 10.811;
    element["Ba"] = 137.33;
    element["Be"] = 9.012;
    element["Bi"] = 208.98;
    element["Bk"] = 247.07;
    element["Br"] = 79.904;
    element["C"] = 12.011;
    element["Ca"] = 40.078;
    element["Cd"] = 112.41;
    element["Ce"] = 140.12;
    element["Cf"] = 251.08;
    element["Cl"] = 35.453;
    element["Cm"] = 247.07;
    element["Co"] = 58.933;
    element["Cr"] = 51.996;
    element["Cs"] = 132.905;
    element["Cu"] = 63.546;
    element["Dy"] = 162.5;
    element["Er"] = 167.26;
    element["Es"] = 252.083;
    element["Eu"] = 151.96;
    element["F"] = 18.998;
    element["Fe"] = 55.847;
    element["Fm"] = 257.095;
    element["Fr"] = 223.02;
    element["Ga"] = 69.723;
    element["Gd"] = 157.25;
    element["Ge"] = 72.59;
    element["H"] = 1.008;
    element["He"] = 4.003;
    element["Hf"] = 178.49;
    element["Hg"] = 200.59;
    element["Ho"] = 164.93;
    element["I"] = 126.905;
    element["In"] = 114.82;
    element["Ir"] = 192.22;
    element["K"] = 39.098;
    element["Kr"] = 83.8;
    element["La"] = 138.906;
    element["Li"] = 6.941;
    element["Lr"] = 260.105;
    element["Lu"] = 174.967;
    element["Md"] = 258.099;
    element["Mg"] = 24.305;
    element["Mn"] = 54.938;
    element["Mo"] = 95.94;
    element["N"] = 14.007;
    element["Na"] = 22.99;
    element["Nb"] = 92.906;
    element["Nd"] = 144.24;
    element["Ne"] = 20.179;
    element["Ni"] = 58.69;
    element["No"] = 259.101;
    element["Np"] = 237.048;
    element["O"] = 15.999;
    element["Os"] = 190.2;
    element["P"] = 30.974;
    element["Pa"] = 231.036;
    element["Pb"] = 207.2;
    element["Pd"] = 106.42;
    element["Pm"] = 144.913;
    element["Po"] = 208.982;
    element["Pr"] = 140.908;
    element["Pt"] = 195.08;
    element["Pu"] = 244.064;
    element["Ra"] = 226.025;
    element["Rb"] = 85.468;
    element["Re"] = 186.207;
    element["Rh"] = 102.906;
    element["Rn"] = 222.018;
    element["Ru"] = 101.07;
    element["S"] = 32.066;
    element["Sb"] = 121.75;
    element["Sc"] = 44.956;
    element["Se"] = 78.96;
    element["Si"] = 28.086;
    element["Sm"] = 150.36;
    element["Sn"] = 118.71;
    element["Sr"] = 87.62;
    element["Ta"] = 180.948;
    element["Tb"] = 158.925;
    element["Tc"] = 97.907;
    element["Te"] = 127.6;
    element["Th"] = 232.038;
    element["Ti"] = 47.88;
    element["Tl"] = 204.383;
    element["Tm"] = 168.934;
    element["U"] = 238.029;
    element["V"] = 50.942;
    element["W"] = 183.85;
    element["Xe"] = 131.29;
    element["Y"] = 88.906;
    element["Yb"] = 173.04;
    element["Zn"] = 65.39;
    element["Zr"] = 91.224;


    return 0;
}