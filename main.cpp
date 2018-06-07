#include<iostream>
#include<cmath>

using namespace std;
double f(double);

int main()
{
    double a, b, h, vsota = 0, integral;
    int n;

    cout << "Vnesite meje integracije!\nZacetna meja a = ";
    cin >> a;
    cout << "Koncna meja, b = ";
    cin >> b;
    cout << "Vnesite stevilo pod intervalov, n = ";
    cin >> n;

    double x[n+1],y[n+1];
    h = (b - a) / n;                    // sirina pod intervala

    for (int i = 0; i <= n; i++)  // x0,...xn in y0,...yn
    {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }

    cout << "Nase tocke x: ";
    for (int i = 0; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;

    cout << "Nase tocke y: ";
    for (int i = 0; i <= n; i++)
        cout << y[i] << " ";
    cout << endl;

    for (int i = 1; i < n ; i++)            // h * (y1+...+yn-1)
    {
        vsota = vsota + h * y[i];
    }

    integral = (h / 2.0) * (y[0] + y[n]) + vsota;        // (h/2) * [y0+2(y1+y2+y3+...yn-1)+yn]
    cout << "Doloceni integral znasa: " << integral << endl;

    return 0;
}

double f(double x)        // nasa funkcija
{
    double a = 1 / (1 + x * x);
    return a;
}
