#include <_types/_uint16_t.h>
#include <stdint.h>
#include <stdio.h>

static uint16_t msg_payload_a[sizeof(uint16_t) * 8] = {0};
static uint16_t msg_payload_b[sizeof(uint16_t) * 4] = {0};

// Unsecure modification
void set_msg_payload(uint16_t *msg_payload, 
                     uint16_t index, 
                     uint16_t value)
{
    msg_payload_a[index] = value;

    // Invalid modification
    msg_payload_a[index + sizeof(uint16_t) * 9] = value; 
}

int main(int argc, char *argv[])
{
    set_msg_payload(msg_payload_a, 0, 0xFF);
    printf("%i\n", msg_payload_a[0]); // 0xff -> 255
    printf("%i\n", msg_payload_b[sizeof(uint16_t)]); // 0xff -> 255
    return 0;
}

