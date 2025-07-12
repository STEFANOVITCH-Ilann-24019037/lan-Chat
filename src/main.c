// src/main.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "discovery.h"
#include "chat.h"

int main() {
    printf("🟢 Lancement du chat LAN peer-to-peer\n");

    pthread_t discovery_thread, chat_thread;

    // Lancer la découverte réseau (UDP broadcast)
    if (pthread_create(&discovery_thread, NULL, start_discovery, NULL) != 0) {
        perror("Erreur création thread discovery");
        exit(EXIT_FAILURE);
    }

    // Lancer la boucle de chat (réception + envoi)
    if (pthread_create(&chat_thread, NULL, start_chat, NULL) != 0) {
        perror("Erreur création thread chat");
        exit(EXIT_FAILURE);
    }

    pthread_join(discovery_thread, NULL);
    pthread_join(chat_thread, NULL);

    return 0;
}
