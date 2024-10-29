#include "SickDog.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Detection de fuite de mémoire

    locale::global(locale("")); // UTF8


    Animal _animal;
    Dog _dog;
    SickDog _sickDog;

    _animal.Sleep();
    _sickDog.Sleep(); // Masquage !

    _dog.Bark(); 
    _sickDog.Bark(); // Demasquagee !

    _animal.Introduce();
    _dog.Introduce();
    _sickDog.Introduce();

    return EXIT_SUCCESS;
}
