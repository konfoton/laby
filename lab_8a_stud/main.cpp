#include <iostream>

#include "Character.h"
#include "Archer.h"
#include "Wizard.h"

int main() {

    std::cout << "\n******************* ETAP 1 *******************\n\n";

    Character aragorn{"Aragorn", 9};
    Character boromir{"Boromir", 10};
    Archer legolas{"Legolas", 6, 2};

    std::cout << aragorn << std::endl;
    std::cout << boromir << std::endl;
    std::cout << legolas << std::endl << std::endl;

    aragorn.Attack(boromir);
    legolas.Attack(boromir);
    legolas.Attack(boromir);

    boromir.Attack(aragorn);

    std::cout << aragorn << std::endl;
    std::cout << boromir << std::endl;
    std::cout << legolas << std::endl << std::endl;

    boromir.Rest(12);
    boromir.Attack(aragorn);
    boromir.Attack(legolas);

    std::cout << aragorn << std::endl;
    std::cout << boromir << std::endl;
    std::cout << legolas << std::endl << std::endl;

    std::cout << "\n******************* ETAP 2 *******************\n\n";

    Wizard gandalf{"Gandalf", 8, 2};
    Wizard saruman{"Saruman", 12, 4};

    std::cout << gandalf << std::endl;
    std::cout << saruman << std::endl << std::endl;

    gandalf.Rest(0);
    gandalf.Rest(0);
    gandalf.Rest(1);
    saruman.Rest(0);
    saruman.Rest(1);
    saruman.Rest(1);

    std::cout << gandalf << std::endl;
    std::cout << saruman << std::endl << std::endl;

    saruman.Attack(gandalf);
    gandalf.Attack(saruman);
    gandalf.Attack(saruman);
    saruman.Attack(gandalf);
    gandalf.Attack(saruman);

    std::cout << gandalf << std::endl;
    std::cout << saruman << std::endl << std::endl;

    return 0;
}
