#include <string>

using namespace std;
class Product
{
private:
    string name;
    short size;
    string color;
public:
    Product();
    Product(string name, short size, string color);
    Product(const Product &product);
    void printInformationAboutProduct() const ;
    void setName(string name_in);
    void setSize(short size_in);
    void setColor(string color_in);
    string getName();
    short getSize();
    string getColor();
    Product& operator ++ (); //префиксный инкремент
    Product& operator -- (); // префиксный декремент
    Product operator ++ (int); //постфиксный инкремент
    Product operator -- (int); // постфиксный декремент
    int operator == (const Product product11);//создание оператора равенства
    int operator != (const Product product11);//создание оператора неравенства
    int operator > (const Product product11);//создание оператора больше
    int operator < (const Product product11);//создание оператора меньше
    int operator >= (const Product product11);//создание оператора больше или равно
    int operator <= (const Product product11);//создание оператора меньше или равно
    Product& operator = (const Product product);//создание оператора присваивания

    friend ostream& operator << (ostream &out, const Product &product_in);//создание оператора вывода
    friend istream& operator >> (istream &in, Product &product_in);//создание оператора ввода
};
