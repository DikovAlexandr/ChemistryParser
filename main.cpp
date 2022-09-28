#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

void massCase(vector<double> massesOfSubstance, vector<string> intoSubstance, int num) {
    vector<double> moleFractions(num);
    vector<double> massElements(num);
    vector<double> moleElements(num);
    vector<double> massFractions(num);
    vector<double> n(num);
    double massOfAll = 0;
    cout << "Enter the mole fractions of substances in the same order" << endl;
    for (int i = 0; i < num; i++) cin >> moleFractions[i];
    n[0] = 1; // We consider the amount of one of the substances to be equal to one
    n[1] = 1 / moleFractions[1] - n[0];
    for (int i = 0; i < num; i++) {
        massElements[i] = n[i] * massesOfSubstance[i];
        massOfAll += massElements[i];
    }
    for (int i = 0; i < num; i++) {
        massFractions[i] = massElements[i] / massOfAll;
        cout << intoSubstance[i] << " has mass fraction " << massFractions[i] << endl;
    }
}

void moleCase(vector<double> massesOfSubstance, vector<string> intoSubstance, int num) {
    vector<double> moleFractions(num);
    vector<double> massElements(num);
    vector<double> moleElements(num);
    vector<double> massFractions(num);
    vector<double> n(num);
    double moleOfAll = 0;
    cout << "Enter the mass fractions of substances in the same order" << endl;
    for (int i = 0; i < num; i++) cin >> massFractions[i];
    massElements[0] = 100 * massFractions[0];
    massElements[1] = 100 - massFractions[1];
    for (int i = 0; i < num; i++) {
        moleElements[i] = massElements[i] / massesOfSubstance[i];
        moleOfAll += moleElements[i];
    }
    for (int i = 0; i < num; i++) {
        massFractions[i] = massElements[i] / moleOfAll;
        cout << intoSubstance[i] << " has mole fraction " << massFractions[i] << endl;
    }
}


// Разбиение формулы поэлементно с учетом коэффициентов
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
        if (formula[0] == '(')
            brackets = true;
        if (formula[0] == ')') {
            brackets = false;
            if (isdigit(formula[1])) {
                formula.erase(0, 1);
                for (; jndex; jndex--)
                    elements[index - jndex + 1].second *= int(formula[0]) - 48;
            }
        }
        formula.erase(0, 1);
    }
    return elements;
}

// Вывод таблицы входящих в соединение элементов
void printElements(const vector<pair<string, int>> &elements) {
    for (auto &element: elements)
        cout << element.first << "  " << element.second << endl;
}

// Нахождение массы соединения
double getMass(const vector<pair<string, int>> &elements, const map<string, double> &element_m) {
    double M = 0;
    for (const auto &i: elements)
        for (const auto &j: element_m)
            if (i.first == j.first)
                M += j.second * i.second;
    return M;
}

int main() {
    vector<string> intoSubstance;
    vector<double> massesOfSubstance;
    string plug;
    int num;
    map<string, double> elementAtomicMass;
    {
        elementAtomicMass["Ac"] = 227.028;
        elementAtomicMass["Ag"] = 107.868;
        elementAtomicMass["Al"] = 26.982;
        elementAtomicMass["Am"] = 243.061;
        elementAtomicMass["Ar"] = 39.948;
        elementAtomicMass["As"] = 74.922;
        elementAtomicMass["At"] = 209.987;
        elementAtomicMass["Au"] = 196.967;
        elementAtomicMass["B"] = 10.811;
        elementAtomicMass["Ba"] = 137.33;
        elementAtomicMass["Be"] = 9.012;
        elementAtomicMass["Bi"] = 208.98;
        elementAtomicMass["Bk"] = 247.07;
        elementAtomicMass["Br"] = 79.904;
        elementAtomicMass["C"] = 12.011;
        elementAtomicMass["Ca"] = 40.078;
        elementAtomicMass["Cd"] = 112.41;
        elementAtomicMass["Ce"] = 140.12;
        elementAtomicMass["Cf"] = 251.08;
        elementAtomicMass["Cl"] = 35.453;
        elementAtomicMass["Cm"] = 247.07;
        elementAtomicMass["Co"] = 58.933;
        elementAtomicMass["Cr"] = 51.996;
        elementAtomicMass["Cs"] = 132.905;
        elementAtomicMass["Cu"] = 63.546;
        elementAtomicMass["Dy"] = 162.5;
        elementAtomicMass["Er"] = 167.26;
        elementAtomicMass["Es"] = 252.083;
        elementAtomicMass["Eu"] = 151.96;
        elementAtomicMass["F"] = 18.998;
        elementAtomicMass["Fe"] = 55.847;
        elementAtomicMass["Fm"] = 257.095;
        elementAtomicMass["Fr"] = 223.02;
        elementAtomicMass["Ga"] = 69.723;
        elementAtomicMass["Gd"] = 157.25;
        elementAtomicMass["Ge"] = 72.59;
        elementAtomicMass["H"] = 1.008;
        elementAtomicMass["He"] = 4.003;
        elementAtomicMass["Hf"] = 178.49;
        elementAtomicMass["Hg"] = 200.59;
        elementAtomicMass["Ho"] = 164.93;
        elementAtomicMass["I"] = 126.905;
        elementAtomicMass["In"] = 114.82;
        elementAtomicMass["Ir"] = 192.22;
        elementAtomicMass["K"] = 39.098;
        elementAtomicMass["Kr"] = 83.8;
        elementAtomicMass["La"] = 138.906;
        elementAtomicMass["Li"] = 6.941;
        elementAtomicMass["Lr"] = 260.105;
        elementAtomicMass["Lu"] = 174.967;
        elementAtomicMass["Md"] = 258.099;
        elementAtomicMass["Mg"] = 24.305;
        elementAtomicMass["Mn"] = 54.938;
        elementAtomicMass["Mo"] = 95.94;
        elementAtomicMass["N"] = 14.007;
        elementAtomicMass["Na"] = 22.99;
        elementAtomicMass["Nb"] = 92.906;
        elementAtomicMass["Nd"] = 144.24;
        elementAtomicMass["Ne"] = 20.179;
        elementAtomicMass["Ni"] = 58.69;
        elementAtomicMass["No"] = 259.101;
        elementAtomicMass["Np"] = 237.048;
        elementAtomicMass["O"] = 15.999;
        elementAtomicMass["Os"] = 190.2;
        elementAtomicMass["P"] = 30.974;
        elementAtomicMass["Pa"] = 231.036;
        elementAtomicMass["Pb"] = 207.2;
        elementAtomicMass["Pd"] = 106.42;
        elementAtomicMass["Pm"] = 144.913;
        elementAtomicMass["Po"] = 208.982;
        elementAtomicMass["Pr"] = 140.908;
        elementAtomicMass["Pt"] = 195.08;
        elementAtomicMass["Pu"] = 244.064;
        elementAtomicMass["Ra"] = 226.025;
        elementAtomicMass["Rb"] = 85.468;
        elementAtomicMass["Re"] = 186.207;
        elementAtomicMass["Rh"] = 102.906;
        elementAtomicMass["Rn"] = 222.018;
        elementAtomicMass["Ru"] = 101.07;
        elementAtomicMass["S"] = 32.066;
        elementAtomicMass["Sb"] = 121.75;
        elementAtomicMass["Sc"] = 44.956;
        elementAtomicMass["Se"] = 78.96;
        elementAtomicMass["Si"] = 28.086;
        elementAtomicMass["Sm"] = 150.36;
        elementAtomicMass["Sn"] = 118.71;
        elementAtomicMass["Sr"] = 87.62;
        elementAtomicMass["Ta"] = 180.948;
        elementAtomicMass["Tb"] = 158.925;
        elementAtomicMass["Tc"] = 97.907;
        elementAtomicMass["Te"] = 127.6;
        elementAtomicMass["Th"] = 232.038;
        elementAtomicMass["Ti"] = 47.88;
        elementAtomicMass["Tl"] = 204.383;
        elementAtomicMass["Tm"] = 168.934;
        elementAtomicMass["U"] = 238.029;
        elementAtomicMass["V"] = 50.942;
        elementAtomicMass["W"] = 183.85;
        elementAtomicMass["Xe"] = 131.29;
        elementAtomicMass["Y"] = 88.906;
        elementAtomicMass["Yb"] = 173.04;
        elementAtomicMass["Zn"] = 65.39;
        elementAtomicMass["Zr"] = 91.224;
    }
    cout << "How many elements are in your mixture?" << endl;
    //cin >> num;
    num = 2;
    cout << "Enter you chemical substances in different lines:" << endl;
    vector<pair<string, int>> elements;
    for (int i = 0; i < num; i++) {
        cin >> plug;
        intoSubstance.push_back(plug);
        elements = splitter(intoSubstance[i]);
        //printElements(elements);
        massesOfSubstance.push_back(getMass(elements, elementAtomicMass));
    }
    cout << "What value do you need to find?" << endl
         << "Are you entering mole fractions and want to find mass fractions? - 1" << endl
         << "Are you entering mass fractions and want to find mole fractions? - 2" << endl;
    int marker;
    cin >> marker;
    if (marker == 1) massCase(massesOfSubstance, intoSubstance, num);
    if (marker == 2) moleCase(massesOfSubstance, intoSubstance, num);
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////
// Считываем количество веществ, считываем их формулы, находим молекулярные массы          //
// Вводятся мольные доли - находятся массовые ИЛИ вводятся массовые - находятся молярные   //
// Массовая доля: w(элемента) = m(элемента) / m(сумма масс всех веществ) * 100             //
// Мольная доля: x(элеманта) = n(элемента) / n(сумма количества вещества всех компонентов) //
// Количество вещества: n(элемента) = m(элемента) / M(вещества)                            //
/////////////////////////////////////////////////////////////////////////////////////////////