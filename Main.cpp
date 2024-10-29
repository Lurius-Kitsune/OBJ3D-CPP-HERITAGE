#include "Main.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Detection de fuite de mémoire

    locale::global(locale("fr-FR")); // UTF8
    ShapeExcercice();
    return EXIT_SUCCESS;
}

void HeritageDecouvert()
{
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
}

void ShapeExcercice()
{
    const Color& _color = Color(465, 25, 32, 255);
    DISPLAY(_color.ToString(), true);

    Square _square = Square(3.00f, PURPLE);
    Rectangle _rectangle = Rectangle(5.00f, 12.00f, YELLOW);
    Circle _circle = Circle(6.00f, RED);

    struct ShapeData
    {
        string name;
        Shape* shape; // pointeur pour les mettre a la "meme taille"
    };

    ShapeData _shapesData[] =
    {
        {"Carrée" , new Square(3.00f, PURPLE)},
        {"Rectangle", new Rectangle(5.00f, 12.00f, YELLOW)},
        {"Cercle", new Circle(6.00f, RED)}
    };

    const u_int _shapesDataCount = sizeof(_shapesData) / sizeof(ShapeData);

    for (u_int _i = 0; _i < _shapesDataCount; _i++)
    {
        const ShapeData& _shapeData = _shapesData[_i];
        _shapeData.shape->Introduce(_shapeData.name);

        Square* _square = dynamic_cast<Square*>(_shapeData.shape);
        // Dynamic cast -> convertit classe poly en classe fille
        if (_square)
        {

        }

        delete _shapeData.shape;
    }

    //delete _color;
}
