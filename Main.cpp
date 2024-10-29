#include "SickDog.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Detection de fuite de mémoire

    locale::global(locale("")); // UTF8


    //Animal _animal;
    Dog* _dog = new Dog("TrouDuc", 100.0f, 20.0);
    SickDog* _sickDog = new SickDog("Deldu", 3, 100.0f, 20.0, "BOB");

    //_animal.Sleep();
    _sickDog->Sleep(); // Masquage !

    _dog->Bark();
    _sickDog->Bark(); // Demasquagee !

    //_animal.Introduce();
    _dog->Introduce();
    _sickDog->Introduce();


    delete _dog;
    delete _sickDog;

    return EXIT_SUCCESS;
}
