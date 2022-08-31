#include <stdint.h>
#include <stdio.h>

#define MSG_PAYLOAD_LEN 0xFF
static int16_t msg_payload_a[MSG_PAYLOAD_LEN * 8] = {0};
static int16_t msg_payload_b[MSG_PAYLOAD_LEN * 8] = {0};

// Unsecure modification
void set_msg_payload(int16_t *msg_payload, 
                     int16_t index, 
                     int16_t value)
{
    msg_payload_a[index] = value;

    // Invalid modification
    msg_payload_a[index + MSG_PAYLOAD_LEN * 9] = value; 
}

int main(int argc, char *argv[])
{
    set_msg_payload(msg_payload_a, 0, 0xFF);
    printf("%i\n", msg_payload_a[0]); // 0xff -> 255
    printf("%i\n", msg_payload_b[MSG_PAYLOAD_LEN]); // 0xff -> 255
    return 0;
}

