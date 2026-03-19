using System;

class RegresionLineal
{
    static void Main(string[] args)
    {
        // Dataset Benetton (Advertising vs Sales)
        double[] advertising = { 23, 26, 30, 34, 43, 48, 52, 57, 58 };
        double[] sales = { 651, 762, 856, 1063, 1190, 1298, 1421, 1440, 1518 };

        int n = advertising.Length;

        double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

        // Calcular sumatorias
        for (int i = 0; i < n; i++)
        {
            sumX += advertising[i];
            sumY += sales[i];
            sumXY += advertising[i] * sales[i];
            sumX2 += advertising[i] * advertising[i];
        }

        // Calcular B1 (pendiente)
        double B1 = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);

        // Calcular B0 (intersección)
        double B0 = (sumY - B1 * sumX) / n;

        // Imprimir ecuación
        Console.WriteLine("Ecuación de Regresión:");
        Console.WriteLine($"Sales = {B0:F2} + {B1:F2} * Advertising");

        Console.WriteLine("\nPredicciones:\n");

        // 5 valores nuevos de Advertising
        double[] nuevosValores = { 60, 65, 70, 75, 80 };

        foreach (double x in nuevosValores)
        {
            double y = B0 + B1 * x;
            Console.WriteLine($"Advertising = {x} -> Sales estimado = {y:F2}");
        }

        Console.ReadLine();
    }
}