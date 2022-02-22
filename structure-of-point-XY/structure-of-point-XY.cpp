// 1. Створіть структуру, що описує точку у двовимірній системі координат (x, y). За допомогою цієї структури задайте дві точки.Напишіть функцію, яка обчислює відстань між цими двома точками.
//Єдиною умовою є зчитування даних з файлу і запис даних в файл
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
struct Point//структура, що описує точку у двовимірній системі координат (x, y)
{  
    double x = 0;//координати точки
    double y = 0;//координати точки
};
double Distance(Point &first, Point &second) {//функція знаходження відстані між  двома точками.
    double d = abs(sqrt(pow((second.x - first.x), 2) + pow((second.y - first.y ), 2)));//знаходимо значення відстань між  двома точками.
    return d;//повертаємо значення відстань між  двома точками.
}
int main()
{  
    Point first;
    Point second;
    ifstream fileIn;//використовуємо для зчитування даних з файлу
    string Path = "C:/Users/Яна/Desktop/point.txt";//шлях до файлу - можна вибрати або однакові файли або різні
    fileIn.open(Path);//відкриваємо файл за вказаним шляхом
    cout << "Enter coordinates of the first point" << endl;
    fileIn >> first.x;//зчитування даних з файлу
    fileIn >> first.y;//зчитування даних з файлу
    cout << first.x << "\t" << first.y<<endl;
    cout << "Enter coordinates of the second point" << endl;
    fileIn >> second.x;//зчитування даних з файлу
    fileIn >> second.y;//зчитування даних з файлу
    cout << second.x << "\t" << second.y<<endl;
    fileIn.close();//закриваємо файл	
    ofstream file;
    string path = "C:/Users/Яна/Desktop/circle.txt ";//шлях до файлу
    file.open(path);//відкриваємо файл за вказаним шляхом
    if (!file.is_open())cout << "Didn't open" << endl;//якщо файл не видкривається- виводимо повідомлення про це
    else {
        cout << "File is open" << endl;//якщо файл  видкривається- виводимо повідомлення про це
        file << "Distance of two points is= "<< Distance(first, second) <<endl;//вводимо значення функції у файл
    }
    file.close();//закриваємо файл	
}