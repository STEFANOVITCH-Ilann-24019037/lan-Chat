// src/chat.c

#include <stdio.h>
#include <string.h>
#include "chat.h"

void* start_chat(void* arg) {
    char buffer[256];
    while (1) {
        printf("> ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "/quit") == 0) {
            printf("Déconnexion...\n");
            break;
        }

        // TODO : envoyer à tous les pairs connus
        printf("[MOI] %s\n", buffer);
    }
    return NULL;
}
