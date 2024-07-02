typedef struct {
    int client;
    int socket;

    int funcionando;
} tratador;




#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <sys/time.h>       // para criar o alarme
#include <signal.h>

#include <sys/stat.h>       // para obter diretorios
#include <openssl/md5.h>    // MD5



#define CODE_PATH "./SourceCode/"



#include "./SourceCode/FileLocationManager.h"
#include "./SourceCode/FileReader.h"



//----------------------------------------------------------------



#define PORT 2984