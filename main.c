#include <stdio.h>

int getMaj(int x8, int y10, int z10); // returns the majority vote

#define KEYSTREAMS 8

int main()
{

    int X[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    int Y[] = {1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1};
    int Z[] = {1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
    int KEY[KEYSTREAMS] = {0};

    for (int keyBIt = 0; keyBIt < KEYSTREAMS; keyBIt++)
    {

        int maj = getMaj(X[8], Y[10], Z[10]);
        // printf("maj %d\n", maj);
        int t = 0;

        if (X[8] == maj)
        { // x steps
            t = X[13] ^ X[16] ^ X[17] ^ X[18];
        
            for (int i = sizeof(X) / sizeof(X[0]); i > 0; i--)
            {
                X[i - 1] = X[i - 2];
            }

                X[0] = t;
        }

        if (Y[10] == maj)
        { // y steps

            t = Y[20] ^ Y[21];
        
            for (int i = sizeof(Y) / sizeof(Y[0]); i > 0; i--)
            {
                Y[i - 1] = Y[i - 2];
            }

                Y[0] = t;
        }

        if (Z[10] == maj)
        { // z steps
            t = Z[7] ^ Z[20] ^ Z[21] ^ Z[22];
          
            for (int i = sizeof(Z) / sizeof(Z[0]); i > 0; i--)
            {
                Z[i - 1] = Z[i - 2];
            }

              Z[0] = t;
        }

        // printf("keyBit : %d\n", X[18] ^ Y[21] ^ Z[22]);
        KEY[keyBIt] = X[18] ^ Y[21] ^ Z[22];
    }

    printf("KEYSTREAM: ");
    for (int i = 0; i < sizeof(KEY) / sizeof(KEY[0]); i++)
    {
        printf("%d", KEY[i]);
    }
    printf("\n");

    printf("X: ");
    for (int i = 0; i < sizeof(X) / sizeof(X[0]); i++)
    {
        printf("%d", X[i]);
    }
    printf("\n");

    printf("Y: ");
    for (int i = 0; i < sizeof(Y) / sizeof(Y[0]); i++)
    {
        printf("%d", Y[i]);
    }
    printf("\n");

    printf("Z: ");
    for (int i = 0; i < sizeof(Z) / sizeof(Z[0]); i++)
    {
        printf("%d", Z[i]);
    }
    printf("\n");

    return 0;
}

int getMaj(int x8, int y10, int z10)
{
    // printf("x y z: %d, %d, %d\n", x8, y10, z10);

    if(x8&y10&z10) return 1;

    if(!x8&!y10&!z10) return 0;

    return !(x8 ^ y10 ^ z10);
}