#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <unistd.h>

#include "../include/common.h"
#include "../include/file.h"
#include "../include/parse.h"

void print_usage(char *argv[]) {
    //print standard Unix usage
    printf("Usage: %s -n -f <database file>\n", argv[0]);
    printf("\t -n  - create new database file\n");
    printf("\t -f  - (required) path to database file\n");
    return;
}

int main(int argc, char* argv[]) {
    char* filepath = NULL;
    char* addstring = NULL;
    bool newfile = false;
    bool list = false;
    int dbfd = -1;
    struct dbheader_t* dbhdr = NULL;
    struct employee_t *employees = NULL;
    //set up the use flags
    int flags = 0;
    //n is boolean, f is filename and : means there will be a name
    while ((flags = getopt(argc, argv, "nf:a:l")) != -1) {
        switch (flags) {
            case 'n':
                newfile = true;
                break;
            case 'f':
                filepath = optarg;
                break;
            case 'a':
                addstring = optarg;
                break;
            case 'l':
                list = true;
                break;
            case'?':
                printf("Unknown option -%c\n", flags);
                break;
            default:
                return -1;
        }
    }

    if (filepath == NULL) {
        printf("Filepath is a required argument\n");
        print_usage(argv);

        return 0;
    }

    if (newfile) {
        dbfd = create_db_file(filepath);
        if (dbfd == STATUS_ERROR) {
            printf("Unable to create database file\n");
            return -1;
        }

        if (create_db_header(dbfd, &dbhdr) == STATUS_ERROR) {
            printf("failed to create database header\n");
            return -1; //maybe need to free
        }
    } else {
        dbfd = open_db_file(filepath);
        if (dbfd == STATUS_ERROR) {
            printf("Unable to open database file\n");
            return -1;
        }

        if (validate_db_header(dbfd, &dbhdr) == STATUS_ERROR) {
            printf("failed to validate db header\n");
            return -1; //maybe free
        }
    }

    if (read_employees(dbfd, dbhdr, &employees) != STATUS_SUCCESS) {
        printf("Failed to read employees\n");
        return 0;
    }

    if (addstring) {
        dbhdr->count++;
        employees = realloc(employees, dbhdr->count*(sizeof(struct employee_t)));

        add_employee(dbhdr, employees, addstring);
    }

    if (list) {
        list_employees(dbhdr, employees);
    }

    printf("Newfile: %d\n", newfile);
    printf("Filepath: %s\n", filepath);

    output_file(dbfd, dbhdr, employees);

    return 0;
}















