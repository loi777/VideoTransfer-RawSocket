#include "VideoTransfer.h"

//=============================

//=============================


int main() {

    while(1) {

        printf("\nVideo file transfer:\n1) try connection (as sender)\n2) try connection (as receiver)\n3) close program\n");

        //

        int input;

        scanf("%d", &input);

        //

        switch(input) {

            case(1) :
                printf("Attempting to connect...\n");
            break;

            case(2) :
                printf("Attempting to connect...\n");
            break;

            case(3) :
                printf("Closing...\n");
                return 0;
            break;

        }

    }

}
