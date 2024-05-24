struct fields{
    struct {
        int protocol;
        int offset;
        char* bytestream;
        int length;
    } selector, field1, field2;
} fields;

enum{
    ENUM_IP,
    ENUM_UDP,
    ENUM_TCP
} protocol;

