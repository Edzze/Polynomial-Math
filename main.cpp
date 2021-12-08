#include <iostream>
#include <cmath>

using namespace std;

int addition();
int subtraction();
int multiplication();
int root();

int *multiply(int Eq1[], int Eq2[], int m, int n)
{
   int *product = new int[m + n - 1];
   for (int i = 0; i < m + n - 1; i++)
   {
      product[i] = 0;
   }
   for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
         product[i + j] += Eq1[i] * Eq2[j];
      }
   }
   return product;
}
void printP(int polynomial[], int n)
{
   for (int i = n - 1; i >= 0; i--)
   {
      cout << polynomial[i];
      if (i != 0)
      {
         cout << "x^" << i;
         cout << " + ";
      }
   }
   cout << endl;
}


int main()
{
    int choice;
    cout << "Welcome to Polynomial maths!" << endl;
    cout << "Enter 1 for addition" << endl;
    cout << "Enter 2 for subtraction" << endl;
    cout << "Enter 3 for multiplication" << endl;
    cout << "Enter 4 for find the root" << endl;
    cout << "Please enter your choice: " << endl;
    cin >> choice;

    //choose a choice for an action

    if (choice == 1)
    {
        addition();
    }

    else if (choice == 2)
    {
        subtraction();
    }

    else if (choice == 3)
    {
        multiplication();
    }

    else if (choice == 4)
    {
        root();
    }
    else
    {
        cout << "Please enter a valid choice!" << endl;
        main();
    }

    return 0;
}

int addition()
{
    cout << "You chose Addition (1)!" << endl;
    float a1, b1, c1, a2, b2, c2, a3, b3, c3;

    cout << "ax^2 + bx + c" << endl;
    cout << "Enter the coefficient for the first a: ";
    cin >> a1;
    cout << "Enter the coefficient for the first b: ";
    cin >> b1;
    cout << "Enter the coefficient for the first c: ";
    cin >> c1;
    cout << a1 << "x^2 + " << b1 << "x + " << c1 << endl;

    //cout << "(" << a1 << ")" << "x^2 + " << "(" << b1 << "x) + " << c1;
    //testing formated printing but didn't work

    cout << "ax^2 + bx + c" << endl;
    cout << "Enter the coefficient for the first a: ";
    cin >> a2;
    cout << "Enter the coefficient for the first b: ";
    cin >> b2;
    cout << "Enter the coefficient for the first c: ";
    cin >> c2;
    cout << a2 << "x^2 + " << b2 << "x + " << c2 << endl;

    //simple math, get the a, b, c values and add them together

    a3 = a1 + a2;
    b3 = b1 + b2;
    c3 = c1 + c2;

    cout << "The sum is:" << endl;
    cout << a3 << "x^2 + " << b3 << "x + " << c3 << endl;

    return 0;
}

int subtraction()
{
    cout << "You chose Subtraction (2)!" << endl;
    float a1, b1, c1, a2, b2, c2, a3, b3, c3;

    cout << "ax^2 + bx + c" << endl;
    cout << "Enter the coefficient for the first a: ";
    cin >> a1;
    cout << "Enter the coefficient for the first b: ";
    cin >> b1;
    cout << "Enter the coefficient for the first c: ";
    cin >> c1;
    cout << a1 << "x^2 + " << b1 << "x + " << c1 << endl;

    cout << "ax^2 + bx + c" << endl;
    cout << "Enter the coefficient for the first a: ";
    cin >> a2;
    cout << "Enter the coefficient for the first b: ";
    cin >> b2;
    cout << "Enter the coefficient for the first c: ";
    cin >> c2;
    cout << a2 << "x^2 + " << b2 << "x + " << c2 << endl;

    //same with addition but subtracting instead

    a3 = a1 - a2;
    b3 = b1 - b2;
    c3 = c1 - c2;

    cout << "The difference is:" << endl;
    cout << a3 << "x^2 + " << b3 << "x + " << c3 << endl;

    return 0;
}

int multiplication()
{
    cout << "You chose Multiplication (3)!" << endl;
    float a1, b1, c1, a2, b2, c2;
    int m = 3;
    int n = 3;

    cout << "ax^2 + bx + c" << endl;
    cout << "Enter the coefficient for the first a: ";
    cin >> c1;
    cout << "Enter the coefficient for the first b: ";
    cin >> b1;
    cout << "Enter the coefficient for the first c: ";
    cin >> a1;
    cout << c1 << "x^2 + " << b1 << "x + " << a1 << endl;

    //storing the numbers inputted into an array
    //a1 has a degree of 2, b1 has a degree of 1 and c1 has a degree of 0

    int Eq1[] = {a1, b1, c1};

    cout << "ax^2 + bx + c" << endl;
    cout << "Enter the coefficient for the first a: ";
    cin >> c2;
    cout << "Enter the coefficient for the first b: ";
    cin >> b2;
    cout << "Enter the coefficient for the first c: ";
    cin >> a2;
    cout << c2 << "x^2 + " << b2 << "x + " << a2 << endl;

    //same as above, but replacing a1 with a2, b1 with b2 and c1 with c2

    int Eq2[] = {a2, b2, c2};

    //too lazy and tired to figure out why it is multiplying from the right
    //band-aid solution and I really don't like it

    int *product = multiply(Eq1, Eq2, m, n);
    printP(product, m + n - 1);

    return 0;
}

int root()
{
    cout << "You chose Find the Root (4)!" << endl;
    float a, b, c, x1, x2, discriminant, real, imaginary;

    cout << "ax^2 + bx + c" << endl;
    cout << "Enter the coefficient for a: ";
    cin >> a;
    cout << "Enter the coefficient for b: ";
    cin >> b;
    cout << "Enter the coefficient for c: ";
    cin >> c;

    //checking the type of root

    discriminant = b * b - 4 * a * c;

    //if greater than zero, use quadratic equation

    if (discriminant > 0)
    {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    //if equal to zero, use -b / 2a
    //I can't remember the name of the formula

    else if (discriminant == 0)
    {
        x1 = -b /(2 * a);
        cout << "x1 = x2 = " << x1 << endl;
    }

    //if less than zero, use quadratic equation but with i (imaginary number)

    else
        {
        real = -b / (2 * a);
        imaginary = sqrt(-discriminant) / (2*a);
        cout << "Roots are complex and different"  << endl;
        cout << "x1 = " << real << "+" << imaginary << "i" << endl;
        cout << "x2 = " << real << "-" << imaginary << "i" << endl;
    }

    return 0;
}
