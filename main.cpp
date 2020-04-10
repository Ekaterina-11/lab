#include <iostream>
#include "Product.h"
#include <string>
#include <stdlib.h>


using namespace std;


void showMenu()
{
    cout << "\t\t\t***Menu***" << endl;
    cout << "\t0)Menu up" << endl;
    cout << "\t1)Show all information about product" << endl;
    cout << "\t2)Set name of product" << endl;
    cout << "\t3)Set size of product" << endl;
    cout << "\t4)Set color of product" << endl;
    cout << "\t5)Get name of product" << endl;
    cout << "\t6)Get size of product" << endl;
    cout << "\t7)Get color of product" << endl;
    cout << "\t8)Copy this product" << endl;
    cout << "\t9)Delete this product" << endl;
    cout << "\t10)Testing operator" << endl;
}

void showAllProducts(short countOfProduct, Product *Products)
{
    for (short i = 0; i < countOfProduct; i++)
    {
        cout << i+1 << ")";
        Products[i].printInformationAboutProduct();
    }
}

int main()
{
    string tmpName, tmpColor;
    short var = 0, tmpsize = 0, countOfProduct = 1, i = 0, y = 0;
    Product *Products = new Product[countOfProduct], *tmpProducts;
    while (1)
    {
        cout << "\nEntry number of product(1-" << countOfProduct << ") or close program(input 0)\n" << endl;
        showAllProducts(countOfProduct, Products);
        cin >> i;
        if (i == 0)
        {
            delete Products;
            return 0;
        }

        while (i != 0)
        {
            showMenu();
            cin >> var;
            switch (var)
            {
                case 0:
                    i = 0;
                    break;
                case 1:
                    cout << Products[i-1] << endl;
                    break;
                case 2:
                    cout << "\nEntry name of product:" << endl;
                    cin >> tmpName;
                    Products[i-1].setName(tmpName);
                    break;
                case 3:
                    cout << "\nEntry size of product:" << endl;
                    cin >> tmpsize;
                    if (tmpsize >= 0)
                    {
                        Products[i-1].setSize(tmpsize);
                    }else{
                        cout << "\nUncorrect size set. Repeat." << endl;
                        }
                    break;
                case 4:
                    cout << "\nEntry color of product:" << endl;
                    cin >> tmpColor;
                    Products[i-1].setColor(tmpColor);
                    break;
                case 5:
                    cout << "\nTaken name of product:\t" << (tmpName = Products[i-1].getName()) << endl;
                    break;
                case 6:
                    cout << "\nTaken size of product:\t" << (tmpsize = Products[i-1].getSize()) << endl;
                    break;
                case 7:
                    cout << "\nTaken color of Product:\t" << (tmpColor = Products[i-1].getColor()) << endl;
                    break;
                case 8:{
                    countOfProduct++;
                    tmpProducts = new Product[countOfProduct];
                    for (y = 0; y < countOfProduct-1; y++)
                    {
                        tmpProducts[y] = Products[y];
                        delete &(Products[y]);
                    }
                    delete Products;
                    Products = tmpProducts;
                    Product newProduct(Products[i-1]);
                    cout << "\n" << countOfProduct;
                    Products[countOfProduct-1] = newProduct;
                    break;}
                case 9:{
                    Products[i-1] = Products[countOfProduct-1];
                    delete & (Products[countOfProduct-1]);
                    countOfProduct --;
                    tmpProducts = new Product[countOfProduct];
                    for (y = 0; y < countOfProduct; y++)
                        {
                            tmpProducts[y] = Products[y];
                            delete & (Products[y]);
                        }
                    delete Products;
                    Products = tmpProducts;
                    i = 0;
                    break;}
                case 10:
                    cout << "\nInput # for comprassion:\t" << endl;
                    int z;
                    cin >> z;
                    if (Products[i-1] == Products[z])
                        {cout << "\nTRUE";}
                    else
                        {cout << "\nFALSE";}
                    break;                }
            }
        }
    }
