#include <iostream>
#include "list.h"
#include "Figure.h"
#include "rectangle.h"
#include "Rhombus.h"
#include "Trapeze.h"
#include <memory>
#include "iterator.h"

using std::cin;
using std::cout;
using std::endl;

void menu();

int main() {
    int key;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    std::shared_ptr<Figure> ptr;
    // TList<Figure> list;
    TList <Figure> *list = new TList <Figure>;
    do {
        menu();
        cin >> key;
        switch(key) {
            case 1:
                cout << "Enter sides of rectangle, pls" << endl;
                cin >> a >> b;
                ptr = std::shared_ptr<Figure>(new TRectangle(a, b));
                list->Push(ptr);
                break;
            case 2:
                cout << "Enter sides of trapeze, pls" << endl;
                cin >> a >> b >> c >> d;
                ptr = std::shared_ptr<Figure>(new TTrapeze(a, b, c ,d));
                list->Push(ptr);
                break;
            case 3:
                cout << "Enter diagonals of rhombus, pls" << endl;
                cin >> a >> b;
                ptr = std::shared_ptr<Figure>(new TRhombus(a, b));
                list->Push(ptr);
                break;
            case 4:
                ptr = list->Pop();
                break;
            case 5:
                for (const auto& i : *list) {
                    i->Print();
                }
                break;
            case 0:
                break;
            default:
                cout << "Unknown command" << endl;
                break;
        }
    } while(key);
    return 0;
}

void menu() {
    cout << "Choose an option:" << endl;
    cout << "1)Add rectangle." << endl;
    cout << "2)Add trapeze." << endl;
    cout << "3)Add rhombus." << endl;
    cout << "4)Get figure." << endl;
    cout << "5)Print list." << endl;
    cout << "0)Exit" << endl;
    cout << "------------------------" << endl;
}