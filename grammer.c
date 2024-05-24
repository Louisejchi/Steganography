#include "Module/utils.h"
#include "Module/readwrite.h"
#include "Module/steganography.h"

void inject_file(char* infile, char* outfile, char* hiddenfile, char* keyfile,
                int proto0, int offset0, int proto1, int offset1, int proto2, int offset2){

    struct fields fields;
    struct fields* fields_ptr = &fields;

    /* Config the information of selector, field1 and field2. */
    set_fields(fields_ptr, proto0, offset0, proto1, offset1, proto2, offset2);
    /* Get the bytestreams of selector, field1 and field2 from the infile. */
    read(infile, fields_ptr);

    /* Inject hidden message into bytestreams of field1 and field2 with selector. */
    inject(hiddenfile, keyfile, fields_ptr);
    /* Write the new bytestreams field1 and field2 into outfile. */
    write(infile, outfile, fields_ptr);

    /* Free the bytestreams. */
    clear_bytestream(fields_ptr);

}

void select_file(char* infile, char* outfile, char* keyfile,
                int proto0, int offset0, int proto1, int offset1, int proto2, int offset2){

    struct fields fields;
    struct fields* fields_ptr = &fields;

    /* Config the information of selector, field1 and field2. */
    set_fields(fields_ptr, proto0, offset0, proto1, offset1, proto2, offset2);
    /* Get the bytestreams of selector, field1 and field2 from the infile. */
    read(infile, fields_ptr);

    /* Get the  hidden message from bytestreams of field1 and field2 with selector
     * and write into . */
    select(infile, outfile, keyfile, fields_ptr);

    /* Free the bytestreams. */
    clear_bytestream(fields_ptr);

}
