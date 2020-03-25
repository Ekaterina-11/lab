#include <string>

using namespace std;
class Product
{
private:// �������� �� �������� ������
    string name;
    short size;
    string color;
public:
    Product();//����������� �� ���������
    Product(string name, short size, string color);//����������� � �����������
    Product(const Product &product);//����������� �����������
    void printInformationAboutProduct();
    void setName(string name_in);//���������� ���
    void setSize(short size_in);
    void setColor(string color_in);
    string getName();//��������
    short getSize();
    string getColor();
    Product& operator ++ (); //���������� ���������
    Product& operator -- (); // ���������� ���������
    Product operator ++ (int); //����������� ���������
    Product operator -- (int); // ����������� ���������
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
