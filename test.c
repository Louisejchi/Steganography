#include <stdio.h>
#include <malloc.h>

struct fields{
    struct {
        int protocol;
        int offset;
        char* bytestream;
        int length;
    } selector, field1, field2;
};

int read(char* infile, struct fields* fields){
    puts("=============== read() ===============");
    printf("Read from: %s\n", infile);
    printf(" Selector: %d[%d]\n", fields->selector.protocol, fields->selector.offset);
    printf("   Field1: %d[%d]\n", fields->field1.protocol, fields->field1.offset);
    printf("   Field2: %d[%d]\n", fields->field2.protocol, fields->field2.offset);
    puts("========== return errorcode ==========");
}

int write(char* outfile, struct fields* fields){
    puts("=============== write() ==============");
    printf("Write to: %s\n", outfile);
    printf(" Selector(ignore)\n");
    printf("   Field1: %d[%d]\n", fields->field1.protocol, fields->field1.offset);
    printf("   Field2: %d[%d]\n", fields->field2.protocol, fields->field2.offset);
    puts("========== return errorcode ==========");
}

int clear_fields(struct fields* fields){
    /* selector */
    free(fields->selector.bytestream);
    fields->selector.protocol = 0;
    fields->selector.offset = 0;
    fields->selector.bytestream = NULL;
    fields->selector.length = 0;
    /* field1 */
    free(fields->field1.bytestream);
    fields->field1.protocol = 0;
    fields->field1.offset = 0;
    fields->field1.bytestream = NULL;
    fields->field1.length = 0;
    /* field2 */
    free(fields->field2.bytestream);
    fields->field2.protocol = 0;
    fields->field2.offset = 0;
    fields->field2.bytestream = NULL;
    fields->field2.length = 0;
}

int steganography(char* hiddenfile, char* keyfile, struct fields* fields){
    puts("=========== steganography() ==========");
    printf("Hidden Information: %s\n", hiddenfile);
    printf("Secret Key: %s\n", keyfile);
    printf(" Selector: %d[%d]\n", fields->selector.protocol, fields->selector.offset);
    printf("   Field1: %d[%d]\n", fields->field1.protocol, fields->field1.offset);
    printf("   Field2: %d[%d]\n", fields->field2.protocol, fields->field2.offset);
    puts("========== return errorcode ==========");
}

int main(){
    struct fields* fields = malloc(sizeof(struct fields));
    
    clear_fields(fields);
    read("TEST1", fields);
    write("TEST2", fields);
    steganography("hidden", "key", fields);
}
