#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <map>

using namespace std;
// Разбиение формулы поэлементно с учетом коэфиициентов
vector<pair<string, int>> splitter(string s) {
    string formula = s;
    vector<pair<string, int>> elements;
    int index = -1;
    int jndex = 0;
    bool brackets = false;
    while (formula.length() > 0) {
        if (isupper(formula[0])) {
            index++;
            elements.emplace_back("", 1);
            elements[index].first = formula[0];
            if (brackets) jndex++;
        }
        if (islower(formula[0]))
            elements[index].first += formula[0];
        if (isdigit(formula[0]))
            elements[index].second = int(formula[0]) - 48;
        if (formula[0] == '(') brackets = true;
        if (formula[0] == ')') brackets = false;
        if (!brackets && jndex>0 && isdigit(formula[0]))
            while (jndex) {
                elements[index - jndex].second *= int(formula[0]) - 48;
                jndex--;
            }
        formula.erase(0, 1);
    }
    return elements;
}
// Вывод таблицы входящих в соединение элементов
void printElements(const vector<pair<string, int>>& elements) {
    for (auto &element: elements)
        cout << element.first << "  " << element.second << endl;
}
// Нахождение массы соединения
double getMass(const vector<pair<string, int>>& elements, const map<string, double>& element_m) {
    double M=0;
    for (const auto& i: elements) {
        for (const auto& j:element_m) {
            if (i.first==j.first) M+=j.second*i.second;
        }
    }
    return M;
}

int main() {
    string substance;
    cout  << "Enter you chemical substance:\n";
    getline(cin, substance);
    vector<pair<string, int>> elements;
    elements = splitter(substance);
    printElements(elements);
    map<string, double> element_m;
    {
        element_m["Ac"] = 227.028;
        element_m["Ag"] = 107.868;
        element_m["Al"] = 26.982;
        element_m["Am"] = 243.061;
        element_m["Ar"] = 39.948;
        element_m["As"] = 74.922;
        element_m["At"] = 209.987;
        element_m["Au"] = 196.967;
        element_m["B"] = 10.811;
        element_m["Ba"] = 137.33;
        element_m["Be"] = 9.012;
        element_m["Bi"] = 208.98;
        element_m["Bk"] = 247.07;
        element_m["Br"] = 79.904;
        element_m["C"] = 12.011;
        element_m["Ca"] = 40.078;
        element_m["Cd"] = 112.41;
        element_m["Ce"] = 140.12;
        element_m["Cf"] = 251.08;
        element_m["Cl"] = 35.453;
        element_m["Cm"] = 247.07;
        element_m["Co"] = 58.933;
        element_m["Cr"] = 51.996;
        element_m["Cs"] = 132.905;
        element_m["Cu"] = 63.546;
        element_m["Dy"] = 162.5;
        element_m["Er"] = 167.26;
        element_m["Es"] = 252.083;
        element_m["Eu"] = 151.96;
        element_m["F"] = 18.998;
        element_m["Fe"] = 55.847;
        element_m["Fm"] = 257.095;
        element_m["Fr"] = 223.02;
        element_m["Ga"] = 69.723;
        element_m["Gd"] = 157.25;
        element_m["Ge"] = 72.59;
        element_m["H"] = 1.008;
        element_m["He"] = 4.003;
        element_m["Hf"] = 178.49;
        element_m["Hg"] = 200.59;
        element_m["Ho"] = 164.93;
        element_m["I"] = 126.905;
        element_m["In"] = 114.82;
        element_m["Ir"] = 192.22;
        element_m["K"] = 39.098;
        element_m["Kr"] = 83.8;
        element_m["La"] = 138.906;
        element_m["Li"] = 6.941;
        element_m["Lr"] = 260.105;
        element_m["Lu"] = 174.967;
        element_m["Md"] = 258.099;
        element_m["Mg"] = 24.305;
        element_m["Mn"] = 54.938;
        element_m["Mo"] = 95.94;
        element_m["N"] = 14.007;
        element_m["Na"] = 22.99;
        element_m["Nb"] = 92.906;
        element_m["Nd"] = 144.24;
        element_m["Ne"] = 20.179;
        element_m["Ni"] = 58.69;
        element_m["No"] = 259.101;
        element_m["Np"] = 237.048;
        element_m["O"] = 15.999;
        element_m["Os"] = 190.2;
        element_m["P"] = 30.974;
        element_m["Pa"] = 231.036;
        element_m["Pb"] = 207.2;
        element_m["Pd"] = 106.42;
        element_m["Pm"] = 144.913;
        element_m["Po"] = 208.982;
        element_m["Pr"] = 140.908;
        element_m["Pt"] = 195.08;
        element_m["Pu"] = 244.064;
        element_m["Ra"] = 226.025;
        element_m["Rb"] = 85.468;
        element_m["Re"] = 186.207;
        element_m["Rh"] = 102.906;
        element_m["Rn"] = 222.018;
        element_m["Ru"] = 101.07;
        element_m["S"] = 32.066;
        element_m["Sb"] = 121.75;
        element_m["Sc"] = 44.956;
        element_m["Se"] = 78.96;
        element_m["Si"] = 28.086;
        element_m["Sm"] = 150.36;
        element_m["Sn"] = 118.71;
        element_m["Sr"] = 87.62;
        element_m["Ta"] = 180.948;
        element_m["Tb"] = 158.925;
        element_m["Tc"] = 97.907;
        element_m["Te"] = 127.6;
        element_m["Th"] = 232.038;
        element_m["Ti"] = 47.88;
        element_m["Tl"] = 204.383;
        element_m["Tm"] = 168.934;
        element_m["U"] = 238.029;
        element_m["V"] = 50.942;
        element_m["W"] = 183.85;
        element_m["Xe"] = 131.29;
        element_m["Y"] = 88.906;
        element_m["Yb"] = 173.04;
        element_m["Zn"] = 65.39;
        element_m["Zr"] = 91.224;
    }
    cout << getMass(elements, element_m);
    cout << "What value do you need to find?";
    return 0;
}