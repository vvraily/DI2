#ifndef HEADER_H
#define HEADER_H


#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

class Perm
{
protected:
        unsigned int *array;
        int size;
        ofstream file;
public:
        Perm(int s) : size(s)
        {
          array = new unsigned int[size];
          for(int i=0; i<size; i++)
          array[i] = i+1;

          file.open("data.txt");
        }
        ~Perm() { file.close(); delete [] array; }

        unsigned int Factorial(int n);
        bool Permutations();
        void Show();
};

class Comb : public Perm
{
public:
        Comb(int s) : Perm(s) {}
        void Combinations(int &r);
        void Show(int &n);
};


unsigned int Perm::Factorial(int n)
{
    int f = 1;
    for(int i=1; i<=n; i++)
    f *= i;

    return f;
}

bool Perm::Permutations()
{
  int j = size - 2;
  while (j != -1 && array[j] >= array[j + 1]) j--;

  if (j == -1)
    return false;

  int k = size - 1;
  while (array[j] >= array[k]) k--;

  swap(array[j],array[k]);

  sort(array+j+1, array+size);

  return true;
}

void Perm::Show()
{
    static int i = 2;
    if(i == 2)
    {
        cout << "[1]: ";
        copy(array, &array[size], ostream_iterator<int>(cout, " "));
        cout << endl;

        if(file.is_open())
        {
            file << "[1]: ";
            copy(array, &array[size], ostream_iterator<int>(file, " "));
            file << endl;
        }
        else cout << "File hasn't opened!" << endl;
    }

    cout << "[" << i << "]: ";
    copy(array, &array[size], ostream_iterator<int>(cout, " "));
    cout << endl;

    if(file.is_open())
    {
        file << "[" << i << "]: ";
        copy(array, &array[size], ostream_iterator<int>(file, " "));
        file << endl;
    }
    else cout << "File hasn't opened!" << endl;

    ++i;
}

void Comb::Combinations(int &r)
{
    unsigned int i = r - 1;

    while (array[i] >= size - r + 1 + i) --i;

    array[i]++;

    for (int j = i + 1; j <= r; j++)
    array[j] = array[i] + j - i;
}

void Comb::Show(int &n)
{
    static int i = 1;

    cout << "[" << i << "]: ";
    copy(array, &array[n], ostream_iterator<int>(cout, " "));
    cout << endl;

    i++;
}

#endif // HEADER_H
