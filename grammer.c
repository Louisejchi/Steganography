#include <stdio.h>
#include <malloc.h>
#include "Module/utils.h"
#include "Module/readwrite.h"
#include "Module/steganography.h"

void inject_file(char* infile, char* outfile, char* hiddenfile, char* keyfile,
                 int protocal, int start, int size){

    /* Declare Variables*/
    char *data = NULL;
    int data_size = 0;

    /* Get the bytestream. */
    read_pcap(infile, protocal, start, size, &data, &data_size);

    /* Inject hidden message into the bytestream. */
    inject(hiddenfile, keyfile, protocal, start, size, &data, data_size);

    /* Write the bytestream. */
    write_pcap(infile, outfile, protocal, start, size, data, data_size);

    /* Free the bytestream. */
    free(data);

}

void select_file(char* infile, char* outfile, char* keyfile,
                 int protocal, int start, int size){

    /* Declare Variables*/
    char *data = NULL;
    int data_size = 0;

    /* Get the bytestream. */
    read_pcap(infile, protocal, start, size, &data, &data_size);

    /* Get the hidden message from the bytestream. */
    select(infile, outfile, keyfile, protocal, start, size, data, data_size);

    /* Free the bytestreams. */
    free(data);

}

void chi_square_analysis_of_file(char* infile, int protocal, int start, int size){

    /* Declare Variables*/
    char *data = NULL;
    int data_size = 0;

    /* Get the bytestream. */
    read_pcap(infile, protocal, start, size, &data, &data_size);

    /* Analysis */
    double result = chi_square_analysis(data, size, data_size / start);
    
    /* Output */
    printf("%f\n", result);

    /* Free the bytestreams. */
    free(data);

}

void rescaled_range_analysis_of_file(char* infile, int protocal, int start, int size){

    /* Declare Variables*/
    char *data = NULL;
    int data_size = 0;

    /* Get the bytestream. */
    read_pcap(infile, protocal, start, size, &data, &data_size);

    /* Analysis */
    double result = chi_square_analysis(data, size, data_size / start);
    
    /* Output */
    printf("%f\n", result);

    /* Free the bytestreams. */
    free(data);

}

void help(int type){
    if(!type){
        /* Title */
        puts("Compiler Term Project: Steganography");
    }
    if(!type || type == ENUM_DEF){
        /* Define Grammer */
        puts("DEFINITION");
        puts("\tSELECT");
        puts("\tINJECT");
    }
    if(!type || type == ENUM_SELECT || type == ENUM_INJECT || type == ENUM_GRAMMER ){
        /* Grammer */
        puts("GRAMMAR");
    }
    if(!type || type == ENUM_INJECT || type == ENUM_GRAMMER ){
        /* Steganography */
        puts("\tSteganography");
        printf("\t");
    }
    if(!type || type == ENUM_INJECT || type == ENUM_GRAMMER ){
        puts("  INJECT \e[4mmessage\e[0m INTO \e[4min.pcap\e[0m USEKEY \e[4mkey\e[0m "
             "IF \e[4mproto1[offset1]\e[0m DO \e[4mproto2[offset2]\e[0m ELSE \e[4mproto3[offset3]\e[0m "
             "OUT \e[4mout.pcap\e[0m;");
    }
    if(!type || type == ENUM_INJECT || type == ENUM_GRAMMER ){
        printf("\t");
    }
    if(!type || type == ENUM_INJECT || type == ENUM_GRAMMER ){
        puts("  INJECT \e[4mmessage\e[0m INTO \e[4min.pcap\e[0m USEKEY \e[4mkey\e[0m "
             "IF \e[4mproto1[offset1]\e[0m DO \e[4mproto2[offset2]\e[0m ELSE \e[4mproto3[offset3]\e[0m;");
    }
    if(!type || type == ENUM_SELECT || type == ENUM_GRAMMER ){
        /* Extract */
        puts("\tExtract");
        printf("\t");
    }
    if(!type || type == ENUM_SELECT || type == ENUM_GRAMMER ){
        puts("  SELECT FROM \e[4mcovert.pcap\e[0m INTO \e[4mextract\e[0m USEKEY \e[4mkey\e[0m "
             "IF \e[4mproto1[offset1]\e[0m DO \e[4mproto2[offset2]\e[0m ELSE \e[4mproto3[offset3]\e[0m;");
    }
    if(!type){
        puts("");
        /* Argument */
        puts("ARGUMENT");
        /* in.pcap */
        puts("\t\e[4min.pcap\e[0m");
        puts("\t\tThe input PCAP file is used for hiding data.");
        /* out.pcap */
        puts("\t\e[4mout.pcap\e[0m");
        puts("\t\tThe output PCAP file contains hidden data. The default filename is \e[3mcovert.pcap\e[0m.");
        /* covert.pcap */
        puts("\t\e[4mcovert.pcap\e[0m");
        puts("\t\tThe input PCAP file may contain hidden data.");
        /* message */
        puts("\t\e[4mmessage\e[0m");
        puts("\t\tThe file has the data you want to hide.");
        /* key */
        puts("\t\e[4mkey\e[0m");
        puts("\t\tThe file has the key used to do hidden data.");
        /* extract */
        puts("\t\e[4mextract\e[0m");
        puts("\t\tThe file has the extracted data from covert.pcap.");
        /* proto */
        puts("\t\e[4mproto\e[0m");
        puts("\t\tThe protocol name, including \e[3mIP, UDP, TCP\e[0m");
        /* offset */
        puts("\t\e[4moffset\e[0m");
        puts("\t\tThe offset of the \e[4mproto\e[0m header.");
        /* proto[offset] */
        puts("\t\e[4mproto1[offset1]\e[0m");
        puts("\t\tThe byte is used to select the byte which is used to hide data.");
        puts("\t\e[4mproto2[offset2]\e[0m");
        puts("\t\e[4mproto3[offset3]\e[0m");
        puts("\t\tThe byte is used to hide data.");
    }
        puts("");
}
