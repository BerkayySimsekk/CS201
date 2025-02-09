//Berkay Simsek 22303338
using namespace std;

#include "User.h"

User::User() {
    name = "";
    ID = -1;
}

User::~User() {
    for(int i = 1; i <= playlists.getLength(); i++) {
        playlists.remove(i);
        i--;
    }
}

User::User(User& aUser) {
    name = aUser.name;
    ID = aUser.ID;

    for(int i = 1; i <= aUser.getPlaylists().getLength(); i++)
        playlists.insert(i, aUser.getPlaylists().getEntry(i));
}

User::User(const string userName, const int userID) {
    name = userName;
    ID = userID;
}

void User::sortPlaylistsByAscendingOrder() {
    for(int i = 1; i <= getPlaylists().getLength(); i++)
        for(int j = 1; j <= getPlaylists().getLength() - i; j++)
            if(getPlaylists().getEntry(j).getID() > getPlaylists().getEntry(j + 1).getID()) {
                Playlist temp(getPlaylists().getEntry(j));
                getPlaylists().remove(j);
                getPlaylists().insert(j + 1, temp);
            }
}

void User::setName(const string userName) {
    name = userName;
}

void User::setID(const int userID) {
    ID = userID;
}

string User::getName() const {
    return name;
}

int User::getID() const {
    return ID;
}

LinkedList<Playlist>& User::getPlaylists() {
    return playlists;
}
