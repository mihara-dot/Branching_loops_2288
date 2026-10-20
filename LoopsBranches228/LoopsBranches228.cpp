/*********************************
 * Автор:    Рычков Михаил       *
 * Название: Циклы с ветвлениями *
 * Вариант:  24                  *
 *********************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double w, viscosity, d, alpha, Re, Pe, l, D, pecletProduct, Nu;
  int lengthCount = 5;

  cout << "Movement speed (cm/s) = ";
  cin >> w;

  cout << "Fluid viscosity (cm^2/s) = ";
  cin >> viscosity;

  cout << "Pipe diameter (cm) = ";
  cin >> d;

  cout << "Thermal diffusivity (cm^2/s) = ";
  cin >> alpha;

  Re = w * d / viscosity;
  Pe = w * d / alpha;

  for (int lengthIndex = 0; lengthIndex < lengthCount; ++lengthIndex) {
    cout << "Enter pipe length in meters (5, 10, 20, 50, 100): ";
    cin >> l;

    l = l * 100.0;

    D = d / l;
    pecletProduct = Pe * D;

    if (pecletProduct > 12.0) {
      Nu = 1.61 * pow(Re * D, 0.33);
    } else {
      Nu = 3.66;
    }

    cout << "Pe * D = " << pecletProduct << ", "
         << "Nu = " << Nu << endl;
  }

  return 0;
}