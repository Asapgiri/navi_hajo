#include <Arduino.h>

class SerialBuffer {
    private:
        int buffer_index = 0;
        int buffer_size;
        int buffer_start = 0;
        int buffer_lenght = 0;
        String *buffer;
    public:
        SerialBuffer(const uint16_t _size);
        void push(String &str);
        String pop();
};