/*********************************
 * Автор:    Рычков Михаил       *
 * Название: Циклы с ветвлениями *
 * Вариант:  24                  *
 *********************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double movementSpeed, fluidViscosity, pipeDiameter, thermalDiffusivity, reynoldsNumber, pecletNumber, pipeLength, dimensionlessDiameter, pecletProduct, nusseltNumber;

  cout << "Movement speed (cm/s) = ";
  cin >> movementSpeed;

  cout << "Fluid viscosity (cm^2/s) = ";
  cin >> fluidViscosity;

  cout << "Pipe diameter (cm) = ";
  cin >> pipeDiameter;

  cout << "Thermal diffusivity (cm^2/s) = ";
  cin >> thermalDiffusivity;

  reynoldsNumber = movementSpeed * pipeDiameter / fluidViscosity;
  pecletNumber = movementSpeed * pipeDiameter / thermalDiffusivity;

  for (int lengthIndex = 0; lengthIndex < 5; ++lengthIndex) {
    cout << "Enter pipe length in meters (5, 10, 20, 50, 100): ";
    cin >> pipeLength;

    pipeLength = pipeLength * 100.0;

    dimensionlessDiameter = pipeDiameter / pipeLength;
    pecletProduct = pecletNumber * dimensionlessDiameter;

    if (pecletProduct > 12.0) {
      nusseltNumber = 1.61 * pow(reynoldsNumber * dimensionlessDiameter, 0.33);
    } else {
      nusseltNumber = 3.66;
    }

    cout << "Pe * D = " << pecletProduct << ", "
         << "Nu = " << nusseltNumber << endl;
  }

  return 0;
}