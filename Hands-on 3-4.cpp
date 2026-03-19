#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Dataset hardcodeado
    vector<double> datos = {
        12.5, 15.2, 14.8, 13.0, 16.5, 18.2, 17.1, 19.0,
        20.5, 21.3, 22.7, 23.1, 24.6, 25.0, 26.4, 27.8,
        28.9, 29.5, 30.2, 31.7
    };

    int n = datos.size();

    // Ordenar datos
    sort(datos.begin(), datos.end());

    // Calcular número de clases (Regla de Sturges)
    int k = 1 + 3.322 * log10(n);
    
    // Rango
    double min = datos.front();
    double max = datos.back();
    double rango = max - min;

    // Amplitud
    double amplitud = ceil(rango / k);

    // Vectores
    vector<int> fi(k, 0);
    vector<double> li(k), ls(k);

    // Construcción de intervalos
    for (int i = 0; i < k; i++) {
        li[i] = min + i * amplitud;
        ls[i] = li[i] + amplitud;
    }

    // Calcular frecuencias
    for (int i = 0; i < k; i++) {
        for (double d : datos) {
            if (i == k - 1) {
                if (d >= li[i] && d <= ls[i]) fi[i]++;
            } else {
                if (d >= li[i] && d < ls[i]) fi[i]++;
            }
        }
    }

    // Cálculos adicionales
    vector<int> Fi(k);
    vector<double> hi(k), Hi(k);

    Fi[0] = fi[0];
    hi[0] = (double)fi[0] / n;
    Hi[0] = hi[0];

    for (int i = 1; i < k; i++) {
        Fi[i] = Fi[i - 1] + fi[i];
        hi[i] = (double)fi[i] / n;
        Hi[i] = Hi[i - 1] + hi[i];
    }

    // Imprimir tabla
    cout << fixed << setprecision(4);
    cout << "Tabla de Frecuencias\n";
    cout << "-------------------------------------------------------------\n";
    cout << "Clase\tLi\tLs\tfi\tFi\thi\tHi\n";
    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < k; i++) {
        cout << i + 1 << "\t"
             << li[i] << "\t"
             << ls[i] << "\t"
             << fi[i] << "\t"
             << Fi[i] << "\t"
             << hi[i] << "\t"
             << Hi[i] << endl;
    }

    return 0;
}
