#pragma once

#include "parson.h"
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64) || defined(WINDOWS)
#include <direct.h>
#define GetCurrentDir _getcwd
#define MakeDir _mkdir
#define platform_path_seperator "\\"
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#define MakeDir mkdir
#define platform_path_seperator "/"
#endif

char *cwd()
{
    return GetCurrentDir(NULL, 0);
}

int newDir(char* path){
    return MakeDir(path);
}

char *path_join(char *a, char *b)
{
    char *str = "";
    strcat(str, a);
#if defined(_WIN32) || defined(_WIN64) || defined(WINDOWS)
    strcat(str, (char *)"\\");
#else
    strcat(str, (char *)"/");
#endif
    strcat(str, b);
    return str;
}

int isFileExists(const char *path)
{
    // Try to open file
    FILE *fptr = fopen(path, "r");

    // If file does not exists 
    if (fptr == NULL)
        return 0;

    // File exists hence close file and return true.
    fclose(fptr);

    return 1;
}

int dirExists(const char *path)
{
    struct stat info;

    if (stat(path, &info) != 0)
        return 0;
    else if (info.st_mode & S_IFDIR)
        return 1;
    else
        return 0;
}

int get_current_second()
{
    time_t now;
    struct tm *tm;

    now = time(0);
    if ((tm = localtime(&now)) == NULL)
    {
        printf("Error extracting time stuff\n");
    }

    return tm->tm_sec;
}

void something()
{
    const JSON_Value *value = json_parse_file("newCode.json");
    if (json_value_get_type(value) == JSONArray)
    {
        JSON_Array *list = json_value_get_array(value);
        for (size_t i = 0; i < json_array_get_count(list); i++)
        {
            JSON_Object *object = json_array_get_object(list, i);
            printf("Name: %s\n", json_object_get_string(object, "name"));
        }
    }
}