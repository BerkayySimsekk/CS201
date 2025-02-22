//Berkay Simsek 22303338
#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

#include "LinkedList.cpp"
#include "Playlist.h"

class Playlist;

class User {
private:
    string name;
    int ID;
    LinkedList<Playlist> playlists;
public:
    User();
    ~User();
    User(User& aUser);
    User(const string userName, const int userID);
    void setName(const string userName);
    void setID(const int ID);
    string getName() const;
    int getID() const;
    LinkedList<Playlist>& getPlaylists();
    void sortPlaylistsByAscendingOrder();
};

#endif //USER_H
