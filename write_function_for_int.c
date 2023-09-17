#include <unistd.h>

void intToChar(int entier, char *charArray) {
    int i = 0;
    int sign = 1;

    // Gérer le cas où l'entier est négatif
    if (entier < 0) {
        sign = -1;
        entier = -entier;
    }

    // Traitement spécial pour zéro
    if (entier == 0) {
        charArray[i++] = '0';
    } else {
        // Convertir les chiffres de l'entier en caractères (de droite à gauche)
        while (entier > 0) {
            charArray[i++] = '0' + entier % 10;
            entier /= 10;
        }

        // Inverser la chaîne de caractères car nous l'avons obtenue à l'envers
        int debut = 0;
        int fin = i - 1;
        while (debut < fin) {
            char temp = charArray[debut];
            charArray[debut] = charArray[fin];
            charArray[fin] = temp;
            debut++;
            fin--;
        }
    }

    // Ajouter le signe '-' si nécessaire
    if (sign == -1) {
        charArray[i++] = '-';
    }

    // Terminer la chaîne de caractères avec un null terminator
    charArray[i] = '\0';
}

int main() {
    int entier = -2222; // L'entier que vous souhaitez convertir en chaîne de caractères
    char charArray[20]; // Tableau de caractères pour stocker la conversion

    intToChar(entier, charArray);

    // Utiliser write pour écrire la chaîne de caractères sur la sortie standard
    write(STDOUT_FILENO, charArray, sizeof(charArray));

    return 0;
}

