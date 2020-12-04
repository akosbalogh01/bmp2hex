#   include <stdio.h>
#   include <stdint.h>

uint8_t data[1024] = {0};
uint8_t output[1024] = {0};

int main(void) {
    uint8_t i, j, k;
    FILE* in  = NULL;
    FILE* outbin = NULL;
    FILE* outhex = NULL;
    outbin = fopen("out.bin", "w");
    outhex = fopen("out.txt", "w");
    in = fopen("data.bmp", "r");
    if (in == NULL) {return -1;}

    for (i = 0; i < 190; i++) {
        data[i] = fgetc(in);
    }

    for (i = 0x3E; i < 190; i++) {
        output[i - 0x3E] = ~data[i];
    }

    for (i = 0; i < (190 - 0x3E); i++) {
        fputc(output[i], outbin);
    }

    for (j = 32; j > 0; j--) {
        for (k = 0; k < 4; k++) {
            fprintf(outhex, "0x%02X, ", output[((j-1)*4)+k]);
        }

        fputc('\n', outhex);
    }

    return 0;
}
