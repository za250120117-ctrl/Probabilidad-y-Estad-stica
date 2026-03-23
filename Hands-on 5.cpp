#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    vector<double> datos = {
        12.5, 15.2, 14.8, 13.0, 16.5, 18.2, 17.1, 19.0,
        20.5, 21.3, 22.7, 23.1, 24.6, 25.0, 26.4, 27.8,
        28.9, 29.5, 30.2, 31.7
    };

    int n = datos.size();
    sort(datos.begin(), datos.end());

    int k = 1 + 3.322 * log10(n);

    double min = datos.front();
    double max = datos.back();
    double rango = max - min;
    double amplitud = ceil(rango / k);

    vector<int> F(k, 0);
    vector<double> li(k), ls(k), XC(k);

    for (int i = 0; i < k; i++) {
        li[i] = min + i * amplitud;
        ls[i] = li[i] + amplitud;
        XC[i] = (li[i] + ls[i]) / 2.0;
    }

    for (int i = 0; i < k; i++) {
        for (double d : datos) {
            if (i == k - 1) {
                if (d >= li[i] && d <= ls[i]) F[i]++;
            } else {
                if (d >= li[i] && d < ls[i]) F[i]++;
            }
        }
    }

    vector<int> Fa(k);
    vector<double> Fr(k), Fra(k);

    Fa[0] = F[0];
    Fr[0] = (double)F[0] / n;
    Fra[0] = Fr[0];

    for (int i = 1; i < k; i++) {
        Fa[i] = Fa[i - 1] + F[i];
        Fr[i] = (double)F[i] / n;
        Fra[i] = Fra[i - 1] + Fr[i];
    }

    // =======================
    // MEDIA AGRUPADA
    // =======================
    double suma = 0;
    for (int i = 0; i < k; i++) {
        suma += F[i] * XC[i];
    }
    double media = suma / n;

    // =======================
    // MEDIANA AGRUPADA
    // =======================
    double mediana = 0;
    double mitad = n / 2.0;

    for (int i = 0; i < k; i++) {
        if (Fa[i] >= mitad) {
            double Lm = li[i];
            double Fm = F[i];
            double Fa_ant = (i == 0) ? 0 : Fa[i - 1];

            mediana = Lm + ((mitad - Fa_ant) / Fm) * amplitud;
            break;
        }
    }

    // =======================
    // MODA AGRUPADA
    // =======================
    int idxModa = max_element(F.begin(), F.end()) - F.begin();

    double moda = 0;
    double Lmo = li[idxModa];
    double fm = F[idxModa];
    double f1 = (idxModa == 0) ? 0 : F[idxModa - 1];
    double f2 = (idxModa == k - 1) ? 0 : F[idxModa + 1];

    double d1 = fm - f1;
    double d2 = fm - f2;

    if ((d1 + d2) != 0) {
        moda = Lmo + (d1 / (d1 + d2)) * amplitud;
    }

    // =======================
    // IMPRESIÓN
    // =======================
    cout << fixed << setprecision(4);

    cout << "Tabla de Frecuencias\n";
    cout << "--------------------------------------------------------------------------\n";
    cout << "Clase\tLi\tLs\tXC\tF\tFa\tFr\tFra\n";
    cout << "--------------------------------------------------------------------------\n";

    for (int i = 0; i < k; i++) {
        cout << i + 1 << "\t"
             << li[i] << "\t"
             << ls[i] << "\t"
             << XC[i] << "\t"
             << F[i] << "\t"
             << Fa[i] << "\t"
             << Fr[i] << "\t"
             << Fra[i] << endl;
    }

    cout << "--------------------------------------------------------------------------\n";
    cout << "Medidas de Tendencia Central (Datos Agrupados)\n";
    cout << "Media: " << media << endl;
    cout << "Mediana: " << mediana << endl;
    cout << "Moda: " << moda << endl;

    return 0;
}