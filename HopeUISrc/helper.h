#pragma once

#include "parson.h"
#include <stdio.h>
#include <time.h>

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