#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <linux/input.h>

// clang-format off
const struct input_event
syn       = {.type = EV_SYN , .code = SYN_REPORT   , .value = 0};
// clang-format on

// KEY_RIGHTALT

int read_event(struct input_event *event) {
    return fread(event, sizeof(struct input_event), 1, stdin) == 1;
}

void write_event(const struct input_event *event) {
    if (fwrite(event, sizeof(struct input_event), 1, stdout) != 1)
        exit(EXIT_FAILURE);
}

unsigned short replaceCode(unsigned short code) {
    switch (code) {
        case KEY_H:
            return KEY_LEFT;
        case KEY_J:
            return KEY_DOWN;
        case KEY_K:
            return KEY_UP;
        case KEY_L:
            return KEY_RIGHT;
        default:
            return code;
    }
}


int main() {
    int isRightAltPressed = 0;
    struct input_event input;

    setbuf(stdin, NULL), setbuf(stdout, NULL);

    while (read_event(&input)) {
        if (input.type == EV_MSC && input.code == MSC_SCAN)
            continue;

        if (input.type != EV_KEY && input.type != EV_REL &&
            input.type != EV_ABS) {
            write_event(&input);
            continue;
        }

        if (input.type == EV_KEY && input.code == KEY_RIGHTALT) {
            isRightAltPressed = input.value;
        } else if (isRightAltPressed) {
            input.code = replaceCode(input.code);
        }

        write_event(&input);
        write_event(&syn);
    }
}

