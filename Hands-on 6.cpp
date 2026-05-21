#include <iostream>

using namespace std;

int main() {

    // Dataset hardcoded con números reales
    double lluviaNublado = 7.0;
    double lluviaNoNublado = 3.0;
    double noLluviaNublado = 2.0;
    double noLluviaNoNublado = 6.0;

    double total = 18.0;

    // Totales marginales
    double totalLluvia = 10.0;
    double totalNoLluvia = 8.0;

    double totalNublado = 9.0;
    double totalNoNublado = 9.0;

    // =========================
    // PROBABILIDADES MARGINALES
    // =========================

    double P_A = totalNublado / total;
    double P_Ac = totalNoNublado / total;

    double P_B = totalLluvia / total;
    double P_Bc = totalNoLluvia / total;

    // =========================
    // PROBABILIDADES CONJUNTAS
    // =========================

    double P_AyB = lluviaNublado / total;
    double P_AcYB = lluviaNoNublado / total;
    double P_AyBc = noLluviaNublado / total;
    double P_AcYBc = noLluviaNoNublado / total;

    // =========================
    // PROBABILIDADES CONDICIONALES
    // =========================

    double P_A_dado_B = lluviaNublado / totalLluvia;
    double P_B_dado_A = lluviaNublado / totalNublado;

    double P_Ac_dado_B = lluviaNoNublado / totalLluvia;
    double P_B_dado_Ac = lluviaNoNublado / totalNoNublado;

    // =========================
    // RESULTADOS
    // =========================

    cout << "=== PROBABILIDADES MARGINALES ===" << endl;
    cout << "P(A)  = " << P_A << endl;
    cout << "P(A') = " << P_Ac << endl;
    cout << "P(B)  = " << P_B << endl;
    cout << "P(B') = " << P_Bc << endl;

    cout << "\n=== PROBABILIDADES CONJUNTAS ===" << endl;
    cout << "P(A y B)   = " << P_AyB << endl;
    cout << "P(A' y B)  = " << P_AcYB << endl;
    cout << "P(A y B')  = " << P_AyBc << endl;
    cout << "P(A' y B') = " << P_AcYBc << endl;

    cout << "\n=== PROBABILIDADES CONDICIONALES ===" << endl;
    cout << "P(A | B)   = " << P_A_dado_B << endl;
    cout << "P(B | A)   = " << P_B_dado_A << endl;
    cout << "P(A' | B)  = " << P_Ac_dado_B << endl;
    cout << "P(B | A')  = " << P_B_dado_Ac << endl;

    return 0;
}