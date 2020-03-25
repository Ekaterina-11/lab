#include <string>

using namespace std;
class Product
{
private:// напрямую их изменить нельзя
    string name;
    short size;
    string color;
public:
    Product();//конструктор по умолчанию
    Product(string name, short size, string color);//конструктор с параметрами
    Product(const Product &product);//конструктор копирования
    void printInformationAboutProduct();
    void setName(string name_in);//установить имя
    void setSize(short size_in);
    void setColor(string color_in);
    string getName();//получить
    short getSize();
    string getColor();
    Product& operator ++ (); //префиксный инкремент
    Product& operator -- (); // префиксный декремент
    Product operator ++ (int); //постфиксный инкремент
    Product operator -- (int); // постфиксный декремент
    int operator == (Product product11);
    int operator != (Product product11);
    int operator > (Product product11);
    int operator < (Product product11);
    int operator >= (Product product11);
    int operator <= (Product product11);
    Product& operator = (Product product);

    friend ostream& operator << (ostream &out, const Product &product_in);
    friend istream& operator >> (istream &in, Product &product_in);
};
