
// s_handler is pointer to function (const char*) -> void
static void (*s_handler)(const char*) = NULL;

// handler is pointer to function (const char*) -> void
void register_error_handler(void (*handler)(const char* msg)) {
    s_handler = handler;
}

void log_error(const char* msg) {
    if (s_handler != NULL) {
        // (const char*) -> void
        s_handler(msg);
    }
}
