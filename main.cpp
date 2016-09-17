#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    int choose;

    while(choose)
    {
        system("cls");

        int size;
        cout << "Permutations - 1; Combinations - 2;" << endl;
        cin >> choose;

        switch (choose)
        {
            case 1: { cout << "Size of array: ";
                      cin >> size;

                      Perm ob(size);

                      cout << endl;
                      cout << "Factorial: " << ob.Factorial(size) << endl;

                      system("pause");
                      while(ob.Permutations()) ob.Show();
                      break;
                     }
            case 2: { cout << "Size of array (n): ";
                      cin >> size;

                      int r;
                      cout << "r: ";
                      cin >> r;

                      Comb obj(size);

                      cout << endl;
                      obj.Show(r);

                      for (unsigned int i = 1; i < obj.Factorial(size)/(obj.Factorial(r)*obj.Factorial(size-r)); i++)
                      {
                          obj.Combinations(r);
                          obj.Show(r);
                      }
                      break;
                     }
        }

        cout << endl;
        cout << "Continue? (1/0)" << endl;
        cin >> choose;
    }

    return 0;
}
