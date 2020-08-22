#pragma once

#include "raylib.h"
#include "helper.h"
#include "components.h"

// This will initialize main things
#define WINDOW_START(width, height, title, background) \
    {                                                  \
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);         \
        SetTraceLogLevel(LOG_ERROR);                   \
        InitWindow(width, height, title);              \
        SetTargetFPS(60);                              \
        while (!WindowShouldClose())                   \
        {                                              \
            BeginDrawing();                            \
            ClearBackground(background);               \
            DrawFPS(10, 10);

// And to end the drawing and window
#define WINDOW_END \
    EndDrawing();  \
    }              \
    CloseWindow(); \
    }

void HUI_Resource_init_empty(char *path)
{
    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);
    JSON_Value *window_value = json_value_init_object();
    JSON_Object *window_object = json_value_get_object(window_value);
    JSON_Value *background_value = json_value_init_array();
    JSON_Array *background = json_value_get_array(background_value);

    json_object_set_string(window_object, "title", "HopeUI");
    json_object_set_number(window_object, "width", 800);
    json_object_set_number(window_object, "height", 600);

    json_array_append_number(background, 255);
    json_array_append_number(background, 255);
    json_array_append_number(background, 255);
    json_array_append_number(background, 255);
    
    json_object_dotset_value(window_object, "background", background_value);
    json_object_dotset_value(root_object, "window", window_value);
    json_serialize_to_file_pretty(root_value, path);
}

void HUI_Setup()
{
    char *currentdir = cwd();
    char *resourceFolder = strcat(currentdir, platform_path_seperator);
    resourceFolder = strcat(resourceFolder, "resource");
    int exist = dirExists(resourceFolder);
    printf("\nChecking if resource folder exist at: %s\n", resourceFolder);
    if (exist != 1)
    {
        printf("\nResource folder not found... Creating one at: %s\n", resourceFolder);
        int create_new_dir = newDir(resourceFolder);
        if (create_new_dir == 0)
        {
            char *app_json_path = strcat(resourceFolder, platform_path_seperator);
            app_json_path = strcat(app_json_path, "app.json");
            printf("\nCreating resource folder success!\n");
            HUI_Resource_init_empty(app_json_path);
        }
        else
        {
            printf("\nCreating resource folder failed...\n");
            return 1;
        }
    }
    else
    {
        printf("\nResource folder found!\n");
        char *app_json_path = strcat(resourceFolder, platform_path_seperator);
        app_json_path = strcat(app_json_path, "app.json");
        printf(app_json_path);
        printf("\nLoading app.json at: %s\n", app_json_path);

        if (isFileExists(app_json_path) == 0)
        {
            printf("\nThe app.json not found... Creating one!\n");
            HUI_Resource_init_empty(app_json_path);
        }
        else
        {
            printf("\nThe app.json was found!\n");
        }
    }
}
