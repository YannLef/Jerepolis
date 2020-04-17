void initMessage(message* msg, bool sender, char* string);
void libereMessage(message* msg);
void ajouteMessage(message*** messages, message* msg, int nbMessageMax, int* nbMessage);
void afficheConversation(message** messages, int nbMessage, DonneesImageRGB* user, DonneesImageRGB* help);
