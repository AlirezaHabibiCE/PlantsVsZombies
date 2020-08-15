#include <QApplication>
#include <ctime>
#include <cstdlib>
#include "View.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //seed random number generator
    srand( time(0) );

    //create game
    auto myview = new View ();
    myview->show();
    return a.exec();
}
