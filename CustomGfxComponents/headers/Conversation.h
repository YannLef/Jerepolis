void initMessage(Message* msg, bool sender, char* string);
void libereMessage(Message* msg);
void ajouteMessage(Message*** messages, Message* msg, int nbMessageMax, int* nbMessage);
void afficheConversation(Message** messages, int nbMessage, DonneesImageRGB* user, DonneesImageRGB* help);
