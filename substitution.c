#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int keyc, string key[])

{

    //Checking number of command line arguments passed

    if (keyc != 2)

    {

        printf("Usage: ./substitution key\n");

        return 1;

    }


    //Checking if key has 26 characters

    int keyn = strlen(key[1]);

    if (keyn != 26)

    {

        printf("Key must contain 26 characters.\n");

        return 1;

    }

    //Declaring alphabet array for comparison and substitution

    int alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


    int count = 0, num = 0;


    //Checking if key has duplicate characters


    for (int k = 0; k < 26; k++)

    {
        for (int l = k + 1; l < 26; l++)

        {
            if (key[1][k] == key[1][l])

            {

                count++;

            }

        }

        //Checking if key contains numbers

        if (isdigit(key[1][k]))

        {
            num++;
        }
    }


    //Printing error message


    if (count != 0 || num != 0)

    {
        printf("Key should contain only alphabets and no duplicate characters\n");

        return 1;
    }


    string text = get_string("plaintext:  ");

    printf("ciphertext: ");

    int n = strlen(text);

    //Substituting plain text with encrypted text

    for (int i = 0; i < n; i++)

    {

        for (int j = 0; j < 26; j++)

        {

            if (toupper(text[i]) == alpha[j])

            {

                //Retaining the case of text

                if (islower(text[i]) > 0)

                {

                    printf("%c", tolower(key[1][j]));

                }

                else if (islower(text[i]) == 0)

                {

                    printf("%c", toupper(key[1][j]));

                }

            }


        }

        //Ensuring to retain commas,spaces,periods and numbers

        if (text[i] == ',' || text[i] == ' ' || text[i] == '.' || isdigit(text[i]))

        {
            printf("%c", text[i]);
        }
    }


    printf("\n");

    return 0;

}
