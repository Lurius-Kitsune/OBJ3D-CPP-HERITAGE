#include "SickDog.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Detection de fuite de mémoire

    locale::global(locale("")); // UTF8


    ////Animal _animal;
    //Dog* _dog = new Dog("TrouDuc", 100.0f, 20.0);
    //SickDog* _sickDog = new SickDog("Deldu", 3, 100.0f, 20.0, "BOB");

    ////_animal.Sleep();
    //_sickDog->Sleep(); // Masquage !

    //_dog->Bark();
    //_sickDog->Bark(); // Demasquagee !

    ////_animal.Introduce();
    //_dog->Introduce();
    //_sickDog->Introduce();


    //delete _dog;
    //delete _sickDog;

    /*
        Definisser des formes géométrique et calculez leurs air  et leur périmètre
        Affichez chacun d'eux avec une couleur différente
    */
    Square _square = Square(3, PURPLE);
    Rectangle _rectangle = Rectangle(5, 12, YELLOW);
    Circle _circle = Circle(23, RED);

    _square.Introduce();
    _rectangle.Introduce();
    _circle.Introduce();
    

    return EXIT_SUCCESS;
}
