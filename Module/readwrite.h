#include "utils.h"
int read_pcap(const char *infile, int protocal, int start, int size, char **data, int *data_size);
int write_pcap(const char *infile, const char *outfile, 
               int protocal, int start, int size, char *data, int data_size);
