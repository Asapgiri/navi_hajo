# include "serialbuffer.h"

SerialBuffer::SerialBuffer(const uint16_t _size) {
    buffer_size = _size;
    buffer = (String *)malloc(sizeof(String) * buffer_size);
}

void SerialBuffer::push(String &str) {
    if (buffer_lenght < buffer_size) {
        buffer_index++;
        if (buffer_index >= buffer_size) buffer_index = 0;
        buffer[buffer_index] = str;
    }
}

String SerialBuffer::pop() {
    String str_ret = buffer_lenght > 0 ? buffer[buffer_start] : "";

    if (buffer_lenght > 0) {
        buffer_start++;
        buffer_lenght--;
        if (buffer_start >= buffer_size) buffer_start = 0;
    }

    return str_ret;
}
