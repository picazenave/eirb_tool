#pragma once
#define ANSI_RED "\033[1;31m"
#define ANSI_YELLOW "\033[1;33m"
#define ANSI_GREEN "\033[1;32m"
#define ANSI_BLUE "\033[1;34m"
#define ANSI_MAGENTA "\033[1;35m"
#define ANSI_CYAN "\033[1;36m"
#define ANSI_WHITE "\033[1;37m"
#define ANSI_BOLD "\033[1;1m"
#define ANSI_UNDERLINE "\033[1;4m"
#define ANSI_RESET "\033[0m"


int extract_line(const char *full, const char *to_search, char *sub, int sens);
void str_before_delimiter(const char *full, const char delimiter, char *sub);