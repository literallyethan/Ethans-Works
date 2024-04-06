#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

#include "../include/common.h"
#include "../include/parse.h"

int create_db_header(int fd, struct dbheader_t** headerOut) {
    struct dbheader_t* header = calloc(1, sizeof(struct dbheader_t));
    if (header == NULL) {
        printf("calloc failed to make db header\n");
        free(header);
        return STATUS_ERROR;
    }

    header->version = 0x1;
    header->count = 0;
    header->magic = HEADER_MAGIC;
    header->filesize = sizeof(struct dbheader_t);

    *headerOut = header; //moves header outside of function so others can use it

    return STATUS_SUCCESS;

}

int validate_db_header(int fd, struct dbheader_t** headerOut) {
    if (fd < 0) {
        printf("got a bad fd from the user\n");
        return STATUS_ERROR;
    }

    struct dbheader_t* header = calloc(1, sizeof(struct dbheader_t));
    if (header == NULL) {
        printf("calloc failed to make db header\n");
        return STATUS_ERROR; //should maybe free
    }

    if (read(fd, header, sizeof(struct dbheader_t)) != sizeof(struct dbheader_t)) {
        perror("read");
        free(header);
        return STATUS_ERROR;
    } //reads data from disk to header

    header->version = ntohs(header->version);
    header->count = ntohs(header->count);
    header->magic = ntohl(header->magic);
    header->filesize = ntohl(header->filesize);

    if (header->version != 1) {
        printf("Improper header version!\n");
        free(header);
        return -1;
    }

    if (header->magic != HEADER_MAGIC) {
        printf("Improper header magic!\n");
        free(header);
        return -1;
    }

    struct stat dbstat = {0};
    fstat(fd, &dbstat);
    if (header->filesize != dbstat.st_size) {
        printf("corrupted database\n");
        free(header);
        return STATUS_ERROR;
    }

    *headerOut = header;
}

void output_file(int fd, struct dbheader_t* dbhdr, struct employee_t* employees) {
    if (fd < 0) {
        printf("got a bad fd from the user\n");
        return; //STATUS_ERROR;
    }

    int realcount = dbhdr->count;

    dbhdr->magic = htonl(dbhdr->magic);
    dbhdr->filesize = htonl(sizeof(struct dbheader_t) + sizeof(struct employee_t) * realcount);
    dbhdr->count = htons(dbhdr->count);
    dbhdr->version = htons(dbhdr->version);

    lseek(fd, 0, SEEK_SET);

    write(fd, dbhdr, sizeof(struct dbheader_t));

    for(int i = 0; i < realcount; ++i) {
        employees[i].hours = htonl(employees[i].hours);
        write(fd, &employees[i], sizeof(struct employee_t));
    }

}

int read_employees(int fd, struct dbheader_t* dbhdr, struct employee_t** employeesOut) {
    if (fd < 0) {
        printf("got a bad fd from the user\n");
        return STATUS_ERROR;
    }

    int count = dbhdr->count;
    struct employee_t* employees = calloc(count, sizeof(struct employee_t));
    if (employees == NULL) {
        printf("calloc fails\n");
        return STATUS_ERROR;
    }

    read(fd, employees, count*sizeof(struct employee_t));

    //loop to unpack endianness
    for (int i = 0; i < count; ++i) {
        employees[i].hours = ntohl(employees[i].hours);
    }

    *employeesOut = employees;
    return STATUS_SUCCESS;
}

int add_employee(struct dbheader_t* dbhdr, struct employee_t* employees, char* addstring) {
    printf("%s\n", addstring);

    char* name = strtok(addstring, ",");
    char* addr = strtok(NULL, ",");
    char* hours = strtok(NULL, ",");

    printf("%s %s %s\n", name, addr, hours);

    strncpy(employees[dbhdr->count-1].name, name, sizeof(employees[dbhdr->count-1].name));
    strncpy(employees[dbhdr->count-1].address, addr, sizeof(employees[dbhdr->count-1].address));
    employees[dbhdr->count-1].hours = atoi(hours);

    return STATUS_SUCCESS;
}

void list_employees(struct dbheader_t* dbhdr, struct employee_t* employees){
    for (int i = 0; i < dbhdr->count; ++i) {
        printf("Employee %d\n", i);
        printf("\tName: %s\n", employees[i].name);
        printf("\tAddress: %s\n", employees[i].address);
        printf("\tHours: %s\n", employees[i].hours);
    }
}



























































