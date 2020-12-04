#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>

using namespace std;

  

    

    //Ham lay ten bien
    vector<string> Laytenbien(int a)
    {
        vector<string> v;
        string letters[] = { "a","b","c","d","e","f","g","h","i","k","l","m","n","o","p","q","r","s","u","v"};
        for (int i = 0; i < a; i++)
            v.push_back(letters[i]);

        return v;
    }

    // Ham chuyen thap phan sang nhi phan
    string decToBin(int n)
    {
        if (n == 0)
            return n + "";

        if (n % 2 == 0)
            return decToBin(n / 2) + "0";
        else
            return decToBin(n / 2) + "1";
    }

    // ham bieu dien nhi phan theo minterm
    string Bieudien(string bin,int a)
    {
        int max = a- bin.length();
        for (int i = 0; i < max; i++)
            bin = "0" + bin;
        return bin;
    }

    // ham kiem tra neu 2 minterm khac nhau 1 bit
    bool Khac1bit(string a, string b)
    {
        int flag = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
                flag++;
        }
        return (flag == 1);
    }

    // ham thay the bit giong nhau = dau gach
    string Thaythe(string a, string b)
    {
        string temp = "";
        for (int i = 0; i < a.length(); i++)
            if (a[i] != b[i])
                temp = temp + "-";
            else
                temp = temp + a[i];

        return temp;
    }

    //ham kiem tra minterm b co la mot phan cua minterm a hay ko
    bool Kiemtra(vector<string> a, string b)
    {
        for (int i = 0; i < a.size(); i++)
            if (a[i].compare(b) == 0)
                return true;
        return false;
    }

    //ham rut gon minterm
    vector<string> reduce(vector<string> minterms)
    {
        std::cout << "Qua trinh rut gon cac minterm :\n";
        for (int i=0; i<minterms.size(); i++)
              std:: cout << minterms[i]<<endl;
             std::  cout <<endl;

        vector<string> reduceminterms;

        int max = minterms.size();
        int* checked = new int[max];
        for (int i = 0; i < max; i++)
        {
            for (int j = i; j < max; j++)
            {
                //neu 2 minterm khac nhau 1 bit thi thay the bang dau phay
                if (Khac1bit(minterms[i], minterms[j]))
                {
                    checked[i] = 1;
                    checked[j] = 1;
                    if (!Kiemtra(reduceminterms, Thaythe(minterms[i], minterms[j])))
                        reduceminterms.push_back(Thaythe(minterms[i], minterms[j]));
                }
            }
        }

        for (int i = 0; i < max; i++)
        {
 
            if (checked[i] != 1 && !Kiemtra(reduceminterms, minterms[i]))
                reduceminterms.push_back(minterms[i]);
        }

        delete[] checked;

        return reduceminterms;
    }


    // bieu dien minterm theo ten bien
    string Laygiatri(string a,string d,vector<string> y)
    {
        string temp = "";
        vector<string> vars = y;
        if (a == d)
            return "1";

        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != '-')
            {
                if (a[i] == '0')
                    temp = temp + vars[i] + "\'";
                else
                    temp = temp + vars[i];
            }
        }
        return temp;
    }

    //kiem tra 2 vector bang nhau
    bool VectorsEqual(vector<string> a, vector<string> b)
    {
        if (a.size() != b.size())
            return false;

       std:: sort(a.begin(), a.end());
      std::  sort(b.begin(), b.end());
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

    // ham chuyen tu maxterm sang minterm
    int* MAXTOMIN(vector<int> x, int n, int count)
    {
        int max = pow(2, n) - (count - 1);
        int l = 0;
        int* y = new int[max];
        for (int i = 0; i < pow(2, n); i++)
        {
            for (int j = 0; j < count + 1; j++)
            {
                if (i != x[j])
                {
                    y[l] = i;
                    l++;
                }
            }
        }
        return y;
    }



// ham chinh
    int main() {
        vector<string> X;
        vector<string> minterms;
        int a,q=1,len=0;
        string d;
     /*  std:: cout << "ham la minterm hay maxterm?(minterm=1/maxterm=0)\n";
        cin >> q;*/
            std::cout << endl << "Nhap so bien cua ham logic:" << endl;
            cin >> a;

            d.append(a, '-');

            string temp = "";
           std:: cout << "Nhap vao ca gia tri cua minterm : " << endl;
            cin >> temp;


            for (int i = 0; i < temp.length(); i++) {

                if (temp[i] == ',') {
                    len = len + 1;
                }

            }
            
           /* if (q == 0) {
                int* Y = new int[(int)pow(2, a)];
                istringstream f(temp);
                string s;


                while (getline(f, s, ',')) {
                    int t = atoi(s.data());
                   X.push_back(t);
                }

                for (int i = 0; i < (int)pow(2, a); i++) {
                    for (int j = 0; j < count + 1; j++) {

                        if (i == X[j]) {
                            Y[X[j]] = 0;
                        }
                        if (i != X[j])
                        {
                            Y[i] = 1;
                        }
                    }
                }





                for (int j = 0; j < sizeof(Y); j++) {
                    if (Y[j] != 0) {
                        string z = decToBin(j);
                        for (int i = 0; i < a - z.length(); i++) {

                            z = "0" + z;
                        }
                        minterm.push_back(z);
                    }
                }
            }*/


            // lay gia tri cua minterm
            if (q == 1) {
                istringstream f(temp);
                string s;


                while (getline(f, s, ','))
                {

                    int t = atoi(s.data());
                    minterms.push_back(Bieudien(decToBin(t), a));
                };
            }

            sort(minterms.begin(), minterms.end());

            do
            {
                minterms = reduce(minterms);
                sort(minterms.begin(), minterms.end());
            } while (!VectorsEqual(minterms, reduce(minterms)));


            int i;
          std::  cout << "Ham logic sau khi da rut gon la" << endl;
            for (i = 0; i < minterms.size() - 1; i++)
            {
                vector<string> y = Laytenbien(a);
              std::  cout << Laygiatri(minterms[i], d, y) << "+";
            }
            vector<string> y = Laytenbien(a);
          std::  cout << Laygiatri(minterms[i], d, y) << endl;


        }
