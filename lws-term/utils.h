#ifndef TTYD_UTIL_H
#define TTYD_UTIL_H

// malloc with NULL check
void *
xmalloc(size_t size);

// realloc with NULL check
void *
xrealloc(void *p, size_t size);

// Convert a string to upper case
char *
uppercase(char *str);

// Check whether str ends with suffix
bool
endswith(const char * str, const char * suffix);

// Get human readable signal string
int
get_sig_name(int sig, char *buf);

// Get signal code from string like SIGHUP
int
get_sig(const char *sig_name);

// Encode text to base64, the caller should free the returned string
char *
base64_encode(const unsigned char *buffer, size_t length);

struct sbuf {
    char *buffer;
    size_t len;
    size_t size;
};

extern void sbuf_init(struct sbuf *buf);
extern void sbuf_free(struct sbuf *buf);
extern void sbuf_extend(struct sbuf *buf, int needed);
extern char *sbuf_blank(struct sbuf *buf, int space);
extern void sbuf_printf(struct sbuf *buf, const char *format, ...);
extern void sbuf_vprintf(struct sbuf *buf, const char *format, va_list ap);

#endif //TTYD_UTIL_H
