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

int convert(char* infile, char* outfile, struct fields* fields){
    puts("=============== write() ==============");
    printf("Write to: %s\n", outfile);
    printf(" Selector(ignore)\n");
    printf("   Field1: %d[%d]\n", fields->field1.protocol, fields->field1.offset);
    printf("   Field2: %d[%d]\n", fields->field2.protocol, fields->field2.offset);
    puts("========== return errorcode ==========");
}

int new_fields(struct fields* fields, int p1, int o1, int p2, int o2, int p3, int o3){
    /* selector */
    free(fields->selector.bytestream);
    fields->selector.protocol = p1;
    fields->selector.offset = o1;
    fields->selector.bytestream = NULL;
    fields->selector.length = 0;
    /* field1 */
    free(fields->field1.bytestream);
    fields->field1.protocol = p2;
    fields->field1.offset = o2;
    fields->field1.bytestream = NULL;
    fields->field1.length = 0;
    /* field2 */
    free(fields->field2.bytestream);
    fields->field2.protocol = p3;
    fields->field2.offset = o3;
    fields->field2.bytestream = NULL;
    fields->field2.length = 0;
}

int clear_bytestream(struct fields* fields){
    /* selector */
    free(fields->selector.bytestream);
    fields->selector.bytestream = NULL;
    fields->selector.length = 0;
    /* field1 */
    free(fields->field1.bytestream);
    fields->field1.bytestream = NULL;
    fields->field1.length = 0;
    /* field2 */
    free(fields->field2.bytestream);
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
    
    new_fields(fields, 1, 2, 3, 4, 5, 6);
    read("TEST1", fields);
    convert("TEST1", "TEST2", fields);
    steganography("hidden", "key", fields);
    clear_bytestream(fields);
    free(fields);
}
